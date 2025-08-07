<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h3>Spring file upload</h3>
	<form action="/upload/formAction" method="post" enctype="multipart/form-data" >
	<input type="file" name="uploadFile" multiple="multiple">
	<hr>
	<button type="submit">upload</button>
	</form>
</body>
</html>