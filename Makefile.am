
CLEANFILES =

AM_CFLAGS = $(LIBIMMUTABLE_CFLAGS)

INTROSPECTION_GIRS = Immutable-1.0.gir
INTROSPECTION_SCANNER_ARGS = --warn-all --warn-error

source_public = \
	src/list.c src/list.h \
	src/immutable-types.h \
	$(NULL)

lib_LTLIBRARIES = libimmutable.la
libimmutable_la_CPPFLAGS = -I $(srcdir)
libimmutable_la_SOURCES = $(source_public)
libimmutable_la_LIBADD = $(LIBIMMUTABLE_LIBS)

include $(INTROSPECTION_MAKEFILE)

Immutable-1.0.gir: libimmutable.la
Immutable_1_0_gir_INCLUDES = GLib-2.0 Gio-2.0
Immutable_1_0_gir_CFLAGS = $(AM_CFLAGS)
Immutable_1_0_gir_LIBS = libimmutable.la
Immutable_1_0_gir_FILES = $(source_public)
Immutable_1_0_gir_SCANNERFLAGS = --identifier-prefix=immutable_ --identifier-prefix=Immutable
CLEANFILES += Immutable-1.0.gir Immutable-1.0.typelib

girdir = $(datadir)/gir-1.0
gir_DATA = Immutable-1.0.gir
typelibdir = $(libdir)/girepository-1.0
typelib_DATA = Immutable-1.0.typelib
