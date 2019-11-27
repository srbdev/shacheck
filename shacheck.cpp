#include <iostream>

#include "shacheck.h"
#include "./ui_shacheck.h"
#include "./picosha2.h"

using namespace std;

ShaCheck::ShaCheck(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ShaCheck)
{
    ui->setupUi(this);
}

ShaCheck::~ShaCheck()
{
    delete ui;
}


void ShaCheck::on_pushBtnSelectFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Select file");
    ui->labelFilename->setText(filename);
    filename_ = filename;

    // clear!
    ui->lineEditHash->setText("");
    ui->labelCalculated->setText("");
    ui->labelMatch->setText("");
}

void ShaCheck::on_pushBtnCheck_clicked()
{
    QString hash = ui->lineEditHash->text();
    QString calculatedHash = calculateHash_(filename_);

    ui->labelCalculated->setText(calculatedHash);

    if (isMatch_(calculatedHash, hash))
    {
        ui->labelMatch->setText("OK");
    } else
    {
        ui->labelMatch->setText("FAIL");
    }
}


QString ShaCheck::calculateHash_(QString filename)
{
    ifstream f(filename.toUtf8().constData(), ios::binary);
    vector<unsigned char> s(picosha2::k_digest_size);
    picosha2::hash256(f, s.begin(), s.end());
    string h = picosha2::bytes_to_hex_string(s.begin(), s.end());
    return QString::fromUtf8(h.c_str());
}

bool ShaCheck::isMatch_(QString hashA, QString hashB)
{
    return hashA.compare(&hashB) == 0;
}
