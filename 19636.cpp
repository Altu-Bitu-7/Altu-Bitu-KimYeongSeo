/*
다이어트 전 
체중 = W0
일일 에너지 섭취량 = I0
일일 기초 대사량 = I0
일일 활동 대사량 = A0 = 0

다이어트 시작
일일 에너지 섭취량 = I
일일 활동 대사량 = A
일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
체중 += 일일 에너지 섭취량 I - (일일 기초 대사량 * + 일일 활동 대사량 A)
기초 대사량 변화 역치 = T
if(|일일 에너지 섭취량 I - (일일 기초 대사량 * + 일일 활동 대사량 A))| > T){
  일일 기초 대사량 * += [(일일 에너지 섭취량 I - (일일 기초 대사량 * + 일일 활동 대사량 A)) / 2]
}
체중 <= 0, 일일 기초대사량 <= 0 이면 사망

입력 
W0, I0, T
다이어트 기간 D, I, A

출력
일일 기초 대사량의 변화를 고려하지 않았을 때 예상 체중, 일일 기초 대사량
고려했을 때 체중, 일일 기초 대사량
요요 현상 여부

참고
일일 기초 대살량 변화 X 일 때 예상 체중 = W0 + D*(I - I0 - A)
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>

using namespace std;



int main(){
  int w0, i0, t, d, i, a;
  int weightWithNoChange, amountWithNoChange;
  int afterWeight, afterAmount;
  string yoyo = "NO";
  bool warning=false;

  cin >> w0 >> i0 >> t;
  cin >> d >> i >> a;
  weightWithNoChange = w0 + d*(i - i0 - a);
  amountWithNoChange = i0;
  afterWeight = w0;
  afterAmount = i0;

  if(weightWithNoChange<=0){
    cout << "Danger Diet" << endl;
  } 
  else cout << weightWithNoChange << " " << i0 << endl;

  for(int j = 0; j < d; j++){
    afterWeight += i - (afterAmount + a);
    int difference = i - (afterAmount + a);

    if(abs(difference)>t){
      afterAmount += std::floor(difference/2.0);
    }

    if(afterAmount<=0){
    warning = true;
    break;
  }

    
  }
  if(afterWeight<=0||warning){
    cout << "Danger Diet" << endl;
  }
  else{
    if(i0 > afterAmount) yoyo = "YOYO";
    cout << afterWeight << " " << afterAmount << " "<< yoyo << endl;
  }

/*
체중 += 일일 에너지 섭취량 I - (일일 기초 대사량 * + 일일 활동 대사량 A)
if(|일일 에너지 섭취량 I - (일일 기초 대사량 * + 일일 활동 대사량 A))| > T)
  일일 기초 대사량 * += [일일 에너지 섭취량 I - (일일 기초 대사량 * + 일일 활동 대사량 A)) / 2]
  */


  return 0;
  
}