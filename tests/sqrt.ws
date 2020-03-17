var abs = (x) => {
    if x < 0.0 {
        return -x
    } else {
        return x
    }
}

var goodenough = (x, approx, delta) => {
    if abs(approx * approx - x) > delta {
        return false
    } else {
        return true
    }
}

var _sqrt = (x, delta, approx) => {
    if goodenough(x, approx, delta) {
        return approx
    }

    return _sqrt(x, delta, (approx + x / approx) / 2.0)
}

var sqrt = 
(x, delta) => {
    return _sqrt(x, delta, 1.0)
} (3.0, 0.000000001)

print(sqrt)


var recur = (x, curr) => {

}
