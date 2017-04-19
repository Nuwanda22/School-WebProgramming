-- 문제 1
select syear as '학년', avg(sgrade) as '학교장인증제 평균점수' from stuinfo group by syear;

-- 문제 2
select sname as '이름', sbirthday as '생년월일', floor((to_days(now()) - to_days(sbirthday)) / 365) as '나이' from stuinfo;

-- 문제 3
select sname as '이름', date_add(sbirthday, interval 20 year)  as '성년의 날' from stuinfo;

-- 문제 4
select syear as '학년', count(*) as '학생수' from stuinfo group by syear;

-- 문제 5
select dcode as '과목코드', count(*) as '과목별 학생수' from sginfo group by dcode;

-- 문제 6
select date_add(now(), interval 1000 day) as '천일 후 날짜' from dual; 

-- 문제 7
select pdept as '학과', count(*) as '교사수' from pinfo group by pdept;

-- 문제 8
select sdept as '학과', count(*) as '인원수' from stuinfo group by sdept having count(*) >= 3;