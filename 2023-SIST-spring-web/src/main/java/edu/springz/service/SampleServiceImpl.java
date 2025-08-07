package edu.springz.service;

import org.springframework.stereotype.Service;

import edu.springz.mapper.SampleMapper1;
import edu.springz.mapper.SampleMapper2;
import lombok.AllArgsConstructor;

@Service
public class SampleServiceImpl implements SampleService {

	@Override
	public int doAdd(String str1, String str2) throws Exception {
		return Integer.parseInt(str1) + Integer.parseInt(str2);
	}


	

	
	

	
}
