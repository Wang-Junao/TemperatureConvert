#include "tempwindow.h"
#include "ui_tempwindow.h"
#include "Atom.h"
#include <QDoubleValidator>
#include <string>
#include <QMessageBox>
#include <QStack>
#include <iostream>
using namespace std;
[[maybe_unused]] double Cc, Ff, Kk, Rr, Rere;
[[maybe_unused]] bool JC = true, JF = false, JK = false, JR = false, JRE = false;

class ConvertData {
public:
    double ConvertC, ConvertF, ConvertK, ConvertR, ConvertRe;
};

[[maybe_unused]] auto *ConvertNumber = new ConvertData;
[[maybe_unused]] QStack<ConvertData *> DoIt;

TempWindow::TempWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::TempWindow) {
    ui->setupUi(this);
    QDoubleValidator *CValidator, *FValidator, *KValidator, *RValidator, *ReValidator;
    CValidator = new QDoubleValidator(-273.15, 999.99, 2, this);
    FValidator = new QDoubleValidator(-459.67, 999.99, 2, this);
    KValidator = new QDoubleValidator(0, 999.99, 2, this);
    RValidator = new QDoubleValidator(0, 999.99, 2, this);
    ReValidator = new QDoubleValidator(-218.52, 999.99, 2, this);
    ui->InputC->setValidator(CValidator);
    ui->InputF->setValidator(FValidator);
    ui->InputK->setValidator(KValidator);
    ui->InputR->setValidator(RValidator);
    ui->InputRe->setValidator(ReValidator);
    connect(ui->About, &QAction::triggered, this, &TempWindow::AboutThis);
    connect(ui->Update, &QAction::triggered, this, &TempWindow::UpdateLog);
    connect(ui->Explain, &QAction::triggered, this, &TempWindow::Explain);
    connect(ui->ExitAction, &QAction::triggered, this, &TempWindow::Exiter);
    connect(ui->ExitButton, &QPushButton::clicked, this, &TempWindow::Exiter);
    connect(ui->ClearAction, &QAction::triggered, this, &TempWindow::ClearAll);
    connect(ui->ClearButton, &QPushButton::clicked, this, &TempWindow::ClearAll);
    connect(ui->ConvertAction, &QAction::triggered, this, &TempWindow::ConvertTemp);
    connect(ui->ConvertButton, &QPushButton::clicked, this, &TempWindow::ConvertTemp);
    connect(ui->InputC, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    connect(ui->InputF, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    connect(ui->InputK, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    connect(ui->InputR, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    connect(ui->InputRe, &QLineEdit::textChanged, this, &TempWindow::TheNew);

}

void TempWindow::Exiter() {
    QApplication::exit();
}

void TempWindow::ConvertTemp() {
    ReadValue();
    if (JC) {
        ConvertNumber->ConvertC = Cc;
        ui->InputC->setText(QString::number(ConvertNumber->ConvertC, 'f', 2));
        ConvertNumber->ConvertF = Atom::CToF(ConvertNumber->ConvertC);
        QString setStr = QString::number(ConvertNumber->ConvertF, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertF, "InputF")) {
            ui->InputF->setText(setStr);
        }
        ConvertNumber->ConvertK = Atom::CToK(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertK, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertK, "InputK")) {
            ui->InputK->setText(setStr);
        }
        ConvertNumber->ConvertR = Atom::CToR(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertR, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertR, "InputR")) {
            ui->InputR->setText(setStr);
        }
        ConvertNumber->ConvertRe = Atom::CToRe(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertRe, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertRe, "InputRe")) {
            ui->InputRe->setText(setStr);
        }
        DoIt.push(ConvertNumber);
        return;
    }
    if (JF) {
        ConvertNumber->ConvertF = Ff;
        ui->InputF->setText(QString::number(ConvertNumber->ConvertF, 'f', 2));
        ConvertNumber->ConvertC = Atom::FToC(ConvertNumber->ConvertF);
        QString setStr = QString::number(ConvertNumber->ConvertC, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertC, "InputC")) {
            ui->InputC->setText(setStr);
        }

        ConvertNumber->ConvertK = Atom::CToK(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertK, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertK, "InputK")) {
            ui->InputK->setText(setStr);
        }

        ConvertNumber->ConvertR = Atom::CToR(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertR, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertR, "InputR")) {
            ui->InputR->setText(setStr);
        }

        ConvertNumber->ConvertRe = Atom::CToRe(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertRe, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertRe, "InputRe")) {
            ui->InputRe->setText(setStr);
        }
        DoIt.push(ConvertNumber);
        return;
    }
    if (JK) {
        ConvertNumber->ConvertK = Kk;
        ui->InputK->setText(QString::number(ConvertNumber->ConvertK, 'f', 2));
        ConvertNumber->ConvertC = Atom::KToC(ConvertNumber->ConvertK);
        QString setStr = QString::number(ConvertNumber->ConvertC, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertC, "InputC")) {
            ui->InputC->setText(setStr);
        }

        ConvertNumber->ConvertF = Atom::CToF(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertF, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertF, "InputF")) {
            ui->InputF->setText(setStr);
        }

        ConvertNumber->ConvertR = Atom::CToR(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertR, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertR, "InputR")) {
            ui->InputR->setText(setStr);
        }

        ConvertNumber->ConvertRe = Atom::CToRe(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertRe, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertRe, "InputRe")) {
            ui->InputRe->setText(setStr);
        }
        DoIt.push(ConvertNumber);
        return;
    }
    if (JR) {
        ConvertNumber->ConvertR = Rr;
        ui->InputR->setText(QString::number(ConvertNumber->ConvertR, 'f', 2));
        ConvertNumber->ConvertC = Atom::RToC(ConvertNumber->ConvertR);
        QString setStr = QString::number(ConvertNumber->ConvertC, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertC, "InputC")) {
            ui->InputC->setText(setStr);
        }

        ConvertNumber->ConvertF = Atom::CToF(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertF, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertF, "InputF")) {
            ui->InputF->setText(setStr);
        }

        ConvertNumber->ConvertK = Atom::CToK(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertR, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertK, "InputK")) {
            ui->InputK->setText(setStr);
        }

        ConvertNumber->ConvertRe = Atom::CToRe(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertRe, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertRe, "InputRe")) {
            ui->InputRe->setText(setStr);
        }
        DoIt.push(ConvertNumber);
        return;
    }
    if (JRE) {
        ConvertNumber->ConvertRe = Rere;
        ui->InputRe->setText(QString::number(ConvertNumber->ConvertRe, 'f', 2));
        ConvertNumber->ConvertC = Atom::ReToC(ConvertNumber->ConvertRe);
        QString setStr = QString::number(ConvertNumber->ConvertC, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertC, "InputC")) {
            ui->InputC->setText(setStr);
        }

        ConvertNumber->ConvertF = Atom::CToF(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertF, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertF, "InputF")) {
            ui->InputF->setText(setStr);
        }

        ConvertNumber->ConvertK = Atom::CToK(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertK, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertK, "InputK")) {
            ui->InputK->setText(setStr);
        }

        ConvertNumber->ConvertR = Atom::CToR(ConvertNumber->ConvertC);
        setStr = QString::number(ConvertNumber->ConvertR, 'f', 2);
        if (TooBigNumber(ConvertNumber->ConvertR, "InputR")) {
            ui->InputR->setText(setStr);
        }
        DoIt.push(ConvertNumber);
        return;
    }
    if(!DoIt.empty()) {
        cout<<"Emp"<<endl;
    }
    JC = false;
    JF = false;
    JK = false;
    JR = false;
    JRE = false;
    if(!DoIt.empty()) {
        cout<<"NM"<<endl;
    }
    if(DoIt.empty()) {
        cout<<"M"<<endl;
    }
    cout<<DoIt.pop()->ConvertC<<endl;
    cout<<"S"<<endl;
}

void TempWindow::TheNew() {
    QObject *Sender = this->sender();
    string ObjName = Sender->objectName().toStdString();
    if (ObjName == "InputC") {
        JC = true;
        JF = false;
        JK = false;
        JR = false;
        JRE = false;
    }
    if (ObjName == "InputF") {
        JC = false;
        JF = true;
        JK = false;
        JR = false;
        JRE = false;
    }
    if (ObjName == "InputK") {
        JC = false;
        JF = false;
        JK = true;
        JR = false;
        JRE = false;
    }
    if (ObjName == "InputR") {
        JC = false;
        JF = false;
        JK = false;
        JR = true;
        JRE = false;
    }
    if (ObjName == "InputRe") {
        JC = false;
        JF = false;
        JK = false;
        JR = false;
        JRE = true;
    }
    if (ui->InputC->text().toDouble() < -273.15) {
        ui->InputC->setText("-273.15");
    }
    if (ui->InputF->text().toDouble() < -459.67) {
        ui->InputF->setText("-459.67");
    }
    if (ui->InputK->text().toDouble() < 0.00) {
        ui->InputK->setText("0.00");
    }
    if (ui->InputR->text().toDouble() < 0.00) {
        ui->InputC->setText("0.00");
    }
    if (ui->InputRe->text().toDouble() < -218.52) {
        ui->InputRe->setText("-218.52");
    }
    if (ui->InputC->text().toDouble() > 999.99) {
        ui->InputC->setText("999.99");
    }
    if (ui->InputF->text().toDouble() > 999.99) {
        ui->InputF->setText("999.99");
    }
    if (ui->InputK->text().toDouble() > 999.99) {
        ui->InputK->setText("999.99");
    }
    if (ui->InputR->text().toDouble() > 999.99) {
        ui->InputR->setText("999.99");
    }
    if (ui->InputRe->text().toDouble() > 999.99) {

        ui->InputRe->setText("999.99");
    }
}

void TempWindow::ClearAll() {
    disconnect(ui->InputF, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    disconnect(ui->InputK, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    disconnect(ui->InputR, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    disconnect(ui->InputRe, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    disconnect(ui->InputC, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    ui->InputC->clear();
    ui->InputF->clear();
    ui->InputK->clear();
    ui->InputR->clear();
    ui->InputRe->clear();
    JC = true;
    connect(ui->InputC, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    connect(ui->InputF, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    connect(ui->InputK, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    connect(ui->InputR, &QLineEdit::textChanged, this, &TempWindow::TheNew);
    connect(ui->InputRe, &QLineEdit::textChanged, this, &TempWindow::TheNew);
}

void TempWindow::ReadValue() {

    Cc = ui->InputC->text().toDouble();

    Ff = ui->InputF->text().toDouble();

    Kk = ui->InputK->text().toDouble();

    Rr = ui->InputR->text().toDouble();

    Rere = ui->InputRe->text().toDouble();
}

bool TempWindow::TooBigNumber(const double &value, const QString &name) {
    string Name = name.toStdString();
    if (value > 999.99) {
        if (Name == "InputC") {
            ui->InputC->setText("Value is too big!");
        }
        if (Name == "InputF") {
            ui->InputF->setText("Value is too big!");
        }
        if (Name == "InputK") {
            ui->InputK->setText("Value is too big!");
        }
        if (Name == "InputR") {
            ui->InputR->setText("Value is too big!");
        }
        if (Name == "InputRe") {
            ui->InputRe->setText("Value is too big!");
        }
        return false;
    }
    return true;
}

void TempWindow::AboutThis() {
    QString str = R"(温度转换小工具v2.1.1
开发者：汪俊豪
开发日期：2023-2-9
发布日期：2023-2-12)";
    QMessageBox MsgBox(QMessageBox::Information, "关于", str);
    MsgBox.setStandardButtons(QMessageBox::Ok);
    MsgBox.setButtonText(QMessageBox::Ok, "好的");
    MsgBox.setWindowIcon(QIcon("Temp.png"));
    MsgBox.show();
    MsgBox.exec();
}

void TempWindow::UpdateLog() {
    QString str = R"(更新日志
v0.0.1：基础界面
v1.0.1：加入摄氏度与华氏度的互相转换
v2.0.1：加入开尔文、兰氏度、列氏度的互相转换
v2.1.1：修复了一些已知的问题)";
    QMessageBox MsgBox(QMessageBox::Information, "更新日志", str);
    MsgBox.setStandardButtons(QMessageBox::Ok);
    MsgBox.setButtonText(QMessageBox::Ok, "好的");
    MsgBox.setWindowIcon(QIcon("Temp.png"));
    MsgBox.show();
    MsgBox.exec();
}

void TempWindow::Explain() {
    /*ExplainWindow WinShow;
    WinShow.setWindowFlags(Qt::Window | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    WinShow.show();
    WinShow.exec();*/
    QString str = R"(<html><head/><body><p><span style=" font-size:8pt;">在百度百科上寻求帮助</span></p><p><span style=" font-size:8pt;">什么是摄氏度？</span><a href="https://baike.baidu.com/item/%E6%91%84%E6%B0%8F%E5%BA%A6/7704261"><span style=" font-size:8pt; text-decoration: underline; color:#0000ff;">点这里</span></a></p><p><span style=" font-size:8pt;">什么是华氏度？</span><a href="https://baike.baidu.com/item/%E5%8D%8E%E6%B0%8F%E5%BA%A6"><span style=" font-size:8pt; text-decoration: underline; color:#0000ff;">点这里</span></a></p><p><span style=" font-size:8pt;">什么是开尔文？</span><a href="https://baike.baidu.com/item/%E5%BC%80%E5%B0%94%E6%96%87/5470"><span style=" font-size:8pt; text-decoration: underline; color:#0000ff;">点这里</span></a></p><p><span style=" font-size:8pt;">什么是兰氏度？</span><a href="https://baike.baidu.com/item/%E5%85%B0%E6%B0%8F%E5%BA%A6"><span style=" font-size:8pt; text-decoration: underline; color:#0000ff;">点这里</span></a></p><p><span style=" font-size:8pt;">什么是列氏度？</span><a href="https://baike.baidu.com/item/%E5%88%97%E6%B0%8F%E5%BA%A6"><span style=" font-size:8pt; text-decoration: underline; color:#0000ff;">点这里</span></a></p></body></html>)";
    QMessageBox MsgBox(QMessageBox::Information, "说明", str);
    MsgBox.setStandardButtons(QMessageBox::Ok);
    MsgBox.setButtonText(QMessageBox::Ok, "好的");
    MsgBox.setWindowIcon(QIcon("Temp.png"));
    MsgBox.show();
    MsgBox.exec();
}

TempWindow::~TempWindow() {
    delete ui;
}
