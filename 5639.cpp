#include <iostream>
using namespace std;

int tree[10001];

void postorder(int start, int end) {
    if (start > end) {
        return;
    }

    int divider = end + 1;
    // start + 1부터 end까지 돌면서 tree[start]보다 큰 값이 있는 위치를 찾는다.
    for (int i = start + 1; i <= end; ++i) {
        if (tree[i] > tree[start]) {
            divider = i;
            break;
        }
    }

    postorder(start + 1, divider - 1);  // 왼쪽 서브트리
    postorder(divider, end);             // 오른쪽 서브트리
    cout << tree[start] << '\n';         // 루트
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int i = 0;
    for (; cin >> tree[i]; ++i);  // 입력을 받을 수 있을 때까지 계속 읽기. 이 부분 구현이 어려워서 검색하여 찾아보았다.

    postorder(0, i - 1); 

    return 0;
}
