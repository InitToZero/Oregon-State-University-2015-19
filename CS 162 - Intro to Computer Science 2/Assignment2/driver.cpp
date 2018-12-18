/*********************************************************************
 ** Program Filename: driver.cpp
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This driver file holds the main function for the game	
				 BlackJack. This will call functions to create the game
				 and then proceed to play the game.
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "dealer.h"
#include "game.h"

/*********************************************************************
* Main Function
*********************************************************************/
int main(){
	cout << "\nWelcome to Blackjack" << endl;
	//Sets up new game
	srand(time(0));		
	deck* d = new deck();	
	d->shuffle_deck_play();		
	game* g = new game();
	//Sets up members of game
	g->setDeck(d);
	g->setNumPlayers();
	g->createPlayers();
	g->createDealer();
	//Plays game
	g = g->BlackJack(g);
	
	//Displays player totals
	cout<<endl<<endl;
	for(int x = 0; x < g->getNumPlayers(); x++){
		cout << "Player " << x+1 << " you have: $" << g->getPlayers()[x]->getMoney() << endl << endl;
	}
	g->replay(d, g);
	return 0;
}