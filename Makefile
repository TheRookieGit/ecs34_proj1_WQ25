CXX=g++
CXXFLAGS = -std=c++17 -Wall -I$(include_folder) -I$(src_folder)
LDFLAGS = -lgtest -lgtest_main -pthread


include_folder = include
src_folder = src
test_folder = testsrc

obj_folder = obj
bin_folder = bin
#??

#includes = $(wildcard $(include_folder)/*.h)
srcs = $(wildcard $(src_folder)/*.cpp)
testsrc = $(wildcard $(test_folder)/*.cpp)
# ● Must compile string utils file and string utils tests using C++17
objs = $(patsubst $(src_folder)/%.cpp, $(obj_folder)/%.o, $(srcs))
testobjs = $(patsubst $(test_folder)/%.cpp, $(obj_folder)/%.o, $(testsrc))

execute_target = $(bin_folder)/teststrutils
all_object = $(objs) $(testobjs)
# ● Must link string utils and string utils tests object files to make teststrutils
# executable

default: test

$(execute_target): $(objs) $(testobjs)
	@mkdir -p $(bin_folder)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(obj_folder)/%.o: $(src_folder)/%.cpp
	@mkdir -p $(obj_folder)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(obj_folder)/%.o: $(test_folder)/%.cpp
	@mkdir -p $(obj_folder)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# default: test
# ● Must execute the teststrutils executable
test: $(execute_target)
	./$(execute_target) || true
# ● Must provide a clean that will remove the obj and bin directories
clean:
	rm -rf $(obj_folder) $(bin_folder)

.PHONY: all test clean
