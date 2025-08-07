package edu.springz.service;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import edu.springz.mapper.SampleMapper1;
import edu.springz.mapper.SampleMapper2;
import lombok.AllArgsConstructor;
import lombok.extern.log4j.Log4j;

@Service
@AllArgsConstructor
@Log4j
public class SampleTxServiceImpl implements SampleTxService{

	private SampleMapper1 sMapper1;
	private SampleMapper2 sMapper2;
	
	@Transactional
	@Override
	public void registerSampleData(String sample) {
		log.info("mapper1......");
		sMapper1.insertSampleData1(sample);
		log.info("mapper2......");
		sMapper2.insertSampleData2(sample);
	}
	
}	

