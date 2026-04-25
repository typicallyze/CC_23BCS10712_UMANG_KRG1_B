
// #include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

const int N = 2e5 + 5;
long long bit[N], a[N];
int n, q;

void upd(int i, long long v)
{
    for (; i <= n; i += i & -i)
        bit[i] += v;
}

long long qry(int i)
{
    long long s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

int main()
{
    cout << endl
         << endl;

    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        upd(i, a[i]);
    }

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int k;
            long long u;
            cin >> k >> u;
            upd(k, u - a[k]);
            a[k] = u;
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << "ANS: " << qry(r) - qry(l - 1) << endl;
        }
    }
    return 0;
}