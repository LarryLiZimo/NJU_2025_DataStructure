#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>

#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
//#define int ll

using namespace std;

inline int Read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    do {
        x = x * 10 + (ch - '0');
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return x * f;
}

const int N = (2e5 + 6);
int n, k, a[N*2],b[N];
int fa[N * 2],sn[N*2][2];
int cnt[N];
int Div(int x, int y) {
    if (x % y == 0) {
        return x / y;
    }
    else {
        return x / y + 1;
    }
}
int dfs(int x) {
    int ret = 0;
    cnt[x] = b[x];
    for (int i = 0; i <= 1; i++) {
        int s = sn[x][i];
        if (s <= 0) {
            continue;
        }
        int r = dfs(s);
        cnt[x] += cnt[s];
        ret += Div(cnt[s], k);
        ret += r;
    }
    //cout << x << ":" << cnt[x] << ":" << ret << endl;
    return ret;
}
signed main() {
    n = Read();
    k = Read();
    queue<int*>q;
    q.push(&sn[0][0]);
    for (int i = 1; i <= 2 * n + 1; i++) {
        int x = Read();
        int* t = q.front();
        q.pop();
        *t = x;
        if (x > 0) {
            q.push(&sn[x][0]);
            q.push(&sn[x][1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        b[i] = Read();
    }

    /*for (int i = 1; i <= n; i++) {
        cout << i << ":"<<sn[i][0] << ":" << sn[i][1] << endl;
    }*/

    int ans = dfs(1);
    cout << ans << endl;
    
}