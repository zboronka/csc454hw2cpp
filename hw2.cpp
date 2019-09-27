#include<iostream>

#include "vendingmachine.hpp"

using namespace std;

int main() {
	VendingMachine * vm = new VendingMachine(0, 0, 0, 0, false);
	for(string command; command != "exit"; cin >> command) {
		cout << vm->lambda() << "\n";
		vm->delta(command);
	}

	delete vm;
	return 0;
}
