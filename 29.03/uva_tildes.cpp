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

struct unionfind
{
    vector<int> rank;
    vector<int> parent;
    vector<int> sizes; // new
    unionfind(int size)
    {
        sizes = vector<int>(size,1); // new
        rank=vector<int>(size,0);
        parent=vector<int>(size);
        for(int i=0;i<size;i++)
            parent[i]=i;
    }

    int get_size(int x) { // new
        return sizes[find(x)];
    }

    int find(int x){
        int tmp=x;
        while(x!=parent[x]) x=parent[x];
        while(tmp!=x)//for log*, not needed most of the time
        {
            int remember=parent[tmp];
            parent[tmp]=x;
            tmp=remember;
        }
        return x;
    }
    void Union(int p, int q){
        p = find(p);
        q = find(q);
        int p_size = get_size(p);
        int q_size = get_size(q);
        if(q==p)
        {
            //alredy in the same group
            return;
        }
        if(rank[p] < rank[q]) {
            parent[p] = q;
            sizes[q] += p_size;
        }
        else {
            parent[q] = p;
            sizes[p] += q_size;
        }
        if(rank[p] == rank[q]) {
            rank[p]++;
        }
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    struct unionfind uf(n);
    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "t") {
            int a, b;
            cin >> a >> b;
            uf.Union(a-1, b-1);
        }
        else if (cmd == "s") {
            int a;
            cin >> a;
            cout << uf.get_size(a-1) << endl;
        }
        else {
            cout << "ERROR" << endl;
            exit(1);
        }
    }
    return 0;
}
