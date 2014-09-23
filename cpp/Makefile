BUILD_OUTPUT_DIR	= out

PROBLEM_SOURCES		= $(wildcard problem*.cc)
PROBLEM_BINARIES	= $(patsubst %.cc, $(BUILD_OUTPUT_DIR)/debug/%, $(PROBLEM_SOURCES)) \
                      $(patsubst %.cc, $(BUILD_OUTPUT_DIR)/release/%, $(PROBLEM_SOURCES))

CC       = clang++
CXXFLAGS = -std=c++11 -Weverything -Wno-c++98-compat -fdiagnostics-color
CXXFLAGS_DEBUG = -g
CXXFLAGS_RELEASE = -O3

.phony : all
all: $(PROBLEM_BINARIES)

$(BUILD_OUTPUT_DIR)/debug/%: %.cc
	@echo Building $< --\> $@
	@mkdir -p $(BUILD_OUTPUT_DIR)/debug
	@$(CC) $(CXXFLAGS) $(CXXFLAGS_DEBUG) $< -o $@

$(BUILD_OUTPUT_DIR)/release/%: %.cc
	@echo Building $< --\> $@
	@mkdir -p $(BUILD_OUTPUT_DIR)/release
	@$(CC) $(CXXFLAGS) $(CXXFLAGS_RELEASE) $< -o $@

.phony : clean
clean:
	@rm -f $(PROBLEM_BINARIES)
	@[ -d $(BUILD_OUTPUT_DIR)/debug ] && rmdir $(BUILD_OUTPUT_DIR)/debug || true
	@[ -d $(BUILD_OUTPUT_DIR)/release ] && rmdir $(BUILD_OUTPUT_DIR)/release || true
	@[ -d $(BUILD_OUTPUT_DIR) ] && rmdir $(BUILD_OUTPUT_DIR) || true
