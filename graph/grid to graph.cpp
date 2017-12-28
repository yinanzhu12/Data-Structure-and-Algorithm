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
int n,m;
vi movei={1,-1,0,0};
vi movej={0,0,1,-1};
bool inboard(int i,int j){
    return i<=n && i>=1 && j<=m && j>=1;
}
int main() {
	/*turn a grid with row 1,...,n, coloumn 1,...,m into an undirected graph where two adjacent grid are connected*/
	matrix(int) alist(n*m + 1);
	matrix(int) id(n,vi(m));
        int count=1;
        lop(i,1,n){
		lop(j,1,m){
			id[i][j]=count;
                        count++;
		}
	}
        lop(i,0,n-1){
		lop(j,0,m-1){
			lop(k,0,3){
				if(inboard(i+movei[k],j+movej[k]))alist[id[i][j]].pb(id[i+movei[k]][j+movej[k]]);
			}
		}
	}
}
