// Rbrgs.cpp
#include <bits/stdc++.h>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#define EPS 1e-6
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define MAXN 1000005

#define sync ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15)
#define FOR(i, a, b) for (int i = int(a); i < int(b); i++)
#define RFOR(i, a, b) for (int i = int(a) - 1; i >= int(b); i--)
#define FORC(it, cont) for (auto it = (cont).begin(); it != (cont).end(); it++)
#define RFORC(it, cont) for (auto it = (cont).rbegin(); it != (cont).rend(); it++)
#define aFor(i, a) for (auto &i : a)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ll> vll;

namespace SegTree
{
    class Cell
    {
    public:
        // UPDATE [TYPE]
        ll val;
        int left;
        int right;
        Cell()
        {
            val = 0;
            left = 0;
            right = 0;
        }
        // UPDATE [TYPE]
        Cell(ll val, int left, int right)
        {
            this->val = val;
            this->left = left;
            this->right = right;
        }
    };
    class SegmentTree
    {
    public:
        int size;
        vector<Cell> segtree; // 1 indexed
        SegmentTree(int size)
        {
            segtree = vector<Cell>(size * 4 + 1);
            this->size = size - 1;
        }
        ll getElementUpdates(int index)
        {
            return increment(0, size, index, 1);
        }
        ll increment(int l, int r, int index, int p)
        {
            if (l == index && r == index)
            {
                return segtree[p].val;
            }
            int mid = (r - l) / 2 + l;
            if (index <= mid)
            {
                return increment(l, mid, index, p * 2) + segtree[p].val;
            }
            return increment(mid + 1, r, index, p * 2 + 1) + segtree[p].val;
        }
        void update(int l, int r, int updateValue)
        {
            update(0, size, l, r, updateValue, 1);
        }
        void update(int l, int r, int queryLeft, int queryRight, int updateValue, int p)
        {
            if (l == queryLeft && r == queryRight)
            {
                segtree[p].val += updateValue;
                return;
            }
            int mid = (r - l) / 2 + l;
            if (queryLeft <= mid)
            {
                update(l, mid, queryLeft, min(mid, queryRight), updateValue, p * 2);
            }
            if (queryRight > mid)
            {
                update(mid + 1, r, max(mid + 1, queryLeft), queryRight, updateValue, p * 2 + 1);
            }
        }
    };
}
using namespace SegTree;

int main()
{
    sync;
    int n, q;
    cin >> n >> q;
    vi nums(n);
    for (auto &i : nums)
    {
        cin >> i;
    }
    SegmentTree seg(n);
    int type, a, b, c;
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> a >> b >> c;
            seg.update(a - 1, b - 1, c);
        }
        else
        {
            cin >> a;
            cout << seg.getElementUpdates(a - 1) + nums[a - 1] << endl;
        }
    }
    return 0;
}