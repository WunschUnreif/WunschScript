# test of while loop etc.

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
    return (b)[a] => {
        while b != 0 {
            var t = a
            a = b
            b = t % b
        }
        return a
    }
}

print(gcd(34986)(3087))
