#ifndef REMOVEACTIVITYDIALOG_H
#define REMOVEACTIVITYDIALOG_H
#include <QPushButton>
#include <qdialog.h>

namespace Ui {
class RemoveActivityDialog;
}

class RemoveActivityDialog : public QDialog
{
    Q_OBJECT
signals:
    void emitSearchString(const QString &c);
    void emitSearchDate(const QDate &d);

public:
    explicit RemoveActivityDialog(QWidget *parent = nullptr);
    ~RemoveActivityDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::RemoveActivityDialog *ui;
};

#endif // REMOVEACTIVITYDIALOG_H
