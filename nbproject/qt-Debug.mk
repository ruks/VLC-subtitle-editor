#############################################################################
# Makefile for building: dist/Debug/GNU-Linux-x86/waveViewer
# Generated by qmake (2.01a) (Qt 4.8.1) on: Mon Sep 2 13:57:47 2013
# Project:  nbproject/qt-Debug.pro
# Template: app
# Command: /usr/bin/qmake VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++ -Inbproject -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -Inbproject -Inbproject -Inbproject -Inbproject -Inbproject -Inbproject -I. -I. -I.
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS)  -L/usr/lib/i386-linux-gnu -lvlc /home/rukshan/NetBeansProjects/waveViewer/lib/libsoundfile.a -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = build/Debug/GNU-Linux-x86/

####### Files

SOURCES       = smem.cpp \
		printbits.cpp \
		main.cpp \
		subtitleSave.cpp \
		subtitleEditor.cpp \
		MainWindow.cpp \
		tests/newsimpletest.cpp \
		source/tgs.cpp \
		player.cpp \
		Observable.cpp moc_MainWindow.cpp
OBJECTS       = build/Debug/GNU-Linux-x86/smem.o \
		build/Debug/GNU-Linux-x86/printbits.o \
		build/Debug/GNU-Linux-x86/main.o \
		build/Debug/GNU-Linux-x86/subtitleSave.o \
		build/Debug/GNU-Linux-x86/subtitleEditor.o \
		build/Debug/GNU-Linux-x86/MainWindow.o \
		build/Debug/GNU-Linux-x86/newsimpletest.o \
		build/Debug/GNU-Linux-x86/tgs.o \
		build/Debug/GNU-Linux-x86/player.o \
		build/Debug/GNU-Linux-x86/Observable.o \
		build/Debug/GNU-Linux-x86/moc_MainWindow.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		nbproject/qt-Debug.pro
QMAKE_TARGET  = waveViewer
DESTDIR       = dist/Debug/GNU-Linux-x86/
TARGET        = dist/Debug/GNU-Linux-x86/waveViewer

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: qttmp-Debug.mk $(TARGET)

$(TARGET): ui_MainWindow.h $(OBJECTS)  
	@$(CHK_DIR_EXISTS) dist/Debug/GNU-Linux-x86/ || $(MKDIR) dist/Debug/GNU-Linux-x86/ 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)
	{ test -n "$(DESTDIR)" && DESTDIR="$(DESTDIR)" || DESTDIR=.; } && test $$(gdb --version | sed -e 's,[^0-9]\+\([0-9]\)\.\([0-9]\).*,\1\2,;q') -gt 72 && gdb --nx --batch --quiet -ex 'set confirm off' -ex "save gdb-index $$DESTDIR" -ex quit '$(TARGET)' && test -f $(TARGET).gdb-index && objcopy --add-section '.gdb_index=$(TARGET).gdb-index' --set-section-flags '.gdb_index=readonly' '$(TARGET)' '$(TARGET)' && rm -f $(TARGET).gdb-index || true

qttmp-Debug.mk: nbproject/qt-Debug.pro  /usr/share/qt4/mkspecs/linux-g++/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/debug.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/i386-linux-gnu/libQtGui.prl \
		/usr/lib/i386-linux-gnu/libQtCore.prl
	$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/debug.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/i386-linux-gnu/libQtGui.prl:
/usr/lib/i386-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) VPATH=. -o qttmp-Debug.mk nbproject/qt-Debug.pro

dist: 
	@$(CHK_DIR_EXISTS) build/Debug/GNU-Linux-x86/waveViewer1.0.0 || $(MKDIR) build/Debug/GNU-Linux-x86/waveViewer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) build/Debug/GNU-Linux-x86/waveViewer1.0.0/ && $(COPY_FILE) --parents Observable.h subtitleEditor.h IObserver.h MainWindow.h player.h smem.h srtFormat.h header/tgs.h printbits.h subtitleSave.h build/Debug/GNU-Linux-x86/waveViewer1.0.0/ && $(COPY_FILE) --parents smem.cpp printbits.cpp main.cpp subtitleSave.cpp subtitleEditor.cpp MainWindow.cpp tests/newsimpletest.cpp source/tgs.cpp player.cpp Observable.cpp build/Debug/GNU-Linux-x86/waveViewer1.0.0/ && $(COPY_FILE) --parents MainWindow.ui build/Debug/GNU-Linux-x86/waveViewer1.0.0/ && (cd `dirname build/Debug/GNU-Linux-x86/waveViewer1.0.0` && $(TAR) waveViewer1.0.0.tar waveViewer1.0.0 && $(COMPRESS) waveViewer1.0.0.tar) && $(MOVE) `dirname build/Debug/GNU-Linux-x86/waveViewer1.0.0`/waveViewer1.0.0.tar.gz . && $(DEL_FILE) -r build/Debug/GNU-Linux-x86/waveViewer1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) qttmp-Debug.mk


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_MainWindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp
moc_MainWindow.cpp: ui_MainWindow.h \
		subtitleSave.h \
		srtFormat.h \
		Observable.h \
		subtitleEditor.h \
		IObserver.h \
		FileIO.h \
		player.h \
		header/tgs.h \
		MainWindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) MainWindow.h -o moc_MainWindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_MainWindow.h
compiler_uic_clean:
	-$(DEL_FILE) ui_MainWindow.h
ui_MainWindow.h: MainWindow.ui
	/usr/bin/uic-qt4 MainWindow.ui -o ui_MainWindow.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

build/Debug/GNU-Linux-x86/smem.o: smem.cpp smem.h \
		MainWindow.h \
		ui_MainWindow.h \
		subtitleSave.h \
		srtFormat.h \
		Observable.h \
		subtitleEditor.h \
		IObserver.h \
		FileIO.h \
		player.h \
		header/tgs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/smem.o smem.cpp

build/Debug/GNU-Linux-x86/printbits.o: printbits.cpp printbits.h \
		MainWindow.h \
		ui_MainWindow.h \
		subtitleSave.h \
		srtFormat.h \
		Observable.h \
		subtitleEditor.h \
		IObserver.h \
		FileIO.h \
		player.h \
		header/tgs.h \
		soundfile.h \
		Options.h \
		Array.h \
		Collection.h \
		Collection.cpp \
		Array.cpp \
		SoundFileRead.h \
		SoundHeader.h \
		SoundFileWrite.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/printbits.o printbits.cpp

build/Debug/GNU-Linux-x86/main.o: main.cpp smem.h \
		MainWindow.h \
		ui_MainWindow.h \
		subtitleSave.h \
		srtFormat.h \
		Observable.h \
		subtitleEditor.h \
		IObserver.h \
		FileIO.h \
		player.h \
		header/tgs.h \
		printbits.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/main.o main.cpp

build/Debug/GNU-Linux-x86/subtitleSave.o: subtitleSave.cpp subtitleSave.h \
		srtFormat.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/subtitleSave.o subtitleSave.cpp

build/Debug/GNU-Linux-x86/subtitleEditor.o: subtitleEditor.cpp subtitleEditor.h \
		IObserver.h \
		srtFormat.h \
		MainWindow.h \
		ui_MainWindow.h \
		subtitleSave.h \
		Observable.h \
		FileIO.h \
		player.h \
		header/tgs.h \
		smem.h \
		printbits.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/subtitleEditor.o subtitleEditor.cpp

build/Debug/GNU-Linux-x86/MainWindow.o: MainWindow.cpp MainWindow.h \
		ui_MainWindow.h \
		subtitleSave.h \
		srtFormat.h \
		Observable.h \
		subtitleEditor.h \
		IObserver.h \
		FileIO.h \
		player.h \
		header/tgs.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/MainWindow.o MainWindow.cpp

build/Debug/GNU-Linux-x86/newsimpletest.o: tests/newsimpletest.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/newsimpletest.o tests/newsimpletest.cpp

build/Debug/GNU-Linux-x86/tgs.o: source/tgs.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/tgs.o source/tgs.cpp

build/Debug/GNU-Linux-x86/player.o: player.cpp player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/player.o player.cpp

build/Debug/GNU-Linux-x86/Observable.o: Observable.cpp Observable.h \
		subtitleEditor.h \
		IObserver.h \
		srtFormat.h \
		FileIO.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/Observable.o Observable.cpp

build/Debug/GNU-Linux-x86/moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o build/Debug/GNU-Linux-x86/moc_MainWindow.o moc_MainWindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

