#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
using namespace std;

//Global Variables

bool gameOver;
// position of snake - (x,y)
// position of target - (tx,ty)
int x,y,tx,ty,score;
// Array for drawing snake
int snakex[100],snakey[100],size;
//dimensions of Console box
const int height=25,width=25;
enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction direction;

void Setup(){
    gameOver=false;
    direction=STOP;
    x=21;
    y=21;
    tx=rand()%width;
    ty=rand()%height;
    score=0;
}

void Game(){
    system("cls");
    //Layout of the game
    for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(j==0)
                cout<<'#';
            else if(i==y && j==x)
                cout<<'o';
            else if(i==ty && j==tx)
                cout<<'x';
            else{
            	int flag=1;
            	for(int k=0;k<size;k++){
            		if(snakex[k]==j && snakey[k]==i){
            			cout<<'o';
            			flag=0;
					}
				}
				if(flag)
					cout<<' ';
			}
			if(j==width-1)
            	cout<<'#';
                
        }
        cout<<endl;
    }

    for(int i=0;i<width+1;i++){
        cout<<"#";
    }
    cout<<endl;
    cout<<"________________\n";
    cout<<"Score : "<<score;
    cout<<"\n________________\n";
    cout<<"Instructions\n Use Keys: \n a - LEFT \n d - RIGHT \n w - UP \n s - DOWN \n q - QUIT\n";
    cout<<"________________\n";
}

void Input(){
	if(_kbhit()){
		switch(_getch()){
			case 'a' :
				direction=LEFT;
				break;
			case 'd' :
				direction=RIGHT;
				break;
			case 'w' :
				direction=UP;
				break;
			case 's' :
				direction=DOWN;
				break;
			case 'q' :
				gameOver=true;
				break;
		}
	}
	
}

void GameLogic(){
	int prevx=snakex[0];
	int prevy=snakey[0];
	int prev2x,prev2y;
	snakex[0]=x;
	snakey[0]=y;
	for(int i=1;i<size;i++){
		prev2x=snakex[i];
		prev2y=snakey[i];
		snakex[i]=prevx;
		snakey[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	} 
	
	switch(direction){
		case LEFT :
			x--;
			break;
		case RIGHT :
			x++;
			break;
		case UP :
			y--;
			break;
		case DOWN :
			y++;
			break;
		default :
			break;
	}
	
	if(x>=width)
		x=0;
	else if(x<0)
		x=width-1;
		
	if(y>=height)
		y=0;
	else if(y<0)
		y=height-1;
	
	for(int i=0;i<size;i++)
		if(snakex[i]==x && snakey[i]==y )
			gameOver=true;
		
	if(x==tx && y==ty){
		score+=5;
		size++;
		tx=rand()%width;
    	ty=rand()%height;		
	}
}


int main(){
    Setup();
    while(!gameOver){
        Game();
        Input();
        GameLogic();
        Sleep(60);
    }
    
    return 0;
}
 
