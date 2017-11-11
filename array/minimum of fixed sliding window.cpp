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

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<long> vl;
typedef long long ll;
typedef pair<long long, long long> llll;
typedef vector<long long> vll;
#define matrix(a) vector< vector<a> >
#define sz(a) int((a).size()) 
#define last(a) a[sz(a)-1]
#define ite(v) v::iterator
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define cisthere(c,x) (find(all(c),x) != (c).end())
#define pb push_back
#define fill(s,v) memset(s,v,sizeof(s))
#define enter cout<<endl

template<typename T>
void initialize(deque<T>& ascendmin, vector<T>& array, int start, int end) {
	ascendmin.push_front(array[end]);
	rlop(i, start, end - 1) {
		if (array[i] <= ascendmin.front())ascendmin.push_front(array[i]);
	}
	return;
}

template<typename T>
void moveright(deque<T>& ascendmin, vector<T>& array, int& cleft, int& cright) {
	while (!ascendmin.empty()) {
		if (ascendmin.back()>array[cright + 1])ascendmin.pop_back();
		else break;
	}
	ascendmin.push_back(array[cright + 1]);
	if (array[cleft] == ascendmin.front())ascendmin.pop_front();
	cleft++;
	cright++;
	return;
}

int main() {
	deque<ll> ascendmin;
	vll p;
	int cleft = l, cright = r;
	/*initialize the ascending min sequence in window [cleft,cright] of p, the minimum of current window is ascendmin.front()*/
	initialize(ascendmin, p, cleft, cright);
	/*movewindow right by 1*/
	moveright(ascendmin, p, cleft, cright);
}
