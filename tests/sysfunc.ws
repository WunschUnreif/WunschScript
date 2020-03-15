
print("Hello, world!");

# var str = readline("Enter a string: ");
# print("You entered: " + str);

var sum = ([elems]) => {
    var result = 0;
    for x in elems {
        result = result + x;
    }
    return result;
};

print(sum(1, 2, 3, 4, 5, 6, 7, 8, 9));
