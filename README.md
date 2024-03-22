Tabu Search
===
this project uses Tabu search to solve the deception problem
- [HackMD link](https://hackmd.io/@B3AsTCbwSKGZWfnA5FLfFA/SyNmVYBAT)

Program Description
---
#### Overview
- 1.The initial value of the Deception Problem will be randomly generated at the beginning.
- 2.Enter iteration 
>- Evolve the next problem by the algorithm
>- Verify that it is legal and in the history
>- Determine whether it is the best solution
- 3.Output results
- note:
>- The algorithm uses the given value to randomly exchange 2 different bits to generate the next new value.
#### Code
- Tabumain
>- main funcion

- tabusearch
>- tabu search algorithm implement

- deception problem
>- deception problem implement
>- #deception problem is a maximization problem

executable file
---
- Linux:PRO
- Window:PRO.exe
- click PRO.exe to see the values ​​generated at the beginning and the final value of the algorithm.

Makefile
---
- test:run program
- clean:delete program
>- #program can determine the os system to generate the executable file

