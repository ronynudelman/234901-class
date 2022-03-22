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
  vector<string> v;
  vector<string> v_orig;
  vector<string> v_out;
  string s;
  while (cin >> s && s != "#") {
    v_orig.push_back(s);
    for (int i = 0; i < s.size(); i++) {
      s[i] = tolower(s[i]);
    }
    sort(s.begin(), s.end());
    v.push_back(s);
  }
  for (size_t i = 0; i < v.size(); i++) {
    int c = count(v.begin(), v.end(), v[i]);
    if (c == 1) {
      v_out.push_back(v_orig[i]);
    }
  }
  sort(v_out.begin(), v_out.end());
  for (size_t i = 0; i < v_out.size(); i++) {
    cout << v_out[i] << endl;
  }
  return 0;
}
