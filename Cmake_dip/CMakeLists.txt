# CMakeList.txt: проект CMake для Cmake_dip; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (Cmake_dip "Cmake_dip.cpp" "Cmake_dip.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Cmake_dip PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
