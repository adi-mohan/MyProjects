#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <unistd.h>

using namespace std;

//int set = 0;
//int round = 0;
//int break = 0;

class Timer
{
	int sec;
public:
	void setTimer(int sec1) {
		this ->sec = sec1;
	}
	void startTimer() {
		while(sec) {
			sleep(1);
			cout << setfill(' ') << setw(55) << sec << "\a Seconds \n";
			sec--;
		}
	}
};

class Workout
{
public:
		int set;
		int round;
		int brk;
		Workout(int set1, int round1, int brk1) {
			this ->set = set1;
			this ->round = round1;
			this ->brk = brk1;
		}
		void startWorkout() {
			Timer *forSet = new Timer();
			Timer *forBreak = new Timer();
			while (round) {
				round--;
				forSet->setTimer(set);
				forBreak->setTimer(brk);
				cout << setfill(' ') << setw(88) << "------------------------------------------------\n";
				cout << setfill(' ') << setw(55) << " " << "Come on Buddy!\n" ;
				cout << setfill(' ') << setw(88) << "------------------------------------------------\n";
				forSet->startTimer();
				cout << setfill(' ') << setw(88) << "------------------------------------------------\n";
				cout << setfill(' ') << setw(55) << " " << "Break Time!\n";
				cout << setfill(' ') << setw(88) << "------------------------------------------------\n";
				forBreak->startTimer();
			}
			delete forSet;
			delete forBreak;
			cout << setfill(' ') << setw(88) << "Workout Session ends! Be wary of the diet BTW" << endl;
		}
};

/** class Tabata : public Workout
{
public:
	Tabata (int set, int round, int brk) : Workout(int set1, int round1, int brk1) {
		set1 = set;
		round1 = round;
		brk1 = brk;
	}
};
**/
int main() {
	Workout *t1 = new Workout(20, 2, 5);
	t1->startWorkout();
	delete t1;
	return 0;
}
