long long euclidean(long long a, long long b) {
	/*To compute gcd(a, b), return r[i].
	To compute 1/a mod b provided gcd(a,b)=1, return s[i]
	To compute solution to a*s+b*t=gcd(a,b), return s[i] and t[i]*/
	vector<long long> r = { a,b };
	vector<long long> s = { 1,0 };
	vector<long long> t = { 0,1 };
	int i;
	long long q;
	while (true) {
		i = r.size() - 1;
		r.push_back(r[i - 1] % r[i]);
		q = r[i - 1] / r[i];
		s.push_back(s[i - 1] - s[i] * q);
		t.push_back(t[i - 1] - t[i] * q);
		if (r[i + 1] == 0)break;
	}
	if (s[i]<0)s[i] += mod;
	if (s[i] >= mod)s[i] -= mod;
	return s[i];
}
