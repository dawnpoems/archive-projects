package edu.springz.mapper;

import org.apache.ibatis.annotations.Insert;

public interface SampleMapper2 {

	@Insert("INSERT INTO tbl_sample2 VALUES (#{sample})")
	public int insertSampleData2(String sample);
}
