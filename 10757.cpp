#include <iostream>
#include <string>

using namespace std;

int change_num(char str) {
  int num;
  num = str - '0';
  return num;
}

char change_char(int num){
  char ch;
  ch = num + '0';
  return ch;
}

string sum(string big, string small) {
    string total;
    bool flag = false;  
    int carry = 0;  

    for (int i = 0; i < small.length(); i++) {
      int int_a = change_num(big[big.length() - 1 - i]);
      int int_b = change_num(small[small.length() - 1 - i]);
      int sum = int_a + int_b + carry;
      carry = sum / 10; 
      total = change_char(sum % 10) + total; 
    }

    for (int i = big.length() - small.length() - 1; i >= 0; i--) {
        int sum = change_num(big[i]) + carry;
        carry = sum / 10;
        total = change_char(sum % 10) + total;
    }

    if (carry) {
        total = change_char(carry) + total;
    }

    return total;
}

int main() {
    string a, b;
    cin >> a >> b;
    if (a.length() > b.length()) {
        cout << sum(a, b);
    } 
    else {
        cout << sum(b, a);
    }
    return 0;
}
