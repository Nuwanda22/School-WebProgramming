-- 문제 1
create database	mytest1;
create database mytest2;
show databases;

-- 문제 2
drop database mytest1;
drop database mytest2;

-- 문제 3
create database dsmstu;
show databases;
use dsmstu;

-- 문제 4
create table department
(
	deptno int not null auto_increment unique,
    deptname char(10),
    floor int,
    
    primary key(deptno)
);

create table employee
(
	empno int not null,
    empname char(10),
    title char(10),
    empdate date,
    manager int,
    salary int,
    dno int,
    
    primary key(empno),
    foreign key(manager) references employee(empno),
    foreign key(dno) references department(deptno)
);

-- 문제 5
/* 
File

Run SQL Script

example.sql

Default Schemas Name : dsmstu
Default Character Set : utf8

Run
*/