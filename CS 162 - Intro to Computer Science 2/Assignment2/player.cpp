/*********************************************************************
 ** Filename: player.cpp
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This file handles stats about the player, such as bets,
				 total money, and what is in their hand.
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "player.h"
/*********************************************************************
 ** Function: player
 ** Description: This is the constructor for player
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: Player.h calls this constructor
 ** Post-Conditions: Members will be changed
 *********************************************************************/ 
player::player(){
	//Each player gets 100 dollars to start
	money = 100;
	bet = 0;
}
/*********************************************************************
 ** Function: setHand
 ** Description: Sets p_hand to the pointer of h. AKA, makes the hand
 ** Parameters: Pointer to hand
 ** Return: None
 ** Pre-Conditions: hand pointer to h must exist
 ** Post-Conditions: Sets hand
 *********************************************************************/ 
void player::setHand(hand* h){
	p_hand = h;
}
/*********************************************************************
 ** Function: getHand
 ** Description: Allows you to get each player's hand
 ** Parameters: None
 ** Return: player's hand
 ** Pre-Conditions: Gets called 
 ** Post-Conditions: Player hand is returned
 *********************************************************************/ 
hand* player::getHand(){
	return p_hand;
}
/*********************************************************************
 ** Function: addBet
 ** Description: This allows the player to add a bet
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: Gets called
 ** Post-Conditions: Sets bet to player's bet
 *********************************************************************/ 
void player::addBet(){
	int temp = 0;
	cin >> temp;
	if(temp < 0){
		bet = -1;
	}
	else{
		bet = temp;
	}
}
/*********************************************************************
 ** Function: getBet
 ** Description: This fetches the bet
 ** Parameters: None
 ** Return: Bet
 ** Pre-Conditions: Gets called
 ** Post-Conditions: Returns bet 
 *********************************************************************/ 
int player::getBet(){
	return bet;
}
/*********************************************************************
 ** Function: getMoney
 ** Description: This fetches the players money amount
 ** Parameters: None
 ** Return: money
 ** Pre-Conditions: Gets called
 ** Post-Conditions: returns money
 *********************************************************************/ 
int player::getMoney(){
	return money;
}
/*********************************************************************
 ** Function: addMoney
 ** Description: This changes amount of money player has based on winnings (or losses)
 ** Parameters: Income 
 ** Return: None
 ** Pre-Conditions: Income must already be created
 ** Post-Conditions: Money will have been updated for the round
 *********************************************************************/ 
void player::addMoney(int income){
	money += income;
}
/*********************************************************************
 ** Function: printHand
 ** Description: This prints the player's hand
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: All required members exist
 ** Post-Conditions: Hand will be printed to screen
 *********************************************************************/ 
void player::printHand(){
	for(int i = 0; i < p_hand->getNumCards(); i++){
		cout << p_hand->getCards()[i]->getValue();
		cout << " " << p_hand->getCards()[i]->getSuit() << endl;
	}
}
