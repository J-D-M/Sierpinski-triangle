CC     = g++
CFLAGS = -Wall -Wextra -pedantic-errors -std=c++17
LFALGS =
SRCDIR = src
BINDIR = bin
OBJS   = $(SRCDIR)/*.cpp
ONAME  = 'sierpinski triangle'

default: $(OBS)
	$(CC) $^ $(CFLAGS) $(LFALGS) -o $(BINDIR)/$(ONAME)
