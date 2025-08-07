package edu.springz.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import lombok.extern.log4j.Log4j;

@Controller
@Log4j
@RequestMapping("/sample/")
public class SecurityController {

	@GetMapping("all")
	public void securityPageAll() {
		log.info("all page......");
	}
	
	@GetMapping("member")
	public void securityPageMember() {
		log.info("member page......");
	}
	
	@GetMapping("admin")
	public void securityPageAdmin() {
		log.info("admin page......");
	}
}
