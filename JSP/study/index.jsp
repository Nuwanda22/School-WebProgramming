<%@page contentType="text/html; charset=utf-8"%>
<%@ page import="java.io.*"%>
<!doctype html>
<html>
    <head>
        <title>JSP Servlet</title>
        <meta charset="utf-8">
        <style type="text/css">
            h1{
                margin: 50px;
                text-align: center;
            }

            #list{
                text-align: center;
            }
        </style>
    </head>
    <body>
        <h1>Welcome to my world!</h1>
    <%
        String filePath = request.getRealPath(".") + "/"; // 현재 위치의 실제경로를 구함
        File[] files = new File(filePath).listFiles();    // 그 경로를 통해 파일 리스트를 추출

        out.println("<div id='list'>");
        for (File file : files) {
            if (file.isFile()) { 
                String fileName = file.getName();
                String title = fileName.substring(0, fileName.indexOf('.'));
                out.println("<a href='" + fileName + "'>"+ title +"</a><br>");
            }
        }
        out.println("</div>");
    %>
    </body>
</html>