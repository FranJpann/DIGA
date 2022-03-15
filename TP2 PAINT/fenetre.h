#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>

class fenetre : public QMainWindow
{
    Q_OBJECT
public:
    fenetre(QWidget *parent = nullptr);
    ~fenetre();
};

#endif // FENETRE_H
