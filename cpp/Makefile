BUILD_OUTPUT_DIR    = out

PROBLEM_SOURCES     = $(wildcard problem*.cc)
PROBLEM_BINARIES    = $(patsubst %.cc, $(BUILD_OUTPUT_DIR)/debug/%, $(PROBLEM_SOURCES)) \
                      $(patsubst %.cc, $(BUILD_OUTPUT_DIR)/release/%, $(PROBLEM_SOURCES))
TEST_BINARY         = $(BUILD_OUTPUT_DIR)/tests
TEST_SOURCES        = $(wildcard *_unittest.cc)
UTIL_SOURCES        = $(shell find -maxdepth 1 -name \*.cc ! -name problem\* ! -name \*_unittest.cc -printf '%P\n')

CC                  = clang++
CXXFLAGS           ?= -std=c++11 -Weverything -Wno-c++98-compat -fdiagnostics-color
CXXFLAGS_DEBUG      = -g
CXXFLAGS_RELEASE    = -O3 -DNDEBUG
GTEST_FLAGS         = -Wno-global-constructors -isystem gtest/include \
                      -lpthread -Lgtest/make -l:gtest.a -l:gtest_main.a

# support V=1 for verbose
V    ?= 0
AT_0 := @
AT_1 :=
AT    = $(AT_$(V))

.phony : all
all: $(PROBLEM_BINARIES)

$(BUILD_OUTPUT_DIR)/debug/%: %.cc $(UTIL_SOURCES)
	$(AT) mkdir -p $(BUILD_OUTPUT_DIR)/debug
	$(AT) echo Building $< --\> $@
	$(AT) $(CC) $(CXXFLAGS) $(CXXFLAGS_DEBUG) $(UTIL_SOURCES) $< -o $@

$(BUILD_OUTPUT_DIR)/release/%: %.cc $(UTIL_SOURCES)
	$(AT) mkdir -p $(BUILD_OUTPUT_DIR)/release
	$(AT) echo Building $< --\> $@
	$(AT) $(CC) $(CXXFLAGS) $(CXXFLAGS_RELEASE) $(UTIL_SOURCES) $< -o $@

.phony : check
check: $(UTIL_SOURCES) $(TEST_SOURCES)
	$(AT) echo Building gtest framework ...
	$(AT) make --quiet -C gtest
	$(AT) mkdir -p $(BUILD_OUTPUT_DIR)
	$(AT) echo Building tests ...
	$(AT) $(CC) $(CXXFLAGS) $(CXXFLAGS_DEBUG) $(UTIL_SOURCES) $(TEST_SOURCES) $(GTEST_FLAGS) -o $(TEST_BINARY)
	$(AT) $(BUILD_OUTPUT_DIR)/tests

.phony : clean
clean:
	$(AT) rm -f $(PROBLEM_BINARIES)
	$(AT) rm -f $(TEST_BINARY)
	$(AT) [ -d $(BUILD_OUTPUT_DIR)/debug ] && rmdir $(BUILD_OUTPUT_DIR)/debug || true
	$(AT) [ -d $(BUILD_OUTPUT_DIR)/release ] && rmdir $(BUILD_OUTPUT_DIR)/release || true
	$(AT) [ -d $(BUILD_OUTPUT_DIR) ] && rmdir $(BUILD_OUTPUT_DIR) || true
