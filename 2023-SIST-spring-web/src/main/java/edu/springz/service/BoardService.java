package edu.springz.service;

import java.util.List;

import edu.springz.domain.BoardAttachVO;
import edu.springz.domain.BoardVO;
import edu.springz.domain.Criteria;

public interface BoardService {

		public List<BoardVO> list(Criteria cri);//전체 게시물
		public int totalCount(Criteria cri); //전체 게시물 수
		
		public boolean modify(BoardVO bvo); //게시물 수정
		public boolean remove(int bno); //게시물 삭제
		public boolean register(BoardVO bvo); //사전에 bno 증가 후 inser

		public BoardVO view(int bno); //게시물 하나
		
		public List<BoardAttachVO> attachList(int bno);
}
