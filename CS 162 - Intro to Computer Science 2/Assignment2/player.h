/*********************************************************************
 ** Program Filename: player.h
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This is the header file for player.cpp
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "hand.h"
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class player{
	private:
		hand* p_hand;
		int playing_total;	
		int card_total;	
		int bet;	
		int money;
	public:
		player();
		void setHand(hand* h);
		hand* getHand();
		void addBet();
		int getBet();
		int getMoney();
		void addMoney(int income);
		void printHand();
};
#endif