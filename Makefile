SRCDIR = src
OBJDIR = obj

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))

CC = /usr/bin/g++
CPPFLAGS = -Wall -O3
LDFLAGS =

podcatcher: $(OBJFILES)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(OBJDIR)/*.o podcatcher

all: clean podcatcher
