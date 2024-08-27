#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> func(int totalNum, int killNum){
  vector<int> numOfList;
  queue<int> originQueue;

  for(int i = 0; i < totalNum; i++){
    originQueue.push(i+1);
  }

  while(originQueue.size()>0){
    for(int i = 0; i < killNum-1; i++){
      originQueue.push(originQueue.front());
      originQueue.pop();
    }
    numOfList.push_back(originQueue.front());
    originQueue.pop();
  }

  return numOfList;


}

int main(){
  int n, k;
  cin >> n >> k;
  vector<int> arr = func(n, k);
  cout << "<";
  for(int i = 0; i < arr.size(); i++){
    cout << arr.at(i);
    if (i!=arr.size()-1){
      cout << ", ";
    }
  }
  cout << ">" << endl;

  return 0;
}

//참고 사이트 : https://velog.io/@dakyommii/c-함수에서-vector-반환 