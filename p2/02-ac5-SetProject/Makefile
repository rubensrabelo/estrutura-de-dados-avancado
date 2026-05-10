CXX = g++
CXXFLAGS = -std=c++17 -Ilib/include

SRC = main.cpp \
	  lib/src/Node.cpp \
	  lib/src/RBTree.cpp \
	  lib/src/Set.cpp

TEST_SRC = test/tests.cpp \
		   lib/src/Node.cpp \
		   lib/src/RBTree.cpp \
		   lib/src/Set.cpp

OUT = app
TEST_OUT = tests

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

tests:
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST_OUT)

run:
	./$(OUT)

run-tests:
	./$(TEST_OUT)

clean:
	rm -f $(OUT) $(TEST_OUT)