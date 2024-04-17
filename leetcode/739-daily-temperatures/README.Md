# 739. Daily temperatures - Useful notes

## Monotonic stack

With the help of a monotonic stack, we can keep track of the indices of the **decreasing** temperatures so that whenever we find a temperature that is greater than the temperature at the top of the stack, we can calculate the difference of the indices and store it in the result array. **This process is repeated until the stack is empty or the temperature oat the index that is at the top of the stack is greater than the current temperature.**
