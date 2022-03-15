#include "calculatrice.h"
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>

calculatrice::calculatrice(QWidget *parent)
    :QWidget(parent)
{

   QWidget * num = new QWidget();
    QGridLayout * nombres = new QGridLayout(num);
    nombres->addWidget(new QPushButton("1", num), 0, 0);
    nombres->addWidget(new QPushButton("2", num), 0, 1);
    nombres->addWidget(new QPushButton("3", num), 0, 2);
    nombres->addWidget(new QPushButton("4", num), 1, 0);
    nombres->addWidget(new QPushButton("5", num), 1, 1);
    nombres->addWidget(new QPushButton("6", num), 1, 2);
    nombres->addWidget(new QPushButton("7", num), 2, 0);
    nombres->addWidget(new QPushButton("8", num), 2, 1);
    nombres->addWidget(new QPushButton("9", num), 2, 2);
    nombres->addWidget(new QPushButton("0", num), 3, 0, 1, 2);
    nombres->addWidget(new QPushButton(",", num), 3, 2);

    QWidget * calcul = new QWidget();
    QGridLayout * c = new QGridLayout(calcul);
    c->addWidget(new QPushButton("+", calcul), 0, 0);
    c->addWidget(new QPushButton("-", calcul), 0, 1);
    c->addWidget(new QPushButton("*", calcul), 1, 0);
    c->addWidget(new QPushButton("/", calcul), 1, 1);
    c->addWidget(new QPushButton("²", calcul), 2, 0);
    c->addWidget(new QPushButton("=", calcul), 2, 1);

    QVBoxLayout * V = new QVBoxLayout();

    QLineEdit * lineEdit = new QLineEdit();
    lineEdit->setAlignment(Qt::AlignRight);
    lineEdit->setReadOnly(true);
    V->addWidget(lineEdit);

    QLineEdit * op = new QLineEdit();
    op->setMaxLength(1);
    op->setFixedWidth(30);
    V->addWidget(op, 0, Qt::AlignRight);

    QWidget * box2 = new QWidget();
    QHBoxLayout * H = new QHBoxLayout();
    H->addStretch(0);
    H->addWidget(num);
    H->addWidget(calcul);
    box2->setLayout(H);

    V->addWidget(box2);
    this->setLayout(V);
    show();
}

calculatrice::~calculatrice()
{}
