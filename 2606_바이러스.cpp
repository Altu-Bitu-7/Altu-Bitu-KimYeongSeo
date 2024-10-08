#include <iostream>
#include <queue>
using namespace std;

int n, m; 
const int MAX = 101; //0부터 100까지 총 101 칸의 배열 생성
int arr[MAX][MAX] = {0, }; //최대 입력갑이 100이므로 인접 행렬 사용 가능
bool visit[MAX] = {false, };
int cnt = 0;
const int CHECKNUM = 1;

void bfs(int virus) { //너비 우선 탐색 함수
    queue<int> q;
    q.push(virus);
    visit[virus] = true;

    while (!q.empty()) {
        int fir = q.front();
        q.pop();
        
        for (int i = 1; i<=n; i++) { 
            if (!visit[i] && arr[fir][i]==1) {
                q.push(i);
                visit[i] = true;
                cnt++;
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i<m; i++) { //이차원 배열로 인접 행렬 채우기
        int col, row;
        cin >> col >> row;
        arr[col][row] = 1;
        arr[row][col] = 1;
    }

    bfs(CHECKNUM);

    cout << cnt;
}
