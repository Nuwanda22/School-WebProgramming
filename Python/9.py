file = open("hello.txt")

for d in file.readlines():
    print(d)

file.close()


fp1 = open("fopen.txt", "w")

for i in range(1, 11):
    content = "%d \n" %i
    fp1.write(content)

fp1.close


lines = ["안녕하세요\n", "こんにちは\n", "Hello\n"]

with open("test_utf8.txt", "wt", encoding="utf8") as file:
    file.writelines(lines)

with open("test_utf8.txt", "rt", encoding="utf8") as file:
    lines = file.readlines()
    for line in lines:
        print(line, end='')
