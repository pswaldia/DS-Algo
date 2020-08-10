//  Copyright © 2020 Pradeep Singh. All rights reserved.

/*
Zeckendrof's theorem : Each positive number can be represented as a sum of three fibonacci numbers such that no two
consecutive fib number is used.
binomial : C(n,r) = C(n-1,r-1)+C(n-1,r) , C(n,0)=1
catalan : C(2*n,n)/(n+1);
*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define ff first
#define ss second
#define int long long
#define str(a) to_string(a)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SORT(c) sort(c.begin(),c.end())
#define mod 1000000007
#define max_heap priority_queue<int>
#define min_heap priority_queue<int,vi,greater<int> >
#define setbits(x) __builtin_popcount(x)
#define ps(x,y) fixed<<setprecision(y)<<x
#define start(t) int x;cin>>x;while(x--)
#define inf LLONG_MAX
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define endl "\n"

// Binary Indexed Tree Functions for range query assuming 1 based indexing

vector<int> BIT;
void update(int i, int incremental, int n) {
	while (i <= n ) {
		BIT[i] += incremental;
		i += (i & (-i));
	}
}
void build(int n, vector<int>&arr) {
	for (int i = 1; i <= n; i++)
		update(i, arr[i], n);
}
int query(int i) {
	int sum = 0;
	while (i > 0) {
		sum += BIT[i];
		i -= (i & (-i));
	}
	return sum;
}
int RangeQuery(int L, int R ) {
	return query(R) - query(L - 1);
}

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	BIT.resize(100005, 0);
	build(n, arr);
	int q; cin >> q;
	cerr << q << endl;
	while (q--) {
		int a, b, c;
		cin >> a >> b >> c;
		cerr << a << " " << b << " " << c << endl;
		if (a == 1) { // range sum query....
			cout << RangeQuery(b, c) << endl;
		} else {	// point update query
			update(b, c, n);
		}
	}



}
