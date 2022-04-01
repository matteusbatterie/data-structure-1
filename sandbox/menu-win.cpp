// Menu example for tjnapster
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <cstdlib>

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); // used for goto
COORD CursorPosition; // used for goto

void gotoXY(int,int); // function defined below if this is new to you.

int main()
{
	int menu_item=0, run, x=7;
	bool running = true;
	
	gotoXY(18,5); cout << "Main Menu";
	gotoXY(18,7); cout << "->";
	
	while(running)
	{
		gotoXY(20,7);  cout << "1) Input";
		gotoXY(20,8);  cout << "2) Output";
		gotoXY(20,9);  cout << "3) ...";
		gotoXY(20,10); cout << "4) ...";
		gotoXY(20,11); cout << "Quit Program";

		system("pause>nul"); // the >nul bit causes it the print no message
		
		if(GetAsyncKeyState(VK_DOWN) && x != 11) //down button pressed
			{
				gotoXY(18,x); cout << "  ";
				x++;
				gotoXY(18,x); cout << "->";
				menu_item++;
				continue;
				
			}
			
		if(GetAsyncKeyState(VK_UP) && x != 7) //up button pressed
			{
				gotoXY(18,x); cout << "  ";
				x--;
				gotoXY(18,x); cout << "->";
				menu_item--;
				continue;
			}
			
		if(GetAsyncKeyState(VK_RETURN)){ // Enter key pressed
			
			switch(menu_item){
				
				case 0: {
					
					gotoXY(20,16);
					cout << "You chose Input...     ";
					break;
				}
					
					
				case 1: {
					gotoXY(20,16);
					cout << "You chose Output...     ";
					break;
				}
					
				case 2: {
					gotoXY(20,16);
					cout << "You chose Option 3...     ";
					break;
				}
					
				case 3: {
					gotoXY(20,16);
					cout << "You chose Option 4...     ";
					break;
				}
					
				case 4: {
					gotoXY(20,16);
					cout << "The program has now terminated!!";
					running = false;
				}
				
			}
				
		}		
		
	}
	
	gotoXY(20,21);
	return 0;
}

void gotoXY(int x, int y) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition); 
}