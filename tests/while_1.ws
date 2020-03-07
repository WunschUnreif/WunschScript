# test of while loop

# correspond to `src/AbstractLang/UnitTest4.cpp`

var sum = (n) => {
    var s = 0;
    while n > 0 {
        s = s + n;
        n = n - 1;
    }
    return <s>;
};

var sumElems = ([elems]) => {
    var ans = 0;
    for x in elems {
        ans = ans + x;
    }
    return <ans>;   # return deep copy of ans
};

var x = sumElems(1, 2, 3);

var gcd = (a) => {
    (b) => {
        while b != 0 {
            a, b = b, a % b
        }
    }
}
