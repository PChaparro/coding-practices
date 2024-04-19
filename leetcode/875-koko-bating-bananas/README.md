# 875. Koko Eating Bananas - Useful notes

## Ceil division without `ceil()` call

```cpp
int ceil_div(int a, int b) {
    return (a + b - 1) / b;
}
```
