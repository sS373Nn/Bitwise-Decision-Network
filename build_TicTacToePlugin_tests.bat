@echo off

REM Works for now, but there is probably a better way to recompile at each test without rebuilding all the static files from gtest

echo [Compiling project sources...]

g++ -c src/NodeSet.cpp -o src/NodeSet.o
g++ -c src/OperationNode.cpp -o src/OperationNode.o
g++ -c src/TicTacToePlugin.cpp -o src/TicTacToePlugin.o


echo [Compiling test file...]

g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/TicTacToePlugin_tests.cpp -o test/TicTacToePlugin_tests.o


echo [Linking...]

g++ -o run_TicTacToePlugin_tests src/TicTacToePlugin.o src/NodeSet.o src/OperationNode.o test/TicTacToePlugin_tests.o test/gtest-all.o test/gtest_main.o


echo [Build Complete. Run with ./run_TicTacToePlugin_tests]
