/*********************************************************************
 ** Program Filename: deck.h
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This is the header file for deck.cpp
 ** Input: None
 ** Output:None
 *********************************************************************/ 
#include "card.h"
#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class deck{
	private:
		card* cards[52];
		int num_cards;
	public:
		deck();
		void shuffle_deck_play();
		card* topCard();
};
#endif