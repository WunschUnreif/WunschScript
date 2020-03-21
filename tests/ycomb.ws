# var Y = (gen) => 
#     ( (f)[gen] => (n)[f, gen] => gen(f(f))(n) ) (
#         (f)[gen] => (n)[f, gen] => gen(f(f))(n)
#     )

# var fac_gen = (g) => (m)[g] => {
#     if m <= 1 {
#         return 1
#     } else {
#         return m * g(m - 1)
#     }
# }

# print(Y(fac_gen)(5))

# var ch0 = (succ) => (zero)[succ] => zero
# var ch1 = (succ) => (zero)[succ] => succ(zero)

# var chAdd = 
# (a) => (b)[a] => 
#     (succ)[a, b] => (zero)[succ, a, b] => 
#         a(succ)(b(succ)(zero))

# var chMul = 
# (a) => (b)[a] => 
#     (succ)[a, b] => (zero)[succ, a, b] => 
#         a(b(succ))(zero)

# var ch2 = chAdd(ch1)(ch1)
# var ch4 = chMul(ch2)(ch2)
# var ch8 = chMul(ch2)(ch4)
# var ch64 = chMul(ch8)(ch8)

# print(ch2  ( (n) => n + 1 ) (0))
# print(ch4  ( (n) => n + 1 ) (0))
# print(ch8  ( (n) => n + 1 ) (0))
# print(ch64 ( (n) => n + 1 ) (0))

# print(power(2, 16, 0, 1))

# var MakePair = (a) => (b)[a] => (f)[a, b] => f(a)(b)
# var GetFirst = (pair) => pair((a) => (b)[a] => a)
# var GetLast  = (pair) => pair((a) => (b)[a] => b)

var Ch0 = (s) => (z)[s] => z
var Ch1 = (s) => (z)[s] => s(z)

var Plus = (m) => (n)[m] => 
    (succ)[m, n] => (zero)[m, n, succ] => 
        m(succ)(n(succ)(zero))

var Mult = (m) => (n)[m] =>
    (succ)[m, n] => (zero)[m, n, succ] =>
        m(n(succ))(zero)

var Ch2 = Plus(Ch1)(Ch1)
var Ch3 = Plus(Ch2)(Ch1)
var Ch9 = Mult(Ch3)(Ch3)

var Power = (base) => (exp)[base] => 
    (succ)[base, exp] => (zero)[base, exp, succ] =>
        exp(Mult(base))(Ch1)(succ)(zero)

print(Power(Ch3)(Ch9)((n) => n + 1)(0))
