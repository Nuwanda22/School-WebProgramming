<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.io.*"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
	request.setCharacterEncoding("utf8");
	String text = request.getParameter("text");
	String fileName = request.getParameter("filename");
	
	try{
		String fileinfo = application.getRealPath("/"+fileName);
		FileWriter writer = new FileWriter(fileinfo);
		writer.write(text);
		out.println(fileinfo + " 저장 성공");
		writer.close();
	}
	catch(IOException e){
		out.println("저장 실패");
	}
	%>
</body>
</html>