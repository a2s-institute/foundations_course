class Ice_Cream():
    def make_Ice_Cream(self):
        pass


class Simple_Icecream(Ice_Cream):

    def make_Ice_Cream(self):
        return "Basic Icecream"


class Ice_Cream_Decorator(Ice_Cream):
    special_Ice_Cream : Ice_Cream = None

    def __init__(self, special_Ice_Cream : Ice_Cream):
        self.special_Ice_Cream = special_Ice_Cream

    def make_Ice_Cream(self):
        return Simple_Icecream.make_Ice_Cream()


class Ice_Cream_Nuts(Ice_Cream_Decorator):
    def __init__(self, special_Ice_Cream : Ice_Cream):
        super().__init__(special_Ice_Cream)

    def make_Ice_Cream(self):
        return self.special_Ice_Cream.make_Ice_Cream()+" With Nuts"


class Ice_Cream_Chocochips(Ice_Cream_Decorator):
    def __init__(self, special_Ice_Cream : Ice_Cream):
        super().__init__(special_Ice_Cream)
        
    def make_Ice_Cream(self):
        return self.special_Ice_Cream.make_Ice_Cream()+" With Chocochips"


basic_ice_cream = Simple_Icecream()
print(basic_ice_cream.make_Ice_Cream())

nuts_ice_cream = Ice_Cream_Nuts(basic_ice_cream)
print(nuts_ice_cream.make_Ice_Cream())

chips_ice_cream = Ice_Cream_Chocochips(basic_ice_cream)
print(chips_ice_cream.make_Ice_Cream())

top_ice_cream = Ice_Cream_Chocochips(nuts_ice_cream)
print(top_ice_cream.make_Ice_Cream())