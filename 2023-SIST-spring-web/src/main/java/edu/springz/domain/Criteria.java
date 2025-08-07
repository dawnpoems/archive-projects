package edu.springz.domain;

import lombok.Getter;
import lombok.Setter;
import lombok.ToString;

@Getter
@Setter
@ToString
public class Criteria {
	
	private int amount;			//한 페이지에 출력할 게시물의 수
	private int pageNum;		//페이지 번호
	private String type;		//검색 타입
	private String keyword;		//검색어
	
	public Criteria() {
		this(3, 1); //기본 생성자 호출시(값을 지정하지 않은 경우), 매개변수를 가지고 있는 생성자 호출
	}
	
	public Criteria(int amount, int pageNum) {
		this.amount = amount;
		this.pageNum = pageNum;
	}
	
	public String[] getTypeArr() {
		//검색 타입의 T,C,W를 배열로 반환
		return type == null ? new String[] {} : type.split("");
		
		
		
	}
}