#include <iostream>
#include <deque>
using namespace std;

int n, k, l;
int map[100][100];
pair<int, int> change[100];
deque<pair<int, int> > snake;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

// 게임판 초기화 함수
void init(int n_input, int k_input, int map_input[100][100]) {
    n = n_input;
    k = k_input;
    for (int i = 0; i < k; ++i) {
        int r, c;
        cin >> r >> c;
        map_input[r - 1][c - 1] = 2; // 사과가 있다는 뜻
    }
}

// 방향 바꾸는 함수
int changeDirection(int di, int direction) {
    int nd = di + direction;
    if (nd < 0) {
        return 3;
    } else if (nd > 3) {
        return 0;
    }
    return nd;
}

// 게임 시작 함수
int play(int n, int map[100][100], pair<int, int> change[100], int l) {
    snake.push_back(pair<int, int>(0, 0));  // 뱀 처음 위치
    int time = 0, li = 0, di = 2;

    while (true) {
        ++time;

        int r = snake.back().first;
        int c = snake.back().second;

        int nr = r + dy[di];
        int nc = c + dx[di];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n) {
            break;
        }
        if(map[nr][nc] == 1){
            break;
        }

        // 사과가 아닌 곳이라면 뱀 길이 줄이기
        if (map[nr][nc] != 2) {
            int fr = snake.front().first;
            int fc = snake.front().second;
            snake.pop_front();
            map[fr][fc] = 0;
        }

        // 뱀 머리 이동
        map[nr][nc] = 1;
        snake.push_back(pair<int, int>(nr, nc));

        // 방향 바꾸기
        if (li != l && time == change[li].first) {
            di = changeDirection(di, change[li].second);
            ++li;
        }
    }

    return time;
}

int main() {
    //입력
    cin >> n >> k;
    int map_input[100][100] = {0}; 
    init(n, k, map_input);

    cin >> l;
    for (int i = 0; i < l; ++i) {
        int x;
        char c;
        cin >> x >> c;
        change[i].first = x;
        if (c == 'L') {
            change[i].second = -1;
        } else {
            change[i].second = 1;
        }
    }
    //연산 및 출력
    cout << play(n, map_input, change, l);
}
