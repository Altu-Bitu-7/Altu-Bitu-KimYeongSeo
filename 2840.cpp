#include <iostream>
#include <vector>
#include <set>

using namespace std;


bool makeVector(vector<char>& v, set<char>& check_dup, int& seq, int num, char ch, int n) {
  seq = (seq + num) % n; //알파벳이 바뀌는 횟수를 배열의 인덱스 번호로 바꿈

  if (v[seq] == '?') { 
    if (check_dup.find(ch) != check_dup.end()) { //알파벳이 중복되었는지 확인한다
      return false;
    }
    v[seq] = ch; //'?' 빈칸이고, 중복되지 않았으면 알파벳 삽입
    check_dup.insert(ch); //set에도 삽입
  }

  if (v[seq] != '?' && v[seq] != ch) { //다른 알파벳이 들어가 있다면 false
  return false;
}

  return true;
}

int main() {
  int n, k, seq = 0;
  set<char> check_dup;
  bool flag = true;

  vector<char> v(n, '?');   //'?' 빈칸으로 모두 초기화

  cin >> n >> k;

  for (int i = 0; i < k; i++) {
    int num;
    char ch;
    cin >> num >> ch;

    if (!makeVector(v, check_dup, seq, num, ch, n)) { //행운의 바퀴가 존재하지 않는 경우 flag = false 로 바꾼다
      flag = false;
      break;
    }
  }

  if (flag) { //행운의 바퀴가 존재하다면 마지막 화살표가 가르키는 칸부터 알파벳을 출력한다
    for (int i = 0; i < n; i++) {
      cout << v[(seq + n - i) % n];
    }
  } else { //행운의 바퀴가 존재하지 않음
    cout << '!' << endl;
  }

  return 0;
}
