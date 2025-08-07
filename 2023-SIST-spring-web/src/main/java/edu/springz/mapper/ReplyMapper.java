package edu.springz.mapper;

import java.util.List;

import org.apache.ibatis.annotations.Param;

import edu.springz.domain.Criteria;
import edu.springz.domain.ReplyVO;

public interface ReplyMapper {
	public int updateReply(ReplyVO rvo); //댓글 수정
	public int deleteReply(int rno); //댓글 삭제
	public int insertReplySelectKey(ReplyVO rvo); //사전에 rno 증가 후 insert
	public int insertReply(ReplyVO rvo); //게시물 등록
	public List<ReplyVO> selectReplyAllPaging(
					@Param("bno")int bno, @Param("cri") Criteria cri); //전체 댓글 목록
			//파라미터를 2개 이상 받을때는 어떤 파라미터인지 구분겸 @Param어노테이션을 붙여줘야 함.
	
	public ReplyVO selectReply(int rno); //댓글 하나
	public int totalReply(int bno);
	
}
