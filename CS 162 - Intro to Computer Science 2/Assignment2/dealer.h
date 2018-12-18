/*********************************************************************
 ** Program Filename: dealer.h
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This is the header file for dealer.cpp
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "hand.h"
#ifndef DEALER_H
#define DEALER_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class dealer {
	private:
		hand* d_hand;
		int card_total;
	public:
		dealer();
		void setDealerHand(hand* h);
		hand* getDealerHand();
		void printDealerHand();
		void printFullHand();
};
#endif