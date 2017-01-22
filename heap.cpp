#include <iostream>
#include <fstream>
#include<vector>
using namespace std;

void maintain(vector<int>::iterator h, int root, int size) {
	int left = 2 * root;
	int right = 2 * root + 1;
	int t;
	if (left>size)return;
	else if (left == size) {
		if (h[left]<h[root]) {
			t = h[root];
			h[root] = h[left];
			h[left] = t;
		}
		else return;
	}
	else {
		if (h[root]<=h[left] && h[root]<=h[right])return;
		else if (h[root]>h[left]) {
			t = h[root];
			h[root] = h[left];
			h[left] = t;
			if (h[root]>h[right]) {
				t = h[root];
				h[root] = h[right];
				h[right] = t;
			}
			maintain(h, left, size);
			maintain(h, right, size);
		}
		else {
			t = h[root];
			h[root] = h[right];
			h[right] = t;
			maintain(h, right, size);
		}
	}
	return;
}

void buildheap(vector<int>::iterator h, int size) {
	for (int i = size / 2; i >= 1; i--) {
		maintain(h, i, size);
	}
	return;
}

void changekey(vector<int>::iterator h, int change, int newkey, int size) {
	if (newkey>h[change]) {
		h[change] = newkey;
		maintain(h, change, size);
	}
	else {
		h[change] = newkey;
		while (change>1 && h[change]<h[change / 2]) {
			int t;
			t = h[change];
			h[change] = h[change / 2];
			h[change / 2] = t;
			change = change / 2;
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