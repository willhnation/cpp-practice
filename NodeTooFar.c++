//includes
#include "NodeTooFar.h"
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair
#include <sstream>
#include <string>
#include <cassert>

void print_results(int c, std::pair<int,int> p, int ttl, std::ostream& w) {
	w << "Case " << c << ": " << p.second << " nodes not reachable from node "
	  << p.first << " with TTL = " << ttl << "." << endl;

}

void solve(std::istream& r, std::ostream& w) {

	int tests;
	r >> tests;

	string x;
	//removes extra newline
	getline(r, x);


}

int main() {
	using namespace std;
	solve(cin, cout);
	return 0;
}