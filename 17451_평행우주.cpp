#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  long long speed;  // speed는 큰 값을 처리해야 하므로 long long으로 설정 -> int로 했더니 에러가 났다.
  vector<int> distance;

  // 입력
  cin >> n;
  while (n--) {
    int input;
    cin >> input;
    distance.push_back(input);
  }

  // 연산
  speed = distance.back();  // 마지막 우주의 목표 속도로 초기화

  for (int i = distance.size() - 1; i > 0; i--) {
    // 현재 속도가 다음 탈출 속도의 배수가 아니라면
    if (speed % distance[i-1] != 0) {
      // 속도를 탈출 속도의 배수로 설정
      speed = (speed / distance[i-1] + 1) * distance[i-1];
    }
  }

  // 출력
  cout << speed << endl;

  return 0;
}
