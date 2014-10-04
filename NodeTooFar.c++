//includes
#include "NodeTooFar.h"
#include <iostream> // endl, istream, ostream
#include <utility>  // make_pair, pair
#include <sstream>
#include <string>
#include <cassert>
#include <tr1/unordered_set>
#include <tr1/unordered_map>
#include <queue>

void eval(int node, int ttl, int c, std::tr1::unordered_map<int, std::tr1::unordered_set<int> > nodes) {
	typedef std::tr1::unordered_map<int, std::tr1::unordered_set<int> > Nodes;


	std::queue<int> q;
	std::tr1::unordered_set<int> current;

	Nodes::iterator it;
	it = nodes.find(node);
	// std::cout << "Node is " << node << " ";
	// std::cout << it->second.size() << std::endl;
	for (std::tr1::unordered_set<int>::iterator i = it->second.begin(); i != it->second.end(); ++i) {
		// std::cout << *i << " ";
		current.insert(*i);
	}
	// std::cout << std::endl;

	int count = 1;
	while (count < ttl) {
		std::tr1::unordered_set<int> temp = current;
		for (std::tr1::unordered_set<int>::iterator i = temp.begin(); i != temp.end(); ++i) {
			//q.push(*i);
			Nodes::iterator it = nodes.find(*i);
			for (std::tr1::unordered_set<int>::iterator itr = it->second.begin(); itr != it->second.end(); ++itr) {
				current.insert(*itr);
			}

		}
		// std::cout << current.size() << "size" << std::endl;
		// std::cout << "Iteration " << count << ", q has: ";
		while (!q.empty()) {
			// std::cout << q.front() << " ";
			current.insert(q.front());
			q.pop();
		}
		// std::cout << std::endl;


		++count;
	}
	int result = nodes.size() - current.size();
	// std::cout << nodes.size() << " " << current.size() << " result: " << result <<  std::endl;
	print_results(c, std::make_pair(node,result), ttl);

}

void print_results(int c, std::pair<int,int> p, int ttl) {
	std::cout << "Case " << c << ": " << p.second << " nodes not reachable from node "
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


	int count = 0;
	while (count < tests) {
		r >> i;
		r >> j;
		// std::cout << i << " " << j << std::endl;

		it = nodes.find(i);
		if (it == nodes.end()) {
			std::tr1::unordered_set<int> neighbor;
			neighbor.insert(j);
			nodes.insert(Nodes::value_type(i,neighbor));
			// std::cout << i << " first" << std::endl;
		}
		else {
			std::tr1::unordered_set<int> current = it->second;
			it->second.insert(j);
			// std::cout << i << " has ";
			// for(std::tr1::unordered_set<int>::iterator itr = it->second.begin(); itr != it->second.end(); ++itr) {
			// 	std::cout << *itr << " ";
			// }
			// std::cout << std::endl;
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

			it->second.insert(i);
			// std::cout << j << " has ";
			// for(std::tr1::unordered_set<int>::iterator itr = it->second.begin(); itr != it->second.end(); ++itr) {
			// 	std::cout << *itr << " ";
			// }
			// std::cout << std::endl;
			// std::cout << it->first << " next" << std::endl;

		}

		// r >> i;
		// r >> j;
		++count;

	}


	r >> i;
	r >> j;
	int test_num = 1;
	while (i != 0 and j != 0) {
		// std::cout << i << " " << j << std::endl;

		eval(i, j, test_num, nodes);
		++test_num;
		r >> i;
		r >> j;
	}

	//remove newline
	// getline(r,x);

	// r >> tests;
	// getline(r,x);

	// r >> i;
	// r >> j;
	// int count = 0;
	// while (i != 0 and j != 0) {


	// 	r >> i;
	// 	r >> j;
	// }


}

int main() {
	using namespace std;
	solve(cin, cout);
	return 0;
}