#include "Vector.h"
#include "Figures.h"
#include "Commands.h"
class CommandExecutioner {
private:
	Vector<Figure*> arr;
	void remove();

public:
	CommandExecutioner();
	CommandExecutioner(const CommandExecutioner& other);
	CommandExecutioner& operator=(const CommandExecutioner& other);
	~CommandExecutioner() { remove(); }


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