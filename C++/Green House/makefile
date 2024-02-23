.SILENT:

PRESENTATION=presentation

CC = g++ -DSUN -I$(PRESENTATION)
OBJS = $(PRESENTATION)/presentation.o 
PROGRAMS = gh

ALL: $(PROGRAMS)

gh:	gh.cpp $(OBJS)
	echo Creation de gh...
	$(CC) gh.cpp -o gh $(OBJS)  -lrt -lpthread -lSDL

$(PRESENTATION)/presentation.o:	$(PRESENTATION)/presentation.c $(PRESENTATION)/presentation.h
		echo Creation de presentation.o ...
		$(CC) -c $(PRESENTATION)/presentation.c
		mv presentation.o $(PRESENTATION)

clean:
	@rm -f $(OBJS) core

clobber:	clean
	@rm -f tags $(PROGRAMS)
