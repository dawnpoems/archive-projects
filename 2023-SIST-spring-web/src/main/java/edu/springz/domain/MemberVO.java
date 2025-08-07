package edu.springz.domain;

import java.util.Date;
import java.util.List;

import lombok.Data;

@Data
public class MemberVO {
	private String id;
	private String pw;
	private String name;
	private Date regDate;
	private Date updateDate;
	private boolean enabled;
	private List<AuthVO> authList;
}
