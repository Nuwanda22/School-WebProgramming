<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8" import="java.io.*,java.util.Date"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
	<%
	request.setCharacterEncoding("utf8");
	
	String name = request.getParameter("name");
	String title = request.getParameter("title");
	String content = request.getParameter("content");
	PrintWriter writer = null;
	String fileName = new Date().getTime() + ".txt";
	
	try{
		String filePath = application.getRealPath("/WEB-INF/bbs/"+fileName);
		
		writer = new PrintWriter(filePath);
		writer.printf("제목: %s %n", title);
		writer.printf("글쓴이: %s %n", name);
		writer.println(content);
		
		writer.flush();
		out.print(application.getRealPath("/WEB-INF/bbs/"+fileName));
		out.println("에 저장되었습니다.");
	}
	catch (IOException e){
		out.println("파일에 데이터를 쓸 수 없습니다.");
	}
	finally{
		writer.close();
	}
	%>
</body>
</html>