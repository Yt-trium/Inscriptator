#ifndef MEMBRES_H
#define MEMBRES_H

#include <QtAlgorithms>
#include <QList>
#include <QFile>
#include <QTextStream>
#include <QDebug>

#include "membre.h"

class Membres
{
public:
    Membres();
    Membres(QString filename);

    void setFilename(QString filename);
    void load();
    void save();
    void exportMailing(QString filename);
    void trier();

    void addM(Membre m);

    QList<Membre> listM;
private:
    QString filename;
};

#endif // MEMBRES_H
