# 예제 1
class Hero:
    def __init__(self, name, age, weight):
        self.name = name
        self.age = age
        self.weight = weight
    def printHero(self):
        print()
        print('_________________________________________')
        print('1. name :'  , self.name)
        print('2. age :'   , self.age)
        print('3. weight :', self.weight)

class MyHero(Hero):
    def __init__(self, inSkill, inPower, idx):
        Hero.__init__(self,'차태현', 41, 69.3)
        self.skill = inSkill
        self.power = inPower
        self.idx = idx
    def printSkill(self):
        print('4. armed weapon :', self.skill, '[ power : ', self.power[self.idx], ']')

skill = ['sword', 'spear', 'bow', 'axe']
power = [98.5, 89.2, 100, 79.2]

querySkill = input('Select weapon : ')

i = 0

for item in skill:
    if item == querySkill:
        myHero = MyHero(querySkill, power, i)
        myHero.printHero()
        myHero.printSkill()
    i += 1
print('_________________________________________')
print()

# 과제 1, 2
class InstanceVar:
    def __init__(self):
        self.text_list = []

    def add(self, text):
        self.text_list.append(text)
    
    def print_list(self):
        print(self.text_list)

if __name__ == '__main__':
    a = InstanceVar()
    a.add('a')
    a.print_list()

    b = InstanceVar()
    b.add('b')
    b.print_list()

# 과제 3
class ContactInfo:
    def __init__(self, name, email):
        self.name = name
        self.email = email

    def print_Info(self):
        print('{}:{}'.format(self.name, self.email))

if __name__ == '__main__':
    me = ContactInfo('전성우', 'njk230@gmail.com')
    friend = ContactInfo('김친구', 'friend@email.com')

    me.print_Info()
    friend.print_Info()