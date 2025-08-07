package edu.springz.controller;

import static org.junit.Assert.assertNotNull;

import org.junit.Before;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;
import org.springframework.test.context.web.WebAppConfiguration;
import org.springframework.test.web.servlet.MockMvc;
import org.springframework.test.web.servlet.request.MockMvcRequestBuilders;
import org.springframework.test.web.servlet.setup.MockMvcBuilders;
import org.springframework.web.context.WebApplicationContext;

import edu.springz.domain.BoardVO;
import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class) //단위 테스트 프레임워크를 JUnit으로 지정
@ContextConfiguration({"file:src/main/webapp//WEB-INF/spring/root-context.xml",
		"file:src/main/webapp//WEB-INF/spring/appServlet/servlet-context.xml"})
@WebAppConfiguration
@Log4j
public class BoardControllerTest {
	
	@Setter(onMethod_ = @Autowired)
	private WebApplicationContext ctx;

	private MockMvc mockMvc;
	
	@Before
	public void setup() {
		mockMvc = MockMvcBuilders.webAppContextSetup(ctx).build();
	}
	
	@Test
	public void testList() throws Exception {
		log.info(mockMvc.perform(MockMvcRequestBuilders.get("/board/list")
							.param("amount", "3")
							.param("pageNum", "2")
							)
						.andReturn().getModelAndView().getModelMap());
	}
	
	
	public void testRemove() throws Exception {
		log.info(mockMvc.perform(MockMvcRequestBuilders.post("/board/remove")
						.param("bno", "11"))
						.andReturn().getModelAndView().getModelMap());
		testList();
	}
	
	public void testModify() throws Exception {
		log.info(mockMvc.perform(MockMvcRequestBuilders.post("/board/modify")
						.param("title", "new title controller")
						.param("content", "new title controller")
						.param("bno", "11"))
						.andReturn().getModelAndView().getModelMap());
		testList();
	}
	
	
	public void testView() throws Exception {
		log.info(mockMvc.perform(MockMvcRequestBuilders.get("/board/view").param("bno", "11"))
						.andReturn().getModelAndView().getModelMap());
	}
	
	public void testRegister() throws Exception {
		log.info(mockMvc.perform(MockMvcRequestBuilders.post("/board/register")
						.param("title", "new title controller")
						.param("content", "new title controller")
						.param("writer", "bbb"))
						.andReturn().getModelAndView().getModelMap());
		testList();
	}
	
//	public void testList() throws Exception {
//		log.info(mockMvc.perform(MockMvcRequestBuilders.get("/board/list"))
//						.andReturn().getModelAndView().getModelMap());
//	}
}	
