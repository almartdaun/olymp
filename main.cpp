#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

const int MAX_N = 10007;

vector<int>a(MAX_N);

void merge(int l1, int r1, int l2, int r2);

void merge_sort(int l, int r) {
    if (r - l < 1) return;

    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    merge(l, mid, mid + 1, r);
}

void merge(int l1, int r1, int l2, int r2) {
    int sz1 = r1 - l1 + 1;
    int sz2 = r2 - l2 + 1;
    vector<int>v1(sz1), v2(sz2);
    vector<int>res(sz1 + sz2);

    int it1 = 0, it2 = 0;
    int itr = 0;

    while (it1 < sz1 && it2 < sz2) {
        if (a[l1 + it1] < a[l2 + it2]) {
            res[itr++] = a[l1 + it1++];
        } else {
            res[itr++] = a[l2 + it2++];
        }
    }

    while (it1 < sz1) res[itr++] = a[l1 + it1++];
    while (it2 < sz2) res[itr++] = a[l2 + it2++];

    itr = 0;
    for (int i = l1; i < l1 + sz1 + sz2; i++) {
        a[i] = res[itr++];
    }
}

void print_vec(vector<int> & vec, int n = -1) {
    if (n == -1) n = vec.size();
    for (int i = 0; i < n; i++) {
        cout << vec[i] << ' ';
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    merge_sort(0, n - 1);

    print_vec(a, n);
}