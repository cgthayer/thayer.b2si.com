# Generated automatically from Makefile.in by configure.
# Makefile.in generated automatically by automake from Makefile.am.
# Copyright (C) 1994 Free Software Foundation, Inc.

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

SHELL = /bin/sh

srcdir = .
top_srcdir = ..
prefix = /usr/local
exec_prefix = ${prefix}

bindir = $(exec_prefix)/bin
sbindir = $(exec_prefix)/sbin
libexecdir = $(exec_prefix)/libexec
datadir = $(prefix)/share
sysconfdir = $(prefix)/etc
sharedstatedir = $(prefix)/com
localstatedir = $(prefix)/var
libdir = $(exec_prefix)/lib
infodir = $(prefix)/info
mandir = $(prefix)/man
includedir = $(prefix)/include
oldincludedir = /usr/include

INSTALL = .././install-sh -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
transform = s,x,x,

ALL = ${PROGRAMS} ${LIBPROGRAMS} ${SCRIPTS} ${LIBSCRIPTS} ${LIBFILES}
CC = gcc
LEX = @LEX@
YACC = @YACC@
ANSI2KNR = ./ansi2knr

DEFS = -DHAVE_CONFIG_H
CPPFLAGS = 
CFLAGS = -g -O
LDFLAGS = 
LIBS =  -lintl

find_OBJECTS = find.o fstype.o parser.o pred.o tree.o util.o version.o
NROFF = nroff

SOURCES =  ${find_SOURCES}
DIST_CONF = Makefile.am Makefile.in
DIST_FILES = $(DIST_CONF) $(SOURCES) $(TEXINFOS) $(INFOS) $(MANS) $(DIST_OTHER)

PROGRAMS = find
find_SOURCES = find.c fstype.c parser.c pred.c tree.c util.c version.c
DIST_OTHER = defs.h
INCLUDES = -I.. -I$(top_srcdir)/lib
LDADD = ../lib/libfind.a
MANS = find.1
CONFIG_HEADER = ../config.h

all:: ${ALL}

.c.o:
	$(CC) -c $(DEFS) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) $<

$(find_OBJECTS): ../config.h
install:: install-programs

install-programs: $(PROGRAMS) $(SCRIPTS)
	$(top_srcdir)/mkinstalldirs $(bindir)
	for p in $(PROGRAMS) $(SCRIPTS); do \
	  $(INSTALL_PROGRAM) $$p $(bindir)/`echo $$p|sed '$(transform)'`; \
	done

uninstall:: uninstall-programs

uninstall-programs:
	for p in $(PROGRAMS) $(SCRIPTS); do \
	  rm -f $(bindir)/`echo $$p|sed '$(transform)'`; \
	done

find: $(find_OBJECTS)
	$(CC) -o $@ $(find_OBJECTS) $(LDADD) $(LDFLAGS) $(LIBS)

install:: install-man

install-man:
	for man in $(MANS); do \
	  sect=`echo $$man|sed 's%.*\.\([0-9][a-z]*\)$$%\1%'`; \
	  inst=`basename $$man $$sect|sed '$(transform)'`$$sect; \
	  mdir=$(mandir)/man$$sect; \
	  $(top_srcdir)/mkinstalldirs $$mdir; \
	  echo installing $$man as $$mdir/$$inst; \
	  $(INSTALL_DATA) $(srcdir)/$$man $$mdir/$$inst; \
	  cdir=$(mandir)/cat$$sect; \
	  if test -d $$cdir; then \
	    echo formatting $$man as $$cdir/$$inst; \
	    $(NROFF) -man $(srcdir)/$$man > $$cdir/$$inst; \
	  fi; \
	done

uninstall:: uninstall-man

uninstall-man:
	for man in $(MANS); do \
	  sect=`echo $$man|sed 's%.*\(\.[0-9][a-z]*\)$$%\1%'; \
	  inst=`basename $$man $sect|sed '$(transform)'`.$$sect; \
	  mdir=$(mandir)/man$$sect; \
	  cdir=$(mandir)/cat$$sect; \
	  rm -f $$mdir/$$inst $$cdir/$$inst; \
	done

mostlyclean:
	rm -f *.o core

clean: mostlyclean
	rm -f $(PROGRAMS) $(LIBPROGRAMS) $(LIBFILES) $(TEXFILES) $(CLEANFILES)

distclean: clean
	rm -f Makefile *.tab.c $(DISTCLEANFILES)
	rm -f config.cache config.log config.status ${CONFIG_HEADER} stamp-h

realclean: distclean
	rm -f TAGS $(INFOS)

dist: $(DIST_FILES) $(DIST_DIRS)
	-mkdir ../`cat ../distname`/$(subdir)
	@for file in $(DIST_FILES); do \
	  echo linking $$file; \
	  ln $(srcdir)/$$file ../`cat ../distname`/$(subdir)/$$file || \
	    { echo copying $$file instead; cp -p $(srcdir)/$$file ../`cat ../distname`/$(subdir)/$$file;}; \
	done

check dvi info install uninstall::

tags:: TAGS

TAGS::
	cd $(srcdir); etags $(SOURCES)

# Tell versions [3.59,3.63) of GNU make to not export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:

$(PROGRAMS): ../lib/libfind.a

parser.o: ../lib/modechange.h
find.o fstype.o parser.o pred.o: ../lib/modetype.h
find.o fstype.o parser.o pred.o tree.o util.o: defs.h 
pred.o: ../lib/wait.h
