# $Id: Makefile.am 43567 2017-03-21 17:43:10Z karl $
# Makefile.am for the TeX Live subdirectory texk/dvisvgm/
#
# Copyright 2015-2017 Karl Berry <tex-live@tug.org>
# Copyright 2009-2015 Peter Breitenlohner <tex-live@tug.org>
# You may freely use, modify and/or distribute this file.
#
# Adapted for TeX Live from original dvisvgm Makefile.am
# Copyright 2005-2017 Martin Gieseking

## Build in the original source setup.
SUBDIRS = . $(DVISVGM_TREE)
DIST_SUBDIRS = $(SUBDIRS)

## We want to re-distribute the whole original dvisvgm source tree.
EXTRA_DIST = $(DVISVGM_TREE)

## Patches applied to the original source tree
EXTRA_DIST += TLpatches

# Files not to be distributed
include $(srcdir)/../../am/dist_hook.am
NEVER_NAMES += $(NEVER_NAMES_SUB)

dvisvgm_dependencies = $(KPATHSEA_DEPEND) $(ZLIB_DEPEND) $(FREETYPE2_DEPEND)
#
config.force: $(dvisvgm_dependencies)
	echo timestamp >config.force
	$(SHELL) ./config.status --recheck
#
DISTCLEANFILES = config.force CXXLD.sh

## Tests (our trivial one, not the original full test suite).
##
TESTS = tests/dvisvgm.test
tests/dvisvgm.log: dvisvgm-src/src/dvisvgm$(EXEEXT)
EXTRA_DIST += $(TESTS)