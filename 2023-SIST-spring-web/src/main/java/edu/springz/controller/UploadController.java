package edu.springz.controller;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.nio.file.Files;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.UUID;

import org.springframework.core.io.FileSystemResource;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.util.FileCopyUtils;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.multipart.MultipartFile;

import edu.springz.domain.AttachFileDTO;
import lombok.extern.log4j.Log4j;
import net.coobird.thumbnailator.Thumbnailator;

@Controller
@Log4j
public class UploadController {
	
	@PostMapping("/deleteFile")
	public ResponseEntity<String> deleteFile(String fileName, String type){
		log.info("---------------------");
		log.info("deleteFile : " + fileName);
		log.info("deleteFileType : " + type);
		//이미지면 원본 + 썸네일 지우고 파일이면 원본만 지우면 됨
		
		try {
			File file = new File("c:\\upload\\" + URLDecoder.decode(fileName, "UTF-8"));
			file.delete(); //파일 삭제
			
			//이미지 파일이면 원본 파일 삭제
			if (type.equals("image")) {
				String originFile = file.getAbsolutePath().replace("s_", ""); // 원본 파일명
				file = new File(originFile);
				file.delete();
			}
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
			return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		}
		
		return new ResponseEntity<>("deleted", HttpStatus.OK);
	}
	
	//현재 시점의 '연/월/일' 폴더 경로 문자열 생성하여 반환
	public String getFolder() {
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
		String str = sdf.format(new Date());
		
		return str.replace("-", File.separator); //-를 파일에서 쓰는 경로구분자로 바꾼 뒤 반환
	}
	//이미지 파일 여부 확인
	public boolean checkImgType(File file) {
		try {
			String contentType = Files.probeContentType(file.toPath()); //파일경로를 알려주면, 타입체크
			return contentType.startsWith("image");
		} catch (IOException e) {
			e.printStackTrace();
		}
		return false;
	}

	//썸네일 이미지 전송
	@GetMapping("/display")
	public ResponseEntity<byte[]> display(String fileName) {
		File file = new File("c:\\upload\\" + fileName);
		ResponseEntity<byte[]> result = null;
		
		HttpHeaders header = new HttpHeaders();
		try {
			header.add("Content-Type", Files.probeContentType(file.toPath()));
			result = new ResponseEntity<byte[]>(
						FileCopyUtils.copyToByteArray(file), header, HttpStatus.OK);
		} catch (IOException e) {
			e.printStackTrace();
		}
		return result;
	}
	
	//파일 다운로드
	@GetMapping(value="/download", produces=MediaType.APPLICATION_OCTET_STREAM_VALUE)
	public ResponseEntity<Resource> download(String fileName){
		Resource resource = new FileSystemResource("c:\\upload\\" + fileName);
		log.info("resource : " + resource);
		
		if(!resource.exists()) {
			return new ResponseEntity<>(HttpStatus.NOT_FOUND);
		}
		
		String fileNm = resource.getFilename();
		
		//UUID 제거한 이름으로 돌려주기
		fileNm = fileNm.substring(fileNm.indexOf("_") + 1);
		
		HttpHeaders header = new HttpHeaders();
		try {
			header.add("Content-Disposition", "attachment; filename="
						+ new String(fileNm.getBytes("UTF-8"), "ISO-8859-1"));
		} catch (UnsupportedEncodingException e) {
			e.printStackTrace();
		} 
		return new ResponseEntity<>(resource, header, HttpStatus.OK);
	}
	
	@GetMapping("/upload/ajaxAction")
	public void uploadAjax() {
		log.info("upload ajaxAction");
	}

	@PostMapping("/upload/ajaxAction")
	public ResponseEntity<List<AttachFileDTO>> uploadAjaxAction(MultipartFile[] uploadFile) {
		List<AttachFileDTO> attachList = new ArrayList<>();
		
		log.info("upload action");
		String upPath = "c:\\upload";
		
		//업로드 폴더 아래에 연/월/일 폴더 생성
		File upFolder = new File(upPath, getFolder());
		log.info("upFolder : " + upFolder);
		
		//업로드 경로에 해당 폴더가 없는 경우에는 생성
		if (!upFolder.exists()) { 
//			upFolder.mkdir(); //준 문자열의 폴더를 생성, 상위 디렉토리가 존재하지 않을 경우 생성 불가
			upFolder.mkdirs(); //준 문자열의 폴더를 생성, 상위 디렉토리가 존재하지 않을 경우 그것까지 생성
		}
		
		
		for (MultipartFile multi : uploadFile) {
			log.info("----------------------------");
			log.info("file name : " + multi.getOriginalFilename());
			log.info("file size : " + multi.getSize());
			
			UUID uuid = UUID.randomUUID(); //128비트로 실행할 때마다 랜덤한 아이디를 넘겨줌
			log.info(uuid);

//			File saveFile = new File(upPath, multi.getOriginalFilename());
			String upFilename = uuid + "_" + multi.getOriginalFilename();
			File saveFile = new File(upFolder, upFilename);

			AttachFileDTO attachDTO = new AttachFileDTO();
			attachDTO.setFileName(multi.getOriginalFilename());
			attachDTO.setUpFolder(getFolder());
			attachDTO.setUuid(uuid.toString());
			
			try {
				multi.transferTo(saveFile);
				if(checkImgType(saveFile)) { //이미지 파일의 경우 썸네일 이미지 생성
					attachDTO.setImage(true);
					FileOutputStream fos = new FileOutputStream(new File(upFolder, "s_" + upFilename));
					Thumbnailator.createThumbnail(multi.getInputStream(), fos, 100, 100);		
					fos.close();
				}
			} catch (IllegalStateException | IOException e) {
				e.printStackTrace();
			}
			attachList.add(attachDTO);
		} //END for
		return new ResponseEntity<>(attachList, HttpStatus.OK);
	}//END uploadAjaxAction;

	@GetMapping("/upload/formAction")
	public void uploadForm() {
		log.info("upload formAction");
	}

	@PostMapping("/upload/formAction")
	public void uploadAction(MultipartFile[] uploadFile) {
		log.info("upload action");
		String upPath = "c:\\upload";
		for (MultipartFile multi : uploadFile) {
			log.info("----------------------------");
			log.info("file name : " + multi.getOriginalFilename());
			log.info("file size : " + multi.getSize());

			File saveFile = new File(upPath, multi.getOriginalFilename());

			try {
				multi.transferTo(saveFile);
			} catch (IllegalStateException | IOException e) {
				e.printStackTrace();
			}
		}
	}
}
