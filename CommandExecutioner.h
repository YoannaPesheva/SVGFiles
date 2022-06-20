#include "Vector.h"
#include "Figures.h"
#include "Commands.h"

class CommandExecutioner {
private:
	ShapesContainer arr;

public:

	//start the program
	void  start();


	//file related commands
	void openFile();

	void closeFile();

	void saveChanges();

	//void saveChangesAs();

	// commands
	void InvalidCommandMessage();

	void executeTranslation();

	void executeWithinFigure();

	void addFigure();

	void removeFigure();

	void printAll();

	void EndProgram();

};