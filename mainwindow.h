#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Registro.h"
#include "editactivitydialog.h"
#include "removeactivitydialog.h"
#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update(QDate o);
public slots:
    void recieveMesg(const QString &q);
    void recieveDate(const QDate &p);
    void recieveNewName(const QString &k);
    void recieveNewDesc(const QString &l);
    void recieveNewStartDate(const QDateTime &o);
    void recieveNewEndaDate(const QDateTime &z);
private slots:
    void on_actionCambia_fuso_orario_changed();

    void on_CalendarWidget_clicked(QDate date);

    void on_pushButton_clicked();

    void on_actionImposta_data_triggered();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public:
    Ui::MainWindow *ui;
    Register *rg;
    QDate searchdate;
    QString searchstring;
    QString newname;
    QDateTime newStartDate;
    QDateTime newEndDate;
    QString newDesc;
};
#endif // MAINWINDOW_H
