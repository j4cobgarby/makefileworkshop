CC=gcc
LD=gcc
AS=gcc

ASFLAGS=
CFLAGS=-Iinclude
LDFLAGS=

EXE=demo
BUILD=build
OBJS=$(BUILD)/main.c.o \
	 $(BUILD)/linked_list.c.o \
	 $(BUILD)/fibonacci.c.o \
	 $(BUILD)/fizzbuzz.c.o \
	 $(BUILD)/func.s.o \

.PHONY: all
all: demo

.PHONY: clean
clean:
	rm -rf $(BUILD)
	rm -f $(EXE)

demo: $(OBJS)
	$(LD) $^ $(LDFLAGS) -o $@ 

build/%.c.o: %.c
	mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.s.o: %.s
	mkdir -p $(BUILD)
	$(AS) -c $< -o $@