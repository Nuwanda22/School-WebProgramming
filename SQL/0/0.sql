-- show all databases
show databases;

-- make and delete database
create database dsm_stu2;
drop database dsm_stu2;

-- i'll make my database for learning 
create database dsm_stu;  

-- use my database 
use dsm_stu;

-- show my tables
show tables;

-- create example table
create table stuinfo(
-- fieldname type [null/not null]
sno varchar(10) primary key,
sname char(15) not null,
sdept char(15),
sphone varchar(15)
);

-- show property of table
desc stuinfo;

/* Run SQL Script
 File - Run SQL Script - lecinfo.sql - Default Sechema Name : dsm_stu
 create table lecinfo ...
 */

-- check it work
desc lecinfo;

-- make example tables
create table pinfo(
pid varchar(5) primary key,
pname char(	15) not null,
pdept char(15),
pphone varchar(15),
psearch varchar(20)
);

create table depinfo(
dcode varchar(5) primary key,
dname char(15),
dtime int,
droom varchar(15)
);

create table signfo(
sno varchar(10),
dcode varchar(5)
);

-- and check
show tables;

-- save data
insert into pinfo values('p001', '홍영재', '컴퓨터 공학과', '010-9120-1230', '공대관 102');

-- show me all data
select * from pinfo;

-- save many data from file
load data local infile "D:/SQL/pinfo.txt" into table pinfo;

-- save data using comma
load data local infile "D:/SQL/stuinfo.txt" into table stuinfo
fields terminated by ',' ;

/*
load data local infile "D:/SQL/stuinfo2.txt" into table stuinfo character set euckr
fields terminated by ',' ;*/

-- check
select * from stuinfo;

-- delete all data (but it doesn't work)
delete from stuinfo;

-- Memo
/* variable type
int : int
not null auto_increment unique
serial default value

char(M), varchar(M) : string
char(M) -> char str[M]
varchar(M) -> string str

date : Date
*/
