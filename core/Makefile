include ../config.mk

SUBDIRS = logger event_manager

CORE_SRC = main.c
CORE_OBJ = $(OBJ_DIR)/core/main.o

.PHONY: all clean $(SUBDIRS)

# Build subdirectories and core object files
all: $(SUBDIRS) $(CORE_OBJ)

# Build each subdirectory
$(SUBDIRS):
	$(MAKE) -C $@

# Compile .cpp files
$(OBJ_DIR)/core/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I../../include -c $(abspath $<) -o $@

# Compile .c files
$(OBJ_DIR)/core/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I../../include -c $(abspath $<) -o $@

clean:
	rm -rf $(OBJ_DIR)/core/*
