var Matrix = {

    data : [],
    row : 0,
    col : 0,

    addWith : (another) => {
        if this.row == another.row && this.col == another.col {
            var i = 0;
            while i < this.row {
                var j = 0;
                while j < this.col {
                    this.data[i][j] = this.data[i][j] + another.data[i][j];
                    j = j + 1;
                }
                i = i + 1;
            }
        } else {
            print("Shape mismatch.");
        }
        return <this>;
    },

    init : (r, c) => {
        this.row = r;
        this.col = c;

        var r = 0;
        while r < this.row {
            this.data = this.data + [0.0] * c;
            r = r + 1;
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

for _ in nil {
    var mat1 = <Matrix>;
    mat1.init(3, 3);
    mat1.data[1][1] = 3.0;

    mat1.print();

    var mat2 = <Matrix>;
    mat2.init(3, 3);
    mat2.data[0][2] = 6.0;

    var mat3 = <mat1>;
    mat3 = mat3.addWith(mat2);
    mat1.print();
    mat3.print();
}
