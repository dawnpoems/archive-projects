package edu.springz.domain;

import lombok.Data;

@Data
public class BoardAttachVO {
	private String uuid;
	private String upFolder;
	private String fileName;
	private boolean image;
	private int bno;
}
