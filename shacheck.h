#ifndef SHACHECK_H
#define SHACHECK_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class ShaCheck; }
QT_END_NAMESPACE

class ShaCheck : public QMainWindow
{
    Q_OBJECT

public:
    ShaCheck(QWidget *parent = nullptr);
    ~ShaCheck();

private slots:
    void on_pushBtnSelectFile_clicked();
    void on_pushBtnCheck_clicked();

private:
    Ui::ShaCheck *ui;
    QString filename_;
    QString calculateHash_(QString filename);
    bool isMatch_(QString hashA, QString hashB);
};
#endif // SHACHECK_H
