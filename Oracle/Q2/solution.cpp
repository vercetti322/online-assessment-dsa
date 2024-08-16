#include <bits/stdc++.h>

using namespace std;

class DSU {
    vector<int> rank, parent, size;
    public:
        DSU(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        // with path compression
        int findUltPar(int node) {
            if (node == parent[node])
                return node;
            else
                return parent[node] = findUltPar(parent[node]);
        }

        // union by rank
        void unionByRank(int u, int v) {
            int ulp_u = findUltPar(u);
            int ulp_v = findUltPar(v);
            
            if (ulp_u == ulp_v) return;
            if (rank[ulp_u] < rank[ulp_v])
                parent[ulp_u] = ulp_v;
            else if (rank[ulp_v] > rank[ulp_v])
                parent[ulp_v] = ulp_u;
            else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            } 
        }

        // union by size
        void unionBySize(int u, int v) {
            int ulp_u = findUltPar(u);
            int ulp_v = findUltPar(v);
            
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }

        int getSize(int node) {
            int ulp_node = findUltPar(node);
            return size[ulp_node];
        }
};

vector<int> getTheGroups(int n, vector<string>& qt, vector<int>& s1, vector<int>& s2) {
    DSU dsu(n);
    vector<int> ans;
    for (int i = 0; i < qt.size(); i++) {
        if (qt[i] == "Friend") {
            dsu.unionBySize(s1[i], s2[i]);
        } else {
            int total_size = dsu.getSize(s1[i]) + dsu.getSize(s2[i]);
            ans.push_back(total_size);
        }
    }

    return ans;
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