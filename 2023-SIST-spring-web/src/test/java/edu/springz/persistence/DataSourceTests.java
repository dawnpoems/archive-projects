package edu.springz.persistence;

import static org.junit.Assert.fail;
import java.sql.Connection;

import javax.sql.DataSource;

import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class)	//JUnit으로 단위 테스트 프레임워크 지정
@ContextConfiguration("file:src/main/webapp/WEB-INF/spring/root-context.xml")
@Log4j
public class DataSourceTests {
	@Setter(onMethod_ = @Autowired)  //세터인젝션
	private DataSource dataSource;	
	
	@Setter(onMethod_ = @Autowired)
	private SqlSessionFactory sqlSessionFactory;
	
	@Test
	public void testMyBatis() {
		try( SqlSession sqlSession = sqlSessionFactory.openSession();
			 Connection con = sqlSession.getConnection()){
			log.info(sqlSession);
			log.info(con);
		} catch(Exception e) {
			fail(e.getMessage());
		}
	}
	
	public void testConnection() {
		try( Connection con = dataSource.getConnection() ){
			log.info(con);
		} catch(Exception e) {
			fail(e.getMessage());
		}
	}
}










