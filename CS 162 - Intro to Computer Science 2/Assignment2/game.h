/*********************************************************************
 ** Program Filename: game.h
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This is the header file for game.cpp
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "deck.h"
#include "player.h"
#include "dealer.h"
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class game{
	private:
		deck* cards;
		player** players;
		dealer* game_dealer;
		int num_players;
	public:
		game();
		void setDeck(deck* d);
		deck* getDeck();
		hand* createHand();
		void setNumPlayers();
		int getNumPlayers();
		void createPlayers();
		player** getPlayers();
		void createDealer();
		dealer* getDealer();
		int getScore(hand* h);
		game* BlackJack(game* g);
		void replay(deck* d, game *g);
};
#endif