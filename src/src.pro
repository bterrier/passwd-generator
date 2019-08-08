TEMPLATE = subdirs
SUBDIRS += cli gui

deployqt.target = deployqt
#deployqt.commands = qmake --version
deployqt.CONFIG += phony recursive
QMAKE_EXTRA_TARGETS += deployqt
