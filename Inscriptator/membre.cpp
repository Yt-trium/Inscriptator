#include "membre.h"

Membre::Membre()
{

}

Membre::Membre(QString nom, QString prenom, QString email, QString annee)
{
    this->nom = nom;
    this->prenom = prenom;
    this->email = email;
    this->annee = annee;
}

QString Membre::getNom()
{
    return nom;
}

QString Membre::getPrenom()
{
    return prenom;
}

QString Membre::getEmail()
{
    return email;
}

QString Membre::getAnnee()
{
    return annee;
}

void Membre::setNom(QString nom)
{
    this->nom = nom;
}

void Membre::setPrenom(QString prenom)
{
    this->prenom = prenom;
}

void Membre::setEmail(QString email)
{
    this->email = email;
}

void Membre::setAnnee(QString annee)
{
    this->annee = annee;
}
