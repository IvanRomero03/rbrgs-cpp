// Rbrgs.cpp
// problem from: https://cses.fi/problemset/task/1650/
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

int getXOR(int x, int y)
{
    return (x + y) - 2 * (x & y);
}

namespace SegTree
{
    class Cell
    {
    public:
        // UPDATE [TYPE]
        int val;
        int left;
        int right;
        Cell()
        {
            val = 0;
            left = 0;
            right = 0;
        }
        // UPDATE [TYPE]
        Cell(int val, int left, int right)
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
        // UPDATE [TYPE]
        int build(int l, int r, int p, vi &nums)
        {
            if (l == r)
            {
                segtree[p] = {nums[l], l, r};
                return nums[l];
            }
            int mid = (r - l) / 2 + l;
            // change operation here if not a sum segtree
            // UPDATE [OPERATION]
            segtree[p] = {getXOR(build(l, mid, p * 2, nums), build(mid + 1, r, p * 2 + 1, nums)), l, r};
            return segtree[p].val;
        }
        SegmentTree(vi &nums)
        {
            segtree = vector<Cell>(nums.size() * 4 + 1);
            this->size = nums.size() - 1;
            build(0, nums.size() - 1, 1, nums);
        }
        // UPDATE [TYPE]
        int getRange(int queryLeft, int queryRight)
        {
            return getRange(0, size, queryLeft, queryRight, 1);
        }
        // UPDATE [TYPE]
        int getRange(int l, int r, int queryLeft, int queryRight, int p)
        {
            if (l == queryLeft && r == queryRight)
            {
                return segtree[p].val;
            }
            // UPDATE [TYPE]
            // UPDATE [OPERATION]
            int res = 0;
            int mid = (r - l) / 2 + l;
            bool changed = false;
            if (queryLeft <= mid)
            {
                // UPDATE [OPERATION]
                res = getRange(l, mid, queryLeft, min(mid, queryRight), p * 2);
                changed = true;
            }
            if (queryRight > mid)
            {
                // UPDATE [OPERATION]
                if (changed)
                {
                    res = getXOR(res, getRange(mid + 1, r, max(queryLeft, mid + 1), queryRight, p * 2 + 1));
                }
                else
                {
                    res = getRange(mid + 1, r, max(queryLeft, mid + 1), queryRight, p * 2 + 1);
                }
            }
            return res;
        }
        void update(int updateIndex, int updateValue)
        {
            update(0, size, updateIndex, updateValue, 1);
        }
        // UPDATE [TYPE]
        int update(int l, int r, int updateIndex, int updateValue, int p)
        {
            if (l == updateIndex && r == updateIndex)
            {
                segtree[p].val = updateValue;
                return updateValue;
            }
            int mid = (r - l) / 2 + l;
            if (updateIndex <= mid)
            {
                // UPDATE [OPERATION]
                segtree[p].val = getXOR(update(l, mid, updateIndex, updateValue, p * 2), segtree[p * 2 + 1].val);
                return segtree[p].val;
            }
            // UPDATE [OPERATION]
            segtree[p].val = getXOR(segtree[p * 2].val, update(mid + 1, r, updateIndex, updateValue, p * 2 + 1));
            return segtree[p].val;
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
    for (int &i : nums)
    {
        cin >> i;
    }
    SegmentTree seg(nums);
    int a, b;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        cout << seg.getRange(a, b) << endl;
    }
    return 0;
}