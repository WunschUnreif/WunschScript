var len = (arr) => {
    var l = 0;
    for _ in arr {
        l = l + 1;
    }
    return l;
};

var binsearch = (arr, e, l, r) => {
    while l < r - 1 {
        var mid = (l + r) / 2;
        if arr[mid] > e {
            r = mid - 1;
        } else {
            l = mid;
        }
    }
    return {
        pos : l,
        hit : arr[l] == e
    };
};

var countRange = (arr, low, high) => {
    var length = len(arr);
    var left = binsearch(arr, low, 0, length - 1);
    var right = binsearch(arr, high, 0, length - 1);

    var ans = right.pos - left.pos;
    if left.hit {
        ans = ans + 1;
    }

    return ans;
};

var testcase = [1, 3, 4, 5, 7, 8, 11, 13];

print(countRange(testcase, 7, 12));
