#include <iostream>
#include <vector>

using namespace std;

int cnt = 0; 


vector<int> makeArr(const string& word) { //알파벳 빈도수에 따른 배열을 만드는 함수
    vector<int> arr(26, 0);  
    for (char c : word) { //char c : word = word에 있는 char c 하나씩 체크 
        if (c >= 'A' && c <= 'Z') {
            arr[c - 'A']++; 
        }
    }
    return arr;
}


bool solution(const vector<int>& main, const vector<int>& check) {
    bool flag;
    int change1 = 0, change2 = 0;
    
    for (int i = 0; i < 26; i++) {
        if (main[i] > check[i]) {
           change1 += main[i] - check[i];  // main에 더 많은 알파벳
        } else if (main[i] < check[i]) {
            change2 += check[i] - main[i];  // check에 더 많은 알파벳
        }
    }

    // 조건: change1와 change2가 모두 1 이하면 비슷한 단어로 간주
    if(change1 <= 1 && change2 <= 1){
        flag = true;
    }
    else flag = false;
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
    int n;
    string main_word;

    cin >> n >> main_word;
    n -= 1;  // 기준 단어는 제외

    vector<int> main_arr = makeArr(main_word);

    while (n--) {
        string checked_word;
        cin >> checked_word;

        vector<int> checked_arr = makeArr(checked_word);

        
        if (solution(main_arr, checked_arr)) { // 비슷한 단어인지 확인
            cnt++;  // 비슷한 단어라면 cnt 개수 증가
        }
    }
    cout << cnt << endl;
    return 0;
}
