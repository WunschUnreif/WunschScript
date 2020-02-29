class A:
    def __init__(self):
        self.dt = 0

    def func(self, x):
        print(id(self))
        print(self.dt + x)

a = A()
b = A()

a.func(1)
b.func(1)

# b.func = a.func 

b.func(2)

def foo(x):
    print(id(x))

# a.func = foo 

a.func(12)

print(a.func == b.func)
