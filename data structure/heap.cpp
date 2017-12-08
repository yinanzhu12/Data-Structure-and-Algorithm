#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef long long ll;
typedef pair<long long, long long> l4;
typedef vector<long long> vll;
typedef double db;
typedef vector<double> vdb;
typedef pair<double, double> dd;
typedef set<int> si;
typedef set<long long> sll;
#define fi first
#define se second
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'
#define lb(i,v) int(lower_bound(all(v),i)-v.begin())
#define ub(i,v) int(upper_bound(all(v),i)-v.begin())

/*a min heap*/
template<typename T>
void maintain(vector<T>& h, int root) {
	int left = 2 * root,right = 2 * root + 1,n=sz(h)-1;
	if (left>n)return;
	if (left ==n) {
		if (h[left]<h[root]) swap(h[left],h[root])
		return;
	}
	else if (h[root]<=h[left] && h[root]<=h[right])return;
	int min_index;
	if (h[left] <= h[right]&&h[left]<=h[root])min_index = left;
	else min_index = right;
	swap(h[root], h[min_index])maintain<T>(h, min_index);
	return;
}

template<typename T>
void buildheap(vector<T>& h) {
	int n=sz(h)-1;
	for (int i = n / 2; i >= 1; i--)maintain<T>(h, i);
	return;
}

template<typename T>
void changekey(vector<T>& h, int index, T newkey) {
	int n=sz(h)-1;
	if (newkey>h[index]) {
		h[index] = newkey;
		maintain<T>(h, index);
	}
	else {
		h[index] = newkey;
		while (index>1 && h[index]<h[index / 2]) {
			swap(h[index], h[index / 2]);
			index /= 2;
		}
	}
	return;
}

template<typename T>
void pop_minimum(vector<T>& h) {
	if (sz(h) < 2)return;
	swap(h[i], h[sz(h) - 1]);
	h.pop_back();
	maintain(h, 1);
	return;
}

template<typename T>
void insert(vector<T>& h, T key) {
	h.pb(key);
	int index = sz(h) - 1;
	while (index>1 && h[index]<h[index / 2]) {
		swap(h[index], h[index / 2]);
		index /= 2;
	}
	return;
}