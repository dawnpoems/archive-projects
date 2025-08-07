package edu.springz.service;

import java.util.List;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import edu.springz.domain.Criteria;
import edu.springz.domain.ReplyPageDTO;
import edu.springz.domain.ReplyVO;
import edu.springz.mapper.BoardMapper;
import edu.springz.mapper.ReplyMapper;
import lombok.AllArgsConstructor;
import lombok.extern.log4j.Log4j;

@Service
@Log4j
@AllArgsConstructor
public class ReplyServiceImpl implements ReplyService {
	private ReplyMapper replyMapper;
	private BoardMapper boardMapper;
	
	@Override
	public boolean modify(ReplyVO rvo) {
		return replyMapper.updateReply(rvo) == 1 ? true : false;
	}

	@Transactional
	@Override
	public boolean remove(int rno) {
		ReplyVO rvo = replyMapper.selectReply(rno);
		boardMapper.updateReplyCnt(-1 , rvo.getBno());
		return replyMapper.deleteReply(rno) == 1 ? true : false;
	}
	
	@Transactional
	@Override
	public boolean register(ReplyVO rvo) {
		boardMapper.updateReplyCnt(1, rvo.getBno());
		boolean result = replyMapper.insertReply(rvo) == 1 ? true : false;
		return result;
	}

	@Override
	public ReplyVO view(int rno) {
		return replyMapper.selectReply(rno);
	}

	@Override
	public ReplyPageDTO list(int bno, Criteria cri) {
		return new ReplyPageDTO(replyMapper.totalReply(bno), replyMapper.selectReplyAllPaging(bno, cri));
	}

	@Override
	public int totalReply(int bno) {
		return replyMapper.totalReply(bno);
	}}
