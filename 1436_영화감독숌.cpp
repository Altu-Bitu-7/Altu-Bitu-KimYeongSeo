#include <iostream>

using namespace std;

const int MAX = 2147483647;

int solution(int number){ //종말의 수 찾는 함수
  int answer = 0;
  for(int i = 666; i < MAX; i++){
    int check = i;
    while(check>0){
      if(check%10 == 6){ //일의 자리부터 6이 연속으로 나오는지 확인하기
        if((check/10)%10 == 6 && (check/10) > 0){
          if(((check/10)/10)%10 == 6 && ((check/10)/10) > 0){
            answer++;
            break;
          }
        }
      }
      check /= 10;
    }
    if(answer == number) return i;
  }
  return 0;
  }
  


int main(){
  int num;
  cin >> num;
  cout << solution(num) ;
  return 0;
}