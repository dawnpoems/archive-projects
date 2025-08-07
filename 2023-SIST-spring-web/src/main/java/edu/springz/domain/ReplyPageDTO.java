package edu.springz.domain;

import java.util.List;

import lombok.AllArgsConstructor;
import lombok.Data;

@Data
@AllArgsConstructor
public class ReplyPageDTO {
	private int totalReply;
	private List<ReplyVO> List;
	
}
