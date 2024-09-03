#include <iostream>

using namespace std;

int getGCD(int& a, int& b) { //최대공약수 구하는 함수
    for (int i = min(a, b); i > 0; i--) {
        if (a % i == 0 && b % i == 0) {
            return i;
        }
    }
    return 1;
}

void getResult(int& a, int& b, int& c, int& d){ //분수 합 결과를 출력하는 함수
  int nume = a*d + b*c;
  int deno = b*d;
  int gcd = getGCD(nume, deno); //분모, 분자의 최대공약수 구하기
  nume /= gcd; //기약 분수 만들기
  deno /= gcd; 
  cout << nume << " " << deno << endl;
}



int main(){
  int nume1, deno1, nume2, deno2;
  cin >> nume1 >> deno1 >> nume2 >> deno2; //변수 초기화
  getResult(nume1, deno1, nume2, deno2); //결과 출력하기

  return 0;
}

