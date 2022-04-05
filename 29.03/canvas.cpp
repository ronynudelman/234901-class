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
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<ll> v;
        while (N--) {
            ll next;
            cin >> next;
            v.push_back(next);
        }
        priority_queue<ll, vector<ll>, greater<ll>> q = {v.begin(), v.end()};
        ll min_sum = 0;
        while (q.size() > 1) {
            ll a = q.top();
            q.pop();
            ll b = q.top();
            q.pop();
            min_sum += (a + b);
            q.push(a + b);
        }
        cout << min_sum << endl;
    }
    return 0;
}
