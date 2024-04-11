# Useful notes about the `918` round

## Problem E

### `Set` vs `Unordered Set`

If you're using an `Unordered Set` to search for an element but your code isn't passing the time limit, try using a `Set` instead. The `Set` has a `log(n)` complexity for searching, while the `Unordered Set` has a `O(1)` average complexity and **`O(n)` worst-case complexity** [1].

The reason seems to be that the `Hash Function` used by the `Unordered Set` takes "too long" to compute the hash of `int` / numeric values [2].

Refs:

- [1] [GeeksforGeeks](https://www.geeksforgeeks.org/set-vs-unordered_set-c-stl/)
- [2] [Codeforces](https://codeforces.com/blog/entry/22947)

### Same `Prefix sum` at two indices

If the prefix sum at two indices `i` and `j` are the same, then, the sum of elements between `i` (not inclusive) and `j` (inclusive) is zero:

```cpp
int numbers[8] = {-1, 2, -11, 4, -1, 5, -1, 2};
int prefix_sum[8] = {-1, 1, -10, -6, -7, -2, -3, -1};
```

In the above example, the prefix sum at index `0` and `7` is `-1`, which means the sum of elements in the range `(0, 7]` is zero:

```cpp
int sum = prefix_sum[7] - prefix_sum[1];
```

`sum` is `0` since `2` + `-11` + `4` + `-1` + `5` + `-1` + `2` = `0`.
