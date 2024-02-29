# OS specific setup
ID=$(shell . /etc/os-release ; echo $$ID)
ifeq "$(ID)" "kali"
DEBUG=true
endif
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
OBJECTS=$(patsubst $(MAIN_SRC)/%.c,$(MAIN_OBJ)/%.o,$(wildcard $(MAIN_SRC)/*.c))

### commands
# compiler
CC=gcc
# compile arguments
ifdef DEBUG
CFLAGS=-Wall -Wextra -g -Og -DDEBUG -I$(MAIN_SRC)
else
CFLAGS=-Wall -Wextra -O3 -std=c99 -I$(MAIN_SRC)
endif
# link arguments
LDFLAGS=-lncurses

#compilation
MAIN_COMPILE=$(CC) $(CFLAGS) -c $< -o $@
#linking
MAIN_LINK=$(CC) $^ -o $@ $(LDFLAGS)
#deletion
RM=rm -rf
#silent log
LOG=@printf

.PHONY: all run build graph setup clean full-clean
.SECONDARY: $(OBJECTS)

all: setup build run

$(MAIN_OBJ)/%.o: $(MAIN_SRC)/%.c $(HEADERS)
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

graph: $(MAIN_SRC)/main.c $(HEADERS)
	$(LOG) '\n\033[42mcreation of the control flow graph\033[49m\n'
	$(RM) graph/*
	mkdir -p graph
	-$(CC) -O3 -I$(MAIN_SRC) $(LDFLAGS) -fdump-tree-cfg-graph $(MAIN_SRC)/main.c
	dot a-main.c.015t.cfg.dot -Tsvg -o graph/main.svg
	$(RM) a-main.c.015t.cf*
	$(LOG) '\n\033[44mmake graph finished\033[49m\n\n'

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