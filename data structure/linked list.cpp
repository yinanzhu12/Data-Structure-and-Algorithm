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

template<typename T>
class node{
public:
	T key;
	node* next;
	node* previous;
	node(T k) {
		key = k;
		next = nullptr;
		previous = nullptr;
	}
};

template<typename T>
class double_list {
public:
	node<T>* head;
	node<T>* tail;
	list() {
		head = nullptr;
		tail = nullptr;
	}
	void insert(node<T>* n) {
		n->next = this->head;
		if (this->head != nullptr) this->head->previous = n;
		this->head = n;
		return;
	}
	node<T>* search(T k) {
		node<T>* t = this->head;
		while (t != nullptr) {
			if (t->key == k)return t;
			t = t->next;
		}
		return nullptr;
	}
	void delete(node<T>* n) {
		if (n->previous == nullptr) {
			if (n->next == nullptr) {
				this->head = nullptr;
				this->tail = nullptr;
				delete n;
				return;
			}
			this->head = n->next;
			this->head->previous = nullptr;
			delete n;
			return;
		}
		if (n->next == nullptr) {
			this->tail = n->previous;
			this->tail->next = nullptr;
			delete n;
			return;
		}
		n->previous->next = n->next;
		n->next->previous = n->previous;
		delete n;
		return;
	}
};

template<typename T>
class double_circular_list {
public:
	node<T>* sentinel;
	list(T k) {
		sentinel = new node(k);
		sentinel->next = sentinel;
		sentinel->previous = sentinel;
	}
	void insert(node<T>* n) {
		n->next = this->sentinel->next;
		n->next->previous = n;
		this->sentinel->next = n;
		n->previous = this->sentinel;
		return;
	}
	node<T>* search(T k) {
		node<T>* t = this->sentinel->next;
		while (t!=sentinel) {
			if (t->key == k)return t;
			t = t->next;
		}
		return nullptr;
	}
	void delete(node<T>* n) {
		n->previous->next = n->next;
		n->next->previous = n->previous;
		delete n;
		return;
	}
};