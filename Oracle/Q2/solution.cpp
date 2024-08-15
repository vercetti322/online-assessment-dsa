#include <bits/stdc++.h>

using namespace std;

// dsu approach
vector<int> getTheGroups(int n, vector<string>& qType, vector<int>& s1, vector<int>& s2) {
    int q = qType.size();
    vector<int> ans;
    vector<set<int>> grps;
    int grp_size = 0;

    for (int i = 0; i < q; i++) {
        if (qType[i] == "Friend") {
            
        } else {
            ans.push_back(grp_size);
        }
    }
}


int main() {
    int n, q;
    cin >> n >> q;
    vector<string> queryType(q);
    vector<int> students1(q), students2(q);

    for (int i = 0; i < q; i++)
        cin >> queryType[i];

    for (int i = 0; i < q; i++)
        cin >> students1[i];

    for (int i = 0; i < q; i++)
        cin >> students2[i];

    vector<int> ans = getTheGroups(n, queryType, students1, students2);

    for (const auto& it: ans)
        cout << it << " ";
    cout << endl;
}