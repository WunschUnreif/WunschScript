var Dict = {
    a : 1
    b : 2

    set: (what, towhat) => {
        this[what] = towhat
    }
}

var d1 = <Dict>
d1.set("a", 3)

var d2 = <Dict>
d2.set("b", 4)

print(d1)
print(d2)
