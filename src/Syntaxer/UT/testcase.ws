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
    } else {
        var a = fibo(n - 1);
        var b = fibo(n - 2);
        return a + b;
    }
};

var range = (start, end, step) => {
    var result = [];
    var curr = start;
    while curr < end {
        result = result + curr;
        curr = curr + step;
    }
    return result;
}

for i in range(1, 11, 1) {
    print(fibo(i));
}

print(range(0, 10, 2));
