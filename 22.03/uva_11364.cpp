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
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    vector<int> v;
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
      int next;
      cin >> next;
      v.push_back(next);
    }
    sort(v.begin(), v.end());
    cout << ((v[v.size()-1]-v[0]) * 2) << endl;
  }
  return 0;
}
