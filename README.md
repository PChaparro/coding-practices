# 🔥 Coding Practices

In this repository you can find some coding practices from different sources like [CodeWars](https://www.codewars.com/), [LeetCode](https://leetcode.com/), [HackerRank](https://www.hackerrank.com/), etc.

## 💻 Technologies

### 🟦 `TypeScript`

To run and test the `TypeScript` code, I'm using `Deno` instead of `Node` as the runtime environment, so that I can run the `.ts` files directly without the need of transpiling them to `.js` files:

```bash
deno run <file_name>.ts
```

Similarly, to run the tests, you can use the following command:

```bash
deno test <file_name>.ts
```

### 🇨 `C++`

To run and test the `C++` code, I'm using `g++` compiler:

```bash
g++ <file_name>.cpp -o <file_name>.bin
```

After compiling the code, you can run the binary file:

```bash
./<file_name>.bin
```

You can compile and run the code using the following one-liner:

```bash
g++ <file_name>.cpp -o <file_name>.bin && ./<file_name>.bin
```
