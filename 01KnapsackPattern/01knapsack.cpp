//  Created by Pradeep Singh on 06/08/2020.
//  Copyright © 2020 Pradeep Singh. All rights reserved.

/*
Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack which has a capacity ‘C’.
The goal is to get the maximum profit out of the items in the knapsack. Each item can only be selected once,
as we don’t have multiple quantities of any item.
*/




#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int>&weights, vector<int>&profits, int currindex, int capacity, vector<vector<int>>&dp) {
	if (capacity == 0)
		return 0;
	if (currindex >= weights.size())
		return 0;
	if (dp[currindex][capacity] != -1)
		return dp[currindex][capacity];
	int take = 0, leave = 0;
	if (weights[currindex] <= capacity)
		take = profits[currindex] + knapsack(weights, profits, currindex + 1, capacity - weights[currindex], dp);
	leave = knapsack(weights, profits, currindex + 1, capacity, dp);
	return dp[currindex][capacity] = max(take, leave);
}


int knapsackBottom_up(vector<int>&weights, vector<int>&profits, int capacity) {
	int n = weights.size();
	vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

	for (int i = 0; i <= capacity; i++) {
		if (weights[0] <= i)
			dp[0][i] = profits[0];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= capacity; j++) {
			if (weights[i] <= j) {
				dp[i][j] = max(dp[i][j], profits[i] + dp[i - 1][j - weights[i]]);
			}
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	int totalprofit = dp[n - 1][capacity];
	int cap = capacity;
	cerr << "selected Items:" << endl;
	for (int i = n - 1; i > 0; i--) {
		if (totalprofit != dp[i - 1][cap]) {
			cerr << weights[i] << " ";
			totalprofit -= profits[i];
			cap -= weights[i];
		}
	}
	if (totalprofit != 0)
		cerr << weights[0] << endl;
	cerr << endl;
	return dp[n - 1][capacity];
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n; cin >> n;
	vector<int> weights(n);
	vector<int> profits(n);

	for (int i = 0; i < n; i++)
		cin >> weights[i];
	for (int i = 0; i < n; i++)
		cin >> profits[i];
	int c; cin >> c;
	vector<vector<int>> dp(n, vector<int>(c + 1, -1));
	cerr << knapsackBottom_up(weights, profits, c) << endl;
}