QT       += core network

TEMPLATE = lib
CONFIG+= c++11
OBJECTS_DIR = temp/
MOC_DIR = $$OBJECTS_DIR
RCC_DIR = $$OBJECTS_DIR
UI_DIR = $$OBJECTS_DIR

HEADERS +=season.h \
    episode.h \
    series.h \
    serieslist.h \
    serieslistlist.h \
    actor.h \
    image.h \
    API/thetvdbapi.h \
    API/trakttvapi.h \
    diskcache.h

SOURCES +=season.cpp \
    episode.cpp \
    series.cpp \
    serieslist.cpp \
    serieslistlist.cpp \
    actor.cpp \
    image.cpp \
    API/thetvdbapi.cpp \
    API/trakttvapi.cpp \
    diskcache.cpp


INCLUDEPATH += $$PWD/../SignalList/source
DEPENDPATH += $$PWD/../SignalList/source


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../SignalList/release/ -lSignalList
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../SignalList/debug/ -lSignalList
else:unix: LIBS += -L$$OUT_PWD/../SignalList/ -lSignalList

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
    ANDROID_EXTRA_LIBS = $$OUT_PWD/../SignalList/libSignalList.so
}

OTHER_FILES += \
    README.md \
    .gitignore

