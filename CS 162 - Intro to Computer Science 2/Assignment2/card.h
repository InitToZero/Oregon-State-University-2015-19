/*********************************************************************
 ** Program Filename: card.h
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: This is the header file for card.cpp
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

class card{
	private:
		int value;		
		string suit;	
	public:
		card(int v, string s);	
		int getValue();		
		string getSuit();	
};
#endif