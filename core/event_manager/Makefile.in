include ../../config.mk

EVENT_MANAGER_SRC = event_manager.cpp	

EVENT_MANAGER_OBJ = $(OBJ_DIR)/core/event_manager/event_manager.o

.PHONY: all clean install

all: $(EVENT_MANAGER_OBJ)

$(OBJ_DIR)/core/event_manager/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $(abspath $<) -o $@

$(OBJ_DIR)/core/event_manager/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $(abspath $<) -o $@

clean:
	rm -rf $(OBJ_DIR)/core/event_manager/*

install:
	@echo "Installing event_manager..."
