#ifndef ZONEDESSIN_H
#define ZONEDESSIN_H

#include <QWidget>

class zoneDessin : public QWidget
{
    Q_OBJECT
public:
    zoneDessin(QWidget *parent = nullptr);
    ~zoneDessin();
    void paintEvent(QPaintEvent* e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    bool OpenImage(const QString &filename);
    bool SaveImage(const QString &filename);
    void chargerImage();
    void supprimerAnnot();

    QPoint x;
    QPoint y;
    QPixmap image;
    QString imageName;
    bool dessine = true;
    bool zone = false;
    QColor penColor = Qt::black;
    int penWidth = 3;
};


#endif // ZONEDESSIN_H
