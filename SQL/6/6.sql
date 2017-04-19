# 문제 1
insert into pinfo values('p008', '송혜교', '정보보안과', '010-3349-9889', '공대관301');
insert into pinfo values('p009', '윤동구', '경제학과', '011-566-7767', '인화관501');
select * from pinfo;

# 문제 2
update pinfo set pdept = '정보통계학과' where pname = '황민섭';
select * from pinfo;

# 문제 3
update deptinfo set dtime = dtime + 1;
select * from deptinfo;

# 문제 4
delete from pinfo where pdept like '정보%';
select * from pinfo;

# 문제 5
update deptinfo set dname = 'JAVA' where dcode = 'c007';
select * from deptinfo;

# 문제 6
insert into deptinfo values('c009', '네트워크', 4, 'c-101', '2016-08-16');
insert into deptinfo values('c010', '운영체제', 4, 'c-102', '2015-08-30');
select * from deptinfo;

# 문제 7
delete from pinfo where pdept = '경제학과';
select * from pinfo;