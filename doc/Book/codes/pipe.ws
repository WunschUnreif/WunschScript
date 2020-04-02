var somestr = "12 34 121 564"

var somelist = 
    somestr                 |>
    splitstring             |>
    map(parseint)           |>
    filter((x) => x > 100)
    
# somelist = [121, 564]
