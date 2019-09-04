add_executable(codec_study codec_study.cpp)
add_executable(file_io_study file_io_study.cpp)
add_executable(std_paths_study std_paths_study.cpp)
add_executable(string_study string_study.cpp)
add_executable(meta_object meta_object.cpp)

target_link_libraries(codec_study common Qt5::Core)
target_link_libraries(file_io_study common Qt5::Core)
target_link_libraries(std_paths_study common Qt5::Core)
target_link_libraries(string_study common Qt5::Core)
target_link_libraries(meta_object common Qt5::Core)

add_subdirectory(signals_slots)
add_subdirectory(i18n)
