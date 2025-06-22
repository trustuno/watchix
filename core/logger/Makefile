include ../../config.mk

LOGGER_SRC = logger_manager.cpp	\
				logger.c

LOGGER_OBJ = $(OBJ_DIR)/core/logger/logger_manager.o $(OBJ_DIR)/core/logger/logger.o

.PHONY: all clean install

all: $(LOGGER_OBJ)

$(OBJ_DIR)/core/logger/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $(abspath $<) -o $@

$(OBJ_DIR)/core/logger/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(abspath $<) -o $@

clean:
	rm -rf $(OBJ_DIR)/core/logger/*

install:
	@echo "Installing logger..."
