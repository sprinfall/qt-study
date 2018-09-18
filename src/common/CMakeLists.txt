set(COMMON_SRCS
	utility.cpp
	utility.h
	)

add_library(common ${COMMON_SRCS})

target_link_libraries(common Qt5::Widgets)
