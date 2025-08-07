package edu.springz.persistence;

import static org.junit.Assert.fail;
import java.sql.Connection;
import java.sql.DriverManager;

import javax.sql.DataSource;

import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.mybatis.spring.SqlSessionFactoryBean;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import edu.springz.domain.BoardVO;
import edu.springz.domain.Criteria;
import edu.springz.mapper.BoardMapper;
import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)
@ContextConfiguration("file:src/main/webapp//WEB-INF/spring/root-context.xml")
@Log4j
public class BoardMapperTests {

	@Setter(onMethod_ = @Autowired)
	private DataSource dataSource; //세터인젝션
	
	@Setter(onMethod_ = @Autowired)
	private SqlSessionFactory sqlSessionFactory;
	
	@Setter(onMethod_ = @Autowired)
	private BoardMapper boardMapper;
	
	@Test
	public void testSearch() {
		Criteria cri = new Criteria();
		cri.setType("TW");
		cri.setKeyword("aaaa");
		boardMapper.selectBoardAllPaging(cri).forEach(bvo -> log.info(bvo));
	}
	
	public void testSelectAllPaging() {
		Criteria cri = new Criteria(3, 2);
		boardMapper.selectBoardAllPaging(cri).forEach(bvo -> log.info(bvo));
		log.info("total count : " + boardMapper.totalCount(cri));
	}
	
	public void testUpdate() {
		BoardVO bvo = new BoardVO();
		bvo.setTitle("updated title");
		bvo.setContent("updated content");
		bvo.setBno(6);
		log.info("update COUNT : " + boardMapper.updateBoard(bvo));
		testSelectAll();
}	
	
	public void testDelete() {
		log.info("DELETE COUNT : " + boardMapper.deleteBoard(5));
		testSelectAll();
}	
	
	
	public void testInsertSelectKey() {
		BoardVO bvo = new BoardVO();
		bvo.setTitle("new title");
		bvo.setContent("new content");
		bvo.setWriter("newbie");
		boardMapper.insertBoardSelectKey(bvo);
		log.info(bvo);
}	
	
	public void testInsert() {
		BoardVO bvo = new BoardVO();
		bvo.setTitle("new title");
		bvo.setContent("new content");
		bvo.setWriter("newbie");
		boardMapper.insertBoard(bvo);
}	
	
	
	public void testSelect() {
		log.info(boardMapper.selectBoard(5));
}	
	public void testSelectAll() {
			boardMapper.selectBoardAll().forEach(bvo -> log.info(bvo));
	}
	

	
}
