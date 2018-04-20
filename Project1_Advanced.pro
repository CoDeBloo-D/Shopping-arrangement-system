#-------------------------------------------------
#
# Project created by QtCreator 2018-04-17T22:38:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project1_Advanced
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


SOURCES += \
        main.cpp \
        home.cpp \
    user.cpp \
    file.cpp \
    admin.cpp \
    userlogin.cpp \
    usermenu.cpp \
    searchitemname.cpp \
    searchitembrand.cpp \
    searchitemvague.cpp \
    additem.cpp \
    deleteitem.cpp \
    pay.cpp \
    usercreate.cpp \
    changepassword.cpp \
    adminlogin.cpp \
    adminmenu.cpp \
    newitem.cpp \
    offitem.cpp \
    modifyitemnum.cpp \
    modifyitemprice.cpp

HEADERS += \
        home.h \
    users.h \
    user.h \
    history.h \
    item.h \
    admin.h \
    shoppingcart.h \
    file.h \
    userlogin.h \
    usermenu.h \
    searchitemname.h \
    searchitembrand.h \
    searchitemvague.h \
    additem.h \
    deleteitem.h \
    pay.h \
    usercreate.h \
    changepassword.h \
    adminlogin.h \
    adminmenu.h \
    newitem.h \
    offitem.h \
    modifyitemnum.h \
    modifyitemprice.h

FORMS += \
        home.ui \
    userlogin.ui \
    usermenu.ui \
    searchitemname.ui \
    searchitembrand.ui \
    searchitemvague.ui \
    additem.ui \
    deleteitem.ui \
    pay.ui \
    usercreate.ui \
    changepassword.ui \
    adminlogin.ui \
    adminmenu.ui \
    newitem.ui \
    offitem.ui \
    modifyitemnum.ui \
    modifyitemprice.ui

RESOURCES += \
    src/logofile.qrc
