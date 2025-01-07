# The target to build if no targets specified
.DEFAULT_GOAL := add-two-numbers

# A list of extra modules to compile besides main one
SRCMODULES = helper.c
OBJMODULES = $(SRCMODULES:.c=.o)

# Compiler and compiler flags to use
CC = clang
CFLAGS = -Wall -Wpedantic -Wextra

debug: CFLAGS += -g -DDEBUG
debug: add-two-numbers

# Common target's rule:
# $< - name of the 1st target in the dependencies list
# $@ - name of the target
%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

# $^ - whole list of dependencies
add-two-numbers: add-two-numbers.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o $@

# Gather dependencies
deps.mk: $(SRCMODULES)
	$(CC) -MM $^ > $@

# Include dependencies if not clean
ifneq (clean, $(MAKECMDGOALS))
-include deps.mk
endif

clean:
	rm -f *.o deps.mk add-two-numbers

run: add-two-numbers
	./add-two-numbers
