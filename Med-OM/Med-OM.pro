#-------------------------------------------------
#
# Project created by QtCreator 2019-10-17T15:05:59
#
#-------------------------------------------------

QT       += core gui printsupport serialport
QT       += widgets multimedia
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Med-OM
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += resources_big

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    dashboard.cpp \
    connection_med_om.cpp \
    login_add.cpp \
    gestion_login.cpp \
    gestion_login2.cpp \
    login_ajouter.cpp \
    login_modifier.cpp \
    login_historique.cpp \
    login_class.cpp \
    arduino.cpp \
    login_historique_class.cpp \
    rdv.cpp \
    rendez_vous.cpp \
    mainwin.cpp \
    ordonnance.cpp \
    chambre.cpp \
    patient.cpp \
    dialog.cpp \
    gestion_patient.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    dashboard.h \
    connection_med_om.h \
    login_add.h \
    gestion_login.h \
    gestion_login2.h \
    login_ajouter.h \
    login_modifier.h \
    login_historique.h \
    login_class.h \
    arduino.h \
    login_historique_class.h \
    rdv.h \
    rendez_vous.h \
    mainwin.h \
    ordonnance.h \
    chambre.h \
    patient.h \
    dialog.h \
    gestion_patient.h

FORMS += \
        mainwindow.ui \
    login.ui \
    dashboard.ui \
    login_add.ui \
    gestion_login.ui \
    gestion_login2.ui \
    login_ajouter.ui \
    login_modifier.ui \
    login_historique.ui \
    rendez_vous.ui \
    mainwin.ui \
    dialog.ui \
    gestion_patient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image_ressources.qrc
