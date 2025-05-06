@echo off

REM Works for now, but there is probably a better way to recompile at each test without rebuilding all the static files from gtest

echo [Compiling GoogleTest sources...]

g++ -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest" -c "C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/src/gtest-all.cc" -o test/gtest-all.o

g++ -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest" -c "C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/src/gtest_main.cc" -o test/gtest_main.o


echo [Compiling project sources...]

g++ -c src/core_logic.cpp -o src/core_logic.o

echo [Compiling test file...]

g++ -I./src -I"C:/Users/David/DevLibs/googletest/googletest-1.17.0/googletest/include" -c test/google_tests.cpp -o test/google_tests.o


echo [Linking...]

g++ -o run_tests src/core_logic.o test/google_tests.o test/gtest-all.o test/gtest_main.o


echo [Build Complete. Run with ./run_tests]
