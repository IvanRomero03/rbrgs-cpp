// Get factors of a number

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
#define _ ios_base::sync_with_stdio(0), cin.tie(0), cin.tie(0), cout.tie(0), cout.precision(15);

typedef long long ll;

const ll MAXM = 1e5;
vector<ll> factors[MAXM + 5];

// Maximal factors of A are bounded by A^(1/3)
void init()
{
    for (ll i = 1; i <= MAXM; i++)
    {
        for (ll j = i; j <= MAXM; j += i)
        {
            factors[j].push_back(i);
        }
    }
}

// Maximal number of divisors of n-digit numbers: https://oeis.org/search?q=1344+maximal+divisors

int main()
{
    _;

    init();

    // 1, 2, 3, 6
    for (auto f : factors[6])
    {
        cout << f << " ";
    }
    cout << "\n";

    // 1, 2, 5, 10
    for (auto f : factors[10])
    {
        cout << f << " ";
    }

    cout << "\n";

    return 0;
}
