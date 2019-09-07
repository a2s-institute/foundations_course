class Singleton:
    __instance = None
    a = 10
    @staticmethod 
    def getInstance():
        """ Static access method. """
        if Singleton.__instance is None:
            Singleton()
        return Singleton.__instance

    def __init__(self):
        """ Virtually private constructor. """
        if Singleton.__instance is not None:
            raise Exception("This class is a singleton!")
        else:
            Singleton.__instance = self

    def class_name(self):
        print("You are in Singleton class..")

s = Singleton()
s.kill()
s.a = 50
print(s.a)
print s

s1 = Singleton.getInstance()
s1.kill()
print(s1.a)
s1.a = 100
print(s.a)
print(s1.a)
print s1

s2 = Singleton.getInstance()
print s2
