#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QClipboard>
#include <QFont>
#include <QFontDatabase>
#include <QFontInfo>

#include "passwdgenerator.h"

#include <QDebug>

static bool isFixed(const QFont &font) {
    QFontInfo fi(font);
    return fi.fixedPitch();
}

static QFont getMonospaceFont() {
    QFont font = QFontDatabase::systemFont(QFontDatabase::FixedFont);
    if (isFixed(font))
        return font;

    font.setStyleHint(QFont::Monospace);
    if (isFixed(font))
        return font;

    font.setStyleHint(QFont::TypeWriter);
    if (isFixed(font))
        return font;


    return font;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pbGenerate, &QPushButton::clicked, this, &MainWindow::onPbGenerateClicked);

    QFont font = getMonospaceFont();
    QFontInfo fi(font);
    qDebug() << fi.fixedPitch() << fi.family();
    ui->lePasswd->setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPbGenerateClicked()
{
    PasswdGenerator generator;
    PasswdGenerator::SymbolTypes types;

    if (ui->cbLowercase->isChecked())
        types.setFlag(PasswdGenerator::Lowercase);
    if (ui->cbUppercase->isChecked())
        types.setFlag(PasswdGenerator::Uppercase);
    if (ui->cbDigits->isChecked())
        types.setFlag(PasswdGenerator::Digits);
    if (ui->cbSymbols->isChecked())
        types.setFlag(PasswdGenerator::Symbols);

    generator.setTypes(types);
    QString passwd = generator.generate(ui->sbLength->value());
    ui->lePasswd->setText(passwd);
}

void MainWindow::on_cbCustom_toggled(bool checked)
{
    ui->leCustom->setEnabled(checked);
}

void MainWindow::on_pbCopy_clicked()
{
    auto clipboard = QGuiApplication::clipboard();
    clipboard->setText(ui->lePasswd->text());
}
