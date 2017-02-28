#include <vector>
#include <string>

using namespace std;

/*determine the alphabet needed to deal with*/
const char start = 'a';
const int range = 26;

class trie {
public:
	int words;
	int prefixes;
	vector<trie*> edges;
	trie() {
		words = 0;
		prefixes = 0;
		edges = vector<trie*>(range, nullptr);
	}
	void add(string& s) {
		if (!sz(s)) {
			this->words += 1;
			return;
		}
		this->prefixes += 1;
		int c = s[0] - start;
		if (this->edges[c] == nullptr) this->edges[c] = new trie;
		(*(this->edges[c])).add(s.substr(1));
		return;
	}
	int countword(string& s) {
		if (!sz(s)) return this->words;
		else {
			int c = s[0]-start;
			if (this->edges[c] == nullptr) return 0;
			else return (*(this->edges[c])).countword(s.substr(1))
		}
	}
	int countprefix(string& p) {
		if (!sz(p)) return this->prefixes;
		else {
			int c = p[0] - start;
			if (this->edges[c] == nullptr) return 0;
			else return (*(this->edges[c])).countprefix(p.substr(1));
		}
	}
};
