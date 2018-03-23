#############################################################
# Makefile configuration
#############################################################
# DIRECTORIES
BASE_DIR=./src
OUTPUT_DIR=./output
LIB_DIR=./temp
OBJ_DIR=./temp
#------------------------------
# FILENAMES (without extension)
OUTPUT_NAME=executable
MAIN_NAME=main_testing
# MAIN_NAME=testProcincia
FN_FILES_NAMES=clases/Municipio clases/Provincia wrapers/csv/CSV_reader
LIB_NAME=gestor_de_provincias
HEADERS_LOCATION=auxiliares clases wrapers/csv
# where the headers are located inside of the BASE_DIR folder
#------------------------------
# COMPILERS
COMPILER=g++
#------------------------------
# EXTENSIONS
CODE_EXTENSION=cpp
#------------------------------
# OPTIONS
EXECUTE_AFTER_COMPILATION=YES
	# [YES/NO]
EXECUTION_DATA=SIMPLE
	# [SIMPLE/COMPLETE(generate a more verbose file)]
		# todo complete does not works
COMPILATION_FLAGS=Wpedantic
#the binary compilation flags without the "-"

#############################################################
# GTEST configuration
#############################################################

GTEST=YES
#[YES/NO]

# Please tweak the following variable definitions as needed by your
# project.

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR=googletest/googletest

# All tests produced by this Makefile.  Remember to add new tests you
# created to the list.
TESTS=prueba_unittest Municipio_unittest
TESTS_DIR=./tests


#############################################################
# the previous configuration compiles the following tree
# ./
#  ├main/
#  │ ├main.cc
#  │ ├foo.cc
#  │ └var.cc
#  ├output/
#  │ └executable.out
#  └temp/
#    ├lib_name.a
#    ├foo.o
#    └var.o
# Unitest:
#
#############################################################
# Makefile: you should not touch here...
#############################################################

###
# gloval configuration
###

TEMP:=$(BASE_DIR)
BASE_DIR:=$(addsuffix /,$(TEMP))

TEMP:=$(OUTPUT_DIR)
OUTPUT_DIR:=$(addsuffix /,$(TEMP))

TEMP:=$(LIB_DIR)
LIB_DIR:=$(addsuffix /,$(TEMP))

TEMP:=$(OBJ_DIR)
OBJ_DIR:=$(addsuffix /,$(TEMP))

TEMP:=$(TESTS_DIR)
TESTS_DIR:=$(addsuffix /,$(TEMP))

# MAKEFILE VARIABLES ASSIGNATION
TEMP := $(addsuffix .$(CODE_EXTENSION),$(FN_FILES_NAMES))
CODE_FILES_W_ROUTE := $(addprefix $(BASE_DIR),$(TEMP))

# wip
TEMP := $(addsuffix .o,$(FN_FILES_NAMES))
OBJ_FILES_W_ROUTE:= $(addprefix $(OBJ_DIR),$(FN_FILES_NAMES))
OBJ_FILES_W_ROUTE_EXT:= $(addprefix $(OBJ_DIR),$(TEMP))

FLAGS :=$(addprefix -,$(COMPILATION_FLAGS))
FLAGS_DIN := $(addprefix -I $(BASE_DIR),$(HEADERS_LOCATION))


###
# BINARY EXECUTION
###

ifeq ($(EXECUTE_AFTER_COMPILATION), YES)
execute : $(OUTPUT_DIR)$(OUTPUT_NAME)
ifeq ($(EXECUTION_DATA), SIMPLE)
	@echo Executing
	@echo
	@time "$(OUTPUT_DIR)$(OUTPUT_NAME).out"
endif
ifeq ($(EXECUTION_DATA), COMPLETE)
	@echo Executing
	@echo
	@echo WIP, try EXECUTION_DATA as simple
endif
ifeq ($(EXECUTION_DATA_RECOVERY), NO)
	@echo Executing
	@echo
	@$(OUTPUT_DIR)$(OUTPUT_NAME).out
endif
endif

# BINARY COMPILATION (gcc -o a.out main.cc lib.a -flags)
$(OUTPUT_DIR)$(OUTPUT_NAME) : $(BASE_DIR)$(MAIN_NAME).$(CODE_EXTENSION) $(LIB_DIR)$(LIB_NAME).a
	@echo Building binaries
	@$(COMPILER) -o $(OUTPUT_DIR)$(OUTPUT_NAME).out $(BASE_DIR)$(MAIN_NAME).$(CODE_EXTENSION) $(LIB_DIR)$(LIB_NAME).a $(FLAGS) $(FLAGS_DIN)


# .o COMPILATION (gcc -c var.cc foo.cc)
#generates the .o's and moves them into their corresponding foldet in the OBJ_DIR
$(OBJ_FILES_W_ROUTE_EXT) : $(CODE_FILES_W_ROUTE)
	@echo Building objects
	@for file in $(FN_FILES_NAMES) ; do \
			$(COMPILER) -c $(BASE_DIR)$$file.$(CODE_EXTENSION) $(FLAGS_DIN); \
			mv ./*.o $(OBJ_DIR)$$file.o ; \
	done

#.a COMPILATION (ar -rs .lib.a var.o foo.o)
$(LIB_DIR)$(LIB_NAME).a : $(OBJ_FILES_W_ROUTE_EXT)
	@echo Building library
	@ar -rs $@ $^

# CLEAN
clean:
	@echo cleaning
	@rm -rf $(OUTPUT_DIR)**/*.out $(OUTPUT_DIR)*.out $(OBJ_DIR)**/*.o $(OBJ_DIR)*.o $(LIB_DIR)**/*.a $(LIB_DIR)*.a

#############################################################
# GTEST: you should not touch here
#############################################################

googletest : gtest_build $($(TESTS_DIR)$$unittest.$(CODE_EXTENSION))
	@for unittest in $(TESTS) ; do \
		echo ; \
		echo \	Running $$unittest; \
		echo ; \
		$(OUTPUT_DIR)$$unittest.out ; \
	done


gtest_build : $(LIB_DIR)libgtest.a
	@for unittest in $(TESTS) ; do \
		echo Building $$unittest ; \
		g++ -isystem $(GTEST_DIR)/include -pthread $(FLAGS_DIN) $(TESTS_DIR)$$unittest.$(CODE_EXTENSION) $(LIB_DIR)libgtest.a -o $(OUTPUT_DIR)$$unittest.out ; \
	done

# gtest object creation (all.o)
$(OBJ_DIR)gtest-all.o : $(GTEST_DIR)/src/gtest-all.cc
	@echo Creating gtest-all.o
	@g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest-all.cc
	@mv ./*.o $(OBJ_DIR)

# gtest object creation (main.o)
$(OBJ_DIR)gtest_main.o : $(GTEST_DIR)/src/gtest_main.cc
	@echo creating gtest_main.o
	@g++ -isystem $(GTEST_DIR)/include -I$(GTEST_DIR) -pthread -c $(GTEST_DIR)/src/gtest_main.cc
	@mv ./*.o $(OBJ_DIR)

# gtest library compilation
$(LIB_DIR)libgtest.a : $(OBJ_DIR)gtest_main.o $(OBJ_DIR)gtest-all.o
	@echo Building googletest library
	@ar -rv $(LIB_DIR)libgtest.a $(OBJ_DIR)gtest-all.o $(OBJ_DIR)gtest_main.o > /dev/null


help:
	#                            _                        _         __ _ _
	#                           (_)                      | |       / _(_) |
	#  __ _  ___ _ __   ___ _ __ _  ___   _ __ ___   __ _| | _____| |_ _| | ___
	# / _` |/ _ \ '_ \ / _ \ '__| |/ __| | '_ ` _ \ / _` | |/ / _ \  _| | |/ _ \.
	#| (_| |  __/ | | |  __/ |  | | (__  | | | | | | (_| |   <  __/ | | | |  __/
	# \__, |\___|_| |_|\___|_|  |_|\___| |_| |_| |_|\__,_|_|\_\___|_| |_|_|\___|
	#  __/ |
	# |___/                                             by Danitico and Riera90.
	#
	## Implementation
	# 	git clone git@github.com:riera90/generic-makefile.git
	# 	cd greneric-makefile
	# 	mv * <working directory>
	# 	cd <working directory>
	#
	# Configure the variables.
	# 	make
	#
	# And enjoy the binaries!
	#
	# For a more extense manual prease, refer to README.md
	#
