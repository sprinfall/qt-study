set(CMAKE_AUTORCC ON)

set(TARGET_NAME gui_toolbar_resources)

file(GLOB_RECURSE SHARED_RESC
  "*.qss"
  "*.css"
  "*.qrc"
  "*.def"
)

file(GLOB_RECURSE SHARED_IMGS
  "*.png"
  "*.ico"
  "*.svg"
  "*.jpg"
  "*.bmp"
)

set(SRCS
  ${SHARED_RESC}
  ${SHARED_IMGS}
)

add_library(${TARGET_NAME} SHARED ${SRCS})

target_link_libraries(${TARGET_NAME} LINK_PRIVATE Qt5::Core)
