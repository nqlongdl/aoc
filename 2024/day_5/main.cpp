#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Input here
bool a[101][101];

vector<vector<int>> v;

void input() {
    string s;
    while (getline(cin, s)) {
        if (s == "") break;

        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == '|') {
                int x1 = stoi(s.substr(0, i));
                int x2 = stoi(s.substr(i + 1, s.size() - i - 1));
                a[x1][x2] = true;
            }
        }
    }

    while (getline(cin, s)) {
        vector<int> vi;
        int pre = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (s[i] == ',') {
                vi.push_back(stoi(s.substr(pre, i - pre)));
                pre = i + 1;
            }
        }
        vi.push_back(stoi(s.substr(pre, s.size() - pre)));
        v.push_back(vi);
    }

}

// ----------------------------------------------------------------


// Part 1
void part_1() {
    int ans = 0;
    for (vector<int>& vi : v) {
        bool ok = true;
        for (int i = 0; i < (int)vi.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (a[vi[i]][vi[j]]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok)
            ans += vi[vi.size() / 2];
    }
    cout << ans << '\n';
}

// Part 2
void part_2() {
    int ans = 0;
    for (vector<int>& vi : v) {
                bool ok = true;
        for (int i = 0; i < (int)vi.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (a[vi[i]][vi[j]]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) continue;

        sort(vi.begin(), vi.end(), [&](int x, int y) {
            return a[x][y];
        });
        ans += vi[vi.size() / 2];
    }
    cout << ans << '\n';
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    input();
    part_1();
    part_2();

    return 0;
}