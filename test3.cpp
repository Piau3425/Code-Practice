#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> v;

struct node {
	int l, r, f, w;
} tree[9000005];

inline void build(int k, int ll, int rr)
{
	tree[k].l = ll, tree[k].r = rr;
	if (tree[k].l == tree[k].r) {tree[k].w = v[tree[k].l]; return;}
	int mid = (tree[k].l + tree[k].r) / 2;
	build(2*k,ll,mid);
	build(2 * k + 1,mid+1,rr);
	tree[k].w = tree[2 * k].w + tree[2 * k + 1].w;
}

inline void down(int k)
{
	tree[2 * k].f += tree[k]. f;
	tree[2 * k + 1].f += tree[k].f;
	tree[2 * k].w += tree[k].f * (tree[2 * k].r - tree[2 * k].l + 1);
	tree[2 * k + 1].w += tree[k].f * (tree[2 * k + 1].r - tree[2 * k + 1].l + 1);
	tree[k].f = 0;
}

inline int ask_interval(int k, int x, int y)
{
	int ans = 0;
	if (x <= tree[k].l && y >= tree[k].r)
	{
		return tree[k].w;
	}
	if (tree[k].f)down(k);
	int mid = (tree[k].l + tree[k].r) / 2;
	if (x <= mid)ans += ask_interval(2 * k, x, y);
	if (y > mid)ans += ask_interval(2 * k + 1, x, y);
	return ans;
}

inline void change_interval(int k, int x, int y, int add)
{
	if (x <= tree[k].l && y >= tree[k].r)
	{
		tree[k].w += add * (tree[k].r - tree[k].l + 1);
		tree[k].f += add;
		return;
	}
	if (tree[k].f)down(k);
	int mid = (tree[k].l + tree[k].r)/2;
	if (x <= mid)change_interval(2 * k, x, y, add);
	if (y > mid)change_interval(2 * k + 1, x, y, add);
	tree[k].w = tree[2 * k].w + tree[2 * k + 1].w;
}

signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int n, m;cin >> n >> m;
    v.assign(4*n, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];
	build(1, 1, n);
	for (int i = 1;i <= m;i++)
	{
		int sec;cin >> sec;
		if (sec == 1)
		{
			int x, y, add;cin >> x >> y >> add;
			change_interval(1, x, y, add);
		}
		else if(sec == 2)
		{
			int x, y;cin >> x >> y;
			cout << ask_interval(1, x, y) << endl;
		}
	}
}
