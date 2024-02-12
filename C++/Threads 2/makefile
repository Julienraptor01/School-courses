### paths
# sources sub directories
MAIN=/main
# sources
SRC=./src
MAIN_SRC=$(SRC)$(MAIN)
# build
BUILD=./build
# build -> objs
OBJ=$(BUILD)/obj
MAIN_OBJ=$(OBJ)$(MAIN)
# build -> bins
BIN=$(BUILD)/bin
MAIN_BIN=$(BIN)$(MAIN)
# lists
# use a generic rule to list all the headers
HEADERS=$(wildcard $(MAIN_SRC)/*.h)
# use a generic rule to list all the objects
OBJECTS=$(patsubst $(MAIN_SRC)/%.cpp,$(MAIN_OBJ)/%.o,$(wildcard $(MAIN_SRC)/*.cpp))

### commands
# compiler
CXX=g++
# compile arguments
CXXFLAGS=-Wall -Wextra -O3 -I$(MAIN_SRC)
# link arguments
LDFLAGS=

#compilation
MAIN_COMPILE=$(CXX) $(CXXFLAGS) -c $< -o $@
#linking
MAIN_LINK=$(CXX) $^ -o $@ $(LDFLAGS)
#deletion
RM=rm -rf
#silent log
LOG=@printf

.PHONY: all run build setup clean full-clean
.SECONDARY: $(OBJECTS)

all: setup build run

$(MAIN_OBJ)/%.o: $(MAIN_SRC)/%.cpp $(HEADERS)
	$(LOG) '\n\033[42mcreation of the $* object file\033[49m\n'
	$(MAIN_COMPILE)

$(MAIN_BIN)/%: $(MAIN_OBJ)/%.o
	$(LOG) '\n\033[42mcreation of the $* executable\033[49m\n'
	$(MAIN_LINK)

run:
	$(LOG) '\n\033[42mrunning the main executable\033[49m\n'
	$(MAIN_BIN)/main
	$(LOG) '\n\033[44mmake run finished\033[49m\n\n'

build:
	$(LOG) '\n\033[42mbuilding the main executable\033[49m\n'
	make $(MAIN_BIN)/main
	$(LOG) '\n\033[44mmake build finished\033[49m\n\n'

setup:
	$(LOG) '\n\033[42msetup of the directories\033[49m\n'
	mkdir \
	-p \
	$(MAIN_OBJ) \
	$(MAIN_BIN)
	$(LOG) '\n\033[44mmake setup finished\033[49m\n\n'

clean:
	$(LOG) '\n\033[41mdeletion of the object directory\033[49m\n'
	$(RM) $(OBJ)/*
	make setup
	$(LOG) '\n\033[44mmake clean finished\033[49m\n\n'

full-clean:
	$(LOG) '\n\033[41mdeletion of ALL the build directories\033[49m\n'
	$(RM) $(BUILD)/*
	make setup
	$(LOG) '\n\033[44mmake full-clean finished\033[49m\n\n'