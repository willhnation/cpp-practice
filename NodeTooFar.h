#ifndef NodeTooFar_h
#define NodeTooFar_H

//includes
#include <iostream>
#include <vector>

struct Node {
	int num; //node number
	std::vector<int> neighbors; //nodes connected
};


/*
 * @params c is the case number
 * @param the node and the number of nodes that can't be reached
 * @param ttl the Time To Live number
 * @param w an std::ostream
*/
void print_results (int c, std::pair<int,int> p, int ttl);

/*
 * @param r an std::istream
 * @param w an std::ostream
 */
void solve (std::istream& r, std::ostream& w);

#endif

