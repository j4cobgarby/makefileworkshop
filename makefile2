CC=gcc
LD=gcc
AS=gcc

CFLAGS=-Iinclude -O2
LDFLAGS=
ASFLAGS= -O2

CFILES=$(shell find . -type f -name '*.c' -printf "%f\n")
ASFILES=$(shell find . -type f -name '*.s' -printf "%f\n")
OBJ=$(CFILES:%.c=%.o) $(ASFILES:%.s=%.o)

BUILD=build
EXE=demo

.PHONY: all
all: $(addprefix build/, $(OBJ))
	$(LD) $(LDFLAGS) $^ -o $(EXE)

.PHONY: clean
clean:
	rm -rf $(BUILD)
	rm -f $(EXE)

$(BUILD)/%.o: %.c $(BUILD)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/%.o: %.s $(BUILD)
	$(AS) $(ASFLAGS) -c $< -o $@

$(BUILD):
	mkdir -p $(BUILD)