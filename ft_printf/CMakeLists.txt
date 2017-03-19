cmake_minimum_required(VERSION 3.6)
project(Printf)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc libft/includes) # headers
link_directories(libft) # libraries

set(SOURCE_FILES
        printf_main.c wide_chars.c chars.c conversion.c decimals.c flagged_base.c flagged_decimals.c flagged_unsigned.c ft_printf.c other.c output.c printf_lib.c unsigned.c pointer.c octal.c hex.c widechr.c)

add_executable(Printf ${SOURCE_FILES})

target_link_libraries(Printf libft.a) # linkage