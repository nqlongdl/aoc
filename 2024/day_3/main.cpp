#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Input here
vector<string> a;

void input() {
    string s;
    while (getline(cin, s)) {
        a.push_back(s);
    }
}

// ----------------------------------------------------------------

int mul(string &s, int l, int r) {
    if (r - l + 1 < 3) return 0;
    string tmp = s.substr(l, r - l + 1);
    int n1 = 0, n2 = 0;
    
    // validate that string is n1,n2
    for (int i = 1; i < (int)tmp.size() - 1; i++) {
        if (tmp[i] == ',') {
            for (int j = 0; j < i; j++)
                if (!isdigit(tmp[j]))
                    return 0;
            for (int j = i + 1; j < (int)tmp.size(); j++)
                if (!isdigit(tmp[j]))
                    return 0;
            n1 = stoi(tmp.substr(0, i));
            n2 = stoi(tmp.substr(i + 1, tmp.size() - i - 1));
            return n1 * n2;
        }
    }
    return 0;
}

// Part 1
void part_1() {
    int ans = 0;
    for (string s : a) {
        for (int i = 0; i < (int)s.size() - 3; i++) {
            if (i + 3 < (int)s.size() && s.substr(i, 4) == "mul(") {
                for (int j = i + 4; j < (int)s.size(); j++) {
                    if (s[j] == ')') {
                        ans += mul(s, i + 4, j - 1);
                        break;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}

// Part 2
void part_2() {
    int ans = 0;
    bool enabled = true;
    for (string s : a) {
        for (int i = 0; i < (int)s.size() - 3; i++) {
            if (enabled && i + 3 < (int)s.size() && s.substr(i, 4) == "mul(") {
                for (int j = i + 4; j < (int)s.size(); j++) {
                    if (s[j] == ')') {
                        ans += mul(s, i + 4, j - 1);
                        break;
                    }
                }
            }
            if (i + 3 < (int)s.size() && s.substr(i, 4) == "do()") enabled = true;
            if (i + 6 < (int)s.size() && s.substr(i, 7) == "don't()") enabled = false;
        }
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