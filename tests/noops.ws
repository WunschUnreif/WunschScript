var x = 13.0;

x = [15.0, [], {x : 4.8}];

var foo = (x, y) => {
    x = y;
    y = 10;
};

foo(1, x);
