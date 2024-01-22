#include "coins.hpp"
#include <iostream>
using namespace std;

Coins::Coins(int q, int d, int n, int p)
		:quarters(q), dimes(d), nickels(n), pennies(p) {
}

void deposit_coins(Coins& coins){
	quarters += coins.quarters;
	dimes += coins.dimes;
	nickels += coins.nickels;
	pennies += coins.pennies;
	coins.quarters = 0;
	coins.dimes = 0;
	coins.nickels = 0;
	coins.pennies = 0;
}

bool has_exact_change_for_coins(const Coins&coins) const{
	return (quarters >= coins.quarters && dimes >= coins.dimes && nickels >= coins.nickels && pennies >= coins.pennies);
}

