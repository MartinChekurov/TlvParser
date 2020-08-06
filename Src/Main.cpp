#include "TlvWindow.h"
#include "qapplication.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	TlvWindow tlvWindow{};
	tlvWindow.show();
	return app.exec();
}
