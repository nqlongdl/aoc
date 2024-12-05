#include <iostream>
#include <sstream>
#include <string>
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

string xmas = "XMAS";

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

bool check_xmas(int x, int y, int dir) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[dir] * i;
        int ny = y + dy[dir] * i;
        if (nx < 0 || nx >= a.size() || ny < 0 || ny >= a[0].size() || a[nx][ny] != xmas[i]) return false;
    }
    return true;
}

// Part 1
void part_1() {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            for (int k = 0; k < 8; k++) {
                if (check_xmas(i, j, k))
                    ans++;
            }
        }
    }
    cout << ans << '\n';
}

bool check_x_mas(int x, int y) {
    if (x + 1 >= a.size() || y + 1 >= a[0].size()) return false;
    if (x - 1 < 0 || y - 1 < 0) return false;
    int cnt = 0;
    if ((a[x - 1][y - 1] == 'M' && a[x + 1][y + 1] == 'S') || (a[x - 1][y - 1] == 'S' && a[x + 1][y + 1] == 'M')) cnt++;
    if ((a[x - 1][y + 1] == 'M' && a[x + 1][y - 1] == 'S') || (a[x - 1][y + 1] == 'S' && a[x + 1][y - 1] == 'M')) cnt++;

    return cnt == 2;
}

// Part 2
void part_2() {
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a[0].size(); j++) {
            if (a[i][j] == 'A' && check_x_mas(i, j))
                ans++;
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