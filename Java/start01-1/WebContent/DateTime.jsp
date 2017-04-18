<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import="java.util.GregorianCalendar" %>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>날짜와 시간</title>
</head>
<body>
	<% 
	GregorianCalendar now = new GregorianCalendar(); 
	String date = String.format("%TF", now);
	String time = String.format("%TT", now);
	%>
	
	날짜 <%= date %> <br>
	시각 <%= time %> <br>
</body>
</html>