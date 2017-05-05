#include <vector>;

const int inf=100000;
int nextprime(vi& sieve, int previous) {
	int next = previous + 1;
	while (next <= sz(sieve) - 1) {
		if (sieve[next])break;
		next++;
	}
	int nextmultiple = next * 2;
	while (nextmultiple <= sz(sieve) - 1) {
		sieve[nextmultiple] = 0;
		nextmultiple += next;
	}
	return next;
}

void findprime(int l, int r, vi& bigsieve, vi& prime) {
	bigsieve.resize(r - l + 1, 1);
	if (l == 1)bigsieve[0] = 0;
	vlop(i, prime) {
		if (1LL * prime[i] * prime[i] <= r) {
			int t = l / prime[i] * prime[i];
			if (t<l)t += prime[i];
			if (t == prime[i])t *= 2;
			while (t <= r) {
				bigsieve[t - l] = 0;
				t += prime[i];
			}
		}
		else break;
	}
	return;
}

int main() {
	vi sieve(inf + 1, 1);
	/*define 1 as non-prime*/
	sieve[1] = 0;
	int newprime = 1;
	/*i is prime iff sieve[i]=1*/
	while (newprime*newprime <= inf) newprime = nextprime(sieve, newprime);
	vi prime;
	lop(i, 2, inf) {
		if (sieve[i])prime.pb(i);
	}
	int l, r;
	vi bigsieve;
	findprime(l, r, bigsieve, prime);/*get all prime numbers in [l,r], r<=inf^2. bigsieve[i]=1 iff i+l is prime*/
	return 0;
}
