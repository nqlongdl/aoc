#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <map>
#include <unordered_map>

using namespace std;

// Input here
vector<int> a, b;

void input() {
    string s;
    while (getline(cin, s)) {
        istringstream iss(s);
        int x, y;
        iss >> x >> y;
        a.push_back(x);
        b.push_back(y);
    }
}

// Part 1
void part_1() {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    for (int i = 0; i < a.size(); i++)
        ans += abs(a[i] - b[i]);
    cout << ans << '\n';
}

// Part 2
void part_2() {
    unordered_map<int, int> mp;
    for (int v : b)
        mp[v]++;

    int ans = 0;
    for (int v : a)
        ans += v * mp[v];
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