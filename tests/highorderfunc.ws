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
