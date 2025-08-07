package edu.springz.controller;

import java.util.List;

import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.DeleteMapping;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PatchMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.PutMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.servlet.mvc.support.RedirectAttributes;

import edu.springz.domain.Criteria;
import edu.springz.domain.ReplyPageDTO;
import edu.springz.domain.ReplyVO;
import edu.springz.service.ReplyService;
import lombok.AllArgsConstructor;
import lombok.extern.log4j.Log4j;

@RestController
@RequestMapping("/replies/")
@AllArgsConstructor
@Log4j
public class ReplyController {

	private ReplyService replyService;
	
	//댓글 목록 가져오기
	@GetMapping("list/{bno}/{pageNum}")
	public ResponseEntity<ReplyPageDTO> list(@PathVariable("bno") int bno,
											@PathVariable("pageNum") int pageNum) {
		log.info("list()..........");
		Criteria cri = new Criteria(3, pageNum);
		//댓글 목록과 200번 코드 반환
		return new ResponseEntity<>(replyService.list(bno, cri), HttpStatus.OK);
	}
	
	//댓글 하나 가져오기
	@GetMapping("{rno}")
	public ResponseEntity<ReplyVO> view(@PathVariable("rno") int rno) {
		log.info("list()..........");
		//댓글 목록과 200번 코드 반환
		return new ResponseEntity<>(replyService.view(rno), HttpStatus.OK);
	}
	
	//댓글 등록
	@PostMapping(value="register", produces= { MediaType.TEXT_PLAIN_VALUE})
	public ResponseEntity<String> register(@RequestBody ReplyVO rvo) {
		log.info("register().......");
		
		if (replyService.register(rvo)) {
			return new ResponseEntity<>("success", HttpStatus.OK);
		} else {
			return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
		}
	}
	
	//댓글 수정
	@RequestMapping(value="{rno}", produces= { MediaType.TEXT_PLAIN_VALUE}, 
									method = {RequestMethod.PUT, RequestMethod.PATCH})
	public ResponseEntity<String> modify(@RequestBody ReplyVO rvo,
										 @PathVariable("rno") int rno) {
		log.info("modify().......");
		rvo.setRno(rno);
		
		return replyService.modify(rvo)
					? new ResponseEntity<>("success", HttpStatus.OK)
					: new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
		
	}
	
	//댓글 삭제
	@DeleteMapping(value="{rno}", produces= { MediaType.TEXT_PLAIN_VALUE})
	public ResponseEntity<String> remove(@PathVariable("rno") int rno) {
		log.info("remove().......");
		
		if (replyService.remove(rno)) {
			return new ResponseEntity<>("success", HttpStatus.OK);
		} else {
			return new ResponseEntity<>(HttpStatus.INTERNAL_SERVER_ERROR);
		}
	}
	
}
