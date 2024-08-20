#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std; 

vector<string> makeVector(int num){ 
  vector<string> serial(num);
  for(int i = 0; i < num; i++){
    cin >> serial[i];
  }
  return serial;
}

int sumOfDigits(const string& str) {
    int sum = 0;
    for(char ch : str) {
        if(isdigit(ch)) { 
            sum += ch - '0'; 
        }
    }
    return sum;
}

bool compareSize(string& small, string& big){
  if(small.size() != big.size()){
    if(small.size() < big.size()) return true;
    else return false;
  }
  

  if(sumOfDigits(small) != sumOfDigits(big)){
    if(sumOfDigits(small) < sumOfDigits(big)) return true;
    else return false;
  }
  

  return small < big;
}


int main(){
  int num;
  cin >> num;
  
  vector<string> serial = makeVector(num);

  sort(serial.begin(),serial.end(), compareSize);

  for(const string& str : serial) {
        cout << str << endl;
    }

  return 0;
}

//참고 사이트 : https://blog.naver.com/ndb796/221227975229, https://velog.io/@mttw2820/C-algorithm-sort 
