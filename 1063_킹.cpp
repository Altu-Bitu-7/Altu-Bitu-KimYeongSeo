#include <iostream>
#include <vector>

using namespace std;


bool checkMove(vector<char>& location, string str) { //이동 가능 여부 체크
    if (str == "R" && location[0] == 'H') return false;
    if (str == "L" && location[0] == 'A') return false;
    if (str == "B" && location[1] == '1') return false;
    if (str == "T" && location[1] == '8') return false;
    if (str == "RT" && (location[0] == 'H' || location[1] == '8')) return false;
    if (str == "LT" && (location[0] == 'A' || location[1] == '8')) return false;
    if (str == "RB" && (location[0] == 'H' || location[1] == '1')) return false;
    if (str == "LB" && (location[0] == 'A' || location[1] == '1')) return false;
    return true;
}


void moveFunction(vector<char>& location, string str) { //실제로 이동시키기
    if (str == "R") location[0]++;
    else if (str == "L") location[0]--;
    else if (str == "B") location[1]--;
    else if (str == "T") location[1]++;
    else if (str == "RT") { location[0]++; location[1]++; }
    else if (str == "LT") { location[0]--; location[1]++; }
    else if (str == "RB") { location[0]++; location[1]--; }
    else if (str == "LB") { location[0]--; location[1]--; }
}

int main() {
    string first_king, first_stone;
    int move;
    vector<char> location_king, location_stone;

    cin >> first_king >> first_stone >> move;

    location_king.push_back(first_king[0]); //처음 위치로 초기화
    location_king.push_back(first_king[1]);
    location_stone.push_back(first_stone[0]);
    location_stone.push_back(first_stone[1]);

    for (int i = 0; i < move; i++) {
        string input;
        cin >> input;

        
        if (checkMove(location_king, input)) { //이동 가능한지 확인 후 가능한 상태라면 이동시키기
            vector<char> next_king = location_king;
            moveFunction(next_king, input);

            
            if (next_king[0] == location_stone[0] && next_king[1] == location_stone[1]) {  //위치가 겹친다면 돌 밀기
                if (checkMove(location_stone, input)) {
                    moveFunction(location_stone, input);
                    location_king = next_king;
                }
            } 
            else {
                location_king = next_king;
            }
        }
    }

    // 결과 출력
    cout << location_king[0] << location_king[1] << '\n';
    cout << location_stone[0] << location_stone[1] << '\n';

    return 0;
}
