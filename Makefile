#detect underlying system
#create program name
ifeq ($(OS),Windows_NT)
 	PLATFORM:=Windows
	PROGRAM=PRO.exe
	RM=del
else
  	PLATFORM:=Linux
	PROGRAM=PRO
	RM=rm
endif


CC=gcc
CFLAGS=-O1 -g -Wall -Werror
OBJS=Tabumain.c tabusearch.c deceptionProblem.c 



#-lm:use to link math.
$(PROGRAM):$(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lm
	./$(PROGRAM)

#run program
test:
	./$(PROGRAM)

#delete program
clean:
	$(RM) $(PROGRAM)

#show os platform
os:
	@echo $(PLATFORM) $(PROGRAM)