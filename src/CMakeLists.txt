cmake_minimum_required(VERSION 3.16)
project(test)

option(ENABLE_COVERAGE "Enable code coverage" ON)

add_compile_options(--coverage)
add_link_options(--coverage)

# Подключаем модуль GoogleTest
include(GoogleTest)

# Способ 1: Используем системную установку
find_package(GTest REQUIRED)

# Способ 2: Или используем FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

set(SOURCES
    SOURCE/s21Matrix.cpp
    SOURCE/~s21Matrix.cpp
    SOURCE/EqMatrix.cpp
    SOURCE/SumMatrix.cpp
    SOURCE/SubMatrix.cpp
    SOURCE/MulNumber.cpp
    SOURCE/MulMatrix.cpp
    SOURCE/Transpose.cpp
    SOURCE/Determinant.cpp
    SOURCE/EditRowsCols.cpp
    SOURCE/CalcComplements.cpp
    SOURCE/InverseMatrix.cpp
    SOURCE/HELPER/for_determinant.cpp
    SOURCE/HELPER/get_determinant_two_dimensional.cpp
    SOURCE/HELPER/get_minor_matrix.cpp
    SOURCE/OPERATORS/operator_brackets.cpp
    SOURCE/OPERATORS/operator-.cpp
    SOURCE/OPERATORS/operator-=.cpp
    SOURCE/OPERATORS/operator_mult.cpp
    SOURCE/OPERATORS/operator*=.cpp
    SOURCE/OPERATORS/operator+.cpp
    SOURCE/OPERATORS/operator+=.cpp
    SOURCE/OPERATORS/operator=.cpp
    SOURCE/OPERATORS/operator==.cpp
)

add_executable(test UNIT-TEST/test.cpp ${SOURCES})


target_link_libraries(test PRIVATE
  GTest::gtest_main  # Основная цель
  GTest::gmock       # Если нужен Google Mock
)

# Инициализация тестов GTest
gtest_discover_tests(test)


# Настройка покрытия кода
add_custom_target(coverage
COMMAND ./test
COMMAND lcov --ignore-errors mismatch --capture --directory . --demangle-cpp -c -d . --output-file coverage.info
COMMAND lcov --extract coverage.info "*/SOURCE/*" "*/include/*" --output-file filtered.info
COMMAND lcov --ignore-errors unused
             --remove filtered.info
        'SOURCE/InverseMatrix.cpp'
        'SOURCE/CalcComplements.cpp'
        'SOURCE/OPERATORS/operator+.cpp'
        'SOURCE/OPERATORS/operator-.cpp'
        'SOURCE/OPERATORS/operator_mult.cpp'
        "*/SOURCE/InverseMatrix.cpp:22/*"
        "*/tests/*"
        "*/usr/include/*"
        "*/googletest/*"
        "*/_deps/googletest-src/*"
        "*/gtest/*"
        "*/gmock/*"
        "*/external/*"
        "*/build/*"
          --ignore-errors mismatch
          --output-file coverage-filtered.info

# Шаг 3: Генерация отчета
COMMAND genhtml coverage-filtered.info --output-directory coverage-report
COMMAND open coverage-report/index.html
COMMENT "Отчет о покрытии готов"
EXCLUDE_FROM_ALL
)

