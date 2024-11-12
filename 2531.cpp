#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // 입력
    int n, d, k, c;
    int cnt;
    int maxi = 0;
    cin >> n >> d >> k >> c;

    vector<int> chobab(n);
    vector<int> eat(d + 1, 0); 

    for(int i = 0; i < n; i++) {
        cin >> chobab[i];
    }

    cnt = 0;
    //연산
    // 쿠폰 초밥을 처음부터 먹었다고 가정하고 포함시킴
    eat[c] = 1; 
    cnt = 1;    

    // 슬라이딩 윈도우 준비
    for (int i = 0; i < k; i++) {
        if (eat[chobab[i]] == 0) {
            cnt++;
        } 
        eat[chobab[i]]++;
    }

    // 최대 개수 설정
    maxi = cnt;

    // 윈도우 움직이기(첫 번째 원소는 빼고, 마지막 원소의 오른쪽 원소 추가)
    for (int i = 1; i < n; i++) {
        int removeSushi = chobab[i - 1];
        eat[removeSushi]-=1;
        if (eat[removeSushi] == 0) {
          cnt--;
          }

        int addSushi = chobab[(i + k - 1) % n];
        if (eat[addSushi] == 0) cnt++; 
        eat[addSushi]+= 1;

        maxi = max(maxi, cnt);
    }

    //출력
    cout << maxi;

    return 0;
}
