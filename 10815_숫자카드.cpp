#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 이분 탐색
bool binarySearch(int n, vector<int>& card) {
    int left = 0, right = card.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (card[mid] == n) {
            return true;
        }
        else if (card[mid] < n) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false; //찾지 못한 경우
}

int main() {
    int n, m;

    // 입력
    cin >> n;
    vector<int> card(n);
    for (int i = 0; i < n; i++) {
        cin >> card[i];
    }

    // 연산을 위해 정렬
    sort(card.begin(), card.end());

    //입력
    cin >> m;
    vector<int> num(m);
    for (int i = 0; i < m; i++) {
        cin >> num[i];
    }

    // 연산 및 출력
    for (int i = 0; i < m; i++) {
        if (binarySearch(num[i], card)) {
            cout << "1 ";
        }
        else {
            cout << "0 ";
        }
    }
    cout << "\n";

    return 0;
}
