<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h3>/sample/admin Page</h3>
	<a href="/customLogout" type="submit">Log Out</a>
	<hr>
	<form action="/customLogout" method="post">
		<fieldset>
			<!-- Change this to a button or input when using this as a form -->
			<button class="btn btn-lg btn-success btn-block">LogOut</button>
			<input type="hidden" name="${_csrf.parameterName }"
				value="${_csrf.token }">
		</fieldset>
	</form>
</body>
</html>