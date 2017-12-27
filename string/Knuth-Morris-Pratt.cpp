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
#define lop(i,a,b) for (int i=a; i<=b; i++)
#define vlop(i,v) lop(i,0,sz(v)-1)
#define vlop1(i,v) lop(i,1,sz(v)-1)
#define rlop(i,a,b) for (int i=b; i>=a; i--)
#define vrlop(i,v) rlop(i,0,sz(v)-1)
#define vrlop1(i,v) rlop(i,1,sz(v)-1)
#define printv(i,v) vlop(i,v)cout<<v[i]<<" "
#define all(s) (s).begin(),(s).end()
#define isthere(c,x) ((c).find(x) != (c).end()) 
#define pb push_back
#define enter cout<<'\n'

void failure(vi& f, string& s) {
	int n=sz(s);
	lop(i, 1,n-1) {
		int t = f[i-1];
		while (true) {
			if (s[i] == s[t]) {
				f[i]=t+1;
				break;
		}
			else if(!t){
				f[i]=0;
				break;
			}
			else t = f[t-1];
		}

	}
	return;
}

void findsubstring(vi& st,vi& ft,string& s,string& t){
    int success=0,n=sz(s);
    lop(i,0,n-1){
        if(success==sz(t))success=ft.back();
        if(s[i]==t[success])success++;
        else{
            while(true){
                if(!success)break;
                success=ft[success-1];
                if(s[i]==t[success]){
                    success++;
                    break;
                }
            }
        }
        st[i]=success;
    }
}

void dfs(matrix(int)& alist, int root, vi& count, vi& subtreesum) {
	for(auto child: alist[root]) {
		dfs(alist, alist[root][i], count,subtreesum);
		subtreesum[root]+=subtreesum[alist[root][i]];
	}
	subtreesum[root]+=count[root];
	return;
}

void findprefix(int l,vi& f, vi& result){
	int t=l+1;
	while(t){
		result.pb(t);
		t=f[t-1];
	}
	return;
}

int main(){
	string s,t;
	vi f(sz(s));
	f[0]=0;
	/*compute failure function, s start from index 0
	fs[i] is the maximum LENGTH the suffix ending in s[i] can be realized as prefix of s, EXCEPT the string (s[0]...s[i]) itself*/
	failure(fs, s);
	failure(ft,t);
	vi st(sz(s));
	/*st[i]=j iff j is the length of the longest prefix of t that can be realized as a substring of s ending at s[i]*/
	findsubstring(st,ft,s,t);
	
	/*applications*/
	vi result;
	/*find all the t such that (s[0]...s[t-1]) can be realized as a suffix ending at s[l]*/
	findprefix(l,f,result);
	vlop(i,f)count[f[i]]++;
	
	/*build a DIRECTED tree rooted at 0, with vertice 0...sz(s), edge f[i]->i*/
	matrix(int) alist(sz(s)+1);
	vlop(i,f) alist[f[i]].pb(i+1);
	/*subtreesum[i]+1 will be the time s[0]...s[i-1] appears in s as a substring*/
	dfs(alist,0,count,subtreesum);
        
}
