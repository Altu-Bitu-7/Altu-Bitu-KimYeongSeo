#include<iostream>
#include<set>
#include<vector>

using namespace std;

int n, m;
int nums[8], selected[8];
vector<vector<int>> results; //뽑은 벡터를 저장할 벡터


void backtracking(int cnt){
  vector<int> result;

  if (cnt == m){ //m개의 수를 모두 뽑았다면 벡터에 저장해두기 -> 출력을 main 함수에서 하기 위해
    for (int i = 0; i < m; i++){ 
      result.push_back(selected[i]);
    }
    results.push_back(result);
    return;
  }


  for (int i = 0; i < n; i++){ //숫자 뽑기
    selected[cnt] = nums[i];

    backtracking(cnt + 1);
  }
}

int main() {
  set<int> only_one;

  // 입력
  cin >> n >> m;
  //입력 및 초기화
  for (int i = 0; i < n; i++){
    int num;
    cin >> num; //모든 숫자를 배열에 넣기
    only_one.insert(num);
  }


  n = only_one.size();
  int index = 0;
  for (int num : only_one){ //중복된 숫자는 제거하고 배열에 넣기
    nums[index++] = num;
  }

  //연산

  backtracking(0);


  //출력
  for (int i = 0; i < results.size(); i++){
    for (int j = 0; j < results[i].size(); j++){
      cout << results[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
