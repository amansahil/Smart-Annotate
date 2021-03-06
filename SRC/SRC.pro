QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auto_save_thread.cpp \
    custom_resizer.cpp \
    dark_style.cpp \
    image_editor.cpp \
    labeller_model.cpp \
    main.cpp \
    labeller.cpp \
    string_date_hash.cpp

HEADERS += \
    auto_save_thread.h \
    custom_resizer.h \
    dark_style.h \
    image_editor.h \
    labeller.h \
    labeller_model.h \
    string_date_hash.h

FORMS += \
    labeller.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    dark_style.qrc
