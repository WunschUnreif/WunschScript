print("Hello, world!");

var add = (x, y) => {
    return x + y;
};


print("add(1, 2) ==> ", add(1, 2));

var factorial = (n) => {
    if n == 0 || n == 1 {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
};

print("factorial(0) ==> ", factorial(0));
print("factorial(1) ==> ", factorial(1));
print("factorial(10) ==> ", factorial(10));
print("factorial(15) ==> ", factorial(15));


var dict1 = {
    x : 0,

    add : (n) => {
        this.x = this.x + n;
    }
};

print(dict1);
dict1.add(3);
print(dict1);

var fibo = (n) => {
    if n == 1 || n == 2 {
        return 1;
    } 
    var a = fibo(n - 1);
    var b = fibo(n - 2);
    return a + b;
};

for i in [1, 2, 3, 4, 5, 6, 7, 8] {
    print(fibo(i));
}

var sum = (n) => {
    var s = 0;
    while n > 0 {
        s = s + n;
        n = n - 1;
    }
    return <s>;
};

print(sum(1000000));
