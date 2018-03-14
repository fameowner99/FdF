cmake_minimum_required(VERSION 3.9)
project(fdf)
set(CMAKE_CXX_STANDARD 11)
include_directories(${CMAKE_SOURCE_DIR}/libft/includes)
include_directories(${CMAKE_SOURCE_DIR}/includes)
add_executable(fdf
        alg_bresenham.c
        connecting_lines.c
        fdf.c
        fdf.h
        main.c
        read_map.c
        fdf.c
        Makefile)
add_library(libft STATIC IMPORTED) # Создание статической библиотеки
set_property(TARGET libft PROPERTY
        IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(fdf libft)  # Линковка программы с библиотекой
find_library(_mlx mlx)
find_library(_m m)
find_library(_openGL OpenGL)
find_library(_appkit AppKit)
target_link_libraries(fdf ${_mlx})
target_link_libraries(fdf ${_m})
target_link_libraries(fdf ${_openGL})
target_link_libraries(fdf ${_appkit})
set(TARGETS test_maps/42.fdf)

