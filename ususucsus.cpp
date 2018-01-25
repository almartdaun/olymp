#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

typedef long long ll;

ll c[26];

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	ll res = 0;
	cin >> n;

	for (int i = 0; i < n; i++)	cin >> c[i];

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (c[j] >= c[i]) {
				res += c[i];
				c[j] -= c[i];
			}
			else {
				c[i] = c[j];
				res += c[j];
				c[j] = 0;
			}
		}
	}

	cout << res;
}