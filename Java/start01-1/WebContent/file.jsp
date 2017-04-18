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
	BufferedReader reader = null;
	try{
		String path = application.getRealPath("/WEB-INF/input.txt");
		reader = new BufferedReader(new FileReader(path));
		
		while(true){
			String context = reader.readLine();
			
			if(context != null){
				out.println(context + "<br>");
			}
			else {
				break;
			}
		}
	}
	catch(FileNotFoundException e){
		out.println("파일이 존재하지 않습니다.");
	}
	catch(IOException e){
		out.println("파일을 읽을 수 없습니다.");
	}
	finally{
		reader.close();
	}
	%>
</body>
</html>