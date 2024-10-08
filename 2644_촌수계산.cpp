#include <iostream>
#include <queue>
using namespace std;

int n, x, y, m;
int fam[101][101] = {0, };  // 최대 입력값이 100이므로 인접 행렬 사용
bool visited[101] = {false, };  // 방문 여부 배열 초기화
int number[101]={0, };  // 촌수를 저장할 배열

void bfs(int cal){
    queue<int> q;
    q.push(cal);
    visited[cal] = true;  
    
    while (!q.empty()){
        int fir = q.front();
        q.pop();



        for (int i = 1; i<=n; i++){ 

            if (fam[fir][i]==1 && !visited[i]){ 
                q.push(i);
                visited[i] = true; 

                number[i] = number[fir]+1;  // 촌수는 현재 노드의 촌수 + 1
            }
        }
    }
}

int main() {
    //입력
    cin >> n >> x >> y >> m;

    for (int i = 0; i < m; i++){
        int p1, p2;
        cin >> p1 >> p2;

        fam[p1][p2] = fam[p2][p1]= 1; 
    }


    //연산
    bfs(x);  


    //출력
    if(!visited[y]){  // 친척 관계가 없는 경우
        cout << -1;
    } 
    else {
        cout << number[y];  // y까지의 촌수 출력
    }

    return 0;
}
