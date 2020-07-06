add_executable(gui_font_study font_study.cpp)

target_link_libraries(gui_font_study common Qt5::Core Qt5::Gui)

add_subdirectory(toolbar)
