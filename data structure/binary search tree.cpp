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

template <typename T>
class node {
public:
	T val;
	node* left;
	node* right;
	node* parent;
	node(T v = 0) {
		val = v;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
	void insert(int v) {
		if (v <= this->val) {
			if (this->left == nullptr) {
				this->left = new node(v);
				this->left->parent = this;
				return;
			}
			this->left->insert(v);
			return;
		}
		if (this->right == nullptr) {
			this->right = new node(v);
			this->right->parent = this;
			return;
		}
		this->right->insert(v);
		return;
	}
	void inorder() {
		if (this->left != nullptr) this->left->inorder();
		cout << this->val << endl;
		if (this->right != nullptr)this->right->inorder();
		return;
	}
	node* search(int v) {
		if (this->val == v)return this;
		if (this->val >= v) {
			if (this->left == nullptr)return nullptr;
			return this->left->search(v);
		}
		if (this->right == nullptr)return nullptr;
		return this->right->search(v);
	}
	node* maximum() {
		if (this->right == nullptr)return this;
		return this->right->maximum();
	}
	node* minimum() {
		if (this->left == nullptr)return this;
		return this->left->minimum();
	}
	node* successor() {
		if (this->right == nullptr) {
			node* s = this;
			while (s ->parent!= nullptr) {
				if (s != s->parent->right) break;
				s = s->parent;
			}
			return s->parent;
		}
		return this->right->minimum();
	}
	node* predecessor() {
		if (this->left == nullptr) {
			node* s = this;
			while (s->parent != nullptr) {
				if (s == s->parent->right)break;
				s = s->parent;
			}
			return s->parent;
		}
		return this->left->maximum();
	}
};
template<typename T>
class tree{
public:
	node<T>* root;
	tree() {
		root = nullptr;
	}
	tree(vector<T>& a) {
		if (!sz(a))root = nullptr;
		else {
			root = new node<T>(a[0]);
			lop(i, 1, sz(a) - 1)root->insert(a[i]);
		}
	}
	void insert(T n) {
		if (this->root == nullptr)this->root = *new node(n);
		else this->root.insert(n);
		return;
	}
	void inorder() {
		if (this->root == nullptr)return;
		this->root->inorder();
	}
	node<T>* search(T v) {
		if (this->root == nullptr)return nullptr;
		return this->root->search(v);
	}
	node<T>* maximum() {
		if (this->root == nullptr)return nullptr;
		return this->root->maximum();
	}
	node<T>* minimum() {
		if (this->root == nullptr)return nullptr;
		return this->root->minimum();
	}
	void erase(node<T>* n) {
		if (n == nullptr)return;
		if (n->left == nullptr) {
			if (n->right == nullptr) {
				if (n->parent==nullptr)this->root = nullptr;
				else if (n->parent->right == n)n->parent->right = nullptr;
				else n->parent->left = nullptr;
				delete n;
				return;
			}
			n->right->parent = n->parent;
			if (n == this->root)this->root = n->right;
			delete n;
			return;
		}
		if (n->right == nullptr) {
			n->left->parent = n->parent;
			if (n == this->root)this->root = n->left;
			delete n;
			return;
		}
		node<T>* s = n->successor();
		if (s == n->right) {
			s->parent = n->parent;
			if (n->parent != nullptr) {
				if (n == n->parent->right)n->parent->right = s;
				else n->parent->left = s;
			}
			s->left = n->left;
			n->left->parent = s;
			if (n == this->root)this->root = s;
			delete n;
			return;
		}
		if (s->right != nullptr) {
			node<T>* sp = s->parent;
			s->right->parent = sp;
			sp->left = s->right;
		}
		s->right = n->right;
		n->right->parent = s;
		s->left = n->left;
		n->left->parent = s;
		s->parent = n->parent;
		if (n->parent != nullptr) {
			if (n == n->parent->right)n->parent->right = s;
			else n->parent->left = s;
		}
		if (n == this->root)this->root = s;
		delete n;
		return;
	}
};

