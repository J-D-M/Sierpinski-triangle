CC       = clang++
CFLAGS   = -Wall -Wextra -pedantic-errors -std=c++17
LFLAGS   = -lSDL2

SRCDIR   = ./src
BINDIR   = ./bin
OBJDIR   = ./obj

SRCFILES = $(wildcard $(SRCDIR)/*.cpp)
OBJS     = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCFILES))

ONAME    = 'sierpinski triangle'

default: $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $(BINDIR)/$(ONAME)


$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

clean:
	rm $(OBJDIR)/*.o
