#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가능한지 확인
bool poss(int h, vector<int>& x, int len) {
    int cur = 0; 

    for (int i = 0; i < x.size(); i++) {
        if (cur < x[i] - h) {
            return false;
        }
        cur = x[i] + h;
    }

    return cur >= len;
}


int binarySearch(int left, int right, vector<int>& x, int n) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (poss(mid, x, n)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n, m;

    // 입력
    cin >> n >> m;
    vector<int> x(m);
    for (int i = 0; i < m; i++) {
        cin >> x[i];
    }

    // 정렬 (가로등 위치 정렬)
    sort(x.begin(), x.end());

    // 연산 & 출력
    cout << binarySearch(1, n, x, n) << "\n";

    return 0;
}
