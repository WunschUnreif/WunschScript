var Greeting = {
    text : "Hello, WunschScript!"

    greet : () => {
        print(this.text)
    }
}

var greeting = <Greeting>

greeting.greet()
