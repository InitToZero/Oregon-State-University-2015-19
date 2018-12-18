/*********************************************************************
 ** Program Filename: deck.cpp
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This file creates and makes changes to the deck
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "deck.h"
/*********************************************************************
 ** Function: deck
 ** Description: Constructor for deck that dynamically allocates memory
				 for the cards
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: Members are good
 ** Post-Conditions: Members are initialized
 *********************************************************************/ 
deck::deck(){		
	num_cards = 0;
	for(int s = 0; s < 4; s++){
		for(int n = 1; n < 14; n++){
			if(s == 0){
				cards[num_cards] = new card(n, "Spades");
			}else if(s == 1){
				cards[num_cards] = new card(n, "Clubs");
			}else if(s == 2){
				cards[num_cards] = new card(n, "Hearts");
			}else{
				cards[num_cards] = new card(n, "Diamonds");
			}
			num_cards++;
		}
	}
}
/*********************************************************************
 ** Function: shuffle_deck_play
 ** Description: Shuffles the deck of cards
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: Members are good
 ** Post-Conditions: Deck will be shuffled
 *********************************************************************/ 
void deck::shuffle_deck_play(){	//mutator for deck using card cards[52]
	int x, y;
	num_cards = 52;
	card *temp;
	for(int z = 0; z < 100; z++){	
		x = rand() % 52;	//picks two random numbers
		y = rand() % 52;
		temp = cards[x];	//switches the two cards
		cards[x] = cards[y];
		cards[y] = temp;
	}
}
/*********************************************************************
 ** Function: topCard
 ** Description: Removes top card from the deck
 ** Parameters: None
 ** Return: cards
 ** Pre-Conditions: Members are good
 ** Post-Conditions: Returns a new size of cards
 *********************************************************************/ 
card* deck::topCard(){
	num_cards--;
	return cards[num_cards];
}
