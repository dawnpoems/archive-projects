package edu.springz.security;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.springframework.security.core.Authentication;
import org.springframework.security.web.authentication.AuthenticationSuccessHandler;

import lombok.extern.log4j.Log4j;

@Log4j
public class CustomLoginSuccessHandler implements AuthenticationSuccessHandler{

	@Override
	public void onAuthenticationSuccess(HttpServletRequest request,
								HttpServletResponse response,
								Authentication authentication) throws IOException, ServletException {
		
		log.warn("로그인 성공!!");
		List<String> roleNames = new ArrayList<String>();
		
		authentication.getAuthorities().forEach(auth -> { roleNames.add(auth.getAuthority());});
		
		log.warn("roleNames : " + roleNames);
		
		//ROLE_ADMIN이면 /sample/admin으로 리다이렉트
		//ROLE_MEMBER라면 /sample/member로 리다이렉트
		//그 이외의 경우 모두 /로 리다이렉트
		
		if(roleNames.contains("ROLE_ADMIN")) {
			response.sendRedirect("/sample/admin");
		} else if (roleNames.contains("ROLE_MEMBER")) {
			response.sendRedirect("/sample/member");
		} else {
			response.sendRedirect("/");
		}
	}
	
}
