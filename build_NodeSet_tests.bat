@echo off

REM Works for now, but there is probably a better way to recompile at each test without rebuilding all the static files from gtest

echo [Compiling project sources...]

g++ -c src/NodeSet.cpp -o src/NodeSet.o
g++ -c src/OperationNode.cpp -o src/OperationNode.o


echo [Compiling test file...]

g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/NodeSet_tests.cpp -o test/NodeSet_tests.o


echo [Linking...]

g++ -o run_NodeSet_tests src/NodeSet.o src/OperationNode.o test/NodeSet_tests.o test/gtest-all.o test/gtest_main.o


echo [Build Complete. Run with ./run_NodeSet_tests]
