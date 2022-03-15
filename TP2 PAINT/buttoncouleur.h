#ifndef BUTTONCOULEUR_H
#define BUTTONCOULEUR_H

#include <QtWidgets>

class buttoncouleur : public QAbstractButton
{
    Q_OBJECT
public:
    buttoncouleur(QWidget *p = nullptr);
    buttoncouleur(QString name);
    ~buttoncouleur();
    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *e);

    QString name;
    QColor couleur;
    bool rond = true;

};

#endif // BUTTONCOULEUR_H
