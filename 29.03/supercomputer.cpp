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


void modify(int* t, int p, int value, int n) { // set value at position p
    for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}


int query(int* t, int l, int r, int n) { // sum on interval [l, r)
    int res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}


void flip(int* t, int i, int n) {
    int val;
    val = query(t, i, i+1, n);
    if (val == 0) {
        modify(t, i, 1, n);
        return;
    }
    else if (val == 1) {
        modify(t, i, 0, n);
        return;
    }
    else {
        cout << "ERROR2" << endl;
        exit(1);
    }
}


int count(int* t, int l, int r, int n) {
    return query(t, l, r, n);
}


void print(int* t, int n) {
    for (int i = n; i <= 2*n-1; i++) {
        cout << t[i];
    }
    cout << endl;
}


int main() {
    int n; // num of bits
    int k; // num of queries
    cin >> n;
    cin >> k;

    const int LIMIT = 1e6; // limit for array size
    int t[2 * LIMIT] = {0};
    // build
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
    // run
    for (int i = 0; i < k; i++) {
        // cout << "current: "; print(t, n);
        string cmd;
        cin >> cmd;
        if (cmd == "F") { // flip
            int i;
            cin >> i;
            flip(t, i-1, n);
            // cout << "after flip of " << i << ": "; print(t, n);
        }
        else if (cmd == "C") { // count
            int l, r;
            cin >> l >> r;
            // cout << "count: " << count(t, l-1, r, n) << endl;
            cout << count(t, l-1, r, n) << endl;
        }
        else {
            cout << "ERROR1" << endl;
            exit(1);
        }
    }
    return 0;
}
