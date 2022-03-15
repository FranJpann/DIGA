#include <iostream>
#include <QApplication>
#include <QtWidgets>
#include "fenetre.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    fenetre f;
    f.show();
    return a.exec();
}
