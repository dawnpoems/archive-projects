package edu.springz.controller;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import edu.springz.domain.SampleVO;
import lombok.extern.log4j.Log4j;

@RestController
@RequestMapping("/sample/")
@Log4j
public class SampleController {
	
	@PostMapping("sample")
	public SampleVO sample(@RequestBody SampleVO svo) {
		log.info("sample : " + svo);
		return svo;
	}
	//json데이터를 받아서 VO 객체로 반환하자
	
	@GetMapping("product/{cat}/{pid}")
	public String[] getPath(@PathVariable("cat") String cat,
							@PathVariable("pid") int pid) {
		//url 경로의 일부를 파라미터로 사용하는 방식.
		//? & = 이런거 안쓰고 바로 값으로 사용할 수 있음
		return new String[] {"category:" + cat, "product id:" + pid};
	} 
	
	@GetMapping(value="check")
	public ResponseEntity<SampleVO> check(int height, int weight) {
		SampleVO svo = new SampleVO(6, "six", "Yuk");
		ResponseEntity<SampleVO> resp = null;
		if (height >= 100) {
			resp = ResponseEntity.status(HttpStatus.OK).body(svo);
		} else {
			resp = ResponseEntity.status(HttpStatus.BAD_GATEWAY).body(svo);
		}
		return resp;
	}
	
	@GetMapping(value="getMap")
	public Map<String, SampleVO> getMap(){
		Map<String, SampleVO> map = new HashMap<String, SampleVO>();
		map.put("Han", new SampleVO(5, "San", "Han"));
		return map;
	}
	
	@GetMapping(value="getList")
	public List<SampleVO> getList(){
		return IntStream.range(1, 5)
						.mapToObj(i -> new SampleVO(i, "Anony" + i, "Laa"))
						.collect(Collectors.toList());
	}
	
	@GetMapping(value="getSample", produces= {MediaType.APPLICATION_JSON_VALUE,
												MediaType.APPLICATION_XML_VALUE} ) //얘들은 생략가능. 없으면 기본으로 만들어줌
	public SampleVO getSampleVO() {
		return new SampleVO(1, "ben", "Lee");
	}
	
	@GetMapping(value="getText", produces="text/plain; charset=UTF-8") //서버에서 보낸 값을 어떤 식으로 받을 것인가?
	public String getText() {
		log.info("getText().......MIME TYPE : " + MediaType.TEXT_PLAIN_VALUE);
		return "Hello World~!";
	}
}
