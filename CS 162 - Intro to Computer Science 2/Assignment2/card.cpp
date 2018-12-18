/*********************************************************************
 ** Program Filename: card.cpp
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: The card class holds the value and the suit for each card
	             that the game blackjack will use.
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "card.h" 
/*********************************************************************
 ** Function: card
 ** Description: This is the constructor for a card
 ** Parameters: int v, string s
 ** Return: None
 ** Pre-Conditions: Parameters and members are good
 ** Post-Conditions: Members will be initialized
 *********************************************************************/ 
card::card(int v, string s){		
	//Sets value and suit for the constructed card
	value = v;
	suit = s;
}
/*********************************************************************
 ** Function: getValue
 ** Description: This function gets the value of a card
 ** Parameters: None 
 ** Return: value
 ** Pre-Conditions: Members are good
 ** Post-Conditions: Value is returned
 *********************************************************************/ 
int card::getValue(){
	return value;
}
/*********************************************************************
 ** Function: getSuit
 ** Description: This function gets the suit of a card
 ** Parameters: None 
 ** Return: suit
 ** Pre-Conditions: Members are good
 ** Post-Conditions: Suit is returned
 *********************************************************************/ 
string card::getSuit(){
	return suit;
}
