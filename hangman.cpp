#include<iostream>
#include<conio.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;
void startgame();
int rules();
int gotogame(string, string, string);
int hintword();
int hangman();
int playagain();
string result;
string word;
string Typeofword;
string hint;
char choice;
int wrongcount = 0;
bool activation;
bool mark;
int main()
{
	startgame();
	_getch();
	return 0;
}
void startgame()
{
	//MAIN MENU
	activation = true;
	while (activation)
	{

		cout << "\t\t              ____________  " << endl;
		cout << "\t\t |             ===========              | " << endl;
		cout << "\t\t |     =====                 =====      | " << endl;
		cout << "\t\t |       :     HANGMAN GAME    :        | " << endl;
		cout << "\t\t |       :                     :        | " << endl;
		cout << "\t\t |       O     1.Play Game     O        |" << endl;
		cout << "\t\t |      /|\\                   /|\\       |" << endl;
		cout << "\t\t |      / \\   2.Game Rules    / \\       |" << endl;
		cout << "\t\t |                                      |" << endl;
		cout << "\t\t |             3.Exit Game              |" << endl;
		cout << "\t\t |______________________________________|" << endl;

		//USER CHOICE
		cout << "\t\t\t ENTER CHOICE > ";
		cin >> choice;
		switch (choice)
		{
		case '1':
		{
			system("cls");
			activation = false; //ACTIVATION=0 LOOP CONDITION IS FALSE BREAKS;
			hintword();     //FUNCTION IS CALLED 
			break;
		}
		case '2':
		{
			system("cls");
			activation = false;
			rules();
			break;
		}
		case '3':
		{
			system("cls");
			exit(0);
			break;
		}
		default:
		{
			system("cls");
			break;
		}
		}
	}
}
int rules()
{
	activation = true;
	//USING OF FILE HANDLING 
	//STORING FOR NEW USERS TO CREATE A FILE AND STORE DATA AND READING IT AFTER
	while (activation)
	{
		fstream file;
		file.open("RULES.txt", ios::out);
		file << "                                WELCOME TO HANGMAN                                           " << endl;
		file << "__________________________________________________________________________________________________" << endl;

		file << "(1) Choose one person(PLAYER 1)to choose the word.This person that gives the word" << endl;
		file << "for the other individuals to solve.There task will be  with choosing a word that" << endl;
		file << "will complete the word." << endl;
		file << endl;
		file << "(2) Choose a word you think will be difficult to guess." << endl;
		file << endl;
		file << "(3) Start guessing the letters.Begin by guessing letters that you think are in the word." << endl;
		file << endl;
		file << "(4) When the player guess the letter that is not in the word they increment each step on the" << endl;
		file << "hanged man, that brings them closer to losing the game and gives a beep." << endl;
		file << endl;
		file << "-GOODLUCK!-" << endl;
		file << "~ PRESS 1 TO START THE GAME" << endl;
		file << "~ PRESS 2 TO EXIT THE GAME" << endl;
		file << endl;
		file << "---------------------------------------------------------------------------------------------- " << endl;
		file.close();

		cout << endl;
		string line;
		ifstream myfile("RULES.txt", ios::in);
		if (!myfile)
		{
			cout << "FILE CANNOT BE OPENED" << endl;
			exit(0);
		}
		while (getline(myfile, line))
		{
			cout << line << endl; //PRINTS EACH LINE IN A FILE
		}
		myfile.close();

		cout << endl;
		cout << "\t\t\t  ENTER >";
		cin >> choice;
		if (choice == '1')
		{
			system("cls");
			activation = false;
			hintword();
		}
		if (choice == '2')
		{
			cout << "\t\t\t EXITED GAME" << endl;
			exit(0);
		}
		else                   //REPEATEDLY ASKS TO ENTER 1 TO START GAME
		{
			system("cls");
		}
	}
	return 0;
}
int hintword()
{
	cout << "\t    |***********************" << endl;
	cout << "\t    |                       " << endl;
	cout << "\t    |                       " << endl;
	cout << "\t    |                       " << endl;
	cout << "\t    |         O             " << endl;
	cout << "\t    |        /|7            " << endl;
	cout << "\t   _|_       / \\           " << endl;
	cout << endl << endl;

	cout << "\t\t Player 1:" << endl;
	cout << "\t\t ~ ENTER THE WORD TO BE FOUND (NO SPACES): " << endl;
	cout << "\t\t\t\t ENTER > ";
	cin >> word;

	transform(word.begin(), word.end(), word.begin(), tolower);//COPIED FROM THE INTERNET THE TOLOWER FUNCTION WAS NOT WORKING FOR STRING
															   // ALOGRITHM HEADERFILE IS USED FOR THIS
															   //TAKES START AND END OF THE STRING RANGE, ALSO TAKES THE START OF THE OUTPUT STRING 
															   //AND LASTLY THE FUNCTION YOU WANT TO APPLY
	cout << endl;

	cout << "\t ~ ENTER WORD TYPE.example.Movie/Name/Food/City/Countries.etc: ";
	cout << "\t ENTER > ";

	cin.ignore();//THE GETLINE FUNCTION WAS GETTING SKIPPED SO A SOLUTION FOR IT WAS USED FROM THE INTERNET
				 //CIN IGNORE FUNCTION IS USED WHEN WE ENTER A GETLINE BEFORE AND THE USER PRESS ENTER AFTER 
				 //THE \N CHAR GETS IN CIN BUFFER SO WHEN THE NEXT GETLINE FUNCTION IS USED IT STORES CHAR INSTEAD OF STRING
	getline(cin, Typeofword);
	cout << endl;

	cout << "\t ~ HINT:\t\t\t";
	cout << "\t\t\t\t ENTER > ";
	getline(cin, hint);

	gotogame(word, Typeofword, hint); //PASSING ARGUMENTS TO START GAME
	return 0;
}

int gotogame(string word, string Typeofword, string hint)
{
	system("cls");
	//CONVERTING WORDS TO UNDERSCORE
	for (int loop1 = 0; loop1 < word.length(); loop1++) //DETERMINES STRING LENGTH
	{
		result.append("_"); //CONVERTS CHARACHTERS TO UNDERSCORE AND APPENDS IT IN A STRING
	}
	int occur = 0;
	activation = true;
	while (activation)
	{
		int index;
		mark = true;
		hangman(); //FUNCTION IS CALLED TO DIPLAY HANGED MAN WITH RESPECT TO NUMBER OF WRONG COUNTS
		cout << endl << endl;
		cout << "\t\t Player 2:" << endl;
		cout << "\t\t WORD TYPE IS --- " << Typeofword;
		cout << "\t\t\t\t  SECRET WORD   ";
		//PRINTING WORDS IN UNDERSCORE
		for (int loop2 = 0; loop2 < word.length(); loop2++)
		{
			cout << result[loop2] << " "; //AS THE PLAYER GUESSES LETTER IT FINDS AND STORES IT AT THE INDEX
										  //SO THE NEXT TIME THE WHILE LOOPS EXECUTE IT DISPLAYS THE NUMBER THAT IS AREADY GUESSED
		}
		cout << endl;
		cout << "\t\t WORD HINT IS --- " << hint << endl;
		cout << "\t\t\t\t\t\t\t\t  ~ ENTER '#' TO EXIT GAME" << endl;
		cout << endl;
		if (mark == true)
		{
			cout << "\t\t  ENTER LETTER >";
			cin >> choice;
		}

		if (choice == '#')//WHEN USER WANTS TO EXIT
		{
			exit(0);
		}

		if ((choice >= 'A') && (choice <= 'Z'))//CONVERTING TO LOWER
		{
			choice += 32;
			occur = word.find(choice); //FIND THE CHARACHTER IF FOUND SAVES THE INDEX IN VARIABLE IF NOT SAVES -1
									   //IT ONLY SAVES THE FIRST INDEX AT WHICH THE CHARACHTER IS FOUND
		}
		else//IF ALREADY IN LOWER
		{
			occur = word.find(choice);
		}

		while (word.find(choice, occur) != -1)//THE WORD FIND, FINDS THE WORD AT THE FIRST STORED INDEX, IF FOUND THE LOOP EXECUTES  
											   //SO (ANY INDEX)!=-1
		{
			index = word.find(choice, occur);
			result[index] = choice;//THE RESULT ARRAY STORES THE CHOICE AT THAT PARTICULAR INDEX AT WHICH LETTER WAS FOUND
			occur++;               //FIND THE NEXT OCCURRENCE OF THE CHARACTER BY INCREMENTING THE INDEX NUMBERS ON THE STRING
								   //AND THE LOOP GOES TO CONDITION TO CHECK ANY OTHER OCCURRENCE
		}
		if (occur == -1) //SO WORD NOT FOUND -1==-1	                       
		{
			wrongcount++;
			cout << "\a";//ESCAPE SEQUENCE FOR BEEP
		}

		//IF TRIES ARE FINISHED
		if (wrongcount == 6)
		{
			system("cls");
			playagain();
		}
		//IF THE USER GUESSES THE COMPLETE WORD
		else if (result == word)
		{
			system("cls");
			playagain();
		}
		system("cls");
	}
	return 0;
}

int hangman()
{
	switch (wrongcount)
	{
	case 0:
	{
		cout << "\t     ______           " << endl;
		cout << "\t    |      |          " << endl;
		cout << "\t    |      !          " << endl;
		cout << "\t    |                 " << endl;
		cout << "\t    |                 " << endl;
		cout << "\t    |                 " << endl;
		cout << "\t   _|_                " << endl;
		break;
	}
	case 1:
	{
		cout << "\t    ______          " << endl;
		cout << "\t   |      |         " << endl;
		cout << "\t   |      !         " << endl;
		cout << "\t   |      O         " << endl;
		cout << "\t   |                " << endl;
		cout << "\t   |                " << endl;
		cout << "\t  _|_               " << endl;
		break;
	}
	case 2:
	{
		cout << "\t     ______         " << endl;
		cout << "\t    |      |        " << endl;
		cout << "\t    |      !        " << endl;
		cout << "\t    |      O        " << endl;
		cout << "\t    |      |        " << endl;
		cout << "\t    |               " << endl;
		cout << "\t   _|_              " << endl;
		break;
	}
	case 3:
	{
		cout << "\t    ______          " << endl;
		cout << "\t   |      |         " << endl;
		cout << "\t   |      !         " << endl;
		cout << "\t   |      O         " << endl;
		cout << "\t   |      |\\       " << endl;
		cout << "\t   |                " << endl;
		cout << "\t  _|_               " << endl;
		break;
	}
	case 4:
	{
		cout << "\t     ______         " << endl;
		cout << "\t    |      |        " << endl;
		cout << "\t    |      !        " << endl;
		cout << "\t    |      O        " << endl;
		cout << "\t    |     /|\\      " << endl;
		cout << "\t    |               " << endl;
		cout << "\t   _|_              " << endl;
		break;
	}
	case 5:
	{
		cout << "\t     ______         " << endl;
		cout << "\t    |      |        " << endl;
		cout << "\t    |      !        " << endl;
		cout << "\t    |      O        " << endl;
		cout << "\t    |     /|\\      " << endl;
		cout << "\t    |     /         " << endl;
		cout << "\t   _|_              " << endl;
		break;
	}
	case 6:
	{
		cout << "\t     ______         " << endl;
		cout << "\t    |      |        " << endl;
		cout << "\t    |      !        " << endl;
		cout << "\t    |      O        " << endl;
		cout << "\t    |     /|\\      " << endl;
		cout << "\t    |     / \\      " << endl;
		cout << "\t   _|_              " << endl;
		break;
	}
	}
	return 0;
}
int playagain()
{
	string line;
	activation = true;
	while (activation)
	{
		//USING FILE HANDLING BY FIRST CREATING FILE(FOR NEW COMPUTERS NOT HAVING THE FILE) AND THEN READING AND PRINTING IT

		fstream fout;
		fout.open("NAMES.txt", ios::out);
		fout << "KEVIN" << endl;
		fout.close();

		//OPENING FILE TO GET THE SUPPOSED NAME OF MAN AND THEN PRINT IT
		cout << endl;
		ifstream myyfile("NAMES.txt");
		if (!myyfile)
		{
			cout << "FILE CANNOT BE OPENED" << endl;
		}
		while (getline(myyfile, line))
		{
			cout << "\t\t\t " << line;
		}
		myyfile.close();


		if (wrongcount == 6)
		{
			cout << endl;
			cout << "\t\t\t" << " DIED! " << endl;
			cout << "\t |              YOU LOST!             | " << endl;
			cout << "\t |             ===========            | " << endl;
			cout << "\t |                                    | " << endl;
			cout << "\t |                                    | " << endl;
			cout << "\t |                                    | " << endl;
			cout << "\t |       _____      <O>               | " << endl;
			cout << "\t |      | RIP |      |                | " << endl;
			cout << "\t |      | ___ |     <<                | " << endl;
			cout << "\t |   ------------------------------   | " << endl;
			cout << "\t |                                    | " << endl;
			cout << "\t |          1.  Play Again            | " << endl;
			cout << "\t |                                    | " << endl;
			cout << "\t |          2.  Exit Game             | " << endl;
			cout << "\t |____________________________________|" << endl << endl;
			cout << "\t  THE WORD WAS---" << word << endl;
		}
		else
		{
			cout << endl;
			cout << "\t\t\t" << " LIVES!   " << endl;
			cout << "\t |              YOU WON!               | " << endl;
			cout << "\t |             ===========             | " << endl;
			cout << "\t |        \\O/                          | " << endl;
			cout << "\t |         |                           | " << endl;
			cout << "\t |        / >                          | " << endl;
			cout << "\t |      _____                          | " << endl;
			cout << "\t |     /     \\                         | " << endl;
			cout << "\t |    /       \\                        | " << endl;
			cout << "\t |   -------------------------------   | " << endl;
			cout << "\t |                                     | " << endl;
			cout << "\t |          1.  Play Again             | " << endl;
			cout << "\t |                                     | " << endl;
			cout << "\t |          2.  Exit Game              | " << endl;
			cout << "\t |_____________________________________| " << endl;
		}
		cout << endl;
		cout << "\t  ENTER CHOICE >";
		cin >> choice;
		switch (choice)
		{
		case'1':
		{
			//RESET GAME;
			activation = false;
			wrongcount = 0;
			mark = true;
			word = "0";
			hint = "0";
			result = " ";
			Typeofword = "0";
			system("cls");
			hintword();
			break;
		}
		case'2':
		{
			cout << "\t  EXITED GAME" << endl;
			exit(0);
			break;
		}
		default:
		{
			system("cls");
		}
		}
	}
	return 0;
}
