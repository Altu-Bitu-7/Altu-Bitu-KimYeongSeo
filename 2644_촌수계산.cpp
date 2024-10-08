#include <iostream>
#include <queue>
using namespace std;

const int MAX = 101;  // 상수 MAX를 선언하여 101로 설정

int n, x, y, m;
int fam[MAX][MAX] = {0, };
bool visited[MAX] = {false, }; 
int number[MAX] = {0, };  // 촌수를 저장할 배열

void bfs(int cal) {
    queue<int> q;
    q.push(cal);
    visited[cal] = true;  // 시작 노드를 방문 표시
    
    while (!q.empty()) {
        int fir = q.front();
        q.pop();

        for (int i = 1; i <= n; i++) {  // 1번부터 n번까지 탐색
            if (fam[fir][i] == 1 && !visited[i]) {  // 아직 방문하지 않은 경우
                q.push(i);
                visited[i] = true;  // 방문 표시
             number[i] = number[fir] + 1;  // 촌수는 현재 노드의 촌수 + 1
            }
        }
    }
}

int main() {
    cin >> n >> x >> y >> m;

    for (int i = 0; i < m; i++) {
        int p1, p2;
        cin >> p1 >> p2;
        fam[p1][p2] = fam[p2][p1] = 1;  // 관계 설정
    }

    bfs(x);  // 시작점 x에서 BFS 탐색

    if (!visited[y]) {  // y에 도달하지 못한 경우
        cout << -1;
    } else {
        cout << number[y];  // y까지의 촌수 출력
    }

    return 0;
}
