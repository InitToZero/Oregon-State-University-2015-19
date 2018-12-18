/*********************************************************************
 ** Program Filename: hand.cpp
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This file manages the hands for the players
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "hand.h"
/*********************************************************************
 ** Function: hand
 ** Description: This is the constructor for hand
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: Members exist
 ** Post-Conditions: Initialize members
 *********************************************************************/ 
hand::hand(){
	int num_cards = 0;
	player_cards = new card*[1];
}
/*********************************************************************
 ** Function: drawCard
 ** Description: Draws a card from the deck
 ** Parameters: deck * d
 ** Return: None
 ** Pre-Conditions: Deck pointer to d must exist
 ** Post-Conditions: Card will be drawn and 1 taken from deck
 *********************************************************************/ 
void hand::drawCard(deck* d){
	num_cards++;
	card** c = new card*[num_cards];
	for(int i = 0; i < num_cards-1; i++){
		c[i] = player_cards[i];
	}
	c[num_cards-1] = d->topCard();
	player_cards = c;
}
/*********************************************************************
 ** Function: getNumCards
 ** Description: Gets the number of cards
 ** Parameters: None 
 ** Return: num_cards
 ** Pre-Conditions: Members exist
 ** Post-Conditions: Returns the number of cards
 *********************************************************************/ 
int hand::getNumCards(){
	return num_cards;
}
/*********************************************************************
 ** Function: getCards
 ** Description: Gets all cards
 ** Parameters: None 
 ** Return: player_cards
 ** Pre-Conditions: Members exist
 ** Post-Conditions: Returns each of player_cards
 *********************************************************************/ 
card** hand::getCards(){
	return player_cards;
}