#include <iostream>

using namespace std;

void makeBit(int& bit, string str, int n) { //숫자를 input으로 받는 명령어들
    if (str == "add") {
        bit |= (1 << (n - 1));  
    } else if (str == "remove") {
        bit &= ~(1 << (n - 1));  
    } else if (str == "check") {
        if (bit & (1 << (n - 1))) 
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    } else if (str == "toggle") {
        bit ^= (1 << (n - 1));  
    }
}

void onlyorder(int& bit, string str) { //숫자를 입력받지 않는 명령어들
    if (str == "all") {
        bit = (1 << 20) - 1;  
    } else if (str == "empty") {
        bit = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL); //시간 초과 에러 방지
    
    int num;
    cin >> num;

    int bit = 0;  
    while (num-- > 0) {
        string order;
        int element;
        
        cin >> order;
        
        if (order == "all" || order == "empty") { //명령어 종류에 따라서 함수를 다르게 설정
            onlyorder(bit, order);
        } else {
            cin >> element;
            makeBit(bit, order, element);
        }
    }

    return 0;
}
