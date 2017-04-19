-- 문제 1
alter table example 
add column num int not null first;

-- 문제 2
alter table example
add column address varchar(10) after name;

-- 문제 3
alter table example
modify column address varchar(50) not null;

-- 문제 4
alter table example
change column address addr varchar(50) not null;

-- 문제 5
alter table example
drop column addr;

-- 문제 6
alter table example
rename mytable;

-- 문제 7
create table example(num int);
show tables;
drop table example;

-- 문제 8
alter table deptinfo
add column ddate date;

-- 문제 9
load data local infile "D:/Projects/SQL/2/stuinfo.txt" into table stuinfo
fields terminated by ',';

load data local infile "D:/Projects/SQL/2/pinfo.txt" into table pinfo;

load data local infile "D:/Projects/SQL/2/deptinfo.txt" into table deptinfo;

load data local infile "D:/Projects/SQL/2/lecinfo.txt" into table lecinfo;

load data local infile "D:/Projects/SQL/2/sginfo.txt" into table sginfo
fields terminated by ',';