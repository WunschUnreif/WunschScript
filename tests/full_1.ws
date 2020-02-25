# this is a wunschscript code.
# another line of comment
var x = 10;

x = (x + 5 * 3) % 6;

var dictA = 
{
    x : 3,
    y : 5,
    
    setX : (x) => {
        this.x = x;
        return x;
    },

    setY : (y) => {
        this.y = y;
        return nil;
    }
};

var haveMember = (obj, memName) => {
    return obj[memName] != nil;
};

if haveMember(obj1, "setX") {
    obj1.setX(x);
} else {
    print("error");
}

print(obj1);

(x) => 
    print(x);
("hello");

"hello";
[
    "this is a list",
    [],
    [12, 34, 56]
];
64.64e-3;
(x, y) => {
    return 2 * x + y - 1;
};
nil;
{
    hello : ["world", "!"]
};

print("hello, world", "!");
dictA.setX(13);

var x = 3.65;
x = (n) => {
    return n * n;
};

(x + 5 * 3) % 6;
somefunc();

if 3 * 4 == 12 {
    print("Of course");
} else {
    print("Oho!!!")
}

var i = 0;
while i < 4 {
    print("I'm in the loop!");
    i = i + 1;
}

var arr = [1, 2, 3];
var sum = 0;
for elem in arr {
    sum = sum + elem; 
    # `sum` will be 6.
}

var dictA = { x : "y" };
for key in dictA {
    print(key); 
    # will print "x"

    print(dictA[key]); 
    # will print "y"
}

var add = (x, y) => { 
    return x + y;
};

var a = 3;

var curryAdd = (x) => {
    var _ = (y) => { return add(x, y) + a; };
    return _;
};

curryAdd(3)(4);

var t = 3;

var factorial = (n) => {
    if n == 0 {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
# (assign 'factorial 
#   (funcliteral ('n) ()  ))

var out = () => {
    var inn = () ==> {
        out();
        print(t);
    }
    return inn;
}

var t = 4;

var _inn = out();
