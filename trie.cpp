#include <vector>
#include <string>

using namespace std;

class trie {
private:
	/*determined by the alphabet list needed to deal with*/
	const int start = 97;
	const int range = 26;
public:
	int words;
	int prefixes;
	vector<trie*> edges;
	trie() {
		words = 0;
		prefixes = 0;
		edges = vector<trie*>(this->range, nullptr);
	}
	void add(string& s) {
		if (unsigned(s.length()) == 0) {
			this->words += 1;
			return;
		}
		this->prefixes += 1;
		int c = s[0] - this->start;
		if (this->edges[c] == nullptr) {
			this->edges[c] = new trie;
		}
		(*(this->edges[c])).add(s.substr(1));
		return;
	}
	int countword(string& s) {
		if (unsigned(s.length()) == 0) {
			return this->words;
		}
		else {
			int c = s[0]-this->start;
			if (this->edges[c] == nullptr) {
				return 0;
			}
			else {
				return (*(this->edges[c])).countword(s.substr(1));
			}
		}
	}
	int countprefix(string& p) {
		if (unsigned(p.length()) == 0) {
			return this->prefixes;
		}
		else {
			int c = p[0] - this->start;
			if (this->edges[c] == nullptr) {
				return 0;
			}
			else {
				return (*(this->edges[c])).countprefix(p.substr(1));
			}
		}
	}
};
