#include <bits/stdc++.h>
using namespace std;
#define int long long

void compute_abssum_nosort(vector<int> &left, vector<int> &psl, vector<int> &right, vector<int> &orders, int *pref)
{
    vector<int> order_w(right.size()), actual_w(right.size());
    int a = 0, b = 0;
    for (int i = 0; i < right.size(); i++)
    {
        while (a < left.size() && left[a] <= right[i])
            a++;
        while (b < left.size() && left[b] < right[i])
            b++;
        order_w[i] = psl.back() - psl[a] - right[i] * (left.size() - a) + right[i] * b - psl[b];
    }
    for (int i = 0; i < right.size(); i++)
        actual_w[i] = order_w[orders[i]];
    partial_sum(actual_w.begin(), actual_w.end(), pref + 1);
}
int compute_abssum_nosort_value(vector<int> &left, vector<int> &right)
{
    vector<int> psl(left.size() + 1);
    int sum = 0;
    partial_sum(left.begin(), left.end(), psl.begin() + 1);
    int a = 0, b = 0;
    for (int i = 0; i < right.size(); i++)
    {
        while (a < left.size() && left[a] <= right[i])
            a++;
        while (b < left.size() && left[b] < right[i])
            b++;
        sum += psl.back() - psl[a] - right[i] * (left.size() - a) + right[i] * b - psl[b];
    }
    return sum;
}
const int MAXN = 100000, B = 320;
void countingsort(vector<int> &p)
{
    vector<int> count(B), output(p.size());
    for (auto i : p)
        count[i]++;
    for (int i = 1; i < B; i++)
        count[i] += count[i - 1];
    for (int i = p.size() - 1; i >= 0; i--)
        output[--count[p[i]]] = p[i];
    p = output;
}
int extreme_block[MAXN / B + 1][MAXN / B + 1][B + 1];
struct block
{
    vector<int> sorted, orders, psl;
};
int pfs[MAXN / B + 2][MAXN / B + 2];
void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (auto &i : p)
        cin >> i;
    vector<block> block1;
    for (int i = 0; i < n / B; i++)
    {
        block1.push_back(block{vector<int>(p.begin() + i * B, p.begin() + (i + 1) * B),
                               vector<int>(p.begin() + i * B, p.begin() + (i + 1) * B)});
        sort(block1.back().sorted.begin(), block1.back().sorted.end());
        for (auto &i : block1.back().orders)
            i = lower_bound(block1.back().sorted.begin(), block1.back().sorted.end(), i) - block1.back().sorted.begin();
        block1.back().psl.resize(block1.back().sorted.size() + 1);
        partial_sum(block1.back().sorted.begin(), block1.back().sorted.end(), block1.back().psl.begin() + 1);
    }
    block1.push_back(block{vector<int>(p.begin() + (n / B) * B, p.begin() + n),
                           vector<int>(p.begin() + (n / B) * B, p.begin() + n)});
    sort(block1.back().sorted.begin(), block1.back().sorted.end());
    for (auto &i : block1.back().orders)
        i = lower_bound(block1.back().sorted.begin(), block1.back().sorted.end(), i) - block1.back().sorted.begin();
    block1.back().psl.resize(block1.back().sorted.size() + 1);
    partial_sum(block1.back().sorted.begin(), block1.back().sorted.end(), block1.back().psl.begin() + 1);
    for (int i = 0; i <= n / B; i++)
        for (int j = 0; j <= n / B; j++)
            compute_abssum_nosort(block1[i].sorted, block1[i].psl, block1[j].sorted, block1[j].orders,
                                  extreme_block[i][j]);
    for (int i = 0; i <= n / B; i++)
        for (int j = 0; j <= n / B; j++)
            pfs[i + 1][j + 1] = extreme_block[i][j][block1[j].sorted.size()];
    for (int i = 0; i <= n / B + 1; i++)
        for (int j = 1; j <= n / B + 1; j++)
            pfs[i][j] += pfs[i][j - 1];
    for (int i = 1; i <= n / B + 1; i++)
        for (int j = 0; j <= n / B + 1; j++)
            pfs[i][j] += pfs[i - 1][j];
    while (q--)
    {
        int l, r, u, v;
        cin >> l >> r >> u >> v;
        l--, r--, u--, v--;
        if (u / B == v / B)
        {
            swap(l, u);
            swap(r, v);
        }
        int res = 0;
        if (l / B != r / B && u / B != v / B)
        {
            int nl = (l / B + 1) * B - l, nr = r + 1 - (r / B) * B;
            int nu = (u / B + 1) * B - u, nv = v + 1 - (v / B) * B;
            vector<int> vec1(block1[l / B].orders.end() - nl, block1[l / B].orders.end());
            vector<int> vec2(block1[r / B].orders.begin(), block1[r / B].orders.begin() + nr);
            vector<int> vec3(block1[u / B].orders.end() - nu, block1[u / B].orders.end());
            vector<int> vec4(block1[v / B].orders.begin(), block1[v / B].orders.begin() + nv);
            countingsort(vec1);
            countingsort(vec2);
            countingsort(vec3);
            countingsort(vec4);
            vector<int> vecn1(vec1.size());
            vector<int> vecn2(vec2.size());
            vector<int> vecn3(vec3.size());
            vector<int> vecn4(vec4.size());
            for (int i = 0; i < vec1.size(); i++)
                vecn1[i] = block1[l / B].sorted[vec1[i]];
            for (int i = 0; i < vec2.size(); i++)
                vecn2[i] = block1[r / B].sorted[vec2[i]];
            for (int i = 0; i < vec3.size(); i++)
                vecn3[i] = block1[u / B].sorted[vec3[i]];
            for (int i = 0; i < vec4.size(); i++)
                vecn4[i] = block1[v / B].sorted[vec4[i]];
            int lb = l / B + 1, rb = r / B - 1, ub = u / B + 1, vb = v / B - 1;
            res = pfs[rb + 1][vb + 1] - pfs[rb + 1][ub] - pfs[lb][vb + 1] + pfs[lb][ub];
            res += compute_abssum_nosort_value(vecn1, vecn3);
            res += compute_abssum_nosort_value(vecn2, vecn3);
            res += compute_abssum_nosort_value(vecn1, vecn4);
            res += compute_abssum_nosort_value(vecn2, vecn4);
            for (int i = lb; i <= rb; i++)
            {
                res += extreme_block[i][ub - 1][B] - extreme_block[i][ub - 1][B - nu];
                res += extreme_block[i][vb + 1][nv];
            }
            for (int i = ub; i <= vb; i++)
            {
                res += extreme_block[i][lb - 1][B] - extreme_block[i][lb - 1][B - nl];
                res += extreme_block[i][rb + 1][nr];
            }
        }
        else if (u / B != v / B)
        {
            int nu = (u / B + 1) * B - u, nv = v + 1 - (v / B) * B;
            vector<int> vec1(block1[l / B].orders.begin() + l % B, block1[l / B].orders.begin() + r % B + 1);
            vector<int> vec2(block1[u / B].orders.end() - nu, block1[u / B].orders.end());
            vector<int> vec3(block1[v / B].orders.begin(), block1[v / B].orders.begin() + nv);
            countingsort(vec1);
            countingsort(vec2);
            countingsort(vec3);
            vector<int> vecn1(vec1.size());
            vector<int> vecn2(vec2.size());
            vector<int> vecn3(vec3.size());
            for (int i = 0; i < vec1.size(); i++)
                vecn1[i] = block1[l / B].sorted[vec1[i]];
            for (int i = 0; i < vec2.size(); i++)
                vecn2[i] = block1[u / B].sorted[vec2[i]];
            for (int i = 0; i < vec3.size(); i++)
                vecn3[i] = block1[v / B].sorted[vec3[i]];
            int ub = u / B + 1, vb = v / B - 1;
            res += compute_abssum_nosort_value(vecn1, vecn2);
            res += compute_abssum_nosort_value(vecn1, vecn3);
            for (int i = ub; i <= vb; i++)
                res += extreme_block[i][l / B][r % B + 1] - extreme_block[i][l / B][l % B];
        }
        else
        {
            vector<int> vec1(block1[l / B].orders.begin() + l % B, block1[l / B].orders.begin() + r % B + 1);
            vector<int> vec2(block1[u / B].orders.begin() + u % B, block1[u / B].orders.begin() + v % B + 1);
            countingsort(vec1);
            countingsort(vec2);
            vector<int> vecn1(vec1.size());
            vector<int> vecn2(vec2.size());
            for (int i = 0; i < vec1.size(); i++)
                vecn1[i] = block1[l / B].sorted[vec1[i]];
            for (int i = 0; i < vec2.size(); i++)
                vecn2[i] = block1[u / B].sorted[vec2[i]];
            res = compute_abssum_nosort_value(vecn1, vecn2);
        }
        cout << res << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
}