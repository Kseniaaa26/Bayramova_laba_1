#include <iostream>
#include <string>

using namespace std;

struct Pipe {
	string name_pipe;
	double length;
	int diameter;
	bool in_repairing;
};

struct CS {
	string name_CS;
	int number_of_workshops;
	int workshops_in_operation;
	string effectiveness;
}
