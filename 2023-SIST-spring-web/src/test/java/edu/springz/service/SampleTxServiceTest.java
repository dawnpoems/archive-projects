package edu.springz.service;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class) //단위 테스트 프레임워크를 JUnit으로 지정
@ContextConfiguration("file:src/main/webapp//WEB-INF/spring/root-context.xml")
@Log4j
public class SampleTxServiceTest {
	@Setter(onMethod_ = @Autowired)
	private SampleTxService txService;
	
	@Test
	public void testTest() throws Exception {
		txService.registerSampleData("xyzzzzzzzzzzzzzzz12345678");
	}
}
