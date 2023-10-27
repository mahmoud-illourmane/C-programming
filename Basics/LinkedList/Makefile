#
# GENERAL CONFIGURATION (to be configured)
#

EXEC = main
OBJECTS = cell.o list.o
PROJECT_NAME = LIST

#
# SUFFIXES (do not modify)
#

.SUFFIXES: .c .o

#
# OBJECTS (do not modify)
#

EXEC_O = $(EXEC:=.o)
OBJECTS_O = $(OBJECTS) $(EXEC_O)

#
# ARGUMENTS AND COMPILER (to be configured)
#

CC = gcc
CCFLAGS_STD = -Wall -O3 #-Werror
CCFLAGS_DEBUG = -D _DEBUG_
CCFLAGS = $(CCFLAGS_STD)
CCLIBS = 

#
# RULES (do not modify)
#

all: msg $(OBJECTS) $(EXEC_O)
	@echo "Creating executables..."
	@for i in $(EXEC); do \
	$(CC) -o $$i $$i.o $(OBJECTS) $(CCLIBS); \
	done
	@echo "Finished."

msg:
	@echo "Creating objects..."

debug: CCFLAGS = $(CCFLAGS_STD) $(CCFLAGS_DEBUG)
debug: all

#
# DEFAULT RULES (do not modify)
#

.c.o: .h
	@cd $(dir $<) && ${CC} ${CCFLAGS} -c $(notdir $<) -o $(notdir $@)

#
# GENERAL RULES (do not modify)
#

# You can add project-specific commands here
clean:
	@echo "Removing objects and temporary files..."
	@rm -f $(OBJECTS) $(EXEC_O)
	@rm -f *~ *#
	@rm -f $(EXEC)
	@rm -f dependencies
	@echo "Finished."

depend:
	@echo "Creating dependencies..."
	@sed -e "/^# DEPENDENCIES/,$$ d" makefile > dependencies
	@echo "# DEPENDENCIES" >> dependencies
	@for i in $(OBJECTS_O); do \
	$(CC) -MM -MT $$i $(CCFLAGS) `echo $$i | sed "s/\(.*\)\\.o$$/\1.c/"` >> dependencies; \
	done
	@cat dependencies > makefile
	@rm dependencies
	@echo "Finished."

#
# ARCHIVE CREATION (do not modify)
#

ARCHIVE_FILES = *

archive: clean
	@echo "Creating archive $(PROJECT_NAME)$(shell date '+%y%m%d.tar.gz')..."
	@REP=`basename "$$PWD"`; cd .. && tar zcf $(PROJECT_NAME)$(shell date '+--%y-%m-%d.tar.gz') $(addprefix "$$REP"/,$(ARCHIVE_FILES))
	@echo "Finished."
