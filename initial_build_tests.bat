@echo off

REM Works for now, but there is probably a better way to recompile at each test without rebuilding all the static files from gtest

echo [Compiling GoogleTest sources...]

g++ -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest" -c "C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/src/gtest-all.cc" -o test/gtest-all.o

g++ -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest" -c "C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/src/gtest_main.cc" -o test/gtest_main.o


echo [Compiling project sources...]

g++ -c src/OperationNode.cpp -o src/OperationNode.o
g++ -c src/memory.cpp -o src/memory.o
g++ -c src/NodeSet.cpp -o src/NodeSet.o
g++ -c src/TicTacToePlugin.cpp -o src/TicTacToePlugin.o


echo [Compiling test file...]

g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/OperationNode_tests.cpp -o test/OperationNode_tests.o
g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/memory_tests.cpp -o test/memory_tests.o
g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/NodeSet_tests.cpp -o test/NodeSet_tests.o
g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/TicTacToePlugin_tests.cpp -o test/TicTacToePlugin_tests.o


echo [Linking...]

g++ -o run_OperationNode_tests src/OperationNode.o test/OperationNode_tests.o test/gtest-all.o test/gtest_main.o
g++ -o run_memory_tests src/memory.o test/memory_tests.o test/gtest-all.o test/gtest_main.o
g++ -o run_NodeSet_tests src/NodeSet.o src/OperationNode.o test/NodeSet_tests.o test/gtest-all.o test/gtest_main.o
g++ -o run_TicTacToePlugin_tests src/TicTacToePlugin.o src/NodeSet.o src/OperationNode.o test/TicTacToePlugin_tests.o test/gtest-all.o test/gtest_main.o


echo [Build Complete.]
echo [Run with:]
echo [ ./run_OperationNode_tests]
echo [ ./run_memory_tests]
echo [ ./run_NodeSet_tests]
echo [ ./run_TicTacToePlugin_tests]
