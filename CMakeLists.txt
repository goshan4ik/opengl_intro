cmake_minimum_required(VERSION 3.17)
project(opengl_init)

set(CMAKE_CXX_STANDARD 14)
set(GLUT_INCLUDE_DIR "C:/Users/gteme/GLUT/freeglut/include")
set(OPENGL_LIBRARY_DIR "C:/Users/gteme/GLUT/freeglut/lib")
#set(GLEW_INCLUDE_DIRS "C:/Users/gteme/GLUT/glew-1.11.0/include")
#set(GLEW_LIBRARIES "C:/Users/gteme/GLUT/glew-1.11.0/lib")

add_executable(opengl_init main.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
#find_package(GLEW REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
target_link_libraries(opengl_init ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})


