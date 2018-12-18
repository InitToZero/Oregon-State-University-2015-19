/*********************************************************************
 ** Program Filename: game.cpp
 ** Author: Jonathan Ropp
 ** Date: 4/28/2016
 ** Description: 
 ** Input: None
 ** Output: None
 *********************************************************************/ 
#include "game.h"
/*********************************************************************
 ** Function: game
 ** Description: This is the constructor for game
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: 
 ** Post-Conditions: Initialize members
 *********************************************************************/ 
game::game(){
	//Default constructor
}
/*********************************************************************
 ** Function: setDeck
 ** Description: This sets the deck for the game
 ** Parameters: deck* d
 ** Return: None
 ** Pre-Conditions: Members must exist
 ** Post-Conditions: Deck will have cards
 *********************************************************************/ 
void game::setDeck(deck* d){
	cards = d;
}
/*********************************************************************
 ** Function: getDeck
 ** Description: This gets the deck
 ** Parameters: None 
 ** Return: cards
 ** Pre-Conditions: Members exist
 ** Post-Conditions: cards is being returned
 *********************************************************************/ 
deck* game::getDeck(){
	return cards;
}
/*********************************************************************
 ** Function: createHand
 ** Description: Creates a new hand 
 ** Parameters: None
 ** Return: returns the new hand
 ** Pre-Conditions: Members exist
 ** Post-Conditions: New hand is returned
 *********************************************************************/ 
hand* game::createHand(){
	hand* newHand = new hand();
	newHand->drawCard(cards);
	newHand->drawCard(cards);
	return newHand;
}
/*********************************************************************
 ** Function: setNumPlayers
 ** Description: Sets the number of players
 ** Parameters: None
 ** Return: None
 ** Pre-Conditions: Members exist
 ** Post-Conditions: num_players will have input from user
 *********************************************************************/ 
void game::setNumPlayers(){
	cout << "How many people are going to play? ";
	cin >> num_players;
}
/*********************************************************************
 ** Function: getNumPlayers
 ** Description: Gets the number of players
 ** Parameters: None
 ** Return: num_players
 ** Pre-Conditions: Members exist
 ** Post-Conditions: The number of players is returned
 *********************************************************************/ 
int game::getNumPlayers(){
	return num_players;
}
/*********************************************************************
 ** Function: createPlayers
 ** Description: Creates each player for the game
 ** Parameters: None
 ** Return: None 
 ** Pre-Conditions: Members exist
 ** Post-Conditions: Players will have been created
 *********************************************************************/ 
void game::createPlayers(){
	player** p = new player*[num_players];
	for(int i = 0; i < num_players; i++){
		p[i] = new player();
		p[i]->setHand(createHand());
	}
	players = p;
}
/*********************************************************************
 ** Function: getPlayers
 ** Description: gets the players
 ** Parameters: None
 ** Return: Players
 ** Pre-Conditions: Members exist
 ** Post-Conditions: Players is returned
 *********************************************************************/ 
player** game::getPlayers(){
	return players;
}
/*********************************************************************
 ** Function: createDealer
 ** Description: Creates the dealer for the game
 ** Parameters: None
 ** Return: None 
 ** Pre-Conditions: Members exist
 ** Post-Conditions: Dealer will have been made
 *********************************************************************/ 
void game::createDealer(){
	dealer* d = new dealer();
	d->setDealerHand(createHand());
	game_dealer = d;
}
/*********************************************************************
 ** Function: getDealer
 ** Description: Gets the dealer
 ** Parameters: None
 ** Return: Dealer
 ** Pre-Conditions: Members exist
 ** Post-Conditions: dealer is returned
 *********************************************************************/ 
dealer* game::getDealer(){
	return game_dealer;
}
/*********************************************************************
 ** Function: getScore
 ** Description: gets the score
 ** Parameters: hand* h
 ** Return: value total of hand
 ** Pre-Conditions: parameters and members are good
 ** Post-Conditions: Sum of hand will be returned
 *********************************************************************/ 
int game::getScore(hand* h){
	int sum1 = 0;
	int sum11 = 0;
	int temp = 0;
	for(int i = 0; i < h->getNumCards(); i++){
		temp = h->getCards()[i]->getValue();
		//If a face card, their values are 10
		if(temp == 11 || temp == 12 || temp == 13){
			sum1 += 10;
			sum11 += 10;
		//If an ace, have a value of 1 and 11
		}else if(temp == 1){
			sum1 += 1;
			sum11 += 11;
		//Other cards just get their value
		}else{
			sum1 += temp;
			sum11 += temp;
		}
	}
	//Check to see if high ace make total go over 21
	if(sum11 < 22){
		return sum11;
	}else{
		return sum1;
	}
}
/*********************************************************************
 ** Function: BettingPhase
 ** Description: This asks the user how much they want to bet
 ** Parameters: game* g, int b
 ** Return: None
 ** Pre-Conditions: Parameters and members are good
 ** Post-Conditions: User will have given their bet
 *********************************************************************/ 
void BettingPhase(game* g, int b){
	cout << "Player " << b+1 << " you have: $" << g->getPlayers()[b]->getMoney() << endl;
	cout << "Enter the amount you want to bet or enter -1 to fold: ";
	g->getPlayers()[b]->addBet();
}
/*********************************************************************
 ** Function: DrawingPhase
 ** Description: This function shows player score and asks if they want to hit. 
 **              Also handles scoring.
 ** Parameters: game* g, int b
 ** Return: None
 ** Pre-Conditions: Parameters and members are good
 ** Post-Conditions: The drawing phase will have been completed for one player
 *********************************************************************/ 
void DrawingPhase(game* g, int b){
	while(g->getScore(g->getPlayers()[b]->getHand()) < 22){
		//Prints player hand and their current score
		cout << "Player " << b+1 << "'s hand:" << endl;
		g->getPlayers()[b]->printHand();
		string c = " ";
		cout << endl << "Player " << b+1 << "'s score:" << g->getScore(g->getPlayers()[b]->getHand()) << endl;
		cout << "Do you want to draw another card? Enter 1 for yes and 0 for no: ";
		cin >> c;
		cout << endl;
		if(c == "1"){ //If player wants another card...
			g->getPlayers()[b]->getHand()->drawCard(g->getDeck());
			cout << "Drawn Card: " << g->getPlayers()[b]->getHand()->getCards()[g->getPlayers()[b]->getHand()->getNumCards() - 1]->getValue();
			cout << " " << g->getPlayers()[b]->getHand()->getCards()[g->getPlayers()[b]->getHand()->getNumCards() - 1]->getSuit()<< endl;
			if(g->getScore(g->getPlayers()[b]->getHand()) > 21){ //If player went over, they lose bet
				cout << "New score: " << g->getScore(g->getPlayers()[b]->getHand()) << endl << endl;
				cout << "You went over, you lost your bet." << endl << endl;
			}
			else{ //If not over 21, print score
				cout << "New score: " << g->getScore(g->getPlayers()[b]->getHand()) << endl << endl;
			}
		}
		//If user enters anything other than a '1', return
		else{
			return;
		}
	}
}
/*********************************************************************
 ** Function: DealersPhase
 ** Description: This shows the dealer's hand and score
 ** Parameters: game* g
 ** Return: none
 ** Pre-Conditions: Parameters and members are good
 ** Post-Conditions: Dealer's phase will be done
 *********************************************************************/ 
void DealersPhase(game* g){
	//Print dealer's hand and score
	cout << "Dealer's hand: " << endl;
	g->getDealer()->printFullHand();
	cout << "Dealer's Score: " << g->getScore(g->getDealer()->getDealerHand()) << endl;
	//While dealer's total is under 16, keep drawing cards
	while(g->getScore(g->getDealer()->getDealerHand()) < 16){
		g->getDealer()->getDealerHand()->drawCard(g->getDeck());
	}
	cout << endl << "Dealer's hand: " << endl;
	g->getDealer()->printFullHand();
	cout << "Dealer's Score: " << g->getScore(g->getDealer()->getDealerHand()) << endl;
}
/*********************************************************************
 ** Function: DistributeWinnings
 ** Description: This shows the winnings for each player
 ** Parameters: game* g, int b
 ** Return: None
 ** Pre-Conditions: Parameters and members are good
 ** Post-Conditions: Winnings are shown
 *********************************************************************/ 
void DistributeWinnings(game* g, int b){
    //If player got 21, they get 1.5 times bet
	if(g->getScore(g->getPlayers()[b]->getHand()) == 21){
		cout << "\nPlayer "<<b+1<<" you win: $" << g->getPlayers()[b]->getBet() * 1.5<<endl;
		g->getPlayers()[b]->addMoney(g->getPlayers()[b]->getBet() * 1.5);
	}
	//If under 21, they get just their bet
	else{
		cout << "\nPlayer " <<b+1<<" you win: $" << g->getPlayers()[b]->getBet()<<endl;
		g->getPlayers()[b]->addMoney(g->getPlayers()[b]->getBet());
	}
}
/*********************************************************************
 ** Function: BlackJack
 ** Description: This manages all aspects of the blackjack game
 ** Parameters: game* g
 ** Return: None
 ** Pre-Conditions: Parameters and members are good
 ** Post-Conditions: Game is played
 *********************************************************************/ 
game* game::BlackJack(game* g){
	//Make a betting phase for each player
	for(int b = 0; b < g->getNumPlayers(); b++){
		BettingPhase(g, b);
	}
	//Print dealers first card
	cout << "\nDealer's hand: " << endl;
	g->getDealer()->printDealerHand();
	//Make betting phase for each player
	for(int b = 0; b < g->getNumPlayers(); b++){
		if(g->getPlayers()[b]->getBet() != -1 && g->getPlayers()[b]->getMoney() - g->getPlayers()[b]->getBet() > -1){
			DrawingPhase(g, b);
		}
	}
	//Play dealer's phase
	DealersPhase(g);
	
	for(int b = 0; b < g->getNumPlayers(); b++){
		if(g->getPlayers()[b]->getBet() != -1 && g->getPlayers()[b]->getMoney() - g->getPlayers()[b]->getBet() > -1){
			if(g->getScore(g->getPlayers()[b]->getHand()) < 22){
				//Distribute winnings to player 
				if(g->getScore(g->getDealer()->getDealerHand()) < g->getScore(g->getPlayers()[b]->getHand()) || g->getScore(g->getDealer()->getDealerHand()) > 21){
					DistributeWinnings(g, b);
				//No change because plaeyr matched dealer
				}else if(g->getScore(g->getDealer()->getDealerHand()) == g->getScore(g->getPlayers()[b]->getHand())){		
				//If player didn't bust but still lost
				}else{
					//cout << "Case 3" << endl;
					g->getPlayers()[b]->addMoney(g->getPlayers()[b]->getBet() * -1);
				}
			//If player went bust, lose bet	
			}else{
				g->getPlayers()[b]->addMoney(g->getPlayers()[b]->getBet() * -1);
			}
		}
	}
	return g;
}
/*********************************************************************
 ** Function: replay
 ** Description: The user will be asked if they want to keep playing or not
 ** Parameters: deck* d, game* g
 ** Return: None
 ** Pre-Conditions: Parameters and members are good
 ** Post-Conditions: Gets play again info
 *********************************************************************/ 
void game::replay(deck* d, game *g){
	int play_again;
	cout << "If you want to play again, select 0 to end the game, or 1 to play again" << endl;
	cin >> play_again;
	if(play_again == 0){
		exit(0);
	}else if(play_again == 1){ //Plays another round
		deck* d = new deck();	//Makes a new deck
		d->shuffle_deck_play();	//Shuffles new deck
		g->setDeck(d);
		for(int x = 0; x < g->getNumPlayers(); x++){
			g->getPlayers()[x]->setHand(g->createHand());
		}
		g->getDealer()->setDealerHand(g->createHand());
		g = BlackJack(g);
		for(int x = 0; x < g->getNumPlayers(); x++){
		cout << "Player " << x+1 << " you have: $" << g->getPlayers()[x]->getMoney() << endl << endl;
		}
		replay(d, g);
	}else{
		cout << "Sorry you inputted the wrong integer values that are available." << endl;
		replay(d, g);
	}
}
