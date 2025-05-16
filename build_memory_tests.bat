@echo off

REM Works for now, but there is probably a better way to recompile at each test without rebuilding all the static files from gtest

echo [Compiling project sources...]

g++ -c src/memory.cpp -o src/memory.o


echo [Compiling test file...]

g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/memory_tests.cpp -o test/memory_tests.o


echo [Linking...]

g++ -o run_memory_tests src/memory.o test/memory_tests.o test/gtest-all.o test/gtest_main.o


echo [Build Complete. Run with ./run_memory_tests]
