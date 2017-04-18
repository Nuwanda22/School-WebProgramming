# 과제 1
list = []
count = 0
while True:
    num = int(input())
    if num is not 0:
        list.append(num)
        count += 1 
    else:
        break
sum = 0
for i in list:
    sum += i
avg = sum / count

print('sum is {0}'.format(sum))
print('avg is {0}'.format(avg))

# 과제 2
def inputList():
    list = []
    count = 0
    while True:
        num = int(input())
        if num is not 0:
            list.append(num)
            count += 1 
        else:
            break
    return (list, count)    

def sumOfList(list = []):
    sum = 0
    for i in list:
        sum += i
    return sum

def avg(sum, count):
    return sum / count

list, count = inputList()
sum = sumOfList(list)
avg = sum / count

print('sum is {0}'.format(sum))
print('avg is {0}'.format(avg))