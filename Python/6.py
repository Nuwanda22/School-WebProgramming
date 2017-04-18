import calculator
print(calculator.plus(10,5))

import calculator as calc
print(calc.minus(10,5))

from calculator import multiply, divide
print(multiply(10,5)) 
print(divide(10,5)) 


class Base:
    def base_method(self):
        print("base method")

class Derived(Base):
    pass

b = Base()
b.base_method()
d = Derived()
d.base_method()


class A:
    def methodA(self):
        print("Class A method")

class B(A):
    def __init__(self):
        self.instance_of_A = A()

    def call_methodA(self):
        self.instance_of_A.methodA()

b = B()
b.call_methodA()


class ArmorSuite:
    def armor(self):
        print("armored")

class Ironman(ArmorSuite):
    pass

def get_red(s):
    s.armor()

suite = ArmorSuite()
get_red(suite)
ironman = Ironman()
get_red(suite)

class A:
    def __init__(self):
        print("A.__init__()")
        self.message = 'hello'
    def print(self):
        print("haha")

class B(A):
    def __init__(self):
        A.__init__(self)
        print("B.__init__()")

obj = B()
print(obj.message)


class Car:
    def ride(self):
        print("Run")
        self.msg = 'Car Class'

class FlyingCar(Car):        
    def ride(self):
        super().ride()
        print(self.msg)
        print("Fly")

my_car = FlyingCar()
my_car.ride()