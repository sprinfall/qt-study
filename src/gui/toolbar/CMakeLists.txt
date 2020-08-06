add_subdirectory(resources)

add_executable(gui_toolbar toolbar.cpp toolbar.h main.cpp)

target_link_libraries(gui_toolbar gui_toolbar_resources common Qt5::Core Qt5::Gui)
