<%@ page language="java" contentType="text/html; charset=EUC-KR"
    pageEncoding="EUC-KR"%>

<!DOCTYPE html>
<html>
<head>
<meta charset="EUC-KR">
<title>1to100</title>
</head>
<body>
	<%-- ������ 1���� 100������ ���� ���ϴ� �ڵ��̴� --%>
	<% 
	int sum = 0; // ���� ���� ���� ����
	for (int i = 1; i <= 100; i+=2){
		sum += i; /* ������ ���� sum�� ����*/
	}
	%>
	<!-- ������ ���� ����Ѵ�. -->
	1���� 100������ �� = <%= sum %>
</body>
</html>