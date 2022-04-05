#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;


int get_1(int num) {
    return num % 10;
}


int get_2(int num) {
    return (num % 100) / 10;
}


int get_3(int num) {
    return (num % 1000) / 100;
}


int get_4(int num) {
    return (num % 10000) / 1000;
}


int get_5(int num) {
    return (num % 100000) / 10000;
}


int get_6(int num) {
    return (num % 1000000) / 100000;
}


bool is_palindrom(int num) {
    if (get_1(num) != get_6(num)) return false;
    if (get_2(num) != get_5(num)) return false;
    if (get_3(num) != get_4(num)) return false;
    return true;
}


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        if (is_palindrom(num)) {
            cout << num << endl;
            continue;
        }
        for (int i = 1; i <= 999999; i++) {
            if (num - i >= 100000 && is_palindrom(num - i)) {
                cout << num - i << endl;
                break;
            }
            if (num + i <= 999999 && is_palindrom(num + i)) {
                cout << num + i << endl;
                break;
            }
        }
    }
    return 0;
}
