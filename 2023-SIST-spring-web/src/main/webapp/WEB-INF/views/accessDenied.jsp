<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<div style="text-align: center">
		<h3>접근이 거부되었습니다.</h3>
		<p>Spring message : ${SPRING_SECURITY_403_EXCEPTION.getMessage() } </p>
		<img src="/resources/imgs/denied.png"> <br>
		Customized message : ${msg}
	</div>
</body>
</html>