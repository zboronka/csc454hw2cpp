#include<iostream>

#include "vendingmachine.hpp"

using namespace std;

int main() {
	VendingMachine * vm = new VendingMachine(0, 0, 0, 0, false);

	string command;
	for(cin >> command; command != "exit"; cin >> command) {
		try {
			cout << vm->lambda() << endl;
			vm->delta(command);
		} catch (const char* msg) {
			cerr << msg << endl;
			break;
		}
	}

	delete vm;
	return 0;
}
