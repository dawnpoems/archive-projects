package edu.springz.mapper;

import org.apache.ibatis.annotations.Insert;

public interface SampleMapper1 {
	
	@Insert("INSERT INTO tbl_sample1 VALUES (#{sample})")
	public int insertSampleData1(String sample);
	
}
