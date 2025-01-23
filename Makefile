CXX=g++
CXXFLAGS = -std=c++17 -Wall -I$(include_folder) -I$(src_folder)
LDFLAGS = -lgtest -lgtest_main -pthread


include_folder = include
src_folder = src
test_folder = testsrc


# ● Must create obj directory for object files (if doesn’t exist)
obj_folder = obj #mkdir


# ● Must create bin directory for binary files (if doesn’t exist)
bin_folder = bin #mkdir

include_folder = $(wildcard $(include_folder)/*.h)
srcs = $(wildcard $(src_folder)/*.cpp)
testsrc = $(wildcard $(test_folder)/*.cpp)

# ● Must compile string utils file and string utils tests using C++17
objs = $(patsubst $(src_folder)/%.cpp, $(obj_folder)/%.o, $(srcs))
testobjs = $(patsubst $(test_folder)/%.cpp, $(obj_folder)/%.o, $(testsrc))

execute_target = $(bin_folder)/teststrutils
all_object = $(objs) $(testobjs)
# ● Must link string utils and string utils tests object files to make teststrutils
# executable
$(execute_target): $(obj_folder) $(test_obj)
	@mkdir -p $(bin_folder)
	$(CXX) $(CXXFLAGS) -o $@ $(all_object) $(LDFLAGS)


$(obj_folder): $(src_folder)/%.cpp
	@mkdir -p $(obj_folder)
	$(CXX) $(CXXFLAGS) -c $(src_folder)/$*.cpp -o $(obj_folder)/$*.o

$(obj_folder): $(test_folder)/%.cpp
	@mkdir -p $(obj_folder)
	$(CXX) $(CXXFLAGS) -c $(test_folder)/$*.cpp -o $(obj_folder)/$*.o


default: test
# ● Must execute the teststrutils executable
test: $(execute_target)
	./$(execute_target)

# ● Must provide a clean that will remove the obj and bin directories
clean:
	rm -rt $(obj_folder) $(bin_folder)

.PHONY: all test clean
