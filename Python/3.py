# if
from datetime import datetime
hour = datetime.now().hour
if hour < 12:
    print('오전입니다')
numbers = [1,2,3,4,5]
if 5 in numbers:
    print("5가 있다")

# while
i, j, count = 1, 1, 5
while i < count:
    while j <= i:
        print('*', end='')
        j += 1
    print()
    j = 1
    i += 1

# for
for i in range(7):
    print(i)
for i in range(1,7,2):
    print(i)    
for i in range(1,6):
    for j in range(i):
        print('*', end='')
    print()
for s in ['adc', 'de', 'fgh']:
    print(s)
p = ['가위', '바위', '보']
for i in p:
    print(i)
str = ['a', 'bc', 'def', 'ghij']
for i, s in enumerate(str):
    print('{}번 : {}'.format(i + 1, s))
for s2 in "abcdefgh":
    print(s2)

# 예제 1
n = int(input('숫자를 입력하세요 : '))
for i in range(1, n + 1):
    print('2 to the ' + str(i) + ' power is ' + str(2**i))

# 과제 1
n = int(input('숫자를 입력하세요 : '))
i = 0
while i < 10:
    print('2 to the ' + str(i) + ' power is ' + str(2**i))
    i += 1

# 예제 2
sentence = input('문자열 입력 : ')
count = 0
for c in sentence:
    if c in 'aeiou':
        count += 1
print('There are ' + str(count) + ' vowels in that sentence.')

# 과제 2
for i in range(1, 10):
    for j in range(2, 10):
        print("{0:2d} * {1:2d} = {2:2d}".format(j, i, i*j), end='')
    print()