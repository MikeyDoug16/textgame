#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "string.h"
#include "game.h"
#include <fstream>
using namespace std;

/* BEIGN DEFINED CONSTANTS */

#define GBSZ 64
#define AMMO 5
#define FOOD_HEALTH 5
#define MAXBUFSZ 64

/* END DEFINED CONSTANTS*/

/* BEGIN GAME VARIABLES */

int PX = 32; //starting X
int PY = 14;//starting Y
int game_over=0;//is the game over? 0 is no, 1 is yes
int ammo = 0;//ammo the Player has
int health =100;//health for the player
int gun=0;//does the player have a gun? 0 if no, 1 if yes
int food=0;// how much food does the player have?
int L_key=0;//player have the key for the L door? 0 if no, 1 if yes
int B_key=0;//player have the key for the B box? 0 if no, 1 if yes
int H_key=0;//player have the Helicopter Key? 0 if no, 1 if yes
char prev_tile='.';//what was the tile the player was previously on?

string gs[64];//the gameboard, 64 total strings, each string is 64 chars so 64x64
string Wall_Lines[3];//array of strings for when player hits wall
string Tree_Lines[2];//array of strings for when the player hits a tree
string Rock_Lines[3];//array of strings for when player hit a rock

/* END GAME VARIABLES */

//init the game map
void init_game(int * saved)
{
	cout<<"Initializing Game..."<<endl;
	string s = "................................................................";
	string s2 ="......wwwww.....................................................";
	string s3 ="...wwww...ww......T...................................TTT.......";
	string s4 ="...wwwwww..www........................................TNT.......";
	string s5 ="....wwwww........T...........WWWWWWWWWWWWWW...........T.T.......";
	string s6 ="..wwwwww.....................W.F.....E....W.....................";
	string s7 =".....www..........T..........W...........EW.....................";
	string s8 ="..............T..............W.......WWWWWW.....................";
	string s9 =".............................D.......W....W.....................";
	string s10="..................T..........W.......L...BW.....................";
	string s11="...WWWW......................W.....G.W....W.....................";
	string s12="...WAGW......................WWWWWWWWWWWWWW..........TT...TT....";
	string s13="...WA.W...........................................TT.TT.F.......";
	string s14="...WA.D..............ww...........................TT....TT.TT...";
	string s15="...WWWW................wwwww.........................TT.........";
	string s16=".........................www....................TT...TT...TT....";
	string s17=".......................ww.......................TT..A...TF...T..";
	string s18=".....TT..T..TT.....................................TT......T....";
	string s19="................................................T..TT..TT.......";
	string s20="....TT.TT..TT..TT...............................................";
	string s21=".................T..................WWWWWWWWWWWW...TT...........";
	string s22=".....TT..TT..T......................W.E........W...TT...........";
	string s23="..........s...TT................TT..W.......S..W................";
	string s24="....TT..TT.......TT.................W....E.....WWWWWWWWW........";
	string s25="............TT...TT...T.............W..S.....S.W...A...W........";
	string s26="....TT.TT...TT......................W......E...W.A...A.W..T.....";
	string s27=".w.........T...T.................T..W..E.......W.......W...T....";
	string s28="..w..TTTTT.......T..................W..........WWWDDWWWW........";
	string s29=".ww.........TT......................W......A...........W.TT.....";
	string s30="....................................D..............S...W........";
	string s31="..........................T.........W....A...........S.WWWWW....";
	string s32="................T...................WWWWWWW........S..S....W....";
	string s33="..............P......T..............W..F..W.S..............W....";
	string s34="....................................W..F..D.............A..W....";
	string s35="....................................WWWWWWWWWWWWWWWWWWWWWWWW....";
	string s36="..........................T.....................................";
	string s37=".........WWWWWWWWWWW............................................";
	string s38=".........W.........W......................RR....................";
	string s39=".........W....E..A.W................................TTT.........";
	string s40=".........W.........W................................TTTC........";
	string s41=".........W....TT...WWWWWWWWWWWWWWWW......T..........TTT.........";
	string s42=".........W....TT.....dd...W..S..F.W.............................";
	string s43=".........W................D.....F.W.............................";
	string s44=".........W................D.....F.W...........R......RRR........";
	string s45=".........D..........FFA...W.....FAW.............................";
	string s46=".........WWWWDWWWWWWWWWWWWWWWwWWWWW...............R.............";
	string s47=".........W........W.............................................";
	string s48=".........W..A...F.W.............................................";
	string s49=".........W.....AF.W.............................................";
	string s50=".........WWWWWWWWWW.................T........T..TT..............";
	string s51="......................................T...TTT......T..TTTT......";
	string s52=".WWWW.............................T..TT.T......TTT.T...T.T......";
	string s53=".W..D................S...............TT....TT......T...T........";
	string s54=".WA.W.............................T.....TT....TTK....T..........";
	string s55=".WWWW.................................T....T...T.TT....T........";
	string s56="....................S..............TT...TT...T...T...T..TT......";
	string s57="...................................TT...TTA.T...T...TT..........";
	string s58=".......TTTTTTTTTT.....................R.........................";
	string s59=".......T........T................TT...TT........................";
	string s60=".......T.S...S...............................WWWW.....WWWW......";
	string s61=".......T..HH....T............................WE.D.....D..W......";
	string s62=".......T..HH....T............................W..W.....W.FW......";
	string s63=".......TTTTTTTTTT............................WWWW.....WWWW......";
	string s64="................................................................";
	gs[0]=s,gs[1]=s2,gs[2]=s3,gs[3]=s4,gs[4]=s5,gs[5]=s6,gs[6]=s7,gs[7]=s8;
	gs[8]=s9,gs[9]=s10,gs[10]=s11,gs[11]=s12,gs[12]=s13,gs[13]=s14,gs[14]=s15,gs[15]=s16;
	gs[16]=s17,gs[17]=s18,gs[18]=s19,gs[19]=s20,gs[20]=s21,gs[21]=s22,gs[22]=s23,gs[23]=s24;
	gs[24]=s25,gs[25]=s26,gs[26]=s27,gs[27]=s28,gs[28]=s29,gs[29]=s30,gs[30]=s31,gs[31]=s32;
	gs[32]=s33,gs[33]=s34,gs[34]=s35,gs[35]=s36,gs[36]=s37,gs[37]=s38,gs[38]=s39,gs[39]=s40;
	gs[40]=s41,gs[41]=s42,gs[42]=s43,gs[43]=s44,gs[44]=s45,gs[45]=s46,gs[46]=s47,gs[47]=s48;
	gs[48]=s49,gs[49]=s50,gs[50]=s51,gs[51]=s52,gs[52]=s53,gs[53]=s54,gs[54]=s55,gs[55]=s56;
	gs[56]=s57,gs[57]=s58,gs[58]=s59,gs[59]=s60,gs[60]=s61,gs[61]=s62,gs[62]=s63,gs[63]=s64;
	cout<<"Creating Landscape..."<<endl;
	string wL0="There is a building wall in the way. Maybe there is a way into the building.";
	string wL1="A building wall is blocking the way. Is there a way in?";
	string wL2="With this building wall in the way, you'll have to find a way in or around.";
	Wall_Lines[0] = wL0;
	Wall_Lines[1] = wL1;
	Wall_Lines[2] = wL2;
	string tL0="A tree is blocking the way. You have to go around it.";
	string tL1="There is a tree and you must go around it";
	Tree_Lines[0] = tL0;
	Tree_Lines[1] = tL1;
	string rL0 ="A rock is in the way, you must go around it to get by it.";
	string rL1 ="A boulder stands in the direction you want to go. You have to get around it.";
	string rL2 ="With this rock in the way you wont be able to go this direction, you'll have to go around.";
	Rock_Lines[0] = rL0;
	Rock_Lines[1] = rL1;
	Rock_Lines[2] = rL2;
	cout<<"Constructing Houses..."<<endl;
	cout<<"Hiding Bodies and Evidence..."<<endl<<endl;
	
	cout<<"Checking for any saved games"<<endl;
	int save_check = check_for_save();
	int prompt_fail=0;
	if(save_check ==1)
	{
		while(prompt_fail == 0)
			prompt_fail = prompt_for_load(saved);
	}
	else
		cout<<"Checking for saves complete, there are no saved games available."<<endl;
	
	cout<<"Ready..."<<endl;

}


//first prompt the user to say whether they want to load the game or not
//if they do want to load it, do so, checker set to 1, breaks out of loop, loads game and returns 1 to signify it loaded the game or attempted to
//it will attempt to load it three times, if they all fail the game will be started fresh
//if they dont say they will have a new game loaded and return 1 
//else return 0 for them not putting y or n to reprompt them
int prompt_for_load(int * saved)
{
	char input;
	int checker= -1, counter =0;
	cout<<"Upon checking for saved games we found one!"<<endl;
	cout<<"Would you like to load this saved game? y or Y/n or N:";
	cin >> input;
	cin.clear();
	cin.ignore();
	switch(input)
	{
		case 'y':
		case 'Y':
			while(checker == -1)
			{
				checker = load_game(counter);
				++counter;
				if(counter == 3)
				{
					cout<<"Error: could not load the game. Will start a new game for you"<<endl; 
					break;
				}
			}
			if(counter <3)
				*saved = 1;
			return 1;
		case 'n':
		case 'N':
			cout<<"You chose not to load the game, you will have the game start at the beginning"<<endl;
			delete_file_contents();
			return 1;
		default:
			cout<<"Invalid input, use y or Y for yes and n or N for no on whether to load the saved game or not"<<endl;
			return 0;
	}
}

//delete the contents of the file if the uer chooses to not load their last saved data as they want to start a new one.
void delete_file_contents(void)
{
	ofstream out("Saved.data", ios::trunc);
	if(out.is_open())
	{
		out.close();
	}	
}


//try and load the game from the saved data file, if if does load it then set all the values of the game to the loaded ones, return 1 for success
//if it doesnt work tell them you will try again to load it so long as it isnt the third try; if it is the third try tell them max attempts tried to load
int load_game(int count)
{
	ifstream in("Saved.data");
	if(in.is_open() && in.peek() != std::ifstream::traits_type::eof())
	{
			cout<<"\n\nLoading game..."<<endl;
			for(int i=0; i<GBSZ; ++i)
				in>>gs[i];
			in >> ammo;
			in >> health;
			in >> PX;
			in >> PY;
			in >> food;
			in >> gun;
			in >> prev_tile;
			in >> B_key;
			in >> L_key;
			in >> H_key;				
			cout<<"Load complete"<<endl;
			in.close();
			return 1;
	}
	else
	{
		if(count < 2)
			cout<<"Error Loading game, Will try again to load game state"<<endl;
		else
			cout<<"Error Loading game. Max attempts tried to load game"<<endl; 
		in.close();
		return -1;
	}
		
}

//check if there is a save that is available. if there is nothing in the saved file return 1, there is nothing to load
//if the game over flag marked as 1 then there is a save available but the game is over return 2
//if there is something and the game over flag isnt 1 yet then return 1 there is an available game to save. 
int check_for_save(void)
{
//	game_state *g;	
	ifstream in("Saved.data");
	if(in.is_open() && in.peek() != std::ifstream::traits_type::eof())
	{
		in.close();
		return 1;
	}
	in.close();
	return 0; 
	
}


//print out the game state, mainly for debugging and checking if everything runs smoothly
void print_game_state(string game_board[])
{
	for(int i=0; i< GBSZ; ++i)
		cout<< game_board[i]<<endl;
	cout<<endl<<endl;
}

//print the opening monologue as well as some instructions for the game
void print_opening_info(void)
{
	cout<<endl;
    cout<<endl;
    cout<<"You have woken up in a strange small town. It is incredibly dark out."<<endl;
	cout<<"There are massive walls enclosing it and even in the darkness you can tell the incredibly size of the wall."<<endl;
    cout<<"There are no ways to climb it, go under it, or go through. Nothing in or out it seems..."<<endl;
	cout<<"You must find a way out!"<<endl;
    cout<<"Search for clues, be wary of danger, and good luck"<<endl;
	cout<<"     N     "<<endl;
	cout<<"\nW         E"<<endl;
	cout<<"\n     S     "<<endl;
	cout<<"North = \"Up\", East =\"Right\", W = \"Left\", S = \"Down\""<<endl;
	cout<<"Other Commands include: \nSave (You can save your progress)\n Quit (Quit the game, unsaved progress will be lost)\n";
	cout<<"Print (Print the game board, without where you are)"<<endl;
	cout<<endl;
	cout<<endl;	
	cout<<"To the North you see what looks like some woods."<<endl;
	cout<<"To the South you see what looks to be the beginnings of a home"<<endl;
	cout<<endl;
}

//print the opening info but if they are opening a loaded game from before, so tell them their ammo, health, food and if they have a gun or not
void print_opening_saved_info(void)
{
	cout<<endl;
	cout<<endl;
	cout<<"You have woken up in a strange small town. It is incredibly dark out."<<endl;
	cout<<"There are massive walls enclosing it and even in the darkness you can tell the incredibly size of the wall."<<endl;
    cout<<"There are no ways to climb it, go under it, or go through. Nothing in or out it seems..."<<endl;
    cout<<"You must find a way out!"<<endl;
    cout<<"Search for clues, be wary of danger, and good luck"<<endl;
    cout<<"     N     "<<endl;
    cout<<"\nW         E"<<endl;
    cout<<"\n     S     "<<endl;
    cout<<"North = \"Up\", East =\"Right\", W = \"Left\", S = \"Down\""<<endl;
	cout<<"Other Commands include: \nSave (You can save your progress)\n Quit (Quit the game, unsaved progress will be lost)\n";
    cout<<"Print (Print the game board, without where you are)"<<endl;
    cout<<endl;
    cout<<endl;
	cout<<"The Load of you saved game was completed..."<<endl;
	cout<<"You have "<< ammo<<" ammo, "<<health<<" health "<<food<<" food ";
	if(gun)
		cout<< "and a gun.\n Good Luck!"<<endl;
	else
		cout<< "\nGood Luck!"<<endl;
    cout<<endl;
}


//get the player move 
void get_move(char * buf)
{
	cout<<"\nYour Move: ";
	cin.getline(buf,MAXBUFSZ);
}

/*CHECKER FUNCTIONS*/

//get the player move, check if it is in bounds, if it is return 0, if it is out of bounds return -2, if it
//is not one of the four move types then return -1
int check_move(char * buf)
{
	if(strcmp(buf, "Up") ==0)
	{
		if(PX == 0)
			return -2;
		return 0;	
	}
	else if(strcmp(buf,"Down") == 0)
	{
		if(PX == 63)
			return -2;
		return 0;
	}
	else if(strcmp(buf, "Right") == 0)
	{
		if(PY == 63)
			return -2;
		return 0;
	}
	else if(strcmp(buf,"Left") == 0)
	{
		if(PY == 0)
			return -2;
		return 0;
	}
	else if(strcmp(buf,"Save") ==0)
		return 0;
	else if(strcmp(buf,"Quit")==0)
		return 0;
	else if(strcmp(buf,"Print") == 0)
		return 0;
	else
		return -1;

}


//checker for walls on the Up move, 1 if there is a wall, 0 if there is no wall
//if there is a wall print out one of the three random lines.
int wall_checker_up(void)
{
	if(gs[PX-1][PY] == 'W')
	{
		srand(time(nullptr));
		int r = rand();
		cout<< Wall_Lines[r%3]<<endl;
		return 1;
	}
	return 0;

}

//Checks for wall on the down move, 1 if there is a wall, 0 if there is not a wall
//print a wall line if there is a wall in the way
int wall_checker_down(void)
{
	if(gs[PX+1][PY] == 'W')
	{
		srand(time(nullptr));
		int r = rand();
		cout<<Wall_Lines[r%3] <<endl;
		return 1;
	}
	return 0;
}

//Checks for a wall on a left move, 1 if there is a wall, 0 if there is not wall
//print a wall line if there is a wall in the way
int wall_checker_left(void)
{
	if(gs[PX][PY-1] == 'W')
	{
		srand(time(nullptr));
		int r = rand();
		cout<< Wall_Lines[r%3]<<endl;
		return 1;
	}
	return 0;
}

//checks to see if there is a wall in the way of the right move
int wall_checker_right(void)
{
	if(gs[PX][PX+1] == 'W')
	{
		srand(time(nullptr));
		int r = rand();
		cout<< Wall_Lines[r%3] << endl;
		return 1;
	}
	return 0;
}


//checker for trees on the up move, 1 if there is a tree, 0 if there is no tree
//if there is a tree then print out one of random 2 lines.
int tree_checker_up(void)
{
	if(gs[PX-1][PY] == 'T')
	{
		srand(time(nullptr));
		int r = rand();
		cout<< Tree_Lines[r%2]<<endl;
		return 1;
	}
	return 0;

}

//checker for tree on the down move, 1 if there is a tree, 0 if there is not 
//If a tree is in the way print one of two lines for the tree randomly
int tree_checker_down(void)
{
	if(gs[PX+1][PY] == 'T')
	{
		srand(time(nullptr));
		int r = rand();
		cout<< Tree_Lines[r%2] <<endl;
		return 1;
	}
	return 0;
}

//checks to see if tree is in the way for a left move, 1 if yes, 0 if no
//if a tree is in the way print one of the two lines for tree
int tree_checker_left(void)
{
	if(gs[PX][PY-1] == 'T')
	{
		srand(time(nullptr));
		int r = rand();
		cout<< Tree_Lines[r%2]<<endl;
		return 1;
	}
	return 0;
}

//checks to see if tree is in the way of right move, 1 if yes, 0 if no
//if a tree is in the way print one of two for tree
int tree_checker_right(void)
{
	if(gs[PX][PY+1] == 'T')
	{
		srand(time(nullptr));
		int r = rand();
		cout<< Tree_Lines[r%2] << endl;
		return 1;
	}
	return 0;
}

//checker for rocks on the up move, 1 if there is a rock, 0 if there is no rock
//if there is a rock, print one of three random lines.
int rock_checker_up(void)
{
	if(gs[PX-1][PY] == 'R')
	{
		srand(time(nullptr));
		int r = rand();
		cout<<Rock_Lines[r%3]<<endl;
		return 1;
	}
	return 0;
}

//checker for rocks on the down move, 1 if there is a rock and 0 if there is not a rock
//if there is a rock print out one of the 3 random rock lines
int rock_checker_down(void)
{
	if(gs[PX+1][PY] == 'R')
	{
		srand(time(nullptr));
		int r = rand();
		cout<<Rock_Lines[r%3]<<endl;
		return 1;
	}
	return 0;
}

//check if there is a rock in the way of the left move, return 1 if yes 0 if no
//if yes then print one of three random lines in the rock lines
int rock_checker_left(void)
{
	if(gs[PX][PY-1] == 'R')
	{
		srand(time(nullptr));
		int r = rand();
		cout<<Rock_Lines[r%3]<<endl;
		return 1;
	}
	return 0;
}


//check if there is a rock in the way of the right move, return 1 if yes 0 if no
//if yes then print one of three random lines in the rock lines
int rock_checker_right(void)
{
	if(gs[PX][PY+1] == 'R')
	{	
		srand(time(nullptr));
		int r = rand();
		cout<< Rock_Lines[r%3]<<endl;
		return 1;
	}
	return 0;
}

//check if there is a wall in the way of the move, 1 if yes, 0 if not
//Will call wall_checker_X where x is the direction player wants to go
int wall_checker(char move)
{
	switch(move)
	{
		case 'U':
			return wall_checker_up();
		case 'D':
			return wall_checker_down();
		case 'L':
			return wall_checker_left();
		case 'R':
			return wall_checker_right();
	}

}
//check if there is a tree in the way of the move, 1 if yes, 0 if not
//will call tree_checker_X where x is the direction the player wants to go
int tree_checker(char move)
{
	switch(move)
	{
		case 'U':
			return tree_checker_up();
		case 'D':
			return tree_checker_down();
		case 'L':
			return tree_checker_left();
		case 'R':
		return tree_checker_right();
	}	
}

//check if there is a rock in the way of the move, 1 if yes, 0 if not
//will call rock_checker_X where x is the direction the player wants to go
int rock_checker(char move)
{
	switch(move)
	{
		case 'U':
			return rock_checker_up();
		case 'D':
			return rock_checker_down();
		case 'L':
			return rock_checker_left();
		case 'R':
			return rock_checker_right();
	}
}

/* END CHECKER FUNCTIONS*/

/* HANDLE EVENTS (ammo,snakes,food, etc)*/

//handle ammo by giving them 5 ammo and tell them they got that 5 ammo
void handle_ammo(char * move)
{
			ammo += AMMO;
				cout<<"You moved "<<move<<" and you found five rounds of ammunition on the ground! You now have "<< ammo <<" rounds of ammo."<<endl;
}

//handle food by giving them 1 food if they are 100 hp or if they arent replenish 5 HP
void handle_food(char * move)
{
	if(health != 100)
	{
		health+=FOOD_HEALTH;
		if(health >100)
			health=100;
		cout<<"\nYou moved "<<move<<" and you found a piece of food and you regained health from it, you are now at "<<health<<" health"<<endl;
	}
	else
	{
		food+=1;
		cout<<"\nYou moved "<<move<<"and you found a piece of food but you are 100 health, so you keep it. Next time you take damage it will be applied"<<endl;
		cout<<"You now have "<< food<<" food"<<endl;
	}
}

//handle gun, give them the gun, update gun to 1, tell them they picked it up with 0 ammo
void handle_gun(char * move)
{
	if(gun)
	{
		cout<<"\nYou moved "<<move<<" and you found a gun. You already have one though so you put it back down on the ground"<<endl;
		cout<<"You have "<<ammo<<" ammo for the gun you already have"<<endl;
	}
	else
	{
		gun =1;
		cout<<"\nYou moved "<<move<<" and you found a gun. You will be able to defend yourself from enemies"<<endl;
		cout<<"You have "<<ammo<<" ammo"<<endl;
	}
}

//handle the B box event, if you have the key then open the box, if you dont then give the prompt that they have to find it
void handle_B_box(char * move)
{
	if(B_key)
	{
		cout<<"\nYou found a box while trying to move "<<move<<". You have the key to the box."<<endl;
		cout<<"You open it. There seems to be Keys with \"Helicopter\" etched into them. You keep them,"<<endl;
		cout<<"knowing now how you will escape"<<endl;
		H_key=1;
	}
	else
	{
		cout<<"\nYou found a box while trying to move "<<move<<". There is something in it but it seems to be locked."<<endl;
	}	
}

//handle the Empty box event, and tell the player the box was empty
void handle_E_box(char * move)
{
	cout<<"\nYou found a box while trying to move "<<move<<". However it was empty."<<endl;
}

//handle the event where the player finds the corpse, tell them about the note on the body and the uniform
void handle_corpse(char * move)
{
	cout<<"\nYou were moving "<<move<<" and you found a corpse on the ground blocking the way."<<endl;
	cout<<"You Search the body, noticing the decorated military uniform the body has on."<<endl;
	cout<<"There is a note on the body as well, it says: "<<endl;
	cout<<"\"To anyone who reads this, I dropped the keys to my bird among one of the town woods. They stole my gun as well. This is it for me...\""<<endl; 
}

//handle the sign event where the player comes across the sign in the woods, display the note
void handle_sign(char * move)
{
	cout<<"\nWhile moving "<<move<<" you found a sign there and move to read it"<<endl;
	cout<<"\"In Western Woods, South: Filmore Manor, East: Reptile Research Lab, North: Small Gunshop, NorthEast: Haunted House of General Hilsbury\""<<endl;
}

//handle event where the player finds the note on the ground, display it
void handle_note(char * move)
{
	cout<<"\nYou moved "<< move<<" and you found a note on the ground"<<endl;
	cout<<"It reads:"<<endl;
	cout<<"\"The haunting is what you seek, Be wary of cold blood, The Filmores always unlock the meanings of things.\""<<endl;
	cout<<"You put it away wondering what exactly it could mean"<<endl;
}

//handle the event where the player finds the dresser. If they have previously been to the dresser tell them they have
//if they havent tell them they discovered it, searched the dresser then update the L_key value
void handle_dresser(char * move)
{
	if(L_key)
	{
		cout<<"\nYou moved "<<move<<" and you have found a dresser"<<endl;
		cout<<"You have already searched this dresser"<<endl;
	}
	else
	{
		cout<<"\nYou moved "<<move<<" and you found a dresser"<<endl;
		cout<<"You search the dresser and find a door key inside"<<endl;
		cout<<"Where does this key go to?"<<endl;
		L_key=1;
	}
}

//handle the health regen from the food in the snake function
void handle_snake_health(void)
{
	while(health < 100 && food > 0)
	{
		health += FOOD_HEALTH;
		--food;
	}
	if(health > 100)
		health = 100;
	if(health < 0)
		health=0;
}

//Handle if the user runs into a snake, if they ahve a gun check if they have any ammo
//if they do fight the snake with a gun, use 1-5 ammo, and lose 0-10 health, check if ammo is under 0 or health over 100
//if you have no ammo, fight with hands lose 0-15 health, check if health over 100, 
//if no gun fight snake with hands, lose 0-15 health, check if health over 100,
//on all check if food can be applied, if so apply it back, give user feedback, give them health/ammo counts 
void handle_snake(char * move)
{
	if(gun)
	{
		if(ammo>0)
		{
			srand(time(nullptr));
			int r = rand();
			ammo = ammo - ((r%5)+1);
			if(ammo < 0)
			{
				ammo=0;
				health = health - ((r%11)-2);		
			}
			else
				health = health - (r%11);
			cout<<"\nYou moved "<<move<<" and you ran into a snake! You have to fight it"<<endl;
			cout<<"You have a gun to fight back and ammo to kill!"<<endl;
			cout<<"You killed the snake! You now have "<< ammo<< " ammo. "<<endl;
			handle_snake_health();
			cout<<"You now also have "<<health<<" health after any and all food. "<<endl;
		}
		else
		{
			srand(time(nullptr));
			int r = rand();
			health = health - (r%15);
			handle_snake_health();
			cout<<"\nYou moved "<<move<<" and you ran into a snake! You have to fight it!"<<endl;
			cout<<"You have a gun to fight back! However, You have no ammo for the gun!"<<endl;
			cout<<"It looks like you will have to fight with your hands!"<<endl;
			cout<<"You killed the snake! You now have "<<health<<" health after any food and no ammo!"<<endl;
		}
	}
	else
	{
		srand(time(nullptr));
		int r = rand();
		health = health - (r%15);
		handle_snake_health();
		cout<<"\nYou moved "<<move<<" and you ran into a snake! You have to fight it!"<<endl;
		cout<<"You have nothing to fight with except for your hands!"<<endl;
		cout<<"You killed the snake! You now have "<<health<<" health after any and all food!"<<endl;
	}

}

//Handle the case for the Locked door
//if they have the key then unlock it in the perform move function change the door to 'D' for unlocked door
//if they dont have it tell them it is locked and that maybe they need a key
void handle_L_door(char * move)
{
	if(L_key)
	{
		cout<<"\nYou moved "<<move<<" and you found a door that seems to be locked."<<endl;
		cout<<"However, you have the key to the door and you can and do unlock it."<<endl;
	}
	else
	{
		cout<<"\nYou moved "<<move<<" and you have found a door but it seems to be locked."<<endl;
		cout<<"Maybe there is a key for this door somewhere around here..."<<endl;
	}
}

//Handle the case for when a player lands on the 'K' block.
//Tell them that they found a key and ask what it could be for
void handle_key(char * move)
{
	cout<<"\nYou moved "<<move<<" and you found a key on the ground."<<endl;
	cout<<"Where does this key belong?"<<endl;
	B_key =1;
}

//Handle the case for when a player runs into the Helicopter pad. If they have the key they have won the game!
//they can fly away and escpae
//If they do not tell them that they see the helicopter and that they need the keys for the copter
void handle_heli(char * move)
{
	if(H_key)
	{
		cout<<"\nYou are at the Helicopter pad and you have the keys to the Helicopter!"<<endl;
		cout<<"You can escape this terrible town and make it back to your family!"<<endl;
		cout<<"Congratulations you win!!!!!"<<endl;
		game_over=1;
	}
	else
	{
		cout<<"\nYou moved "<<move<<" and you found a helicopter pad with a heli parked on it."<<endl;
		cout<<"It is locked and the keys are missing, maybe they are somewhere around this town?"<<endl;
	}
}

//Handles if a player is nearby the gun shop while also on a '.', if they are it prints the lines needed
//and returns 1 so that the default '.' line does not print
//returns 0 if they are not nearby the gun shop
int handle_nearby_shop(char * move)
{
	if((PX == 9 && (PY >= 2 && PY <= 7)) || ((PX >= 10 && PX <= 14) && PY == 7) || (PX==15 && (PY >= 2 && PY <= 7)) || ((PX >= 10 && PX <= 14 ) && PY ==2))
	{	
		cout << "\nYou moved "<<move<<" and you notice you are right up close to a building..."<<endl;
		cout << "You look closely and you think you see the outlines of a sign on the building say \"Gun Shop\"..."<<endl;
		return 1;
	}
	return 0;
}

//Handles if the player is nearby the general hilsbury house while also on a '.', if they are it prints the lines needed
//and returns 1 to stop any default lines of '.' from printing
//returns 0 if they are not nearby the general hilsbury house
int handle_nearby_GHHouse(char * move)
{
	if((PX>=2 && PY<=3 && PY>=27 && PY<=44) || (PX>=4 && PX<=11 && PY>=27 && PY<=28) || (PX>=12 && PX<=13 && PY>=27 && PY<=44) || (PX>=4 && PX<=11 && PY>=43 && PY<=44))
	{
		cout << "\nYou moved "<< move<<" and you can see the makings of what looks like a medium sized house close by..."<<endl;
		cout << "As you look closely at it you confirm your suspicions and can tell it is a house..."<<endl;
		cout << "You also can see what looks to be Country and its Military Flags around the home..."<<endl;
		return 1;
	}
	return 0;
}

//Handles if the player is nearby the south east forest while also on a '.', if they are it prints the necessary
//lines needed and also returns 1 so as to stop any default '.' lines from printing 
//returns 0 if they are not near the forest
int handle_nearby_SEForest(char * move)
{
	if((PX>=57 && PX<=58 && PY>=32 && PY<=59) || (PX>=49 && PX<=56 && PY>=58 && PY<=59) || (PX>=47 && PX<=48 && PY>=32 && PY<=59) || (PX>=49 && PX<=56 && PY>=32 && PY<= 33))
	{
		cout << "\nYou moved "<<move<<" and you can see what looks like a forest or wooded area..."<<endl;
		cout << "What could lie inside the dark forest?"<<endl;
		return 1;
	}
	return 0;
}

//Handles if the player is near the helipad while also on a '.', if they are it prints the 3 lines 
//and returns 1 so as to stop default '.' lines from printing
//returns 0 if they are not nearby the helipad
int handle_nearby_helipad(char * move)
{
	if((PX==63 && PY>=5 && PY<=18) || (PX>=57 && PX<=62 && PY>=5 && PY<=6) || (PX>=55 && PX<=56 && PY>=5 && PY<=18) || (PX>=57 && PX<=62 && PY>=17 && PY<=18))
	{
		cout << "\nYou moved "<<move<<" and see what looks to be an area surrounded by a trees in a wall formation..."<<endl;
		cout << "You can see a little bit through the trees and spot something metal in the area inside the trees..."<<endl;
		cout << "What lies inside the trees?"<<endl;
		return 1;
	}
	return 0;
}

//handles if the player is near the east woods and also on a '.' if they are it prints all lines associated
//and returns 1 to stop the default '.' lines from printing
//returns 0 if they are not near the east woods
int handle_nearby_EWoods(char * move)
{
	if((PX>=9 && PX<=10 && PY>=46 && PY<=63) || (PX>=11 && PX<=18 && PY>=62 && PY<=63) || (PX==19 && PY>=46 && PY<=63) || (PX>=11 && PX<=18 && PY>=46 && PY<=47))
	{
		cout << "\nYou moved "<<move<<" and you see some trees and what looks to be a woods area or a forest..."<<endl;
		cout << "Maybe you should check what is inside?"<<endl;
		return 1;
	}
	return 0;
}

//handles if the player is near the filmore manor and also on a '.', if so they print out the lines for it 
//and returns 1 so that the default '.' lines are not printed
//returns 0 if they are not near the filmore manor
int handle_nearby_Filmore(char * move)
{
	if((PX>=50 && PX<=51 && PY>=7 && PY<=20) || (PX>=46 && PX<=49 && PY>=19 && PY<=20) || (PX>=46 && PX<=47 && PY>=21 && PY<=36) || (PX>=40 && PX<=45 && PY>=35 && PY<=36) || (PX>=38 && PX<=39 && PY>=22 && PY<=36) || (PX>=36 && PY<=39 && PY>=20 && PY<=21) || (PX>=34 && PX<=35 && PY>=7 && PY<=21) || (PX>=36 && PX<=49 && PY>=7 && PY<=8))
	{
		cout << "\nYou moved "<<move<<" and you make out what looks like a big house..."<<endl;
		cout << "You think that a rich person most definitely lives there because of the size."<<endl;
		return 1;
	}
	return 0;
}

//handles if the player is near the west woods and on a '.', if they are then it prints out the needed lines
//and returns 1 to ignore the default '.' lines
//returns 0 if they are not near the west woods
int handle_nearby_WWoods(char * move)
{
	if((PX>=28 && PX<=29 && PY>=2 && PY<=20) || (PX>=17 && PX<=27 && PY>=2 && PY<=3) || (PX>=15 && PX<=16 && PY>=2 && PY<=20) || (PX>=17 && PX<=27 && PY>=19 && PY<=20))
	{
		cout<< "\nYou moved "<<move<<" and you can see the makings of a forest or wooded area..."<<endl;
		cout<< "It is dark and hard to see anything in the forest..."<<endl;
		cout<< "What could be inside?"<<endl;
		return 1;
	}
	return 0;
}

//handles if the player is nearby the reptile research lab and on a '.', if they are it prints out the needed lines
//and returns 1 to ignore the default '.' lines that would otherwise print
//returns 0 if the player is not near the reptile research lab
int handle_nearby_Reptile(char * move)
{
	if((PX==19 && PY>=34 && PY<=49) || (PX>=20 && PX<=22 && PY>=48 && PY<=49) || (PX>=21 && PX<=22 && PY>=50 && PY<=57) || (PX>=23 && PX<=29 && PY>=56 && PY<=57) || (PX>=28 && PX<=29 && PY>=58 && PY<=61) || (PX>=30 && PX<=34 && PY>=60 && PY<=61) || (PX>=35 && PX<=36 && PY>=34 && PY<=61) || (PX>=20 && PX<=34 && PY>=34 && PY<=35))
	{
		cout<< "\nYou moved "<<move<<" and you see the beginnings of a large building..."<<endl;
		cout<< "You can slightly see something about reptiles but you aren't sure..."<<endl;
		cout<< "Is that hissing you hear?"<<endl;	
		return 1;
	}
	return 0;
}

//handles if they player is in the shop and on a '.', if they are in the shop tell the player and return 1
//if they are not return 0
int handle_in_shop(char * move)
{
	if(PX>=11 && PX<=13 && PY>=4 && PY<=5)
	{
		cout<<"\nYou moved "<<move<<" and you are inside the gun shop walking around looking for anything you can find."<<endl;
		return 1;
	}
	return 0;
}

//Handle if the player is in the general hilsbury house and on a '.', if they are tell the player and return 1
//to stop default '.' lines from printing, return 0 if they are not in the house
int handle_in_GHHouse(char * move)
{
	if(PX>=5 && PX<=10 && PY>=30 && PY<=41)
	{
		cout<<"\nYou moved "<<move<<" and you are inside a military officers house..."<<endl;
		cout<<"What can you find? What type of officer was this person? There seems to be many things scattered all over the place."<<endl;
		return 1;
	}
	return 0;
}

//handle if the player is in the South east forest and on a '.', if they are tell the player and return 1
//to stop default '.' lines and return 0 if they are not within the forest
int handle_in_SEForest(char * move)
{
	if(PX>=49 && PX<=56 && PY>=34 && PY <=57)
	{
		cout<<"\nYou moved "<<move<<" and you are walking around a forest..."<<endl;
		cout<<"It is extremely dark out and you have trouble seeing too far in front..."<<endl;
		cout<<"You are worried about getting lost in here..."<<endl;
		return 1;
	}
	return 0;
}

//handle if the player is in the helipad and on a '.', and return 1 if they are in the helipad area to
//cancel the printing of the default '.' lines, return 0 if they are not in the helipad area
int handle_in_helipad(char * move)
{
	if(PX>=58 && PX<=61 && PY>=8 && PY<=15)
	{
		cout<<"\nYou moved "<<move<<" and you are inside what looks to be an enclosed secret area..."<<endl;
		cout<<"The metal you saw through the tree begins to take shape as a helicopter..."<<endl;
		cout<<"You now know what you need..."<<endl;
		return 1;
	}
	return 0;
}

//handle if the player is in the eastern woods and on a '.', return 1 if they are 
//to stop from default '.' lines printing out and return 0 if they are not within the eastern woods
int handle_in_EWoods(char * move)
{
	if(PX>=11 && PX<=18 && PY>=48 && PY<=61)
	{
		cout<<"\nYou moved "<<move<<" and you are in what seems to be a wooded area..."<<endl;
		cout<<"It is incredibly dark inside these woods and you are not quite sure where you are going..."<<endl;
		cout<<"Where could you be? What could be here inside these woods?"<<endl;
		return 1;
	}
	return 0;
}

//handle if the player is in the filmore manor and on a '.', returns 1 if they are inside
//to stop the '.' default lines from printing, return 0 if they are not within the filmore manor walls
int handle_in_Filmore(char * move)
{
	if((PX>=37 && PX<=48 && PY>=10 && PY<=18) || (PX>=41 && PX<=44 && PY>=19 && PY<=33))
	{
		cout<<"\nYou moved "<<move<<" and you find yourself inside a big mansion..."<<endl;
		cout<<"You are looking around and you notice you the name \"Filmore\" around quite a bit."<<endl;
		cout<<"Who is Filmore? Is this the current owner? Former owner? Mayor?"<<endl;
		return 1;
	}
	return 0;
}

//handle the player being inside the west woods and on '.', returns 1 if they are inside
//to make sure the default '.' lines do not print, returns 0 if they are not inside the western woods
int handle_in_WWoods(char * move)
{
	if(PX>=17 && PX<=27 && PY>=4 && PY<=18)
	{
		cout<<"\nYou moved "<<move<<" and you know you are inside a wooded area..."<<endl;
		cout<<"It is dark and misty in the forest making it hard to see much around you..."<<endl;
		cout<<"You know one thing...You don't want to get lost in here..."<<endl;
		return 1;
	}
	return 0;
}

//handle if the player is in the reptile research lab and on a '.', returns 1 if they are
//this cancels the '.' default lines from printing, returns 0 if they are not inside the reptile research lab
int handle_in_Reptile(char * move)
{
	if((PX>=21 && PX<=33 && PY>=37 && PY<=46) || (PX>=24 && PX<=33 && PY>=47 && PY<=54) || (PX>=31 && PX<=33 && PY>=55 && PY<=58))
	{
		cout<<"\nYou moved "<<move<<" and are inside a large laboratory and everything is broken..."<<endl;
		cout<<"The hissing you heard outside is now much louder and you know what you are hearing..."<<endl;
		cout<<"You can now tell that the hissing is coming from snakes...and a lot of them..."<<endl;
		cout<<"They are in some sort of research lab and have broken out...be careful..."<<endl;
		return 1;
	}
	return 0;
}

//handle if the player is inside one of the small buildings around the map and on a '.', returns 1 if they are in
//any of the three to stop the default '.' lines from printing, returns 0 if they are not in any of the buildings
int handle_in_small_building(char * move)
{
	if((PX>=52 && PX<=53 && PY>=2 && PY<=3) || (PX>=60 && PX<=61 && PY>=46 && PY<=47) || (PX>=60 && PX<=61 && PY>=55 && PY<=56))
	{
		cout<<"\nYou moved "<<move<<" and are inside a small building..."<<endl;
		cout<<"It is very small and you can almost feel all the walls around you..."<<endl;
		cout<<"If people live here...it must be cramped..."<<endl;
		return 1;
	}
	return 0;
}

//handles the '.' case. goes around the map and checks to see if the player is nearby any of the main 8 places
//adding up the function return values(returns 1 if nearby is true). You cant be nearby any of the 8 places and also be in some
//so if the total is 0 after nearby checks then go through and check if the player is in any of the 8 places
//plus three small buildings. if they are nearby or in any places the default '.' line will not print
//if they arent near or in any buildings then the default line prints. 
void handle_dot(char * move)
{
	int total =0;
	total += handle_nearby_shop(move);
	total += handle_nearby_GHHouse(move);
	total += handle_nearby_SEForest(move);
	total += handle_nearby_helipad(move);
	total += handle_nearby_EWoods(move);
	total += handle_nearby_Filmore(move);
	total += handle_nearby_WWoods(move);
	total += handle_nearby_Reptile(move);
	if(total == 0)
	{
		total += handle_in_shop(move);
		total += handle_in_GHHouse(move);
		total += handle_in_SEForest(move);
		total += handle_in_helipad(move);
		total += handle_in_EWoods(move);
		total += handle_in_Filmore(move);
		total += handle_in_WWoods(move);
		total += handle_in_Reptile(move);
		total += handle_in_small_building(move);
	}
	if(total ==  0)
		cout<<"\nYou moved "<<move<<" and are in search of something, anything, to find and grab your attention."<<endl;
}


/*END HANDLE EVENTS FUNCTIONS*/

/*BEGIN UPDATE OF GAME FUNCTIONS */
//update the game state and the previous tile we were on, this does the logic for the up move
void update_after_up(char prev)
{
	gs[PX][PY] = prev_tile;
	prev_tile = prev;
	PX=PX-1;
	gs[PX][PY] = 'P';
}

//update the game state and the previous tile we were on for the down move
void update_after_down(char prev)
{
	gs[PX][PY] = prev_tile;
	prev_tile = prev;
	PX=PX+1;
	gs[PX][PY] = 'P';
}

//update the game state and the previous tile we were on for the left move
void update_after_left(char prev)
{
	gs[PX][PY] = prev_tile;
	prev_tile = prev;
	PY = PY-1;
	gs[PX][PY] = 'P';
}

//update the game state and the previous tile we were on for the right move
void update_after_right(char prev)
{
	gs[PX][PY] = prev_tile;
	prev_tile = prev;
	PY = PY+1;
	gs[PX][PY] = 'P';
}

/*END UPDATE OF GAME FUNCTIONS */

//function for saving the game, open a file for truncated writing to overwrite previous save, go thru
//save the data needed to save the game state (board, ammo, health etc), if errors then return -1 to try again
int save_game(int count)
{
	ofstream out("Saved.data", ios::trunc);
	if(out.is_open())
	{
		for(int i=0; i<GBSZ; ++i)
			out<<gs[i]<<endl;
		out<<ammo<<endl;
		out<<health<<endl;
		out<<PX<<endl;
		out<<PY<<endl;
		out<<food<<endl;
		out<<gun<<endl;
		out<<prev_tile<<endl;
		out<<B_key<<endl;
		out<<L_key<<endl;
		out<<H_key<<endl;
		cout<<"Save completed!"<<endl;
		out.close();
		return 1;
	}
	else
	{
		if(count < 2)
			cout<<"Error saving the game, will retry to save the game"<<endl;
		else
			cout<<"Error saving the game, max attempts to save tried"<<endl;
		out.close();
		return -1;
	}
}


//perform the move of the player, check if the next block is wall, tree,door,etc
//perform actions based on the type of block the player moves to
//for all directions 
//calls handle functions and update functions
void perform_move(char * move)
{
	if(strcmp(move,"Up") ==0)
	{
		if(wall_checker('U'))
			return;
		if(tree_checker('U'))
			return;
		if(rock_checker('U'))
			return;
		switch(gs[PX-1][PY])//A F . W T R w G B E C s N n D d L S
		{
			case 'A':
				handle_ammo(move);
				update_after_up('.');
				return;
			case 'F':
				handle_food(move);
				update_after_up('.');
				return;
			case '.':
				update_after_up('.');
				handle_dot(move);
				return;
			case 'w':
				update_after_up('w');
				cout<<"\nYou've moved 1 space "<<move<<", and you are now in water swimming"<<endl;
				return;
			case 'G':
				if(gun)
					update_after_up('G');
				else
					update_after_up('.');
					handle_gun(move);
				return;
			case 'B':
				handle_B_box(move);
				return;
			case 'E':
				handle_E_box(move);
				return;
			case 'C':
				handle_corpse(move);
				return;
			case 's':
				handle_sign(move);
				update_after_up('s');
				return;
			case 'N':
				handle_note(move);
				update_after_up('.');
				return;
			case 'D':
				cout<<"\nYou've moved "<<move<<" and you have entered a building or home"<<endl;
				update_after_up('D');
				return;
			case 'd':
				handle_dresser(move);
				return;
			case 'S':
				handle_snake(move);
				update_after_up('.');
				return;
			case 'K':
				handle_key(move);
				update_after_up('.');
				return;
			case 'H':
				handle_heli(move);
				update_after_up('H');
				return;
		}

	}
	else if(strcmp(move, "Down") ==0)//A F . W T R w G B E C s N n D d L S
	{
		if(wall_checker('D'))
			return;
		if(tree_checker('D'))
			return;
		if(rock_checker('D'))
			return;
		switch(gs[PX+1][PY])
		{
			case 'A':
				handle_ammo(move);
				update_after_down('.');
				return;
			case 'F':
				handle_food(move);
				update_after_down('.');
				return;
			case '.':
				update_after_down('.');
				handle_dot(move);
				return;
			case 'w':
				update_after_down('w');
				cout<<"\nYou've moved 1 space "<<move<<", and you are now in water swimming"<<endl;
				return;
			case 'G':
				if(gun)
					update_after_down('G');
				else
					update_after_down('.');
					handle_gun(move);
					return;
			case 'B':
				handle_B_box(move);
				return;
			case 'E':
				handle_E_box(move);
				return;
			case 'C':
				handle_corpse(move);
				return;
			case 's':
				handle_sign(move);
				update_after_down('s');
				return;
			case 'D':
				cout<<"\nYou've moved "<<move<<" and you have entered a building or home"<<endl;
				update_after_down('D');
				return;
			case 'd':
				handle_dresser(move);
				return;
			case 'S':
				handle_snake(move);
				update_after_down('.');
				return;
			case 'K':
				handle_key(move);
				update_after_down('.');
				return;
			case 'H':
				handle_heli(move);
				update_after_down('H');
				return;
		}
	}
	else if(strcmp(move, "Left") == 0)
	{
		if(wall_checker('L'))
			return;
		if(tree_checker('L'))
			return;
		if(rock_checker('L'))
			return;
		switch(gs[PX][PY-1])
		{
			case 'A':
				handle_ammo(move);
				update_after_left('.');
				return;
			case 'F':
				handle_food(move);
				update_after_left('.');
				return;
			case '.':
				update_after_left('.');
				handle_dot(move);
				return;
			case 'w':
				update_after_left('w');
				cout<<"\nYou've moved 1 space "<<move<<", and you are now in water swimming"<<endl;
				return;
			case 'G':
				if(gun)
					update_after_left('G');
				else
					update_after_left('.');
					handle_gun(move);
				return;
			case 'B':
				handle_B_box(move);
				return;
			case 'E':
				handle_E_box(move);
				return;
			case 'C':
				handle_corpse(move);
				return;
			case 's':
				handle_sign(move);
				update_after_left('s');
				return;
			case 'D':
				cout<<"\nYou've moved "<<move<<" and you have entered a building or home"<<endl;
				update_after_left('D');
				return;
			case 'd':
				handle_dresser(move);
				return;
			case 'S':
				handle_snake(move);
				update_after_left('.');
				return;
			case 'H':
				handle_heli(move);
				update_after_left('H');
				return;
		}
	}
	else if(strcmp(move, "Right") == 0)
	{
		if(wall_checker('R'))
			return;
		if(tree_checker('R'))
			return;
		if(rock_checker('R'))
			return;
		switch(gs[PX][PY+1])
		{
			case 'A':
				handle_ammo(move);
				update_after_right('.');
				return;
			case 'F':
				handle_food(move);
				update_after_right('.');
				return;
			case '.':
				update_after_right('.');
				handle_dot(move);
				return;
			case 'w':
				update_after_right('w');
				cout<<"\nYou've moved 1 space "<<move<<", and you are now in water swimming"<<endl;
				return;
			case 'G':
				if(gun)
					update_after_right('G');
				else
					update_after_right('.');
					handle_gun(move);
				return;
			case 'B':
				handle_B_box(move);
				return;
			case 'E':
				handle_E_box(move);
				return;
			case 'C':
				handle_corpse(move);
				return;
			case 's':
				handle_sign(move);
				update_after_right('s');
				return;
			case 'D':
				cout<<"\nYou've moved "<<move<<" and you have entered a building or home"<<endl;
				update_after_right('D');
				return;
			case 'd':
				handle_dresser(move);
				return;
			case 'S':
				handle_snake(move);
				update_after_right('.');
				return;
			case 'L':
				handle_L_door(move);
				if(L_key)
					update_after_right('D');
				return;
			case 'H':
				handle_heli(move);
				update_after_right('H');
				return;
		}
	}
	else if(strcmp(move, "Save") ==0)
	{
		char save_input;
		int saver = -1,count=0;
		cout<< "\nWould you like to save the game as this will overwrite previously saved data? y or Y/n or N:";
		cin >> save_input;
		cin.clear();
		cin.ignore();
		switch(save_input)
		{
			case 'y':
			case 'Y':
				while(saver ==-1)
				{
					saver = save_game(count);
					++count;
					if(count == 3)
					{
						cout<<"Error: Could not save the game, save aborted"<<endl;
						break;
					}
				}
				break;
			case 'n':
			case 'N':
			default:
				cout<<"Saved cancelled\n";
				return;
		}
	}
	else if(strcmp(move, "Quit") == 0) 
	{
		char quit_input;
		cout<<"You have chosen to quit. Are you sure you want to quit? Any unsaved progress will be lost..."<<endl;
		cout<<"y/Y or n/N: ";
		cin>> quit_input;
		cin.clear();
		cin.ignore();
		switch(quit_input)
		{
			case 'y':
			case 'Y':
				cout<<"\nYou chose to quit, quitting the game, any unsaved progress lost..."<<endl;
				exit(0);
			case 'n':
			case 'N':
			default:
				cout<<"\nYou chose to not quit, quit aborted."<<endl;
		}
	}
	else
	{
		string board_copy[64];
		for(int i=0; i<64; ++i)
			board_copy[i] = gs[i];
		board_copy[PX][PY] = prev_tile;
		cout<<"\nHere is the game map, where you are is for you to find out...\n"<<endl;
		print_game_state(board_copy);
	}
}

int main()
{
	int saved=0;
	init_game(&saved);
	if(PX == 32 && PY == 14 && saved ==0)
		print_opening_info();
	else
		print_opening_saved_info();
	perform_move((char * )"Print");
	char move[MAXBUFSZ];
	int checker=0;
	do 
	{
		get_move(move);
		checker = check_move(move);
		if (checker == -1)
		{
			cout<< "Invalid Move Type, Choose Up, Right, Left, Down"<<endl;
			continue;
		}
		else if(checker == -2)
		{
			cout<<"The wall is too big to climb over, you must find a different way out"<<endl;
			continue;
		}
		else
		{
			perform_move(move);
		}
		if(health <=0)
		{
			cout<<"You died!"<<endl;
			game_over = 1;
		}
	}while(!game_over);
	cout<<"\nGAME OVER!"<<endl;
	cout<<"Thank you for playing my game"<<endl;
	return 0;
}

