# test of recursion function using cond stmt

# correspond to `src/AbstractLang/UnitTest3.cpp`

var factorial = (n) => {
    if n == 1 || n == 0 {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
};

var rs1 = factorial(0);

var rs2 = factorial(1);

var rs3 = factorial(10);

print(rs3);
