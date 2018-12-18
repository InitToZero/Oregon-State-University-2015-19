/*********************************************************************
 ** Program Filename: hand.h
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This is the header file for hand.cpp
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "deck.h"
#ifndef HAND_H
#define HAND_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class hand{
	private:
		card** player_cards;
		int num_cards;
	public:
		hand();	//constructor
		void drawCard(deck* d);
		int getNumCards();
		card** getCards();
};
#endif