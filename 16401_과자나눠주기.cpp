#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 아이들 인원 수 계산
int children(int len, vector<int>& stick) {
    int count = 0;
    for (int i = 0; i < stick.size(); i++) {
        count += stick[i] / len;
    }
    return count;
}


int binarySearch(int left, int right, int target, vector<int>& stick) {
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        int distributed = children(mid, stick);

        if (distributed >= target) { 
            result = mid;
            left = mid + 1;
        } else { 
            right = mid - 1;
        }
    }
    
    return result; 
}

int main() {
    int m, n;

    // 입력
    cin >> m >> n;
    vector<int> stick(n);
    for (int i = 0; i < n; i++) {
        cin >> stick[i];
    }

    // 과자 길이 정렬
    sort(stick.begin(), stick.end());

    // 연산 및 출력
    cout << binarySearch(1, stick[n - 1], m, stick) << "\n";

    return 0;
}
