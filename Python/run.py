data = []

with open("test.txt", "rt", encoding="utf8") as file:
    fileData = str(file.readline())

    data = fileData.split(',')

for i in range(0, len(data), 2):
    print("이름 : {0} , 나이 : {1}".format(data[i], data[i+1]))