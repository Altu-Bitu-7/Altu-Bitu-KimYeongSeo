#include <iostream>
#include <string>
#include <vector>

using namespace std;

void spin(vector<vector<char>>& wheel, int num, int direction) {
    if (direction == -1) {
        // 반시계 방향 
        char tmp = wheel[num][0];
        for (int i = 0; i < 7; i++) {
            wheel[num][i] = wheel[num][i + 1];
        }
        wheel[num][7] = tmp; // 회전해야 하므로 마지막 위치에 첫 번째 요소 이동
    } else {
        // 시계 방향 
        char tmp = wheel[num][7];
        for (int i = 7; i > 0; i--) {
            wheel[num][i] = wheel[num][i - 1];
        }
        wheel[num][0] = tmp; // (회전)첫 번째 위치에 마지막 요소 이동
    }
}

void solve(vector<vector<char>>& wheel, int num, int direction, int dir) {
    // 첫번째 톱니바퀴이고 반시계 방향 회전일 때
    if (num == 1 && dir == -1) {
        spin(wheel, num, direction);
        return;
    }
    // 마지막 톱니바퀴이고, 시계 방향 회전일 때 
    if (num == wheel.size() - 1 && dir == 1) {
        spin(wheel, num, direction);
        return;
    }

    // 반시계 방향일 때
    if (dir == -1) {
        char prev = wheel[num][6];   // 현재 톱니바퀴의 6시 방향 극
        char check = wheel[num - 1][2]; // 왼쪽 톱니바퀴의 2시 방향 극
        spin(wheel, num, direction);
        if (prev != check) {
            solve(wheel, num - 1, -direction, dir);
        }
    } 
    // 시계 방향일 때
    else {
        char prev = wheel[num][2];   // 현재 톱니바퀴의 2시 방향 극
        char check = wheel[num + 1][6]; // 오른쪽 톱니바퀴의 6시 방향 극
        spin(wheel, num, direction);
        if (prev != check) {
            solve(wheel, num + 1, -direction, dir);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력
    int t, k;
    cin >> t;
    vector<vector<char>> wheel(t + 1, vector<char>(8)); // 입력값에 따른 벡터 크기 초기화

    string str;
    for (int i = 1; i <= t; i++) {
        cin >> str;
        for (int j = 0; j < 8; j++) {
            wheel[i][j] = str[j];
        }
    }
    
    // 연산
    cin >> k;
    int num, direction;
    for (int i = 0; i < k; i++) {
        cin >> num >> direction;
        solve(wheel, num, direction, -1);
        spin(wheel, num, -direction);
        solve(wheel, num, direction, 1);
    }
    
    // 출력
    int cnt = 0;
    for (int i = 1; i <= t; i++) {
        if (wheel[i][0] == '1') cnt++;
    }
    
    cout << cnt;

    return 0;
}
