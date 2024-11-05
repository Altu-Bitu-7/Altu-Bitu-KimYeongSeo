#include <iostream>
#include <set>

using namespace std; 

set<string> makeSet(int n) {
    set<string> set;
    string input;

    for(int i = 0; i < n; i++) {
        cin >> input;
        set.insert(input);
    }

    return set;
}

int checkDuplication(set<string> s, int m){
  int checkNum = 0;
  string input;
  for(int i = 0; i < m; i++){
    cin >> input;
    if(s.find(input) != s.end()){
      checkNum++;
    }
  }
  return checkNum;
}


int main(){
  int n, m;
  cin >> n >> m;
  
  set<string> set = makeSet(n);
  
  
  int checkNum=0;
  checkNum = checkDuplication(set, m);
  cout << checkNum;

  return 0;
}


//참고 사이트 : https://wannabe-gosu.tistory.com/8