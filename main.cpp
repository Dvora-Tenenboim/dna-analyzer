#include "Controller/controller.h"
#include "Controller/console_reader.h"
#include "View/console_writer.h"

int main()
{
	ConsoleReader reader;
	ConsoleWriter writer;
	Controller controller(&reader, &writer);
	return 0;
}
