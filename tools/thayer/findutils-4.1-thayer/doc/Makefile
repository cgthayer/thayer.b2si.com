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
MAKEINFO = makeinfo
TEXI2DVI = texi2dvi

TEXFILES = *.aux *.cp *.cps *.dvi *.fn *.fns *.ky *.log *.pg *.toc *.tp *.vr

INFOS = find.info*
INFO_DEPS = find.info
DVIS = find.dvi
SOURCES = 
DIST_CONF = Makefile.am Makefile.in
DIST_FILES = $(DIST_CONF) $(SOURCES) $(TEXINFOS) $(INFOS) $(MANS) $(DIST_OTHER)

TEXINFOS = find.texi
DIST_OTHER = perm.texi texinfo.tex

all:: ${ALL}

.SUFFIXES: .texi .info .dvi

.texi.info:
	$(MAKEINFO) -I$(srcdir) $<

.texi.dvi:
	TEXINPUTS=$(srcdir):$$TEXINPUTS $(TEXI2DVI) $<

info:: $(INFO_DEPS)

dvi:: $(DVIS)

install:: install-info

install-info: $(INFO_DEPS)
	$(top_srcdir)/mkinstalldirs $(infodir)
	cd $(srcdir); for file in *.info*; do \
	  $(INSTALL_DATA) $$file $(infodir)/$$file; \
	done

uninstall:: uninstall-info

uninstall-info:
	cd $(srcdir); for file in *.info*; do \
	  rm -f $(infodir)/$$file; \
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

find.info find.dvi: perm.texi
