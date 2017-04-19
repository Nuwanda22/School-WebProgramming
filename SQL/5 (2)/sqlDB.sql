create database sqlDB;

create table userTbl -- 회원 테이블 
(
	userID	char(8) not null primary key, -- 사용자 아이디
	name varchar(10) not null, -- 이름
	birthYear int not null, -- 출생년도
	addr char(2) not null, -- 지역(경기, 서울, ...)
	mobile1 char(3), -- 휴대폰 국번
	mobile2 char(8), -- 휴대폰 나머지 번호(하이픈 제외)
	height smallint, -- 키
	mDate date -- 회원 가입일auto_increment
);

create table buyTbl -- 회원 구매 테이블
( 
	num int auto_increment not null primary key, -- 순번(PK)
	userID char(8) not null, -- 아이디(FK)
	prodName char(6) not null, -- 물품명
	groupName char(4), -- 분류
	price int not null, -- 단가
	amount smallint not null, -- 수량 
	foreign key (userID) references userTbl(userID)
);

create table empTbl(emp char(3), manager char(3), empTel varchar(8));

insert into userTbl values('LSG','이승기',1987,'서울','011','1111111',182,'2008-8-8');
insert into userTbl values('KBS','김범수',1979,'경남','011','2222222',173,'2012-4-4');
insert into userTbl values('KKH','김경호',1971,'전남','019','3333333',177,'2007-7-7');
insert into userTbl values('JYP','조용필',1950,'경기','011','4444444',166,'2009-4-4');
insert into userTbl values('SSK','성시경',1979,'서울',NULL,NULL,186,'2013-12-12');
insert into userTbl values('LJB','임재범',1963,'서울','016','6666666',182,'2009-9-9');
insert into userTbl values('YJS','윤종신',1969,'경남',NULL,NULL,170,'2005-5-5');
insert into userTbl values('EJW','은지원',1972,'경북','011','8888888',174,'2014-3-3');
insert into userTbl values('JKW','조관우',1965,'경기','018','9999999',172,'2010-10-10');
insert into userTbl values('BBK','바비킴',1973,'서울','010','0000000',176,'2013-5-5');

insert into buyTbl values(NULL, 'KBS','운동화', NULL, 30, 2);
insert into buyTbl values(NULL, 'KBS','노트북', '전자', 1000, 1);
insert into buyTbl values(NULL, 'JYP','모니터', '전자', 200, 1);
insert into buyTbl values(NULL, 'BBK','모니터', '전자', 200, 5);
insert into buyTbl values(NULL, 'KBS','청바지', '의류', 50, 3);
insert into buyTbl values(NULL, 'BBK','메모리', '전자', 80, 10);
insert into buyTbl values(NULL, 'SSK','책', '서적', 15, 5);
insert into buyTbl values(NULL, 'EJW','책', '서적', 15, 2);
insert into buyTbl values(NULL, 'EJW','청바지', '의류', 50, 1);
insert into buyTbl values(NULL, 'BBK','운동화', NULL, 30, 2);
insert into buyTbl values(NULL, 'EJW','책', '서적', 15, 1);
insert into buyTbl values(NULL, 'BBK','운동화', NULL, 30, 2);

insert into empTbl values('나사장', null, '0000');
insert into empTbl values('김재무' ,'나사장', '2222');
insert into empTbl values('김부장', '김재무', '2222-1');
insert into empTbl values('이부장', '김재무', '2222-2');
insert into empTbl values('우대리', '이부장', '2222-2-1');
insert into empTbl values('지사원', '이부장', '2222-2-2');
insert into empTbl values('이영업', '나사장','1111');
insert into empTbl values('한과장', '이영업','1111-1');
insert into empTbl values('최정보', '나사장','3333');
insert into empTbl values('윤차장', '최정보','3333-1');
insert into empTbl values('이주임', '윤차장','3333-1-1');