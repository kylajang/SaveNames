CC := g++
CFLAGS := -Wall -pedantic -g --std=c++17

# My Variables
	PART1_EXE_NAME := lab11-main
	PART1_EXE_PATH := ./$(PART1_EXE_NAME)
	DEFAULT_DATAFILE_NAME := names.db

# Targets

lab11-main:
	@echo Building $@
	$(CC) $(CFLAGS) main.cpp -o $@ \
		&& chmod +x $@

lab11:	lab11-main
	$(PART1_EXE_PATH) "$(DEFAULT_DATAFILE_NAME)"

clean:
		rm $(PART1_EXE_PATH)
