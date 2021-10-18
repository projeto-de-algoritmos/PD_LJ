#include <bits/stdc++.h>

#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

#define debug(x) cout << "> " << #x << " = " << x << endl;
#define debug_at(arr, at) cout << "> " << #arr << "[" << at << "] = " << arr[at] << endl;
#define debug_pair(p) cout << "> " << #p << " = (" << p.first << ", " << p.second << ")" << endl;

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 123;
const int M = 700; 

int n, money;
int cost[N];
int bonus[N];
int dp[N][M];

int f(int i, int have) {
    if(i == 0) {
        return 0;
    }
    int &ans = dp[i][have];
    if(ans == -1) {
        ans = f(i - 1, have);
        if(cost[i] <= have) {
            ans = max(ans, bonus[i] + f(i, have - cost[i]));
        }
    }
    return ans;
}

int main() {

    for(int t = 1; scanf("%d %d", &n, &money), n | money; t++) {
        fori(i, 1, n + 1) {
            scanf("%d %d", &cost[i], &bonus[i]);
        }
        memset(dp, -1, sizeof dp);
        int ans = f(n, money);
        printf("Instancia %d\n", t);
        printf("%d\n\n", ans);
    }

    return 0;
}
