#include "passwdgenerator.h"
#include <iostream>

#include <QCommandLineOption>
#include <QCommandLineParser>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    QCommandLineOption lengthOption(QStringList() << "l" << "length", "Password length", "LENGTH");
    lengthOption.setDefaultValue("12");
    parser.addOption(lengthOption);
    QCommandLineOption lowercaseOption(QStringList() << "a" << "lowercase", "Add lowercase");
    parser.addOption(lowercaseOption);
    QCommandLineOption uppercaseOption(QStringList() << "A" << "uppercase", "Add uppercase");
    parser.addOption(uppercaseOption);
    QCommandLineOption digitOption(QStringList() << "9" << "d" << "digits", "Add digits");
    parser.addOption(digitOption);
    QCommandLineOption specOption(QStringList() << "s" << "special", "Add special characters (&, #, $...)");
    parser.addOption(specOption);

    parser.process(app);

    PasswdGenerator generator;

    PasswdGenerator::SymbolTypes types;

    if (parser.isSet(lowercaseOption))
        types.setFlag(PasswdGenerator::Lowercase);
    if (parser.isSet(uppercaseOption))
        types.setFlag(PasswdGenerator::Uppercase);
    if (parser.isSet(digitOption))
        types.setFlag(PasswdGenerator::Digits);
    if (parser.isSet(specOption))
        types.setFlag(PasswdGenerator::Symbols);

    generator.setTypes(types);

    auto passwd = generator.generate(parser.value(lengthOption).toInt()).toLocal8Bit();
    std::cout << passwd.constData() << std::endl;

    return 0;
}
