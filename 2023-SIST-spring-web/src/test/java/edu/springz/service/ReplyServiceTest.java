package edu.springz.service;

import static org.junit.Assert.assertNotNull;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import edu.springz.domain.BoardVO;
import edu.springz.domain.Criteria;
import edu.springz.domain.ReplyVO;
import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class) //단위 테스트 프레임워크를 JUnit으로 지정
@ContextConfiguration("file:src/main/webapp//WEB-INF/spring/root-context.xml")
@Log4j
public class ReplyServiceTest {
	
	@Setter(onMethod_ = @Autowired)
	private ReplyService replyService;

	@Test
	public void testList() {
	Criteria cri = new Criteria(3, 2);
	replyService.list(3, cri).getList().forEach(bvo -> log.info(bvo));
	log.info("Total Reply : " + replyService.list(3, cri).getTotalReply());
	}
	
	public void testRemove() {
	log.info("Remove Result : " + replyService.remove(13));
	testList();
	}	
	
	
	public void testModify() {
	ReplyVO rvo = replyService.view(3);
	
	if(rvo == null) return;
	
	rvo.setReply("modified reply");
	
	log.info("Modify RESULT : " + replyService.modify(rvo));
	testView();
	}	
	
	public void testView() {
	log.info(replyService.view(3));
	}
	
	public void testRegister() {
	ReplyVO rvo = new ReplyVO();
	rvo.setBno(3);
	rvo.setReply("newReply");
	rvo.setReplyer("newReplyer");
	replyService.register(rvo);
	
	}	
	
	public void testExist() {
		assertNotNull(replyService);
		log.info(replyService);
	}
	
	
}	
