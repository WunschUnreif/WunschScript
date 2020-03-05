# test of while loop

# correspond to `src/AbstractLang/UnitTest4.cpp`

var sum = (n) => {
    var s = 0;
    while n > 0 {
        s = s + n;
        n = n - 1;
    }
    return s
};

var rs1 = sum(0);

var rs2 = sum(1);

var rs3 = sum(100);
