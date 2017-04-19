# 문제 1
select * from lecinfo order by pid desc;

# 문제 2
select sname from deptinfo, sginfo, stuinfo 
where deptinfo.dcode = sginfo.dcode and sginfo.sno = stuinfo.sno and dname = "데이터베이스";

# 문제 3
select pname from pinfo, lecinfo, deptinfo
where deptinfo.dcode = lecinfo.dcode and lecinfo.pid = pinfo.pid and dname = "데이터베이스";

# 문제 4
select dname from pinfo, lecinfo, deptinfo
where deptinfo.dcode = lecinfo.dcode and lecinfo.pid = pinfo.pid and pname = "홍영재";

# 문제 5
select dname, dtime from deptinfo left outer join sginfo on deptinfo.dcode = sginfo.dcode where sno is null;

# 문제 6
select pname as '교사명', pdept as '학과' from pinfo left outer join lecinfo on pinfo.pid = lecinfo.pid where dcode is null;