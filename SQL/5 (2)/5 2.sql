# 문제 1
select name, height from usertbl where height >= (select height from usertbl where name = '김경호');

# 문제 2
select name, height from usertbl where height >= any(select height from usertbl where addr = '경남');
select name, height from usertbl where height > all(select height from usertbl where addr = '경남');

# 문제 3
select name from usertbl order by birthYear asc limit 5;

# 문제 4
select userid as '사용자 아이디', sum(price * amount) as '총 구매액' from buytbl group by userid having sum(price * amount) >= 1000;

# 문제 5
select name as '이름', addr as '주소', concat(mobile1, mobile2) as '연락처' from buytbl inner join usertbl on buytbl.userID = usertbl.userID where buytbl.userID = 'jyp';

# 문제 6
select usertbl.userid as '회원ID', name as '이름', addr as '주소' from usertbl inner join buytbl on buytbl.userID = usertbl.userID group by name;

# 문제 7
select userid as '회원ID', name as '이름', addr as '주소' from usertbl where exists(select * from buytbl where usertbl.userid = userid group by name);

# 문제 8
select e.emp as '부하직원', m.emp as '상관', m.empTel as '상관 연락처' from emptbl e join emptbl m on e.manager = m.emp where e.emp = '우대리';