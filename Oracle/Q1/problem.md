# String Subsequences
Given two strings determine the number of times the first one appears as a subsequence of the
second string. A subsequence is made by eliminating any >= 0 number of characters from string
without changing the ordering.

## Input
```
s1 = "ABC"
s2 = "ABCBABC"
```

## Output
```
5 (following triples => {0, 1, 2}, {0, 1, 6}, {0, 3, 6}, {0, 5, 6}, {4, 5, 6})
```