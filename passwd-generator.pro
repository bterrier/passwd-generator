TEMPLATE = subdirs
SUBDIRS += src
OTHER_FILES += .qmake.conf \
               .gitignore \
               README.md \
               COPYING


deployqt.target = deployqt
#deployqt.commands = qmake --version
deployqt.CONFIG += phony recursive
QMAKE_EXTRA_TARGETS += deployqt
