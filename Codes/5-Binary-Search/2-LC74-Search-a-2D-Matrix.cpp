#include <bits/stdc++.h>
using namespace std;

static inline int contrib(int a, int b) { return (a != 0 && a == b) ? 1 : 0; }

static inline int getColor(const unordered_map<long long,int>& mp, long long pos, long long n) {
    if (pos < 0 || pos >= n) return 0;
    auto it = mp.find(pos);
    return (it == mp.end()) ? 0 : it->second;
}

vector<int> solution(int length, vector<vector<int>> queries) {
    long long n = length, pairs = 0;
    unordered_map<long long,int> col;
    col.reserve(queries.size() * 2);

    vector<int> ans;
    ans.reserve(queries.size());

    for (auto &q : queries) {
        long long x = q[0];
        int c = q[1];

        auto it = col.find(x);
        int old = (it == col.end()) ? 0 : it->second;

        if (old != c) {
            int L = getColor(col, x - 1, n);
            int R = getColor(col, x + 1, n);

            pairs -= contrib(L, old) + contrib(old, R);
            pairs += contrib(L, c) + contrib(c, R);

            col[x] = c;
        }
        ans.push_back((int)pairs);
    }
    return ans;
}