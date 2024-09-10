#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000000

void eratosthenes(vector<bool>& primeVector) { //에라토스테네스의 체를 이용한 벡터 초기화 함수
    for(int i = 2; i * i <= MAX; i++){
        if (primeVector[i]) {  
            for(int j = i * 2; j <= MAX; j += i){
                primeVector[j] = false; //소수가 아니라면 false. 0, 1을 사용해서 판별하기도 하던데 bool 타입을 쓰는 게 메모리 절약에 도움이 된다.
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); //안 쓰면 시간 초과가 난다. -> c 표준 스트림과의 동기화를 비활성화하면 입출력 연산이 더 빠르게 작동하기 때문이다.

    vector<bool> primeVector(MAX + 1, true);  //0부터 max까지 총 max+1개 크기를 갖는 벡터 생성
    eratosthenes(primeVector); //벡터 초기화

    int input;
    while (1) {
        cin >> input;
        if (input == 0) { //0 입력시 종료
            break;
        }

        bool found = false;
        for (int i = 3; i <= input / 2; i += 2) {
            if (primeVector[i] && primeVector[input - i]) { 
                cout << input << " = " << i << " + " << input - i << "\n"; //"\n" 대신 endl을 쓰면 시간 초과가 뜬다. -> endl 사용시 매번 출력 버퍼를 강제로 플러시하기 때문에 시간이 더 소요된다.
                found = true;
                break;
            }
        }
    }
    return 0;
}
//참고 사이트 : https://khu98.tistory.com/227