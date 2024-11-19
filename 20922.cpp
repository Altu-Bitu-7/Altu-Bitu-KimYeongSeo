#include <iostream>
#include <vector>

using namespace std;

int main(){
  int n, k;
  int left=0, right=0;
  int maxi=0;
  //입력
  cin >> n >> k;

  vector<int> arr(n);
  vector<int> cnt(100001, 0);
  
  for(int i = 0; i<n; i++){
    cin >> arr[i];
  }
  //연산
  while (right < n) {
        // 현재 right 위치의 숫자 카운트 증가
        cnt[arr[right]]++;

        // 중복이 k보다 커지면
        while (cnt[arr[right]] > k) {
            // left 포인터를 오른쪽으로 이동시키며 카운트를 감소
            cnt[arr[left]]--;
            left++;
        }

        // 현재 윈도우 내에서의 최댓값 갱신
        maxi = max(maxi, right - left + 1);

        // right 포인터를 오른쪽으로 이동
        right++;
    }
  //출력
  cout << maxi;

  return 0;
}