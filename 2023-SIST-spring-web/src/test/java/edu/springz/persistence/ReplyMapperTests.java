package edu.springz.persistence;

import java.util.stream.IntStream;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import edu.springz.domain.Criteria;
import edu.springz.domain.ReplyVO;
import edu.springz.mapper.ReplyMapper;
import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp//WEB-INF/spring/root-context.xml")
@Log4j
public class ReplyMapperTests {
	
	@Setter(onMethod_ = @Autowired)
	private ReplyMapper replyMapper;
	
	//실제 게시판의 게시물 번호
	private int[] bnoArr = { 1, 2, 3, 6, 7 };
	
	@Test
	public void testSelectAllPaging() {
	Criteria cri = new Criteria(3, 2);
	replyMapper.selectReplyAllPaging(3, cri).forEach(rvo -> log.info(rvo));
	log.info("total count : " + replyMapper.totalReply(3));
   }
	
	public void testDelete() {
	log.info("DELETE COUNT : " + replyMapper.deleteReply(11));
	}	
	
	public void testUpdate() {
	ReplyVO rvo = new ReplyVO();
	rvo.setRno(5);
	rvo.setReply("updated reply");
	log.info("update COUNT : " + replyMapper.updateReply(rvo));
	}	
	
	
	public void testSelect() {
	log.info(replyMapper.selectReply(5));
	}	
	
	public void testInsert() {
		//각 게시물에 2개씩 댓글 등록
		IntStream.rangeClosed(1, 10).forEach(i -> {
			ReplyVO rvo = new ReplyVO();
			rvo.setBno(bnoArr[i % 5]);
			rvo.setReply("댓글");
			rvo.setReplyer("aaa");
			replyMapper.insertReply(rvo);
		});
	}	
	
	public void replyBeanTest() {
		log.info("replyMapper : " + replyMapper);
	}
	
	
//	public void testSearch() {
//		Criteria cri = new Criteria();
//		cri.setType("TW");
//		cri.setKeyword("aaaa");
//		boardMapper.selectBoardAllPaging(cri).forEach(bvo -> log.info(bvo));
//	}
	
//	public void testSelectAllPaging() {
//		Criteria cri = new Criteria(3, 2);
//		boardMapper.selectBoardAllPaging(cri).forEach(bvo -> log.info(bvo));
//		log.info("total count : " + boardMapper.totalCount(cri));
//	}
	
//	public void testUpdate() {
//		BoardVO bvo = new BoardVO();
//		bvo.setTitle("updated title");
//		bvo.setContent("updated content");
//		bvo.setBno(6);
//		log.info("update COUNT : " + boardMapper.updateBoard(bvo));
//		testSelectAll();
//}	
//	
//	public void testDelete() {
//		log.info("DELETE COUNT : " + boardMapper.deleteBoard(5));
//		testSelectAll();
//}	
//	
//	
//	public void testInsertSelectKey() {
//		BoardVO bvo = new BoardVO();
//		bvo.setTitle("new title");
//		bvo.setContent("new content");
//		bvo.setWriter("newbie");
//		boardMapper.insertBoardSelectKey(bvo);
//		log.info(bvo);
//}	
//	
//	public void testInsert() {
//		BoardVO bvo = new BoardVO();
//		bvo.setTitle("new title");
//		bvo.setContent("new content");
//		bvo.setWriter("newbie");
//		boardMapper.insertBoard(bvo);
//}	
//	
//	
//	public void testSelect() {
//		log.info(boardMapper.selectBoard(5));
//}	
//	public void testSelectAll() {
//			boardMapper.selectBoardAll().forEach(bvo -> log.info(bvo));
//	}
//	

	
}
