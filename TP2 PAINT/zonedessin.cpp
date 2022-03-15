#include "zonedessin.h"
#include <QtWidgets>

zoneDessin::zoneDessin(QWidget *parent)
    :QWidget(parent)
{
    this->setFixedSize(800, 600);
}

bool zoneDessin::OpenImage(const QString &filename){
    imageName = filename;
    return image.load(filename);
}

void zoneDessin::chargerImage(){
    QString file = QFileDialog::getOpenFileName(this);
    OpenImage(file);
    image = image.scaled(this->rect().size());
    imageName = file;
    zone = true;
    update();
}

bool zoneDessin::SaveImage(const QString &filename){
    return image.save(filename, "jpg");
}

void zoneDessin::paintEvent(QPaintEvent *e){
       if(zone) {
            QPainter painter(this);
            if(dessine){
                QPainter painterImage(&image);
                painterImage.setPen(QPen(penColor, penWidth));
                painterImage.drawLine(y, x);
                update();
                y=x;
            }
            painter.drawPixmap(QPoint(0,0), image);
        }
}

void zoneDessin::mousePressEvent(QMouseEvent *e){
    if(e->button() == Qt::LeftButton){
        x = e->pos();
        y=x;
        dessine = true;
    }
}

void zoneDessin::mouseMoveEvent(QMouseEvent *e){
    if((e->type() == QEvent::MouseMove) && dessine){
        x = e->pos();
        update();
    }
}

void zoneDessin::mouseReleaseEvent(QMouseEvent *e){
    if((e->button() == Qt::LeftButton) && dessine){
        dessine = false;
    }
}

void zoneDessin::supprimerAnnot(){
    OpenImage(imageName);
    image = image.scaled(this->rect().size());
    update();
}

zoneDessin::~zoneDessin(){}
