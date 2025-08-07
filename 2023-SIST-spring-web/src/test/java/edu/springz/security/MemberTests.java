package edu.springz.security;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

import javax.sql.DataSource;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;

import lombok.Setter;
import lombok.extern.log4j.Log4j;

@RunWith(SpringJUnit4ClassRunner.class) // 단위 테스트 프레임워크를 JUnit으로 지정
@ContextConfiguration({ "file:src/main/webapp//WEB-INF/spring/root-context.xml",
		"file:src/main/webapp//WEB-INF/spring/security-context.xml" })
@Log4j
public class MemberTests {
	
	@Setter(onMethod_ = @Autowired)
	private PasswordEncoder pwEncoder;
	
	@Setter(onMethod_ = @Autowired)
	private DataSource dataSource;

	@Test
	public void testInsertAuth() {
		// 100명의 권한 등록
		// 일반사용자 : user0 - user79 : ROLE_USER
		// 멤버 : member80 - member89 : ROLE_MEMBER
		// 관리자 : admin90 - admin99  : ROLE_ADMIN

		String query = "INSERT INTO tbl_member_auth(id, auth) VALUES(?, ?) ";

		PreparedStatement pstmt = null;

		try (Connection con = dataSource.getConnection()) {
			for (int i = 0; i < 100; i++) {
				pstmt = con.prepareStatement(query);
				
				if(i < 80) {
					pstmt.setString(1, "user" + i);
					pstmt.setString(2, "ROLE_USER");
				} else if (i < 90) {
					pstmt.setString(1, "member" + i);
					pstmt.setString(2, "ROLE_MEMBER");
				} else {
					pstmt.setString(1, "admin" + i);
					pstmt.setString(2, "ROLE_ADMIN");
				}
				pstmt.executeUpdate();
				
			}
			pstmt.close();
			pstmt = con.prepareStatement(query);
			pstmt.setString(1, "admin99");
			pstmt.setString(2, "ROLE_MEMBER");
			pstmt.executeUpdate();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
				try {
					if(pstmt != null) pstmt.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
		}
	}
	
	public void testInsertMember() {
		// 100명의 데이터 등록
		// 비밀번호는 1111을 PasswoardEncoder로 암호화
		// 일반사용자 : user0 - user79
		// 멤버 : member80 - member89
		// 관리자 : admin90 - admin99

		String query = "INSERT INTO tbl_member(id, pw, name) VALUES(?, ?, ?) ";

		PreparedStatement pstmt = null;

		try (Connection con = dataSource.getConnection()) {
			for (int i = 0; i < 100; i++) {
				pstmt = con.prepareStatement(query);
				pstmt.setString(2, pwEncoder.encode("1111"));
				
				if(i < 80) {
					pstmt.setString(1, "user" + i);
					pstmt.setString(3, "일반사용자" + i);
				} else if (i < 90) {
					pstmt.setString(1, "member" + i);
					pstmt.setString(3, "멤버" + i);
				} else {
					pstmt.setString(1, "admin" + i);
					pstmt.setString(3, "관리자" + i);
				}
				pstmt.executeUpdate();
				
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} finally {
				try {
					if(pstmt != null) pstmt.close();
				} catch (SQLException e) {
					e.printStackTrace();
				}
		}
	}

}
