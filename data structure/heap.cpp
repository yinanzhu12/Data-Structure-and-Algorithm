#include <iostream>
#include <fstream>
#include<vector>
using namespace std;

#define sz(a) int(a.size())

/*a min heap*/
void maintain(vector<int>& h, int root) {
	int left = 2 * root,right = 2 * root + 1,n=sz(h);
	if (left>n)return;
	else if (left ==n) {
		if (h[left]<h[root]) swap(h[left],h[root])
		else return;
	}
	else {
		if (h[root]<=h[left] && h[root]<=h[right])return;
		else if (h[root]>h[left]) {
			if(h[root]<=h[right]){
			}
			swap(h[root],h[left])
			if (h[root]>h[right]) swap(h[root],h[right]);
			maintain(h, left);
			maintain(h, right);
		}
		else {
			swap(h[root],h[right])
			maintain(h, right);
		}
	}
	return;
}

void buildheap(vector<int>& h) {
	int n=sz(h);
	for (int i = n / 2; i >= 1; i--)maintain(h, i);
	return;
}

void changekey(vector<int>& h, int index, int newkey) {
	int n=sz(h);
	if (newkey>h[index]) {
		h[index] = newkey;
		maintain(h, index);
	}
	else {
		h[index] = newkey;
		while (index>1 && h[index]<h[index / 2]) {
			swap(h[index],h[index/2])
			index /= 2;
		}
	}
	return;
}

int minimum(vector<int>::iterator h) {
	return h[1];
}

int main() {
	ifstream infile;
	infile.open("input.txt");
	cin.rdbuf(infile.rdbuf());
	ofstream outfile;
	outfile.open("output.txt");
	cout.rdbuf(outfile.rdbuf());
	int q;
	cin >> q;
	vector<int> heap;
	heap.push_back(0);
	int max = 1000000000;
	for (int i = 0; i<q; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			cin >> b;
			heap.push_back(max);
			changekey(heap.begin(), heap.size() - 1, b, heap.size() - 1);
		}
		else if (a == 2) {
			int b;
			cin >> b;
			for (int j = 1; j <= heap.size() - 1; j++) {
				if (heap[j] == b) {
					int t = heap[j];
					heap[j] = heap[heap.size() - 1];
					heap[heap.size() - 1] = t;
					heap.pop_back();
					if (heap.size() != 1)maintain(heap.begin(), j, heap.size() - 1);
					break;
				}
			}
		}
		else {
			cout <<minimum(heap.begin())<< endl;
		}
	}
	return 0;
}
