#include "passwdgenerator.h"
#include <iostream>

int main(int argc, char *argv[])
{
    PasswdGenerator generator;

    PasswdGenerator::SymbolTypes types = { PasswdGenerator::Digits, PasswdGenerator::Symbols };
    generator.setTypes(types);

    auto passwd = generator.generate(12).toLocal8Bit();
    std::cout << passwd.constData() << std::endl;

    return 0;
}
