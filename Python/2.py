# 1. 사용자로부터 문자열을 입력받아 str의 몇번째에 위치하는지 확인 후,
# str의 시작부터 해당문자열까지 출력하시오.
str = "You're beautiful girl beautiful girl ... 나는 beautiful girl"
userStr = input("input string : ")
len = str.find(userStr)
print(str[len:])

# 2. 처음 'girl'과 마지막 'girl' 사이의 모든 단어를 출력하시오. (문장 앞,뒤 공백 제거)
str = "You're beautiful girl beautiful girl ... 나는 beautiful girl"
girl = "girl"
l = str.find(girl) + len(girl)
s = str.rfind(girl)
print(str[l:s].strip())

# 3. 문장에서 "beautiful girl"의 반복횟수를 출력하고,
# "beautiful girl"을 다른 단어로 바꾸어 출력하시오.
str = "You're beautiful girl beautiful girl ... 나는 beautiful girl"
count = str.count("beautiful girl")
print("반복횟수는 {0}회입니다. ".format(count))
userStr = input("input string : ")
print(str.replace("beautiful girl", userStr))