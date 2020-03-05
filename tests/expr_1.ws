# test basic expressions

# correspond to `src/AbstractLang/UnitTest2.cpp`

var x = 1;          # stmt1

var dict1 = {
    x : 3,
    y : 2
};                  # stmt 2

var foo = (dict) => {
    dict.z = dict.x + dict.y * 5 % 3; # ==> 3 + 2 * 5 % 3 = 4
    return x;
};                  # stmt 3

var rs = foo(dict1);# stmt 4

# print results: {rs, dict1}
