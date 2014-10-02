//includes
#include "NodeTooFar.h"
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair
#include <sstream>
#include <string>
#include <cassert>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

void print_results(int c, std::pair<int,int> p, int ttl, std::ostream& w) {
	w << "Case " << c << ": " << p.second << " nodes not reachable from node "
	  << p.first << " with TTL = " << ttl << "." << std::endl;

}

void solve(std::istream& r, std::ostream& w) {
	typedef std::tr1::unordered_map<int, std::tr1::unordered_set<int> > Nodes;
	Nodes nodes;

	int tests;
	r >> tests;

	std::string x;
	//removes extra newline
	getline(r, x);

	int i;
	int j;
	Nodes::iterator it;

	r >> i;
	r >> j;
	while (i != 0 and j != 0) {
		std::cout << i << " " << j << std::endl;

		it = nodes.find(i);
		if (it == nodes.end()) {
			std::tr1::unordered_set<int> neighbor;
			neighbor.insert(j);
			nodes.insert(Nodes::value_type(i,neighbor));
			// std::cout << i << " first" << std::endl;
		}
		else {
			std::tr1::unordered_set<int> current = it->second;
			current.insert(j);
			// std::cout << it->first << " next" << std::endl;

		}

		it = nodes.find(j);
		if (it == nodes.end()) {
			std::tr1::unordered_set<int> neighbor;
			neighbor.insert(i);
			nodes.insert(Nodes::value_type(j,neighbor));
			// std::cout << j << " first" << std::endl;

		}
		else {
			std::tr1::unordered_set<int> current = it->second;
			current.insert(i);
			// std::cout << it->first << " next" << std::endl;

		}

		r >> i;
		r >> j;

	}


}

int main() {
	using namespace std;
	solve(cin, cout);
	return 0;
}