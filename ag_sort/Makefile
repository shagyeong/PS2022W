CC = gcc
OPTS = -Wall -g
TARG = test
SRCS = main.c
OBJS = $(SRCS:.c=.o)

LIBS = -L. -lsort
LIBSRCS = mergesort.c quicksort.c
LOBJS=$(LIBSRCS:.c=.o)
LARS=libsort.a

make: $(TARG)
$(TARG) : $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS) -static
$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)
$.0: %.c
	$(CC) $(OPTS) -c $< -o $@
clean:
	rm -f $(OBJS) $(LOBJS) $(LARS) $(TARG)
