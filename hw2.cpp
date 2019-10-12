#include<iostream>

#include "vendingmachine.hpp"

using namespace std;

string line(string, int);

int main() {
	VendingMachine * vm = new VendingMachine(0, 0, 0, 0, false);

	cout << "\u001b[1;32mv\u001b[1;33me\u001b[1;34mn\u001b[1;35md\u001b[1;36m$\u001b[0;39;49m ";
	string command;
	for(cin >> command; command != "exit"; cin >> command) {
		try {
			string lambda = vm->lambda();
			int length = lambda.size();

			cout << "\u001b[1;38;5;200m╭" << line("─", length-(24*(length/24))) << "╮" << endl;
			cout << "│" << lambda << "\u001b[1;38;5;200m│" << endl;
			cout << "╰"	<< line("─", length-(24*(length/24))) << "╯\u001b[0;39;49m" << endl;

			vm->delta(command);
		} catch (const char* msg) {
			cerr << msg << endl;
			break;
		}

		cout << "\u001b[1;32mv\u001b[1;33me\u001b[1;34mn\u001b[1;35md\u001b[1;36m$\u001b[0;39;49m ";
	}

	delete vm;
	return 0;
}

string line(string c, int width) {
	string ret = "";
	for(int i = 0; i < width; i++) {
		ret += c;
	}
	
	return ret;
}
