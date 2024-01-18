#include <iostream>
using namespace std;
#include "letter_count.hpp"



int main(){
	string line;
	int counts[N_CHARS] = {0};
	while (getline(cin, line)){
		count(line, counts);
	}

	print_counts(counts, N_CHARS);
	return 0;
}
