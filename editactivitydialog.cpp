#include "editactivitydialog.h"
#include "Registro.h"
#include "ui_editactivitydialog.h"
#include <iostream>

EditActivityDialog::EditActivityDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::EditActivityDialog)
{
    ui->setupUi(this);
    ui->EditStartDAte->setDate(QDate::currentDate());
    ui->EditStartDAte->setTime(QTime::currentTime());
    ui->EditENdDate->setTime(QTime::currentTime().addSecs(60));
    ui->EditENdDate->setDate(QDate::currentDate());
    ui->InputDateEdit->setDate(QDate::currentDate());
    connect(this, SIGNAL(emitSegnal(QString)), parent, SLOT(recieveMesg(QString)));
    connect(this, SIGNAL(emitDate(QDate)), parent, SLOT(recieveDate(QDate)));
    connect(this, SIGNAL(emitNewName(QString)), parent, SLOT(recieveNewName(QString)));
    connect(this, SIGNAL(emitNewDesc(QString)), parent, SLOT(recieveNewDesc(QString)));
    connect(this, SIGNAL(emitNewDate(QDateTime)), parent, SLOT(recieveNewStartDate(QDateTime)));
    connect(this, SIGNAL(emitnewEndate(QDateTime)), parent, SLOT(recieveNewEndaDate(QDateTime)));
}

EditActivityDialog::~EditActivityDialog()
{
    delete ui;
}

void EditActivityDialog::on_buttonBox_accepted()
{
    emit emitSegnal(ui->InputString->text());
    emit emitDate(ui->InputDateEdit->date());
    emit emitNewName(ui->NewNameString->text());
    emit emitNewDesc(ui->NewDescString->text());
    emit emitNewDate(ui->EditStartDAte->dateTime());
    emit emitnewEndate(ui->EditENdDate->dateTime());
}

QDate EditActivityDialog::getInputDateDate()
{
    QDate c;
    c = ui->InputDateEdit->date();
    return c;
}

QString EditActivityDialog::getInputString()
{
    QString d;
    d = ui->InputString->text();
    return d;
}

QString EditActivityDialog::getNewName()
{
    QString f;
    f = ui->NewNameString->text();
    return f;
}
QString EditActivityDialog::getnewDesc()
{
    QString p;
    p = ui->NewDescString->text();
    return p;
}
QDate EditActivityDialog::getnewStartDAte()
{
    QDate o;
    o = ui->EditStartDAte->date();
    return o;
}

QDate EditActivityDialog::getnewEndDate()
{
    QDate k;
    k = ui->EditENdDate->date();
    return k;
}

void EditActivityDialog::on_EditStartDAte_dateChanged(const QDate &date)
{
    ui->EditENdDate->setDate(date);
}

void EditActivityDialog::on_EditENdDate_dateChanged(const QDate &date)
{
    ui->EditStartDAte->setDate(date);
}
