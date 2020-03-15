
print("Hello, world!");

# var str = readline("Enter a string: ");
# print("You entered: " + str);

# var sum = (a, [elems]) => {
#     var result = a;
#     for x in elems {
#         result = result + x;
#     }
#     return result;
# };

# print(sum([1], 2, 3, 4, 5, 6, 7, 8, 9));

var Gender = {
    isMale : false,

    toString : () => {
        if(this.isMale) {
            return "Male";
        } else {
            return "Female";
        }
    }
};

var Student = {
    name : "null",
    idnumber : "0",
    age  : 0,
    gender : <Gender>,

    print : () => {
        print(this.name, 
            " [", this.idnumber, "], ", 
            this.gender.toString(), 
            ", age: ", this.age
        );
    },

    init : (name) => {
        this.name = name;
        return this;
    }
};

# modification on deep copy
var stu1 = <Student name="刘看山" idnumber="123" age=3>;
stu1.gender.isMale = true;

stu1.print();

var stu2 = <Student>.init("北极熊");
stu2.print();

var x = () => {print("sss");};
x();
