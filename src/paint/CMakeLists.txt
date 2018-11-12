file(GLOB SRCS *.cpp *.h)

set(TARGET_NAME paint_study)

add_executable(${TARGET_NAME} WIN32 MACOSX_BUNDLE ${SRCS})

target_link_libraries(${TARGET_NAME} common Qt5::Widgets)
