EXECUTABLE = podcatcher

SRCDIR = src
OBJDIR = obj

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJFILES = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))

CC = /usr/bin/g++
CPPFLAGS = -Wall -O3
LDFLAGS =

debug: CPPFLAGS = -Wall -g -DDEBUG_SETTINGS
debug: podcatcher

$(EXECUTABLE): $(OBJFILES)
	$(CC) $(CPPFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) -c -o $@ $<

clean:
	rm -f *.o $(OBJDIR)/*.o $(EXECUTABLE)

release: clean $(EXECUTABLE)
	strip $(EXECUTABLE)

all: clean debug
