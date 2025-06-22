include config.mk

SUBDIRS = core

TARGET = $(INSTALL_DIR)/watchix

EVENT_ID_HEADER = include/event_manager/event_id.h
EVENT_ID_SCRIPT = scripts/generate_event_id.py
EVENT_LIST_FILE = core/event_manager/event_list.h

.PHONY: all clean install $(SUBDIRS)

all: $(EVENT_ID_HEADER) $(SUBDIRS) link

# Auto-generate event_id.h if event_list.h or the script changes
$(EVENT_ID_HEADER): $(EVENT_LIST_FILE) $(EVENT_ID_SCRIPT)
	@echo "Generating event_id.h..."
	python3 $(EVENT_ID_SCRIPT)

$(SUBDIRS):
	$(MAKE) -C $@

# Linking happens after all subdirectories are built
link:
	@echo "Collecting object files..."
	OBJ_FILES="$$(find $(OBJ_DIR) -name '*.o' 2>/dev/null)"; \
	echo "Linking object files: $$OBJ_FILES"; \
	mkdir -p $(INSTALL_DIR); \
	$(CXX) $$OBJ_FILES -o $(TARGET); \
	echo "Executable built at: $(TARGET)"

clean:
	rm -rf $(OBJ_DIR)/*
	rm -f $(TARGET)

install:
	@echo "Installing Watchix..."
