#include "mainwindow.h"
#include "Registro.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    rg = new Register();
    ui->StartTimeEdit->setTime(QTime::currentTime());
    ui->EndTimeEdit->setTime(QTime::currentTime().addSecs(60));
    MainWindow::update(ui->CalendarWidget->selectedDate());
    QMessageBox k;
    k.setIcon(QMessageBox::Information);
    k.warning(this,
              "Informazioni",
              "Per praticità, è impossibile impostare una attività in date minori al 1600 d.C e in "
              "date maggiori al 2100 d.C");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update(QDate o)
{
    Date f;
    f.ConvertFromQdate(o);
    ui->textBrowser->setText(rg->output2(f));
}

void MainWindow::on_actionCambia_fuso_orario_changed() {}

//Add Activity
void MainWindow::on_pushButton_clicked()
{
    //converting from a QDate type(returned by QT widgets) to Date type used by Registro
    QDate f;
    QTime sd;
    sd = ui->StartTimeEdit->time();
    QTime ed;
    ed = ui->EndTimeEdit->time();
    f  = ui->CalendarWidget->selectedDate();
    Date c;
    c.ConvertFromQdate(f);
    c.COnvertFromQTime(sd);
    Date e;
    e.COnvertFromQTime(ed);
    e.ConvertFromQdate(f);
    Activity z("", "", c, e);
    if (ui->NameLine->text().isEmpty() && ui->DescName->text().isEmpty()) {
        //error message
        ui->DescName->setText("Errore, inserisci una desc");
        ui->NameLine->setText("Errore, inserisci un nome");
    } else {
        if (sd >= ed) {
            std::cout << "Errore!" << std::endl;
            QMessageBox c;
            c.critical(this,
                       tr("Errore"),
                       tr("L'orario di fine deve essere maggiore/uguale dell'orario di'inizio"));
            c.setIcon(QMessageBox::Critical);
        } else {
            QString o;
            o = ui->NameLine->text();
            QString n;
            n = ui->DescName->text();
            z.setDescriptionName(n.toStdString());
            z.setName(o.toStdString());
            Date k;
            k.ConvertFromQdate(f);
            rg->addActivity(k, z);
            rg->printSpecificDay(k);
            MainWindow::update(ui->CalendarWidget->selectedDate());
        }
    }
}

//FIXME implement
void MainWindow::on_actionImposta_data_triggered()
{
    QDate d;
    d.setDate(2002, 01, 10);
    ui->CalendarWidget->setSelectedDate(d);
}
void MainWindow::on_CalendarWidget_clicked(QDate date)
{
    MainWindow::update(date);
}

//Delete activity
void MainWindow::on_pushButton_2_clicked()
{
    RemoveActivityDialog *p;
    p = new RemoveActivityDialog(this);
    p->show();
    if (p->exec() == 1) {
        Date s;
        std::string k;
        s.ConvertFromQdate(searchdate);
        k = searchstring.toStdString();
        rg->DeleteActivity(s, k);
        MainWindow::update(ui->CalendarWidget->selectedDate());
    }
}
//edit Activity
void MainWindow::on_pushButton_3_clicked()
{
    EditActivityDialog *c;
    c = new EditActivityDialog(this);
    c->show();
    if (c->exec() == 1) {
        //if il dialogo è stato accettato
        //code for searching activity by name and start date
        Date converted;
        converted.ConvertFromQdate(searchdate);
        std::string st;
        st = searchstring.toStdString();
        //code for editing the activity
        Date pa;
        pa.ConvertFromQdate(MainWindow::newStartDate.date());
        std::string k;
        Date ka;
        ka.ConvertFromQdate(MainWindow::newStartDate.date());
        ka.COnvertFromQTime(MainWindow::newStartDate.time());
        Date ed;
        ed.ConvertFromQdate(MainWindow::newEndDate.date());
        ed.COnvertFromQTime(MainWindow::newEndDate.time());
        k = MainWindow::newname.toStdString();
        rg->editActivity(converted, st, pa, ka, ed, k);
        MainWindow::update(ui->CalendarWidget->selectedDate());
    }
}
void MainWindow::recieveMesg(const QString &q)
{
    MainWindow::searchstring = q;
}
void MainWindow::recieveDate(const QDate &p)
{
    MainWindow::searchdate = p;
}

void MainWindow::recieveNewName(const QString &k)
{
    MainWindow::newname = k;
}

void MainWindow::recieveNewDesc(const QString &l)
{
    MainWindow::newDesc = l;
}

void MainWindow::recieveNewStartDate(const QDateTime &o)
{
    MainWindow::newStartDate = o;
}

void MainWindow::recieveNewEndaDate(const QDateTime &z)
{
    MainWindow::newEndDate = z;
}
