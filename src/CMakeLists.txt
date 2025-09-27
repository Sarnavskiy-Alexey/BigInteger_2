# Требуемая минимальная версия CMake
cmake_minimum_required(VERSION 3.30)

# Название и версия основного проекта
project("big_integer" VERSION 0.1)

# Создаем переменную, хранящую пути к файлам
file(
    GLOB TARGET_SRC
    *.cc
    ../main.cc
    # ../inc/main.h
)

# Создаем переменную, хранящую пути к заголовочным файлам библиотеки
file(
    GLOB HEADER_LIB
    ../inc/*.h
)

# Создаем переменную, хранящую пути к файлам реализации библиотеки
file(
    GLOB SOURCE_LIB
    ../inc/*((?!main))*.cc
)

# Создаем библиотеку для последующего использования (например, в тестах)
add_library(BigIntegerLib ${HEADER_LIB} ${SOURCE_LIB})

# Добавляем сторонние библиотеки
include(FetchContent)

# Добавляем в проект задачу собрать исполняемый файл
add_executable(
    big_integer
    ${TARGET_SRC}
)

# Добавляем библиотеку BigIntegerLib в проект
target_link_libraries(
    big_integer
    BigIntegerLib
)
