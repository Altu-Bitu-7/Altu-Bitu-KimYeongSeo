#include <iostream>
#include <vector>

using namespace std;

// 북, 동, 남, 서 방향 정의
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    int n, m;
    int r, c, d;
    int cnt=0;

    //입력
    cin >> n >> m;
    cin >> r >> c >> d;

    vector< vector<int> > arr(n, vector<int>(m)); //2차원 벡터 초기화  vector<vector<int>> 이렇게 붙여서 썼더니 에러가 났다.

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    //연산
    while (true) {

        bool empty = false;

        if (arr[r][c] == 0) {
            arr[r][c] = 2;  // 청소 완료
            cnt++;
        }

        

        for (int i = 0; i < 4; i++) {
            // 반시계 방향으로 90도 회전
            d = (d + 3) % 4;
            int xa = r + dx[d];
            int ya = c + dy[d];

            // 청소되지 않은 빈 공간이 있다면 이동
            if (arr[xa][ya] == 0) {
                r = xa;
                c = ya;
                empty = true;
                break;
            }
        }

        // 청소할 곳이 없으면
        if (!empty) {
            // 뒤로 가기
            int back = (d + 2) % 4;
            int bx = r + dx[back];
            int by = c + dy[back];

            // 종료 조건
            if (arr[bx][by] == 1) {
                break;
            } else {
                r = bx;
                c = by;
            }
        }
    }
    //출력
    cout << cnt;
    return 0;
}


