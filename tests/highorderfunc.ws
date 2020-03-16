var getadd = (with) => {

    # this function captures 'with'
    var add = (a)[with] => {

        # this function captures 'a' and 'with'
        var inneradd = (b)[a, with] => {
            return a + b + with;
        };
        
        return inneradd;
    };

    return add;
};

print(getadd(3)(4)(5));

var genfunc = (x) => {
    var a = ()[x] => {
        return x;
    };

    x.a = 2;

    return a;
};

var iden1 = genfunc({a : 1});
var iden2 = genfunc({a : 3});

print(iden1());
print(iden2());
