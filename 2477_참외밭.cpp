#include <iostream>
#include <vector>
#include <utility> 

using namespace std;

int maxcol = 0, maxrow = 0;
int remv1 = 0, remv2 = 0;
bool dupl[5] = {false};
int idx_col, idx_row;
vector<pair<int, int>> vec(6);



int cal(){
  remv1 = vec[(idx_col+3)%6].second; //가장 긴 변의 인덱스에서 3칸 건너가면 작은 직사각형의 가로, 세로 길이가 된다
  remv2 = vec[(idx_row+3)%6].second;
  return (maxcol * maxrow - remv1 * remv2); //큰 직사각형 넓이 - 작은 직사각형 넓이
}

int main(){
  // 입력
  int k;
  cin >> k; 


  //입력 및 초기화
  for (int i = 0; i < 6; i++) {
    cin >> vec[i].first >> vec[i].second; 


    //가장 긴 변 찾기
    if (vec[i].first == 1 || vec[i].first == 2) {  //가로 길이
      if (maxcol < vec[i].second) { 
        maxcol = vec[i].second;
        idx_col = i;
        
      }
      
  } 
    else if (vec[i].first == 3 || vec[i].first == 4) {  //세로 길이
      if (maxrow < vec[i].second) {
        maxrow = vec[i].second;
        idx_row = i;
      }
    }
  }

  //연산 및 출력
  cout << k * cal();

  return 0;
}
