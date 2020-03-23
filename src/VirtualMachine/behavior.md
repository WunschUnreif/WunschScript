# WunschScript VM

## Architecture

- Execution Stack
- Function Stack
- Environment Record



## VM Codegen

- `<expr>`: [R]

  ```pseudocode
  expr.codegen(rval)
  yield 'dcopy'		/* deep copy */
  ```
  
  
  
- `<expr (ID_n = expr_n)+ >`: [R]

  ```pseudocode
  expr.codegen(rval)
  yield 'dcopy'		/* deep copy */
  for n in modcnt begin
  	yield 'copy'		/* copy top GDN and push */
  	yield 'accidL ID_n'	/* access dict by ID as lval */
  	expr_n.codegen(rval)
  	yield 'assign'	/* pop -> b; pop -> a; a := b*/
  end
  ```

  

- `expr.ID`: [R, L]

  ```pseudocode
  [RVAL]
  expr.codegen(rval)
  yield 'accid ID'	/* access dict by ID as rval */
  ```

  ```pseudocode
  [LVAL]
  expr.codegen(rval)
  yield 'accidL ID'	/* access dict by ID as lval */
  ```

- `expr1[expr2]` :[R, L]

  ```pseudocode
  [RVAL]
  expr1.codegen(rval)
  expr2.codegen(rval)
  yield 'access'
  ```

  ```pseudocode
  [LVAL]
  expr1.codegen(rval)
  expr2.codegen(rval)
  yield 'accessL'
  ```

- `expr(e_1, e_2, ...)`: [R]

  ```pseudocode
  expr.codegen()
  yield 'precall'		/* prepare a new call stack */
  for n in param_cnt begin
  	e_n.codegen()
  	yield 'param'		/* put stack top to params */
  end
  yield 'call'
  ```

- `expr?`: [R]

  ```pseudocode
  expr.codegen()
  yield 'opderef'
  ```

- `expr!`: [R]

  ```pseudocode
  expr.codegen()
  yield 'fcderef'
  ```





## Instructions

| Instruction  | Action                                        |
| ------------ | --------------------------------------------- |
| `dcopy`      | `pop->x; push(deepcopy(x))`                   |
| `copy`       | `top->x; push(x)`                             |
| `accid N`    | `pop->x; push(x.CONST[n])`                    |
| `accidL N`   | `pop->x; push(& x.CONST[n])`                  |
| `access`     | `pop->d; pop->k; push(d[k])`                  |
| `accessL`    | `pop->d; pop->k; push(& d[k])`                |
| `assign`     | `pop->v; pop->e; *e = v`                      |
| `precall`    | `callStack.emplace();`                        |
| `arg`        | `pop->x; callStack.top().params.push(x)`      |
| `call`       | `pop->fn; push(fn(callStack.top().params))`   |
| `wref`       | `pop->x; push(@x)`                            |
| `opderef`    | `pop->x; push(x?)`                            |
| `fcderef`    | `pop->x; push(x!)`                            |
| `bnot`       | `pop->x; push(~x)`                            |
| `lnot`       | `pop->x; push(!x)`                            |
| `uadd`       | `typecheck(top, int|float)`                   |
| `usub`       | `pop->x; push(-x)`                            |
| `mul`        | `pop->b; pop->a; push(a * b)`                 |
| `div`        | same                                          |
| `rem`        | same                                          |
| `add`        | same                                          |
| `sub`        | same                                          |
| `lt`         | same                                          |
| `lte`        | same                                          |
| `gt`         | same                                          |
| `gte`        | same                                          |
| `eq`         | same                                          |
| `ne`         | same                                          |
| `band`       | same                                          |
| `bxor`       | same                                          |
| `bor`        | same                                          |
| `land`       | same                                          |
| `lor`        | same                                          |
| `immI N`     | `push(IntGDN(N))`                             |
| `immF N`     | `push(FloatGDN(N))`                           |
| `immB N`     | `push(BoolGDN(N))`                            |
| `immN`       | `push(NilGDN())`                              |
| `immS N`     | `push(StrGDN(Const[N]))`                      |
| `immL`       | `push(ListGDN([]))`                           |
| `immD`       | `push(DictGDN({}))`                           |
| `proc L`     | `ignore next L bytes`                         |
| `endps`      | `nop`                                         |
| `endp`       | `push(nil); returnFromFunc();`                |
| `ret`        | `retaddr.pop->ip`                             |
| `func x`     | `push(<Fn startbyte=x>)`                      |
| `param N`    | `top->fn; fn.paramNames.append(Const[N])`     |
| `arrparam N` | `top->fn; fn.arrTailName = Const[N]`          |
| `bind N`     | `top->fn; fn.bind(name=Const[N])`             |
| `name N`     | `scope[Const[N]]:=nil`                        |
| `get N`      | `push(scope[Const[n]])`                       |
| `set N`      | `pop->x; scope[Const[n]]:=x`                  |
| `this`       | `push this`                                   |
| `jfalse N`   | `pop->x; if x=false then jump to byte N`      |
| `jmp N`      | `jump to byte N`                              |
| `iter N`     | `pop->x; env.iter:=x; env.iterName:=Const[N]` |
| `next N`     | `next iteration, goto byte N`                 |





