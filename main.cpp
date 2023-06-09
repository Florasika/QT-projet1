#include <QApplication>
#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Calculator *winCal = new Calculator;
    winCal->show();
    return app.exec();
}
