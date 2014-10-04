//includes
//#include "NodeTooFar.h"
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair
#include <sstream>
#include <string>
#include <cassert>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <queue>

void print_results(int c, std::pair<int,int> p, int ttl) {
	std::cout << "Case " << c << ": " << p.second << " nodes not reachable from node "
	  << p.first << " with TTL = " << ttl << ".";

}

void eval(int node, int ttl, int c, std::tr1::unordered_map<int, std::tr1::unordered_set<int> > nodes) {
	typedef std::tr1::unordered_map<int, std::tr1::unordered_set<int> > Nodes;

	std::tr1::unordered_set<int> current;
	Nodes::iterator it;

	it = nodes.find(node);
	current.insert(node);

	for (std::tr1::unordered_set<int>::iterator i = it->second.begin(); i != it->second.end(); ++i) {
		current.insert(*i);
	}

	int count = 1;
	while (count < ttl) {
		std::tr1::unordered_set<int> temp = current;
		for (std::tr1::unordered_set<int>::iterator i = temp.begin(); i != temp.end(); ++i) {
			Nodes::iterator it = nodes.find(*i);
			for (std::tr1::unordered_set<int>::iterator itr = it->second.begin(); itr != it->second.end(); ++itr) {
				current.insert(*itr);
			}

		}

		++count;
	}
	int result = nodes.size() - current.size();
	// std::cout << nodes.size() << " " << current.size() << " result: " << result <<  std::endl;
	if (ttl != 0) {
		print_results(c, std::make_pair(node,result), ttl);
	}
	else {
			print_results(c, std::make_pair(node,nodes.size()-1), ttl);
	}

}

int read(std::istream& r, int t, int cn) {
	typedef std::tr1::unordered_map<int, std::tr1::unordered_set<int> > Nodes;
	Nodes nodes;
	Nodes::iterator it;

	int i;
	int j;


	int count = 0;
	while (count < t) {
		r >> i;
		r >> j;

		it = nodes.find(i);
		if (it == nodes.end()) {
			std::tr1::unordered_set<int> neighbor;
			neighbor.insert(j);
			nodes.insert(Nodes::value_type(i,neighbor));
		}
		else {
			std::tr1::unordered_set<int> current = it->second;
			it->second.insert(j);
		}

		it = nodes.find(j);
		if (it == nodes.end()) {
			std::tr1::unordered_set<int> neighbor;
			neighbor.insert(i);
			nodes.insert(Nodes::value_type(j,neighbor));
		}
		else {
			std::tr1::unordered_set<int> current = it->second;
			it->second.insert(i);
		}

		++count;
	}


	r >> i;
	r >> j;
	int test_num = cn;
	std::pair<int,int> result;
	while (i != 0 and j != 0) {
		eval(i, j, test_num, nodes);
		++test_num;
		r >> i;
		r >> j;
		if (i != 0 and j != 0) {
			std::cout << std::endl;
		}

	}

	return test_num;
}

void solve(std::istream& r, std::ostream& w) {

	std::string x;
	int tests;
	int case_num = 1;

	r >> tests;
	while (tests != 0) {

		//removes extra newline
		getline(r, x);

		case_num = read(r,tests, case_num);
		getline(r, x);

		r >> tests;
		if (tests != 0) {
			std::cout << std::endl;
		}
	}

}

int main() {
	using namespace std;
	solve(cin, cout);
	return 0;
}