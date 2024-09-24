#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 알파벳 개수 세기
void count(const string &s, vector<int> &apb){
  for (char i : s){
    apb[i]++;
  }
}

// 팰린드롬의 앞부분 구성 및 홀수 문자가 있는지 확인
void check(const vector<int> &apb, vector<char> &half, vector<char> &odd){
  for (char i = 'A'; i <= 'Z'; i++){
    if (apb[i] % 2){
      odd.push_back(i);  // 홀수 개수 문자가 있을 경우 저장
    }
    for (int j = 0; j < apb[i] / 2; j++){
      half.push_back(i); // 짝수 문자 절반만 저장
    }
  }
}

int main(){
  string s;
  cin >> s; 

  vector<int> apb(97, 0);
  vector<char> odd;
  vector<char> half;

  count(s, apb); // 알파벳 개수 세기
  check(apb, half, odd); // 팰린드롬의 앞부분과 홀수 문자 체크

  //출력
  if (odd.size() > 1){
    cout << "I'm Sorry Hansoo";
  }
  else{
    //앞부분 출력
    for (char c : half) {
      cout << c;
    }
    // 홀수 문자(가운데) 출력
    if (!odd.empty()){
      cout << odd[0];
    }
    // half 벡터를 뒤집어서 뒷부분 출력
    reverse(half.begin(), half.end());
    for (char c : half){
      cout << c;
    }
  }

    return 0;
}

