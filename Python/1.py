# 예제 1. 3와 5의 덧셈과 뺄셈
num1=int(input('input value1 : '))
num2=int(input('input value2 : '))
print('두 수의 합은 ', num1+num2, '입니다.')

# 1. 두 수를 입력받아 곱셈을 한 결과를 출력하기
num1=int(input('input value1 : '))
num2=int(input('input value2 : '))
print(num1*num2)

# 2. 두 수를 입력 받아 두 수의 몫과 나머지를 구하기
num1=int(input('input value1 : '))
num2=int(input('input value2 : '))
print(num1//num2)
print(num1%num2)

# 3. 밑변과 높이를 입력 받아 삼각형의 넓이를 구해 출력하기
num1=int(input('밑변을 입력하시오 : '))
num2=int(input('높이를 입력하시오 : '))
print('삼각형의 넓이는 ', num1*num2/2, '입니다.')

# 4. 3개의 성적을 입력 받아 합과 평균을 출력하기
korean=eval(input('국어 : '))
english=eval(input('영어 : '))
math=eval(input('수학 : '))
sum = korean + english + math
avg=(korean+english+math)/3
print('합은 ', sum, '이고, ', '평균은 ', avg, '점입니다')

# 5. 센티미터를 미터와 센티미터로 변환하기
cm=float(input('cm : '))
m=cm/1000
print('m : ', m)

# 6. 초를 입력 받아 시간과 분, 초로 변환한 결과를 출력하기
second = int(input('초를 입력하시오 : '))
hour = second // 3600
min = (second % 3600) // 60
second = second % 60
print(hour, '시간 ', min, '분 ', second, '초')

# 예제 2. 문자열의 연산
a = '1234'; b = '5678'; c = 'hello!'; d = 'python'; e = c + d
print(a + b);               # 12345678
print(e)                    # hello!python
print(e*3)                  # hello!pythonhello!pythonhello!python
e=eval(a+b); print(e)       # 12345678
print(eval(a) + eval(b))    # 6912

# 예제 3. 문자열의 슬라이싱
str = '20160921184036'
date = str[:8]
time = str[8:]
print(date)
print(time)

# 7. 년, 월, 일, 시, 분, 초를 따로 출력하기
str = '20160921184036'
year = str[:4]
month = str[4:6]
day = str[6:8]
hour = str[8:10]
minute = str[10:12]
second = str[12:14]
print(year, month, day, hour, minute, second)

# 8. 문자열의 날짜를 내일 날짜로 변경하기
str = '20160921184036'
yearMonth = str[:6]
day = str[6:8]
time = str[8:14]

day = "%d" % (int(day) + 1)

tomorrow = yearMonth+day+time
print(tomorrow)