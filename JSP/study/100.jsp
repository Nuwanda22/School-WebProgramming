<%@page contentType="text/html; charset=utf-8"%>
<!doctype html>
<html>
    <head>
        <title>한글</title>
        <meta charset="utf-8">
    </head>
    <body>
        <%
            int total = 0;
            for (int i = 1; i <= 100; i++) total += i;
        %>
        1부터 100까지 더한 값은? <%=total%>
    </body>
</html>