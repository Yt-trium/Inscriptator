#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QDebug>

#include "membres.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuitter_triggered();

    void on_actionOuvrir_triggered();

    void on_actionSauvegarder_triggered();

    void on_pushButton_Inscription_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_actionExporter_Mailing_triggered();

    void on_actionTrier_triggered();

private:
    Ui::MainWindow *ui;

    Membres membres;

    void updateList();
};

#endif // MAINWINDOW_H
