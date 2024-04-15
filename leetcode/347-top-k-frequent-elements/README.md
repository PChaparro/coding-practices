# Top k frequent elements - Useful notes

## Create a vector of pairs from a map

```cpp
unordered_map<int, int> m;
vector<pair<int,int>> v(m.begin(), m.end());
```

## Sort a vector with a custom function

In the following example, we use a `lambda` function to sort the vector of pairs by the second element of the pair.

```cpp
sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second;
});
```

We can also create a "normal" function to sort the vector of pairs.

```cpp
bool compare(pair<int,int>& a, pair<int,int>& b) {
    return a.second > b.second;
}

sort(v.begin(), v.end(), compare);
```
