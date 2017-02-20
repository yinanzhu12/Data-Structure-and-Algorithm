#include <vector>;


int nextprime(vector<int>& sieve, int previous) {
	int next = previous + 1;
	while (sieve[next] == 0)next++;
	int nextmultiple = next * 2;
	while (nextmultiple <= sz(sieve) - 1) {
		sieve[nextmultiple] = 0;
		nextmultiple += next;
	}
	return next;
}
int main() {
	int inf=10000;
	vector<int> sieve(inf + 1, 1);
	sieve[1] = 0;
	int newprime = 1;
	while (newprime <= inf) {
		newprime = nextprime(sieve, newprime);
	}
	return 0;
}
