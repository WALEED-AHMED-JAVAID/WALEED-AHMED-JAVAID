#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Ball{
	public:
		int x,y;
		Ball():x(0),y(0){}
		
		void move(string direction){
			if(direction=="up") y++;
			else if(direction=="down") y--;
			else if(direction=="right") x++;
			else if(direction=="left")x--;
		}
};

class Robot{
	public:
		string name;
		int hits;
		
		Robot(string n): name(n),hits(0){}
		
		void hitball(Ball &ball,string direction){
			ball.move(direction);
			hits++;
		}
};

class Team{
	public:
		string teamname;
		Robot robot;
		
		Team(string name,string robotname): teamname(name), robot(robotname){}
		
};

class Game{
	public:
		Ball ball;
		const int goalx=3,goaly=3;
		
		void play(Team &team){
			if(ball.x!=goalx && ball.y!=goaly){
				string directions[]={"up","down","right","left"};
				string direction=directions[rand() % 4];
				
				team.robot.hitball(ball, direction);
				cout<<team.teamname<<"moved "<<direction<<"to ("<<ball.x<<","<<ball.y<<") \n";
			}
			cout<<team.teamname<<"reached goal in "<<team.robot.hits<<"hits! \n";
		}
		
		void startgame(){
			srand(time(0));
			Team teamone("Team 1","Robot 1");
			Team teamtwo("Team 2","Robot 2");
			
			cout<<"Starting game \n";
			play(teamone);
			ball=Ball();
			play(teamtwo);
			
			if(teamone.robot.hits<teamtwo.robot.hits)
			cout<<teamone.teamname<<"wins!";
			else if(teamtwo.robot.hits<teamone.robot.hits)
			cout<<teamtwo.teamname<<"wins!";
			else
			cout<<"Its a tie \n";
		}
};

int main(){
	Game game;
	game.startgame();
	return 0;
}

