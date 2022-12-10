# Subdirectories to be included.
SUBDIRS = include src tests
# Extra files to be added to the distribution file.
EXTRA_DIST =
# Auto configure local Automake flags.
ACLOCAL_AMFLAGS=-I m4

# Enables code coverage.
include Makefile.coverage.am

if HAVE_DOXYGEN

# Command man page.
man1_MANS = documentation/man/man1/my_program.1

# Library man page.
man3_MANS = documentation/man/man3/my_program_configuration.3

# Generate documentation.
.PHONY: doc
doc: $(man3_MANS) documentation/html/ documentation/latex/

# Man page.
$(man3_MANS):
	$(DOXYGEN) Doxyfile

# Documentation in HTML format.
documentation/html/:
	$(DOXYGEN) Doxyfile

# Documentation in LaTeX format.
documentation/latex/:
	$(DOXYGEN) Doxyfile
	cd documentation/latex && $(MAKE)

endif

# Starts my_program.
.PHONY: start
start: all
	time ./src/${PACKAGE_NAME} $(ARGS)

# Verbose start.
.PHONY: start-verbose
start-verbose: all
	$(MAKE) start ARGS="--verbose"

# Development start.
.PHONY: start-dev
start-dev: all
	./libtool --mode=execute ./src/${PACKAGE_NAME} --verbose

# Extends check to search for memory leaks in my_program.
.PHONY: start-valgrind
start-valgrind: all
	./libtool --mode=execute \
		valgrind --tool=memcheck \
		--log-file="tests/start-valgrind.log" \
		--leak-check=full --show-leak-kinds=all  \
		./src/${PACKAGE_NAME} --verbose

# Generates a suppresions file for tests.
.PHONY: check-valgrind-generate-suppresions-file
check-valgrind-generate-suppresions-file: all
	 ./libtool --mode=execute \
		valgrind \
			--leak-check=full \
			--gen-suppressions=all \
			--log-file="tests/test.log" \
			--show-leak-kinds=all \
			./tests/test

	cat "tests/test.log" | ./parse_valgrind_suppressions.sh > \
		tests/test.supp

# Used to remove the remaining folders created when installing the application.
uninstall-hook:
	if test -d ${prefix}/include/${PACKAGE_NAME}; then \
		rmdir ${prefix}/include/${PACKAGE_NAME}; fi
