#ifndef VENDINGMACHINE_HPP
#define VENDINGMACHINE_HPP

#include<string>

using namespace std;

class VendingMachine {
	private:
		int quarters;
		int nickels;
		int dimes;
		int value;
		bool change;

		string getChange(int);
	public:
		VendingMachine(int, int, int, int, bool);
		string lambda();
		void delta(string);
};

#endif
