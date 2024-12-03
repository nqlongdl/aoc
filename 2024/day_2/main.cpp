#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Input here
vector<vector<int>> a;

void input() {
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        int x;
        vector<int> v;
        while (iss >> x)
            v.push_back(x);
        a.push_back(v);
    }
}

// Part 1
void part_1() {
    int ans = 0;
    for (auto& v : a) {
        int dif = v[1] - v[0];
        if (!dif || abs(dif) > 3) continue;

        bool ok = true;
        for (int i = 2; i < v.size(); i++) {
            int cur_dif = v[i] - v[i - 1];
            if (dif * cur_dif <= 0 || abs(cur_dif) > 3) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << '\n';
}

// Part 2
void part_2() {
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    part_1();
    part_2();

    return 0;
}