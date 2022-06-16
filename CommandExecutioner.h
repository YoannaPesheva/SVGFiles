#include "Vector.h"
#include "Figures.h"
#include "Commands.h"
class CommandExecutioner {
private:
	Vector<Line*> arr;

public:
	~CommandExecutioner() {
		for (int i = 0; i < arr.getCurrSize(); i++)
		{
			delete arr[i];
		}
	}


	//start the program
	void  start();

	// commands
	void InvalidCommandMessage();

	void executeTranslation();

	void executeWithinFigure();

	void addFigure();

	void removeFigure();

	void printAll();

	void EndProgram();

};