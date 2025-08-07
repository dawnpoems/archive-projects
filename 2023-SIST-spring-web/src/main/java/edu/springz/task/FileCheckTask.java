package edu.springz.task;

import java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.stream.Collectors;

import org.springframework.scheduling.annotation.Scheduled;
import org.springframework.stereotype.Component;

import edu.springz.domain.BoardAttachVO;
import edu.springz.mapper.BoardAttachMapper;
import lombok.AllArgsConstructor;
import lombok.extern.log4j.Log4j;

@Component
@Log4j
@AllArgsConstructor
public class FileCheckTask {
	private BoardAttachMapper attachMapper;

	// 5. 어제 날짜의 폴더 문자열을 반환하는 getYesterdayFolder 메서드 작성
	public String getYesterdayFolder() {
		SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
		String str = sdf.format(new Date().getTime() - (1000 * 60 * 60 * 24));

		return str.replace("-", File.separator);
	}

	// 초 분 시 일 월 요일 [연도]
	@Scheduled(cron = "0 0 9 * * *")
	public void checkFiles() throws Exception {
		Date now = new Date();
		log.warn("checkFiles()........." + now.toLocaleString());
		log.warn("========================================");

		// 데이터베이스에서 어제 날짜의 첨부파일 목록 가져오기
		List<BoardAttachVO> attachList = attachMapper.yesterdayFiles();

		List<Path> folderList = attachList.stream()
				.map(bavo -> Paths.get("c:\\upload\\", bavo.getUpFolder(), bavo.getUuid() + "_" + bavo.getFileName()))
				.collect(Collectors.toList());

		attachList.stream().filter(bavo -> bavo.isImage() == true) //이미지인 경우
							.map(bavo -> Paths.get("c:\\upload\\", 
								bavo.getUpFolder(), "s_" + //s_를 붙여서
								bavo.getUuid() + "_" +
								bavo.getFileName()))
							.forEach(path -> folderList.add(path)); // 폴더 리스트에 추가
		
		// 업로드 폴더에서 어제 날짜 폴더의 실제 파일 가져오기
		
		File realFile = Paths.get("c:\\upload\\", getYesterdayFolder()).toFile();
		log.warn("REAL fILE : " + realFile);
		// 여기까지 하면 어제 파일의 경로가 realFile 객체에 담김
		
		//삭제 대상 파일들 추출 - 데이터베이스에 X
		File[] removeFiles = realFile.listFiles(
				file-> folderList.contains(file.toPath()) == false);
		//realfile안에 있는 파일 리스트를 가져와서 folderlist에 없는 경우만 추출
		
		//삭제 대상 파일들 제거
		for (File file : removeFiles) {
			log.warn(file.getAbsoluteFile());
			file.delete();
		}
		//그 없는 파일들제거

	}

}
