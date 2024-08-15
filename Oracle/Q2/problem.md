# Friend Groups
The new students in a college receive an ID from 1 to n, and initially they are ordered as 
singleton {i} (as they don't have friends), as time goes on the groups start to form and the
number of orderings decrease (as friend grp size increases). You are given q queries in each of 3 arrays :- queryType, students1 & students2. The queryType can have either "friend" or 
"total" as the value in it and student arrays will have indices (1 <= index <= n), if query is "friend" then the two corresponding student indices become a part of one grp, otherwise report the sizes of each student grp.

## Input
```
n = 4
q = 3
queryType = ["Friend", "Friend", "Total"]
students1 = [1, 2, 1]
students2 = [2, 3, 4]
```

## Output
```
When we reach total, the grps will transform like below
{{1}, {2}, {3}, {4}} => {{1, 2}, {3}, {4}} => {{1, 2, 3}, {4}} => 3 + 1 = 4
Hence, ans = 4
```
