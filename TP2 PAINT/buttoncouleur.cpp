#include "buttoncouleur.h"

buttoncouleur::buttoncouleur(QWidget *parent)
    : QAbstractButton(parent){}

buttoncouleur::buttoncouleur(QString name){
    this->name = name;
    this->setFixedSize(30, 30);
    if(name == "Black") couleur = Qt::black;
    else if(name == "Red") couleur = Qt::red;
    else if(name == "Blue") couleur = Qt::blue;
    else if(name == "Green") couleur = Qt::green;
}

void buttoncouleur::paintEvent(QPaintEvent *e){
    if(rond){
        QPainter painter(this);
        painter.setBrush(QBrush(couleur));
        painter.drawEllipse(QRect(0, 0, this->width() -5, this->height()-5));
    }
    else {
        QPainter painter(this);
        QPixmap p(this->width()-5, this->height()-5);
        p.fill(couleur);
        painter.drawPixmap(0, 0, p);
    }
}

void buttoncouleur::mousePressEvent(QMouseEvent *e){

}

buttoncouleur::~buttoncouleur(){}
