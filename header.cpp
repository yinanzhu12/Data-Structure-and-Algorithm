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

#include <bits/stdc++.h>/*replace all above,only available for GNC*/
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
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define printv1(i,v) vlop1(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define pb push_back
#define enter cout<<'\n'
#define lb(i,v) int(lower_bound(all(v),i)-v.begin())
#define ub(i,v) int(upper_bound(all(v),i)-v.begin())


const long double pi = acos(-1.0);
const ll M=1e9+7;
string alp="abcdefghijklmnopqrstuvwxyz";
string Alp="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string digit="0123456789";
vi prime={10781,11173,12251,12391,15511,106033,108301,112909,139967,139969};


int main() {
	/*for large input*/
	ios::sync_with_stdio(false);
	
	/* for reading .txt file*/
	ifstream infile;
	ofstream outfile;
	infile.open("input.txt");
	cin.rdbuf(infile.rdbuf());
	outfile.open("output.txt");
	cout.rdbuf(outfile.rdbuf());

	/*output with k digits after decimal*/
	cout<<setprecision(k)<<fixed;
	
	/*interactive questions*/
	fflush(stdout);
	
	/*generate random number in [b,a+b-1]*/
	int t=rand()%a+b;
	return 0;
}
