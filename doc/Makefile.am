if HAVE_DOXYGEN
directory = $(top_srcdir)/doc/man/man3

man_MANS = $(directory)

$(directory): doxyfile.stamp

doxyfile.stamp: Doxyfile
	$(DOXYGEN) $^
	cd latex && $(MAKE)
	echo Timestamp > $@

CLEANFILES = doxyfile.stamp

all-local: doxyfile.stamp
clean-local:
	-rm -rf $(top_srcdir)/doc/man

endif