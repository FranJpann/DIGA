#include "fenetre.h"
#include <QtWidgets>
#include "zonedessin.h"
#include "buttoncouleur.h"


fenetre::fenetre(QWidget *parent)
    :QMainWindow(parent)
{

/*--------------------------------------------*/

        QMenu * menuFile = new QMenu("File");
            QAction * ActionLoad = new QAction("Load a picture");
            ActionLoad->setShortcut(QKeySequence(tr("Ctrl+O")));
            QAction * ActionExit = new QAction("Exit");
            ActionExit->setShortcut(QKeySequence(tr("Ctrl+Q")));
        menuFile->addAction(ActionLoad);
        menuFile->addAction(ActionExit);

        QMenu * menuEdit = new QMenu("Edit");
            QAction * Black = new QAction("Black");
            QAction * Red = new QAction("Red");
            QAction * Green = new QAction("Green");
            QAction * Blue = new QAction("Blue");

        QAction * EraseAnnot = new QAction("Erase annotations");
        menuEdit->addAction(Black);
        menuEdit->addAction(Red);
        menuEdit->addAction(Green);
        menuEdit->addAction(Blue);
        menuEdit->addAction(EraseAnnot);

    this->menuBar()->addMenu(menuFile);
    this->menuBar()->addMenu(menuEdit);

/*--------------------------------------------*/

    QToolBar * toolbar = new QToolBar();

        QLabel * textCouleur = new QLabel("Taille du crayon :");
        QSpinBox * BoxTaille = new QSpinBox();
        BoxTaille->setValue(3);
    toolbar->addWidget(textCouleur);
    toolbar->addWidget(BoxTaille);
    toolbar->addSeparator();

    buttoncouleur * PushButtonBlack = new buttoncouleur("Black");
    buttoncouleur * PushButtonRed = new buttoncouleur("Red");
    buttoncouleur * PushButtonGreen = new buttoncouleur("Green");
    buttoncouleur * PushButtonBlue = new buttoncouleur("Blue");

    toolbar->addWidget(PushButtonBlack);
    toolbar->addWidget(PushButtonRed);
    toolbar->addWidget(PushButtonGreen);
    toolbar->addWidget(PushButtonBlue);

    toolbar->addSeparator();
    toolbar->addAction(EraseAnnot);

    this->addToolBar(toolbar);

/*--------------------------------------------*/

    zoneDessin * dessin = new zoneDessin();

    /*Charger image et exit*/

    QObject::connect(ActionLoad, &QAction::triggered,
        dessin, &zoneDessin::chargerImage);

    QObject::connect(ActionExit, &QAction::triggered,
        this, &QWidget::close);

    /*Curseur*/

    QPixmap * p = new QPixmap(3,3);
    p->fill(Qt::black);
    dessin->setCursor(QCursor(*p));

            //Taille Curseur
    QObject::connect(BoxTaille, QOverload<int>::of(&QSpinBox::valueChanged),
                     [=](int i){*p = p->scaled(QSize(i, i));
                                dessin->setCursor(QCursor(*p));});
            //Couleur Curseur
    QObject::connect(Black, &QAction::triggered,
                     [=](){p->fill(Qt::black);
                           dessin->setCursor(QCursor(*p));});
    QObject::connect(Green, &QAction::triggered,
                     [=](){p->fill(Qt::green);
                           dessin->setCursor(QCursor(*p));});
    QObject::connect(Red, &QAction::triggered,
                     [=](){p->fill(Qt::red);
                           dessin->setCursor(QCursor(*p));});
    QObject::connect(Blue, &QAction::triggered,
                     [=](){p->fill(Qt::blue);
                           dessin->setCursor(QCursor(*p));});

    /*Crayon*/
            //Couleur Crayon

    QObject::connect(Black, &QAction::triggered,
                     [=](){dessin->penColor = Qt::black;});

    QObject::connect(Green, &QAction::triggered,
        [=](){dessin->penColor = Qt::green;});

    QObject::connect(Red, &QAction::triggered,
        [=](){dessin->penColor = Qt::red;});

    QObject::connect(Blue, &QAction::triggered,
        [=](){dessin->penColor = Qt::blue;});

    QObject::connect(EraseAnnot, &QAction::triggered,
                     dessin, &zoneDessin::supprimerAnnot);

            //Taille Crayon

    QObject::connect(BoxTaille, QOverload<int>::of(&QSpinBox::valueChanged),
                     [=](int i){if(i>0) dessin->penWidth = i;});

    this->setCentralWidget(dessin);
}

fenetre::~fenetre(){}
