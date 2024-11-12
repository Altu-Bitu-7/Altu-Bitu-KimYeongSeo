#include <iostream>
#include <vector>


using namespace std;

int n, a[12],maxi, mini;
vector<int> cal;
vector<int> op;
bool visit[12], first = true;


void backtracking(int i){ //백트래킹 함수
  if (i == n-1){
    int total = a[0]; //연산 시작
    for (int j = 0; j < n-1; j++){
      if (cal[j] == 0){ // +일 때
        total += a[j+1];
      } 
      else if (cal[j] == 1){ // -일 때
        total -= a[j+1];
      } 
      else if (cal[j] == 2){ // x일 때
        total *= a[j+1];
      } 
      else if (cal[j] == 3){ // 나누기일 때
        total /= a[j+1];
      }
    }
      //첫번째 연산일 때 그 값을 min, max값으로 설정
      if (first){
        maxi = mini = total;
        first = false;
      } 
      else{ //그 다음부터는 값을 비교하여 최대, 최소 찾기
        if (total < mini) mini = total;
        if (total > maxi) maxi = total;
      }
      return;
  }

  for (int j = 0; j < op.size(); j++){ //백트래킹
      if (visit[j]) { 
        continue; }
        
      visit[j] = true;
      cal.push_back(op[j]);
      backtracking(i+1);
      cal.pop_back();

      visit[j] = false; //빠져나올 때 돌려주기
  }
}

int main(){
  //입력
  cin >> n;

  for (int i = 0; i < n; i++){
    cin >> a[i];
  }

  for (int i = 0; i < 4; i++){
    int temp;
    cin >> temp;

    for (int j = 0; j < temp; j++){
      op.push_back(i);
    }
  }
  //연산
  backtracking(0);


  //출력
  cout << maxi << "\n" << mini << "\n";
  return 0;
}
