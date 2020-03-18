var Y = (gen) => {
    var g = (f)[gen] => {
        return (n)[gen, f] => {
            return gen(f(f))(n)
        }
    }
    return g(g)
}

var fac_gen = (g) => {
    return (m)[g] => {
        if m <= 1 {
            return 1
        } else {
            return m * g(m - 1)
        }
    }
}

print(Y(fac_gen)(5))

var ch0 = (succ) => (zero)[succ] => zero
var ch1 = (succ) => (zero)[succ] => succ(zero)

var chAdd = 
(a) => (b)[a] => 
    (succ)[a, b] => (zero)[succ, a, b] => 
        a(succ)(b(succ)(zero))

var chMul = 
(a) => (b)[a] => 
    (succ)[a, b] => (zero)[succ, a, b] => 
        a(b(succ))(zero)

var ch2 = chAdd(ch1)(ch1)
var ch4 = chMul(ch2)(ch2)
var ch8 = chMul(ch2)(ch4)
var ch64 = chMul(ch8)(ch8)

print(ch2  ( (n) => n + 1 ) (0))
print(ch4  ( (n) => n + 1 ) (0))
print(ch8  ( (n) => n + 1 ) (0))
print(ch64 ( (n) => n + 1 ) (0))

# print(power(2, 16, 0, 1))
