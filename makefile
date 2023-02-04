CC=gcc
LD=gcc

CFLAGS=-Iinclude
LDFLAGS=

EXE=demo
BUILD=build
OBJS=$(BUILD)/main.o $(BUILD)/linked_list.o

all: demo

clean:
	rm -rf $(BUILD)
	rm -f $(EXE)

demo: $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@ 

build/%.o: %.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@