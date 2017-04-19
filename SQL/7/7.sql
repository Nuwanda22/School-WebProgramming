# 문제 1
use dsmstu;
alter table pinfo add column pseq int not null auto_increment unique first;
show index from pinfo;
desc pinfo;

# 문제 2
create index IDX1 on pinfo(pname);
show index from pinfo;
desc pinfo;

# 문제 3
create index IDX2 on pinfo(pdept);
show index from pinfo;
desc pinfo;
drop index IDX2 on pinfo;

# 문제 4
use employees;
create view v_hire_date_employees as select birth_date from employees;
select * from v_hire_date_employees;

# 문제 5
use mysql;
update user set authentication_string = password('apple') where user.User = 'root';

# 문제 6
insert into user(host, user, authentication_string, ssl_cipher, x509_issuer, x509_subject) values("localhost", "apple", password('apple01'),'','','');
grant all privileges on dsmstu.* to apple@localhost identified by 'apple01';
flush privileges;
select * from user;

# 문제 7
insert into db(host, db, user) values("localhost", "dsmstu", 'orange');
flush privileges;
select * from db;

# 문제 8
update user set authentication_string = password('qq1122') where user.User = 'apple';
grant all privileges on *.* to apple@localhost identified by 'qq1122';
flush privileges;

# 문제 9
grant all privileges on mysql.* to orange@localhost identified by 'abcd';
grant select on dsmstu.* to orange@localhost;
flush privileges;