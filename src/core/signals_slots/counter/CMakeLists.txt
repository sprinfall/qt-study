set(TARGET_NAME signals_slots_counter)

set(SRCS counter.cpp counter.h main.cpp)

add_executable(${TARGET_NAME} ${SRCS})

target_link_libraries(${TARGET_NAME} Qt5::Core)
