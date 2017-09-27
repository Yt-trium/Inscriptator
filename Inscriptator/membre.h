#ifndef MEMBRE_H
#define MEMBRE_H

#include <QString>
#include <QDebug>

class Membre
{
public:
    Membre();
    Membre(QString nom, QString prenom, QString email, QString annee);

    QString getNom();
    QString getPrenom();
    QString getEmail();
    QString getAnnee();

    void setNom(QString nom);
    void setPrenom(QString prenom);
    void setEmail(QString email);
    void setAnnee(QString annee);

    QString nom;
    QString prenom;
    QString email;
    QString annee;
};

#endif // MEMBRE_H
