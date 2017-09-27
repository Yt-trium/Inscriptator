#include "membres.h"

Membres::Membres()
{
    listM.clear();
}

Membres::Membres(QString filename)
{
    listM.clear();
    this->filename = filename;
}

void Membres::setFilename(QString filename)
{
    this->filename = filename;
}

void Membres::load()
{
    this->listM.clear();
    if(!filename.isEmpty())
    {
        QFile file(filename);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        QTextStream flux(&file);
        flux.setCodec("UTF-8");

        Membre m;
        QString tmp1, tmp2, tmp3, tmp4;

        while(!flux.atEnd())
        {
            tmp1 = flux.readLine();
            tmp2 = flux.readLine();
            tmp3 = flux.readLine();
            tmp4 = flux.readLine();

            m.setNom(tmp1);
            m.setPrenom(tmp2);
            m.setEmail(tmp3);
            m.setAnnee(tmp4);

            this->listM.append(m);
        }

        file.close();
    }
}

void Membres::save()
{
    if(!filename.isEmpty())
    {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream flux(&file);
        flux.setCodec("UTF-8");

        Membre m;

        for(int i=0;i<this->listM.size();++i)
        {
            m = listM.at(i);
            flux << m.getNom()   << "\n" << m.getPrenom() << "\n"
                 << m.getEmail() << "\n" << m.getAnnee() << "\n";
        }

        file.close();
    }
}

void Membres::exportMailing(QString filename)
{
    this->trier();

    if(!filename.isEmpty())
    {
        QFile file(filename);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
            return;

        QTextStream flux(&file);
        flux.setCodec("UTF-8");

        Membre m;
        QString actual = "";


        for(int i=0;i<this->listM.size();++i)
        {
            m = listM.at(i);

            if(m.getAnnee() != actual)
            {
                actual = m.getAnnee();

                flux << actual.toLower() << ":";
            }
            flux << "\t\t" << m.getEmail() << ",\n";
        }
        file.close();
    }
}

void Membres::trier()
{
    qSort(listM.begin(), listM.end(),
        [](const Membre a, const Membre b) -> bool { return a.annee < b.annee; }
    );
}

void Membres::addM(Membre m)
{
    this->listM.append(m);
}
