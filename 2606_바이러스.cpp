#include <iostream>
#include <queue>
using namespace std;

int n, m; 
int arr[101][101] = {0, };  // 101 크기의 인접 행렬
bool visit[101] = {false, };
int cnt = 0;
const int CHECKNUM = 1;

void bfs(int virus) {  // 너비 우선 탐색 함수
    queue<int> q;
    q.push(virus);
    visit[virus] = true;

    while (!q.empty()) {
        int fir = q.front();
        q.pop();
        
        for (int i = 1; i <= n; i++) { 
            if (!visit[i] && arr[fir][i] == 1) {
                q.push(i);
                visit[i] = true;
                cnt++;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {  // 인접 행렬 입력 받기
        int col, row;
        cin >> col >> row;
        arr[col][row] = 1;
        arr[row][col] = 1;
    }

    bfs(CHECKNUM);

    cout << cnt;
}
