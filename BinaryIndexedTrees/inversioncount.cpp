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

void update(int i, int inc, int n, vector<int>&BIT) {
	while (i <= n ) {
		BIT[i] += inc;
		i += (i & (-i));
	}
}
void build(int n, int*arr, vector<int>&BIT) {
	for (int i = 1; i <= n; i++)
		update(i, arr[i], n, BIT);
}
int query(int i, vector<int>&BIT) {
	int ans = 0;
	while (i > 0) {
		ans += BIT[i];
		i -= (i & (-i));
	}
	return ans;
}
int RangeQuery(int L, int R, vector<int>&BIT) {
	return query(R, BIT) - query(L - 1, BIT);
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
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int arr[n + 1];
		int mx = INT_MIN;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			mx = max(arr[i], mx);
		}
		vector<int> BIT(mx + 1, 0);
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (arr[i] + 1 <= mx) {
				int x = RangeQuery(arr[i] + 1, mx, BIT);
				ans += x;
			}
			else
				ans += 0;
			// cerr << ans << endl;
			update(arr[i], 1, mx, BIT);
		}
		cout << ans << endl;
	}
}
