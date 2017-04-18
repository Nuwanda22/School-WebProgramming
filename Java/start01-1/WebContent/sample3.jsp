<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
	request.setCharacterEncoding("utf-8");
	%>
	
	안녕하세요. <%= request.getParameter("name") %>님 <br>
	입력하신 이메일은 <%= request.getParameter("email") %>입니다.
</body>
</html>