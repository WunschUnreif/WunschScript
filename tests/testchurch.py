Ch0 = lambda s : lambda z : z
Ch1 = lambda s : lambda z : s(z)

Plus = lambda m : lambda n : lambda s : lambda z : m(s)(n(s)(z))
Mult = lambda m : lambda n : lambda s : lambda z : m(n(s))(z)

Ch2 = Plus(Ch1)(Ch1)
Ch3 = Plus(Ch1)(Ch2)
Ch9 = Mult(Ch3)(Ch3)

Power = lambda base : lambda exp: \
    lambda s : lambda z:    \
        exp(Mult(base))(Ch1)(s)(z)

print(Power(Ch9)(Ch9)(lambda n: n+1)(0))

# def sum(n):
#     s = 0
#     while n > 0:
#         s += n
#         n -= 1
#     return s

# print(sum(10000000))