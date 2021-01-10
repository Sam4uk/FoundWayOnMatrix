cmake_minimum_required(VERSION 3.10)

# Forced compiler selection
set(CMAKE_CXX_COMPILER clang++)

project(TT1)

# Compiler options
add_compile_options(
  -Werror
  -pedantic-errors

  -Wpedantic

  -Wcast-align
  -Wcast-qual
  -Wconversion
  -Wctor-dtor-privacy
  -Wextra-semi
  -Wfloat-equal

  -Wnon-virtual-dtor
  -Wold-style-cast
  -Woverloaded-virtual
  -Wredundant-decls
  -Wsign-promo
  -Wall
  -Wextra  
)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES
                source/*.cpp
                          )

add_executable( ${PROJECT_NAME} 
                ${SOURCES}  
               )


enable_testing()

set(VERYFI_TIMEOUT 60)

add_test(Test_mast_be_failed1 ${PROJECT_NAME})
add_test(Test_mast_be_failed2 ${PROJECT_NAME} QLGNAEKIRLRNGEAE)
add_test(TEST2 ${PROJECT_NAME} QLGNAEKIRLRNGEAE KINE U)
add_test(TEST3 ${PROJECT_NAME} QLGNAEKIRLRNGEAE KING)
add_test(TEST4 ${PROJECT_NAME} QLGNAEKIRLRNGEAE LEG)
add_test(TEST5 ${PROJECT_NAME} QLGNAEKIRLRNGEAE QLG)
add_test(Test_mast_be_failed3 ${PROJECT_NAME} QLGNAEKIRLRNGEAE AAA)
add_test(Test_mast_be_failed4 ${PROJECT_NAME} QLGNAEKIRLRNGEAE OPEN)
