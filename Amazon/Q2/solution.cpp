#include <bits/stdc++.h>

using namespace std;

int outlier(vector<int>& arr) {
    int n = arr.size();
    int maxi = INT_MIN;
    for (const auto& it: arr)
        if (maxi < it)
            maxi = it;

    int sec_maxi = INT_MIN;
    for (const auto& it: arr)
        if (sec_maxi < it && it < maxi)
            sec_maxi = it;

    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
        if (arr[i] < sec_maxi)
            sum += arr[i];

    if (sum == sec_maxi)
        return maxi;

    return sum + sec_maxi - maxi;
}

int main() {
    int n; cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = outlier(arr);
    cout << ans << endl;
}