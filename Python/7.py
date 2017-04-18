# 
class Callable:
    def __call__(self):
        print("I am called.")
obj = Callable()
obj()

# 예제 1
class MyDecorator:
    def __init__(self, f):
        print('initializing')
        self.func = f
    def __call__(self):
        print("begin : {}".format(self.func.__name__))
        self.func()
        print("end : {}".format(self.func.__name__))
        
def print_hello():
    print('hello')
    
p_hello = MyDecorator(print_hello)
p_hello()

# 예제 2
class MyDecorator:
    def __init__(self, f):
        print('initializing')
        self.func = f
    def __call__(self):
        print("begin : {}".format(self.func.__name__))
        self.func()
        print("end : {}".format(self.func.__name__))
        
@MyDecorator
def print_hello():
    print('hello')

print_hello()

#
class HasPrivate:
    def __init__(self):
        self.public = "Public"
        self.__private = "Private"
    def print_from_internal(self):
        print(self.public)
        print(self.__private)

obj = HasPrivate()
obj.print_from_internal()
print(obj.public)
# print(obj.__private)

# 과제 1


def change_km_to_mile(km):
    return km * 0.621371

class Car:
    def __init__(self):
        self.__speed = 0
    def get_speed(self):
        return self.__speed
    def start(self):
        self.__speed = 20
        return self.__speed
    def accelerate(self, value):
        self.__speed += value * 10
        return self.__speed
    def pbreak(self, value):
        self.__speed -= value * 10
        return self.__speed
    def stop(self):
        self.__speed = 0
        return self.__speed

mycar = Car()
print(mycar.start())
print(mycar.accelerate(1))
print(mycar.accelerate(2))
print(mycar.get_speed())
print(change_km_to_mile(mycar.get_speed()))
print(mycar.pbreak(1))
print(mycar.get_speed())
print(mycar.accelerate(1))
print(mycar.accelerate(2))
print(mycar.get_speed())
print(change_km_to_mile(mycar.get_speed()))
print(mycar.stop())

