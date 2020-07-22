#include "removeactivitydialog.h"
#include "ui_removeactivitydialog.h"

RemoveActivityDialog::RemoveActivityDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::RemoveActivityDialog)
{
    ui->setupUi(this);
    ui->buttonBox->button(QDialogButtonBox::Ok)->setText("Delete");
    ui->dateEdit->setDate(QDate::currentDate());
    connect(this, SIGNAL(emitSearchDate(QDate)), parent, SLOT(recieveDate(QDate)));
    connect(this, SIGNAL(emitSearchString(QString)), parent, SLOT(recieveMesg(QString)));
}

RemoveActivityDialog::~RemoveActivityDialog()
{
    delete ui;
}

void RemoveActivityDialog::on_buttonBox_accepted()
{
    emit emitSearchString(ui->lineEdit->text());
    emit emitSearchDate(ui->dateEdit->date());
}
