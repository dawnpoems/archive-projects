package edu.springz.service;

import static org.junit.Assert.assertNotNull;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import edu.springz.domain.BoardVO;
import edu.springz.domain.Criteria;
import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class) //단위 테스트 프레임워크를 JUnit으로 지정
@ContextConfiguration("file:src/main/webapp//WEB-INF/spring/root-context.xml")
@Log4j
public class BoardServiceTest {
	
	@Setter(onMethod_ = @Autowired)
	private BoardService boardService;
	
	@Test
	public void testList() {
		Criteria cri = new Criteria(3, 2);
		boardService.list(cri).forEach(bvo -> log.info(bvo));
		log.info("전체 게시글 수 : " + boardService.totalCount(cri));
	}
	
	public void testModify() {
		BoardVO bvo = boardService.view(3);
		
		if(bvo == null) return;
		
		bvo.setTitle("modified title");
		bvo.setContent("modified content");
		
		log.info("Modify RESULT : " + boardService.modify(bvo));
		testList();
}	
	
	public void testRemove() {
		log.info("Remove Result : " + boardService.remove(4));
		testList();
}	
	
	public void testView() {
		log.info(boardService.view(3));
}	
	
	public void testRegister() {
		BoardVO bvo = new BoardVO();
		bvo.setTitle("new title SERVICE");
		bvo.setContent("new SERVICE");
		bvo.setWriter("newbie");
		boardService.register(bvo);
		
		log.info("등록된 게시물 번호 : " + bvo.getBno());
		
}	
	
	public void testExist() {
		assertNotNull(boardService);
		log.info(boardService);
	}
}	
