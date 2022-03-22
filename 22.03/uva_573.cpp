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


int main() {
  while (true) {
    int H, U, D, F;
    cin >> H >> U >> D >> F;
    if (H == 0) {
      break;
    }
    double fatigue = double(U * F) / 100;
    int day = 0;
    double current_h = 0;
    while (true) {
      current_h += max((U - fatigue * day), 0.0);
      day++;
      if (current_h > H) {
        cout << "success on day " << day << endl;
        break;
      }
      current_h -= D;
      if (current_h < 0) {
        cout << "failure on day " << day << endl;
        break;
      }
    }
  }
  return 0;
}
