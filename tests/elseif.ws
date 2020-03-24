var fibo = (n) => {
    if n == 1 {
        return 1
    } else if n == 2 {
        return 1
    } else {
        return fibo(n - 1) + fibo(n - 2)
    }
}

print(fibo(1))
print(fibo(2))
print(fibo(5))
