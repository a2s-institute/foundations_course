from abc import ABC, abstractmethod
class Calculate(ABC):
    @abstractmethod
    def operate(self, x, y):
        pass
        
class Add(Calculate):
    def operate(self, x, y):
        print("operate function in Add class")
        return x+y

class Subtract(Calculate):
    def operate(self, x, y):
        print("operate function in Subtract class")
        return x-y

class User(Calculate):
    __calculate = None
    def __init__(self, function):
        self.__calculate = function()
    def operate(self, x, y):
        return self.__calculate.operate(x, y)

add = User(Add)
print("Addition class: ")
print(add.operate(3, 4))

subtract = User(Subtract)
print("Subtract class: ")
print(subtract.operate(7, 4))