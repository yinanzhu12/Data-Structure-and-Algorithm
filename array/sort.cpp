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

template <typename T >
void quicksort(vector<T>& a, int l, int r) {
	if (l >= r)return;
	int p = l+1, pivot=l,n=sz(a);
	while (p <= r) {
		if (a[p] < a[pivot]) {
			swap(a[p], a[pivot]);
			swap(a[p], a[pivot + 1]);
			pivot++;
		}
		p++;
	}
	quicksort<T>(a, l, pivot-1);
	quicksort<T>(a, pivot+1, r);
	return;
}

template<typename T>
void mergesort(vector<T>& a, int l, int r) {
	if (l >= r)return;
	mergesort(a, l, (l + r) / 2);
	mergesort(a, (l + r) / 2 + 1, r);
	int p1=l, p2 = (l + r) / 2 + 1;
	vector<T> acopy;
	while (p1 <= (l + r) / 2 || p2 <= r) {
		if (p1 > (l + r) / 2) {
			acopy.push_back(a[p2]);
			p2++;
		}
		else if (p2 > r) {
			acopy.push_back(a[p1]);
			p1++;
		}
		else {
			if (a[p1] > a[p2]) {
				acopy.push_back(a[p2]);
				p2++;
			}
			else {
				acopy.push_back(a[p1]);
				p1++;
			}
		}
	}
	copy(all(acopy), a.begin()+l);
	return;
}

