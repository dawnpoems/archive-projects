package edu.springz.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

import lombok.extern.log4j.Log4j;

@Controller
@Log4j
public class CommonController {

	@GetMapping("/accessDenied")
	public void accessDenied(Model model) {
		log.info("accessDenied()........");
		model.addAttribute("msg", "접근 불가 - 권한 부족");
	}
	
	@GetMapping("/customLogin")
	public void customLogin(String error, String logout, Model model) {
		log.info("customLogin()........");
		log.info("error : " + error);
		log.info("logout : " + logout);

		if(error != null) {
			model.addAttribute("error", "로그인 에러 - 계정을 확인해주세요");
		}
		
		if(logout != null) {
			model.addAttribute("logout", "로그아웃이 완료되었습니다");
		}
	}
	
	@GetMapping("/customLogout")
	public void customOut(String error, String logout, Model model) {
		log.info("customLogout()........");

	}
}
