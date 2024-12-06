#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;

// Input here
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string S = "^>v<";

int n, m;
int sx, sy, sdir;
vector<string> a;

void input() {
    string s;
    while (getline(cin, s)) {
        a.push_back(s);
    }

    n = a.size();
    m = a[0].size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (S.find(a[i][j]) != string::npos) {
                sx = i;
                sy = j;
                sdir = S.find(a[i][j]);
            }
        }
}

// ----------------------------------------------------------------

bool vis[1001][1001][4];

void bfs() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            for (int k = 0; k < 4; k++)
                vis[i][j][k] = false;
    queue<iii> q;
    q.emplace(sx, sy, sdir);
    vis[sx][sy][sdir] = true;

    while (!q.empty()) {
        auto [x, y, dir] = q.front(); q.pop();
        int xx = x + dx[dir];
        int yy = y + dy[dir];
        if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
        if (a[xx][yy] == '#') {
            int dd = (dir + 1) % 4;
            if (vis[x][y][dd]) continue;

            vis[x][y][dd] = true;
            q.emplace(x, y, dd);
            continue;
        }

        vis[xx][yy][dir] = true;
        q.emplace(xx, yy, dir);
    }
}

bool reach_edge() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            bool ok = false;
            for (int k = 0; k < 4; k++)
                if (vis[i][j][k])
                    ok = true;
            if (ok && (i == 0 || i == n - 1 || j == 0 || j == m - 1))
                return true;
        }
    return false;
}

// Part 1
void part_1() {
    bfs();

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            bool ok = false;
            for (int k = 0; k < 4; k++)
                if (vis[i][j][k])
                    ok = true;
            if (ok) {
                ans++;
            }
        }
    cout << ans << '\n';
}

// Part 2
void part_2() {
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                a[i][j] = '#';
                bfs();
                if (!reach_edge()) 
                    ++ans;
                a[i][j] = ',';
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