project(gui_font_study)

add_executable(font_study font_study.cpp)

target_link_libraries(font_study common Qt5::Core Qt5::Gui)
