# Index - 준비
create database employees;
# Run SQL Script로 employees 데이터베이스를 초기화
create table indextbl(
	first_name varchar(14), 
    last_name varchar(16), 
    hire_date date
);
insert into indextbl select first_name, last_name, hire_date from employees.employees limit 500;

# Index
select * from indextbl where first_name = 'Mary';				# Query cost가 높음 (103.00, Full Table Scan)
create index idx_indextbl_firstname on indextbl(first_name);	# 인덱스를 준다.
select * from indextbl where first_name = 'Mary';				# Query cost가 낮아짐 (1.20, Non-Unique Key Lookup)

#
create view v_hire_date_employees as select hire_date from employees;

select * from v_hire_date_employees;

# view
use sqldb;
create view v_userbuytbl as select name, addr, concat(mobile1, mobile2) from buytbl inner join usertbl on buytbl.userID = usertbl.userID;
alter view v_userbuytbl (name, address, mobile) as select name as '이름', addr as '주소', concat(mobile1, mobile2) as '연락처' from buytbl inner join usertbl on buytbl.userID = usertbl.userID;
select * from v_userbuytbl;

drop view v_userbuytbl;

create view v_usertbl as select userid, name, addr from usertbl;
select * from v_usertbl;
describe v_usertbl;

show create view v_usertbl;

select * from v_usertbl;
update v_usertbl set addr = '부산' where userid = 'JKW';

select * from usertbl;

insert into v_usertbl(userid, name, addr) values ('KBM','김병만','충북');

desc usertbl;

alter table usertbl modify column birthYear int not null default 0;

create view v_sum as select userid as 'userid', sum(price * amount) as 'total' from buytbl group by userid;

use information_schema;
show tables;
select * from views where TABLE_SCHEMA = 'sqldb' and TABLE_NAME = 'v_sum';

create view v_height177 as select * from usertbl where height >= 177;	# 키가 177 이상인 사람을 구하는 뷰를 만듬
insert into v_height177 values ('KKM', '김건모', 1977, '경기', '010', '55555555', 158, '2019-01-01');	# 키가 177 이하지만 뷰에서 삽입 가능함
select * from v_height177;	# 김건모 없음
select * from usertbl;		# 김건모 있음

alter view v_height177 as select * from usertbl where height >= 177 with check option;	# 177 미만은 삽입이 되지 않도록 함
insert into v_height177 values ('SJH', '서장훈', 1977, '경기', '010', '55555555', 155, '2019-01-01');	# 삽입이 불가해짐
