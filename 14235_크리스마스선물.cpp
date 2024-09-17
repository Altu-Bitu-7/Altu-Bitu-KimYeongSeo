#include <iostream>
#include <queue>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL); 
  cout.tie(NULL);

  int n, stop, value;
  priority_queue<int, vector<int>> q; //우선순위 큐 선언 (가치가 큰 선물부터 출력해야 하므로)
  cin >> n;
  while(n--){
    cin >> stop;
    
    if(stop==0){ //input 값이 0이면 -1 또는 선물 가치 출력
        if(!q.empty()){ //선물이 있을 때
          cout << q.top() << "\n";
          q.pop();
        }
        else { //비어있을 때
          cout << "-1\n";
        }
      }
    while(stop--){ //거점지라면 선물 개수만큼 충전
      cin >> value;
      q.push(value);
      
    }
    
  }



  return 0;
}

//참고 사이트 : https://breakcoding.tistory.com/123