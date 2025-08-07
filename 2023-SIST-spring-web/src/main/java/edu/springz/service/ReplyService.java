package edu.springz.service;

import java.util.List;

import edu.springz.domain.Criteria;
import edu.springz.domain.ReplyPageDTO;
import edu.springz.domain.ReplyVO;

public interface ReplyService {
		
		public boolean modify(ReplyVO rvo); //댓글 수정
		public boolean remove(int rno); //댓글 삭제
		public boolean register(ReplyVO rvo); //댓글 insert
		public ReplyVO view(int rno); //댓글 하나
		
		public ReplyPageDTO list(int bno, Criteria cri);//전체 게시물
		public int totalReply(int bno); //전체 게시물 수

}
