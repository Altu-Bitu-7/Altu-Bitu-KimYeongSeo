#include <iostream>
using namespace std;

const int SIZE = 19;
int stage[SIZE][SIZE] = {0, };  // board -> stage
int win_col = -1, win_row = -1, black_or_white = 0;  // winnerColor -> black_or_white

int dx[] = {1, 0, 1, -1};  // 방향 변화에 따른 행렬의 변화
int dy[] = {0, 1,  1, 1};

// 바둑판 내에 있는지 확인
bool correct(int x, int y){
    return x >= 0 && x < 19 && y >= 0 && y < 19;  //바로 bool 값이 나올 수 있도록
}

// 돌의 개수 확인하는 함수
bool five(int x, int y, int color){
    for (int i = 0; i <4; i++) {
        int count = 1;
        int nx = x + dx[i];
        int ny = y + dy[i];

        int prev_col;
        int prev_row;
        
        while (correct(nx, ny) && stage[nx][ny] == color){  // board -> stage
            count++;
            nx += dx[i];
            ny += dy[i];
        }

        // 6목은 승리 조건이 아님 -> 양방향을 모두 봐줘야 함
        nx = x - dx[i];
        ny = y - dy[i];
        while (correct(nx, ny) && stage[nx][ny] == color){  // board -> stage
            count++;
            nx -= dx[i];
            ny -= dy[i];
        }

        if (count == 5) {  // 딱 5개의 돌만 연속되어 있어야 승리한다.
            // 이전에 돌이 놓인 좌표가 있으면 6목이므로 제외
            prev_col = x - dx[i];
            prev_row = y - dy[i];
            if (correct(prev_col, prev_row) && stage[prev_col][prev_row] == color){  // board -> stage
                continue;
            }

            // 출력해야 하는 가장 왼쪽에 있는 돌의 좌표
            win_col = x;
            win_row = y;
            black_or_white = color;  // winnerColor -> black_or_white
            return true;
        }
    }
    return false;
}

int main() {
    // 입력 
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            cin >> stage[i][j];  // board -> stage, 초기화
        }
    }

    // 보드 전체를 돌며 승리자 찾기
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++) {
            if (stage[i][j] != 0) {  // board -> stage
                if (five(i, j, stage[i][j])){  // board -> stage
                    break; 
                }
            }
        }
    }

    // 결과 출력
    if (black_or_white != 0){  // winnerColor -> black_or_white
        cout << black_or_white << "\n" << win_col + 1 << " " << win_row + 1 << endl;
    } else {
        cout << 0 << '\n';  // 승리자가 없는 경우
    }

    return 0;
}
