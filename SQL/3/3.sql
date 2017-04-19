-- 문제 1
select * from sginfo;

-- 문제 2
select count(*) as '인원수' from sginfo;

-- 문제 3
select sno as '학번', sname as '이름' from stuinfo;

-- 문제 4
select dname as '과목명', dtime as '강의시수' from deptinfo where dtime = 2;

-- 문제 5
select * from deptinfo where droom like 'B%';

-- 문제 6
select sname as '학생명', sphone as '전화번호' from stuinfo where sphone not like '010%';

-- 문제 7
select pname as '교사명' from pinfo where pdept = '컴퓨터공학과';

-- 문제 8
select dname as '강의명', ddate as '강의개설일' from deptinfo where ddate between '2010-01-01' and '2016-08-01';

-- 문제 9
insert into pinfo(pid, pname, pdept, pphone)
values ('p006', '송중기', '소프트웨어개발과', '010-111-2222');

insert into pinfo(pid, pname, pdept, pphone)
values ('p007', '박보검', '소프트웨어개발과', '010-222-3333');

select pname as '교사명' from pinfo where psearch is null;