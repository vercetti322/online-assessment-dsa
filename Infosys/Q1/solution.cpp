#include <bits/stdc++.h>

using namespace std;

long swaps(vector<int>& arr) {
    int n = arr.size();
    
}

int main() {
    int n; cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    long ans = swaps(arr);
    cout << ans << endl; 
}