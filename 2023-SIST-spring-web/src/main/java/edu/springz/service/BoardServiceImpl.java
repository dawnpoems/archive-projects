package edu.springz.service;

import java.util.List;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import edu.springz.domain.BoardAttachVO;
import edu.springz.domain.BoardVO;
import edu.springz.domain.Criteria;
import edu.springz.mapper.BoardAttachMapper;
import edu.springz.mapper.BoardMapper;
import lombok.AllArgsConstructor;
import lombok.extern.log4j.Log4j;

@Service
@Log4j
@AllArgsConstructor
public class BoardServiceImpl implements BoardService {
	private BoardMapper boardMapper;
	private BoardAttachMapper boardAttachMapper;

	@Override
	public boolean modify(BoardVO bvo) {
		int result = boardMapper.updateBoard(bvo);
		boardAttachMapper.deleteAttachAll(bvo.getBno());
		if ( bvo.getAttachList() == null ||bvo.getAttachList().size() < 1) {
			return result == 1 ? true : false;
		} else {
			for (BoardAttachVO bavo : bvo.getAttachList()) {
				bavo.setBno(bvo.getBno());
				boardAttachMapper.insertAttach(bavo);
			}
			return result == 1 ? true : false;
		}

	}

	@Transactional
	@Override
	public boolean remove(int bno) {
		int result1 = boardAttachMapper.deleteAttachAll(bno); //첨부파일 먼저 모두 삭제
		int result2 = boardMapper.deleteBoard(bno);
		return result1 == 1 && result2 == 1 ? true : false;
	}

	@Transactional
	@Override
	public boolean register(BoardVO bvo) {
		int result = boardMapper.insertBoardSelectKey(bvo);

		if ( bvo.getAttachList() == null ||bvo.getAttachList().size() < 1) {
			return result == 1 ? true : false;
		} else {
			for (BoardAttachVO bavo : bvo.getAttachList()) {
				bavo.setBno(bvo.getBno());
				boardAttachMapper.insertAttach(bavo);
			}
			return result == 1 ? true : false;
		}
		
	}

	@Override
	public BoardVO view(int bno) {
		return boardMapper.selectBoard(bno);
	}

	@Override
	public List<BoardAttachVO> attachList(int bno) {
		return boardAttachMapper.selectAttachAll(bno);
	}
	
	@Override
	public List<BoardVO> list(Criteria cri) {
		return boardMapper.selectBoardAllPaging(cri);
	}

	@Override
	public int totalCount(Criteria cri) {
		return boardMapper.totalCount(cri);
	}


	
}
