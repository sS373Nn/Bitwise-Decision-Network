@echo off

REM Works for now, but there is probably a better way to recompile at each test without rebuilding all the static files from gtest

echo [Compiling GoogleTest sources...]

g++ -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest" -c "C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/src/gtest-all.cc" -o test/gtest-all.o

g++ -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest" -c "C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/src/gtest_main.cc" -o test/gtest_main.o


echo [Compiling project sources...]

g++ -c src/OpNode.cpp -o src/OpNode.o
g++ -c src/memory.cpp -o src/memory.o
g++ -c src/NodeSet.cpp -o src/NodeSet.o


echo [Compiling test file...]

g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/OpNode_tests.cpp -o test/OpNode_tests.o
g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/memory_tests.cpp -o test/memory_tests.o
g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/NodeSet_tests.cpp -o test/NodeSet_tests.o


echo [Linking...]

g++ -o run_OpNode_tests src/OpNode.o test/OpNode_tests.o test/gtest-all.o test/gtest_main.o
g++ -o run_memory_tests src/memory.o test/memory_tests.o test/gtest-all.o test/gtest_main.o
g++ -o run_NodeSet_tests src/NodeSet.o src/OpNode.o test/NodeSet_tests.o test/gtest-all.o test/gtest_main.o


echo [Build Complete.]
echo [Run with:]
echo [ ./run_OpNode_tests]
echo [ ./run_memory_tests]
echo [ ./run_NodeSet_tests]
