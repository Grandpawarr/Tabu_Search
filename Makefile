#detect underlying system
ifeq ($(OS),Windows_NT)
 	PLATFORM="Windows"
else
  	PLATFORM="Linux"
endif

export PLATFORM

#set proper program neame	

ifeq ($(PLATFORM),Windows)
	PROGRAM=PRO.exx
else
	PROGRAM=PRO
endif

export PROGRAM

CC=gcc
CFLAGS=-O1 -g -Wall -Werror
OBJS=Tabumain.c tabusearch.c deceptionProblem.c 

all:$(PROGRAM)

#-lm:use to link math.
$(PROGRAM):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm
	./$(PROGRAM)

#run program
test:
	./$(PROGRAM)

#delete program
clean:
	rm $(PROGRAM)

#show os platform
os:
	@echo $(PLATFORM)
