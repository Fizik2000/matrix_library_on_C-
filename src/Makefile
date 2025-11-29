CPPFLAGS = -Wall -Wextra -Werror  # -pedantic -fsanitize=address -fsanitize=undefined


all: s21_matrix_oop.a


s21_matrix_oop.a:
	g++ $(CPPFLAGS) -c -g SOURCE/*.cpp SOURCE/HELPER/*.cpp SOURCE/OPERATORS/*.cpp
	ar cr s21_matrix_oop.a *.o
# r: добавление файлов в архив,
# c: создание архива, если он не существует,
	rm *.o

# run: s21_matrix_oop.a
# 	g++  main.cpp s21_matrix_oop.a -o main.o
# 	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./main.o
# 	rm -rf *.a *.o

test: s21_matrix_oop.a
	mkdir -p build
	cd build && cmake ..
	cd build && make
	valgrind --tool=memcheck --leak-check=yes --track-origins=yes ./build/test

gcov_report: clean_build
	mkdir -p build
	cd build
	cd build && cmake -DENABLE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug ..
	cd build && make test
	cd build && make coverage
	

clang_check:
	clang-format -n *.h SOURCE/*.cpp SOURCE/HELPER/*.cpp SOURCE/OPERATORS/*.cpp UNIT-TEST/test.cpp

clang:
	clang-format -i *.h SOURCE/*.cpp SOURCE/HELPER/*.cpp SOURCE/OPERATORS/*.cpp UNIT-TEST/test.cpp

clean_build:
	rm -rf build

clean:
	rm -rf *.a *.o *.gcno *.gcda *.info

clean_all: clean_build clean