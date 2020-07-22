#ifndef EDITACTIVITYDIALOG_H
#define EDITACTIVITYDIALOG_H

#include "mainwindow.h"
#include <QDialog>

namespace Ui {
class EditActivityDialog;
}

class EditActivityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditActivityDialog(QWidget *parent = nullptr);
    ~EditActivityDialog();
    QDate getInputDateDate();
    QString getInputString();
    QString getNewName();
    QString getnewDesc();
    QDate getnewStartDAte();
    QDate getnewEndDate();
signals:
    void emitSegnal(const QString &c);
    void emitDate(const QDate &d);
    void emitNewDate(const QDateTime &l);
    void emitNewName(const QString &p);
    void emitNewDesc(const QString &o);
    void emitnewEndate(const QDateTime &p);

private slots:
    void on_buttonBox_accepted();

    void on_EditStartDAte_dateChanged(const QDate &date);

    void on_EditENdDate_dateChanged(const QDate &date);

private:
    Ui::EditActivityDialog *ui;
};

#endif // EDITACTIVITYDIALOG_H
