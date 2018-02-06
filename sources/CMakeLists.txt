cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_COMPILER  g++)
project(Gonetlet)

if (UNIX)
  # The version number.
  set(Gonetlet_VERSION_MAJOR 1)
  set(Gonetlet_VERSION_MINOR 0)

  # configure a header file to pass some of the CMake settings
  # to the source code
  configure_file(
    "${PROJECT_SOURCE_DIR}/GonetletConfig.h.in"
    "${PROJECT_BINARY_DIR}/GonetletConfig.h"
    )


  add_compile_options(-std=c++17)
  # add_compile_options(-W)
  # add_compile_options(-Wall)

  find_package(X11 REQUIRED)
  find_package(OpenGL REQUIRED)
  find_package(GLUT REQUIRED)
  find_package(ZLIB REQUIRED)
  find_package(PythonLibs REQUIRED)

  include_directories(SYSTEM
    ${PROJECT_SOURCE_DIR}/libraries/irrlicht/include
  )

  include_directories(
    ${X11_INCLUDE_DIR}
    ${OpenGL_INCLUDE_DIR}
    ${PYTHON_INCLUDE_DIRS}
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/sources
    ${PROJECT_SOURCE_DIR}/sources/Core
    ${PROJECT_SOURCE_DIR}/sources/Entity
    ${PROJECT_SOURCE_DIR}/sources/Events
    ${PROJECT_SOURCE_DIR}/sources/Features
    ${PROJECT_SOURCE_DIR}/sources/GameObject
    ${PROJECT_SOURCE_DIR}/sources/Gui
    ${PROJECT_SOURCE_DIR}/sources/IA
    ${PROJECT_SOURCE_DIR}/sources/Menu
    ${PROJECT_SOURCE_DIR}/sources/Projectil
    ${PROJECT_SOURCE_DIR}/sources/RessourceManager
    ${PROJECT_SOURCE_DIR}/sources/SpawnManager
    ${PROJECT_SOURCE_DIR}/sources/SplashScreen
  )

  FILE(GLOB PROJECT_SOURCES
      sources/*.hpp
      sources/*.h
      sources/*.cpp
      sources/Core/*.hpp
      sources/Core/*.cpp
      sources/Entity/*.hpp
      sources/Entity/*.cpp
      sources/Events/*.hpp
      sources/Events/*.cpp
      sources/Features/*.hpp
      sources/Features/*.cpp
      sources/GameObject/*.hpp
      sources/GameObject/*.cpp
      sources/Gui/*.hpp
      sources/Gui/*.cpp
      sources/IA/*.hpp
      sources/IA/*.cpp
      sources/Menu/*.hpp
      sources/Menu/*.cpp
      sources/Projectil/*.hpp
      sources/Projectil/*.cpp
      sources/RessourceManager/*.hpp
      sources/RessourceManager/*.cpp
      sources/SpawnManager/*.hpp
      sources/SpawnManager/*.cpp
      sources/SplashScreen/*.hpp
      sources/SplashScreen/*.cpp
    )

  add_executable(gonetlet ${PROJECT_SOURCES})

  target_link_libraries(gonetlet
    ${PROJECT_SOURCE_DIR}/libraries/irrlicht/lib/linux/libIrrlicht.a
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${X11_LIBRARIES}
    ${X11_Xxf86vm_LIB}
    ${ZLIB_LIBRARIES}
    ${PYTHON_LIBRARIES}
    -pthread -ldl -lsfml-system -lsfml-audio
    ${PROJECT_SOURCE_DIR}/libraries/irrlicht/lib/linux/libXcursor.so
  )

  install (TARGETS gonetlet DESTINATION ${PROJECT_SOURCE_DIR})
endif (UNIX)
