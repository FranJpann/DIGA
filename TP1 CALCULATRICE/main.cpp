#include <iostream>
#include <QApplication>
#include "calculatrice.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calculatrice c;
    return a.exec();
}
