/*construct Thue Morse sequence*/
int main() {
	vector<int> t(n,0);
	for (int i = 1; i < n; i++) {
		if (i % 2)t[i] = !t[(i - 1) >>1];
		else t[i] = t[i >>1];
	}
	return 0;
}