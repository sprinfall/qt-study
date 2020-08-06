set(TARGET_NAME opengl_triangle)

set(CMAKE_AUTOMOC ON)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}
  )

file(GLOB SRCS *.cpp *.h)

add_executable(${TARGET_NAME} ${SRCS})

target_link_libraries(${TARGET_NAME}
    Qt5::Core Qt5::Gui Qt5::Widgets Qt5::OpenGL)
