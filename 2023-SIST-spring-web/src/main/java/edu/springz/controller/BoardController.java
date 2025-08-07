package edu.springz.controller;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import edu.springz.domain.BoardAttachVO;
import edu.springz.domain.BoardVO;
import edu.springz.domain.Criteria;
import edu.springz.domain.PageDTO;
import edu.springz.domain.ReplyPageDTO;
import edu.springz.mapper.BoardAttachMapper;
import edu.springz.service.BoardService;
import lombok.AllArgsConstructor;
import lombok.Setter;
import lombok.extern.log4j.Log4j;

//스프링이 관리하는 빈 컨트롤러가 되도록 어노테이션 지정
//생성자 인젝션 어노테이션 지정
// /board/로 들어오는 모든 요청을 처리하도록 어노테이션 지정

@Controller
@AllArgsConstructor
@RequestMapping("/board/*")
@Log4j
public class BoardController {
	
	//생성자 인젝션의 대상이 되는 필드 선언
	private BoardService boardService;
	
	
	//첨부파일 삭제(게시물 삭제용)
	public void deleteAttach(List<BoardAttachVO> attachList) {
		log.info("deleteAttach......" + attachList);
		
		if(attachList == null || attachList.size() < 1) {
			return;
		}
		
		attachList.forEach(abvo -> {
			Path file = Paths.get("c:\\upload\\" + abvo.getUpFolder() + "\\" + abvo.getUuid() + "_" + abvo.getFileName());
			try {
				Files.deleteIfExists(file); // 파일이 존재하면 삭제
				
				if(Files.probeContentType(file).startsWith("image")) {
					Path thumbnail = Paths.get("c:\\upload\\" + abvo.getUpFolder() + "\\s_" + abvo.getUuid() + "_" + abvo.getFileName());
					Files.delete(thumbnail); //썸네일 삭제
				}
			} catch (IOException e) {
				e.printStackTrace();
			} 
		});
	}
	
	
	//첨부파일 목록 가져오기
	@GetMapping("attachList")
	public ResponseEntity<List<BoardAttachVO>> attachList(int bno) {
		log.info("attachList()..........");
		//첨부파일 목록과 200번 코드 반환
		return new ResponseEntity<>(boardService.attachList(bno), HttpStatus.OK);
	}
	
	//게시물 삭제
	@PostMapping("remove")
	public String remove(int bno, RedirectAttributes rttr, Criteria cri) {
		log.info("remove()..........");
		
		List<BoardAttachVO> attachList = boardService.attachList(bno);
		log.info(attachList.size());
		boolean result = boardService.remove(bno);
		if (result) {
			deleteAttach(attachList);
			rttr.addFlashAttribute("result", "success"); //삭제에 성공하면 success 가져가기
		}
		rttr.addAttribute("pageNum", cri.getPageNum());
		rttr.addAttribute("amount", cri.getAmount());
		rttr.addAttribute("type", cri.getType());
		rttr.addAttribute("keyword", cri.getKeyword());
		return "redirect:/board/list"; //response.sendRedirect()와 같음
	}
	
	//게시물 수정
	@PostMapping("modify")
	public String modify(BoardVO bvo, RedirectAttributes rttr, Criteria cri) {
		log.info("modify().......");
		boolean result = boardService.modify(bvo);
		
		if (result) {
			rttr.addFlashAttribute("result", "success"); //수정에 성공하면 success 가져가기
		}
		rttr.addAttribute("pageNum", cri.getPageNum());
		rttr.addAttribute("amount", cri.getAmount());
		rttr.addAttribute("type", cri.getType());
		rttr.addAttribute("keyword", cri.getKeyword());
		return "redirect:/board/list"; //response.sendRedirect()와 같음
	}
	
	
	//게시물 조회
	@GetMapping({"view", "modify"})
	public void view(int bno, Model model, @ModelAttribute("cri") Criteria cri) {
		log.info("view() or modifyForm...........");
		model.addAttribute("bvo", boardService.view(bno));
	}
	
	//게시물 등록
	@PostMapping("register")
	public String register(BoardVO bvo, RedirectAttributes rttr) {
		log.info("register().......");
		boardService.register(bvo);
		
		rttr.addFlashAttribute("result", bvo.getBno()); //게시물 번호를 결과로 반환
														//리다이렉트 할 시 이런 식으로 데이터를 가지고 가도록 하면 됨.
		return "redirect:/board/list"; //response.sendRedirect()와 같음
	}
	
	//게시물 등록 폼
	@GetMapping("register")
	public void register() {
		log.info("registerForm().......");
													
	}
	
	//게시물 목록 가져오기
	@GetMapping("list")
	public void list(Criteria cri, Model model) {
		log.info("list().........." + cri);
		model.addAttribute("list", boardService.list(cri));
		
		int totalCount = boardService.totalCount(cri);
		model.addAttribute("pageDTO", new PageDTO(cri, totalCount));
		
		
		
	}
	
}
