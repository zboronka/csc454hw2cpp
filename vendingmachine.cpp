#include "vendingmachine.hpp"

VendingMachine::VendingMachine(int q, int d, int n, int v, bool c) {
	quarters = q;
	dimes = d;
	nickels = n;
	value = v;
	change = c;
}

string VendingMachine::lambda() {
	string ret = "";

	if(change) {
		ret += getChange(value % 100);
		ret += " ";
	}

	for(int i = 0; i < value / 100; i++) {
		ret += "coffee ";
	}

	if(ret.compare("") == 0) {
		ret = "nothing";
	}

	return ret;
}

void VendingMachine::delta(string input) {
	value = value % 100;
	if(change) {
		string changeString = getChange(value);
		for (auto c = changeString.begin(); c < changeString.end(); c++) {
			if(*c == 'q') {
				quarters--;
				value -= 25;
			}
			else if(*c == 'd') {
				dimes--;
				value -= 10;
			}
			else if(*c == 'n') {
				nickels--;
				value -= 5;
			}
		}
	}

	change = false;

	int q = 0;
	int d = 0;
	int n = 0;

	for (auto c = input.begin(); c < input.end(); c++) {
		if(*c == 'q') {
			quarters++;
			value += 25;
		}
		else if(*c == 'd') {
			dimes++;
			value += 10;
		}
		else if(*c == 'n') {
			nickels++;
			value += 5;
		}
	}
}

string VendingMachine::getChange(int v) {
	string ret = "";

	int q = v / 25 > quarters ? quarters : v / 25;
	int d = (v-q*25) / 10 > dimes ? dimes : (v-q*25) / 10;
	int n = ((v-q*25)-d*10) / 5 > nickels ? nickels : ((v-q*25)-d*10) / 5;

	if(q*25 + d*10 + n*5 != v) {
		return "Not enough change in machine";
	}

	for(int i = 0; i < q; i++) {
		ret += "q";
	}
	for(int i = 0; i < d; i++) {
		ret += "d";
	}
	for(int i = 0; i < n; i++) {
		ret += "n";
	}

	return ret;
}
