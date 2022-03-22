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


bool skip(char c) {
  return !(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'));
}


char get_lower(char c) {
  if ('A' < c && c < 'Z') {
    return c - 'A' + 'a';
  }
  return c;
}


int main() {
  string s;
  getline(cin, s);
  while (s != "DONE") {
    //cout << "s: " << s << endl;
    size_t i1 = 0;
    size_t i2 = s.size() - 1;
    bool error = false;
    while (i1 < s.size() / 2 + 1 && i2 >= s.size() / 2 -1) {
      while (skip(s[i1])) {
        //cout << "s[i1] " << s[i1] << endl;
        i1++;
      }
      while (skip(s[i2])) {
        //cout << "s[i2] " << s[i2] << endl;
        i2--;
      }
      char lower1 = get_lower(s[i1]);
      char lower2 = get_lower(s[i2]);
      if (lower1 != lower2) {
        cout << "Uh oh.." << endl;
        error = true;
        break;
      }
      i1++;
      i2--;
    }
    if (!error) {
      cout << "You won't be eaten!" << endl;
    }
    getline(cin, s);
  }
  return 0;
}
