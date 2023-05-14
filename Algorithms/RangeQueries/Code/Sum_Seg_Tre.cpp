// Rbrgs.cpp
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

class SegmentTree
{
private:
    vi tree;
    int n;
    int build(int l, int r, vi &arr, int p)
    {
        if (l == r)
        {
            tree[p] = arr[r - 1];
            return arr[r - 1];
        }
        int mid = (r - l) / 2 + l;
        int val = build(l, mid, arr, p * 2) + build(mid + 1, r, arr, p * 2 + 1);
        tree[p] = val;
        return val;
    }

public:
    SegmentTree(vi &arr)
    {
        this->tree = vi(arr.size() * 4);
        this->n = arr.size();
        build(1, arr.size(), arr, 1);
    }
    void print()
    {
        for (auto &i : this->tree)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    int getRange(int range_l, int range_r, int p, int L, int R){
        // check if range equals the range looking for
        if(range_l == L){
            if(range_r == R){
                return tree[p];
            }
            // check if r in or out of range
            if(R > range_r){
                // check what halfs to get
            }
        }
    }
};

int main()
{
    sync;
    vi arr = {3, 2, 4, 5, 1, 1, 5, 3};
    for (auto &i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
    SegmentTree Seg_Tree(arr);
    Seg_Tree.print();
    return 0;
}