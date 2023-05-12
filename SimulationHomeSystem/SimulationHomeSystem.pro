QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets



CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    airconditionface.cpp \
    automodeface.cpp \
    autorunface.cpp \
    dehumidification.cpp \
    humidificationface.cpp \
    introface.cpp \
    main.cpp \
    mainwindow.cpp \
    readface.cpp \
    runface.cpp \
    sys.cpp \
    underface.cpp \
    ventilation.cpp
HEADERS += \
    airconditionface.h \
    automodeface.h \
    autorunface.h \
    dehumidification.h \
    humidificationface.h \
    introface.h \
    mainwindow.h \
    readface.h \
    runface.h \
    sys.h \
    underface.h \
    ventilation.h
FORMS += \
    mainwindow.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
