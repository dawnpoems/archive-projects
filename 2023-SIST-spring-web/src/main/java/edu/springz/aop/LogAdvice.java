package edu.springz.aop;

import java.util.Arrays;

import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.AfterThrowing;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.stereotype.Component;

import lombok.extern.log4j.Log4j;

@Aspect
@Component
@Log4j
public class LogAdvice {
	//AspectJ 표현식을 이용, 들어가기 전에 로그를 찍어보자
	//excution([접근제한자] 반환타입 [패키지.클래스.] 이름 ([매개변수|...]) [throws 예외])
	
	@Around("execution(* edu.springz.service.SampleService*.*(..))")
	public Object logAround(ProceedingJoinPoint pjp) { 
		log.info("pjp : " + pjp);
		Object result = null;
		
		log.info("TARGET : " + pjp.getTarget());
		log.info("PARAM : " + Arrays.toString(pjp.getArgs()));
		//여기까지 target이 실행되기 전에 실행
		
		try {
			result = pjp.proceed();
		} catch (Throwable e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		//여기 이후로 타겟이 실행된 이후에 실행
		
		log.info("result : " + result);
		return result;
		
	}
	
	@AfterThrowing(pointcut = "execution(* edu.springz.service.SampleService*.*(..))",
					throwing = "exception")
	public void logException(Exception exception) {
		log.info("exception!!");
		log.info("exception : " + exception);
	}
	
	////반환타입 상관없이, sampleService에 있는 doAdd메서드, 매개변수 str1, str2로 두 개인 것)
	@Before("execution(* edu.springz.service.SampleService*.doAdd(String, String)) && args(str1, str2)")
	public void logBeforeWithParam(String str1, String str2) {
		log.info("str1 : " + str1);
		log.info("str2 : " + str2);
	}
	
	//반환타입 상관없이, sampleService에 있는 모든 메서드, 모든 매개변수 
	@Before("execution(* edu.springz.service.SampleService*.*(..))")
	public void logBefore() {
		log.info("logBefore()..........");
	}
}
