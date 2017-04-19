# Procedure
use employees;

drop procedure if exists ifProc2;
delimiter $$
create procedure ifProc2()
begin
	# 변수 선언
	declare hireDate date;
    declare curDate date;
    declare days int;
    
    # 변수 초기화
    select hire_date into hireDate from employees.employees where emp_no = 10001;
    set curDate = current_date();
    set days = datediff(curDate, hireDate); -- hire_date

	# 프로시저 내용
    if (days / 365) >= 5 then
		select concat('입사한지 ', days, '일이나 지났습니다. 축하합니다!') as 'memo';
    else
		select concat('입사한지 ', days, '일밖에 안되었네요. 열심히 일합시다!') as 'memo';
    end if;
end $$
delimiter ;

call ifProc2();


# Trigger
use sqldb;

create table backup_usertbl(
	userid char(8) not null primary key,
    name varchar(10) not null,
    birthYear int not null,
    addr char(2) not null,
    mobile1 char(3),
    mobile2 char(8),
    height int,
    mDate date,
    modType char(2),
    modDate date,
    modUser varchar(256)
);

drop trigger if exists backUserTbl_UpdateTrg;
delimiter //
create trigger backUserTbl_UpdateTrg
	after update
    on usertbl
    for each row
begin
	insert into backup_usertbl values(old.userID, old.name, old.birthYear, old.addr, old.mobile1, old.mobile2, old.height, old.mDate, '수정', curdate(), current_user());
end //
delimiter ;

update usertbl set addr = '미국' where userID='JKW';

select * from backup_usertbl;

delimiter //
create trigger backUserTbl_DeleteTrg
	after delete
    on usertbl
    for each row
begin
	insert into backup_usertbl values(old.userID, old.name, old.birthYear, old.addr, old.mobile1, old.mobile2, old.height, old.mDate, '삭제', curdate(), current_user());
end //
delimiter ;

delete from userTbl where userid = 'YJS';


# Make User Account
use mysql;

select * from db;
select * from user;

insert into user(host, user, authentication_string, ssl_cipher, x509_issuer, x509_subject) values("localhost", "banana2", password('banana2'),'','','');

flush privileges;