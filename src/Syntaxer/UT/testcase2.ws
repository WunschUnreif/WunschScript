var Matrix = {
    data : [],
    rowNum : 0,
    colNum : 0,

    zero : () => {
        this.data = [];
        var i = 0;
        while i < this.rowNum {
            var j = 0;
            this.data = this.data + [];
            while j < this.rowNum {
                this.data[i] = this.data[i] + 0;
                j = j + 1;
            }
            i = i + 1;
        }
    },

    print : () => {
        print("----------------");
        for row in this.data {
            print(row);
        }
        print("----------------");
    }
};
var mat4x4 = <Matrix>;
mat4x4.rowNum = 4;
mat4x4.colNum = 4;
mat4x4.zero();
mat4x4.print();

var mat3x3 = <Matrix>;
mat3x3.rowNum = 3;
mat3x3.colNum = 3;
mat3x3.zero();
mat3x3.print();
mat3x3.data[1][1] = 2;
mat3x3.print();


