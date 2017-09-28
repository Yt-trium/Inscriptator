#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // default file
    membres.setFilename("adem.db");
    membres.load();

    updateList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuitter_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionOuvrir_triggered()
{
    QString filename;
    filename = QFileDialog::getOpenFileName(this,
                                            "DB");

    membres.setFilename(filename);

    membres.load();

    updateList();
}

void MainWindow::on_actionSauvegarder_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this,
                                            "DB");

    membres.setFilename(filename);

    membres.save();

    updateList();
}

void MainWindow::on_pushButton_Inscription_clicked()
{
    Membre m;

    m.setNom(ui->lineEdit_Nom->text());
    m.setPrenom(ui->lineEdit_Prenom->text());
    m.setEmail(ui->lineEdit_Email->text());
    m.setAnnee(ui->comboBox_Annee->currentText());

    ui->lineEdit_Nom->clear();
    ui->lineEdit_Prenom->clear();
    ui->lineEdit_Email->clear();
    ui->comboBox_Annee->setCurrentIndex(0);

    membres.addM(m);

    updateList();
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    updateList();
}

void MainWindow::updateList()
{
    ui->listWidget->clear();

    Membre m;
    QString tmp;

    for (int i = 0; i < this->membres.listM.size(); ++i) {
        m = membres.listM.at(i);

        tmp = m.getNom() + " " + m.getPrenom() + " " +
              m.getEmail() + " " + m.getAnnee();

        if (ui->lineEdit->text().isEmpty()) {
            ui->listWidget->addItem(tmp);
        } else if (m.getNom().contains(ui->lineEdit->text()) ||
                   m.getPrenom().contains(ui->lineEdit->text())) {
            ui->listWidget->addItem(tmp);
        }

    }
}

void MainWindow::on_actionTrier_triggered()
{
    membres.trier();
    updateList();
}

void MainWindow::on_actionMulti_Fichiers_triggered()
{
    membres.exportMultiMailing();
}

void MainWindow::on_actionSimple_Fichier_triggered()
{
    QString filename;
    filename = QFileDialog::getSaveFileName(this,
                                            "mailing", "");

    membres.exportMailing(filename);
}
