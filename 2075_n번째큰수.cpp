#include <iostream>
#include <queue>

using namespace std;

int greater_Queue(int num) {
    priority_queue<int, vector<int>, greater<int>> gr_queue;  // 최소 힙 사용


    for (int i = 0; i < num * num; i++) { //n의 제곱만큼 숫자 입력 받기
        int number;
        cin >> number;

        gr_queue.push(number); //큐에 push

        if (gr_queue.size() > num) { //n제곱만큼의 수를 담기에는 메모리 초과 에러가 뜬다. -> 우리는 n번째 수를 찾아야하므로 딱 n개만 넣어주기
            gr_queue.pop(); //가장 작은 수가 pop 된다.
        }
    }


    return gr_queue.top(); //오름차순으로 정렬한 수 중에서 가장 작은 수는 전체에서 n번째로 큰 수이다. 그리고 그 수는 제일 앞에 존재함!
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    cin >> n;

    cout << greater_Queue(n);

    return 0;
}
