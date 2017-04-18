<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>1to100</title>
</head>
<body>
	<%-- 다음은 1부터 100까지의 합을 더하는 코드이다 --%>
	<% 
	int sum = 0; // 합을 담을 변수 저장
	for (int i = 1; i <= 100; i+=2){
		sum += i; /* 루프를 돌며 sum에 저장*/
	}
	%>
	<!-- 다음과 같이 출력한다. -->
	1부터 100까지의 합 = <%= sum %>
</body>
</html>