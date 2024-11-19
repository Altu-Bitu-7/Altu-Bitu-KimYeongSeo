#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int n, r, q, u, v, k, res;
map<int, vector<int> > adj;  //인접 리스트를 map으로 사용
map<int, int> dp;  //dp 배열을 map으로 사용
map<int, bool> visited;  //방문 여부를 map으로 사용

//dfs로 그래프를 순회하면서, dp 배열에 값 저장 -> 서브트리에 속한 정점의 수 저장
int dfs(int x) {
    if (dp.find(x) != dp.end()) return dp[x];  
    visited[x] = true;
    int ret = 1;
    for (int i : adj[x]) {
        if (!visited[i]) {
            ret += dfs(i);
        }
    }
    dp[x] = ret;
    return ret;
}

int main() {
    //입력
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr); //이 부분을 추가하였더니 시간 초과 에러가 해결되었다.
    cin >> n >> r >> q;
    
    //입력 및 연산(양방향 그래프 생성)
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dp[r] = dfs(r);  // 루트 노드에서부터 dfs 시작
    
    for (int i = 0; i < q; i++) {
        cin >> k;
        cout << dp[k] << '\n';
    }

    return 0;
}
