#include <vector>;


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
int main() {
	int inf=10000;
	vi sieve(inf + 1, 1);
	/*define 1 as non-prime*/
	sieve[1] = 0;
	int newprime = 1;
	/*i is prime iff sieve[i]=1*/
	while (newprime <= inf) newprime = nextprime(sieve, newprime);
	return 0;
}
