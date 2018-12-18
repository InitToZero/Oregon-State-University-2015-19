/*********************************************************************
 ** Program Filename: dealer.cpp
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This file manages and prints the dealer's cards 
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "dealer.h"
/*********************************************************************
 ** Function: dealer
 ** Description: Constructor for dealer
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: None
 ** Post-Conditions: Members will be initialized
 *********************************************************************/ 
dealer :: dealer(){
	//Default constructor
}
/*********************************************************************
 ** Function: setDealerHand
 ** Description: This function sets the d_hand equal to the hand
 ** Parameters: hand* h
 ** Return: None
 ** Pre-Conditions: Parameters and members are good
 ** Post-Conditions: d_hand will be equal to hand
 *********************************************************************/ 
void dealer::setDealerHand(hand* h){
	d_hand = h;
}
/*********************************************************************
 ** Function: getDealerHand
 ** Description: This function accesses d_hand
 ** Parameters: None
 ** Return: h_hand
 ** Pre-Conditions: Members are good
 ** Post-Conditions: d_hand will be returned
 *********************************************************************/ 
hand* dealer::getDealerHand(){
	return d_hand;
}
/*********************************************************************
 ** Function: printDealerHand
 ** Description: Prints the dealer's first card
 ** Parameters: None 
 ** Return: None 
 ** Pre-Conditions: Members are good
 ** Post-Conditions: Dealer hand will be printed to screen
 *********************************************************************/ 
void dealer::printDealerHand(){
	cout << d_hand->getCards()[0]->getValue();
	cout << " of " << d_hand->getCards()[0]->getSuit() << endl << endl;
}
/*********************************************************************
 ** Function: printFullHand
 ** Description: Prints the dealer's full hand
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: Members are good 
 ** Post-Conditions: 
 *********************************************************************/ 
void dealer::printFullHand(){
	for(int i = 0; i < d_hand->getNumCards(); i++){
		cout << d_hand->getCards()[i]->getValue();
		cout << " " << d_hand->getCards()[i]->getSuit() << endl;
	}
}