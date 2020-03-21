var merge = (arr, left, mid, right) => {
    var temp = [nil] * (right - left)
    var i = left
    var j = mid 
    var k = 0

    while i < mid && j < right {
        if arr[i] < arr[j] {
            temp[k] = arr[i]
            i = i + 1
        } else {
            temp[k] = arr[j]
            j = j + 1
        }
        k = k + 1
    }

    while i < mid {
        temp[k] = arr[i]
        i = i + 1
        k = k + 1
    }

    while j < right {
        temp[k] = arr[j]
        j = j + 1
        k = k + 1
    }

    for k in range(right - left) {
        arr[left + k] = temp[k]
    }
}

var mergesort = (arr, left, right) => {
    if right - left <= 1 {
        return nil
    }
    var mid = (left + right) / 2
    mergesort(arr, left, mid)
    mergesort(arr, mid, right)
    merge(arr, left, mid, right)
}

var testcase = [1, 5, 3, 2, 10, 6, 4, 7, 3, 3, 1]
mergesort(testcase, 0, len(testcase))
print(testcase)
