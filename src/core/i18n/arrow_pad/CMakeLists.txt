set(TARGET_NAME i18n_arrow_pad)

# For Qt5LinguistTools macros (e.g., qt5_create_translation).
find_package(Qt5 REQUIRED LinguistTools)

set(SRCS
	arrow_pad.cpp
	arrow_pad.h
	main_window.cpp
	main_window.h
	main.cpp)

file(GLOB_RECURSE TR_SRCS
	*.cpp
	*.h
	*.qml
	*.ui
)

set(TS_FILES
	ts/arrow_pad_zh_CN.ts
	ts/arrow_pad_zh_TW.ts)

# See: https://doc.qt.io/qt-5/cmake-manual.html
qt5_create_translation(QM_FILES ${TR_SRCS} ${TS_FILES})

# The ts_files must exist and are not updated in any way.
#qt5_add_translation(QM_FILES ts/arrow_pad_fr.ts)

add_custom_target(i18n_arrow_pad_tr DEPENDS ${QM_FILES})
message(STATUS "QM: " ${QM_FILES})

add_executable(${TARGET_NAME} ${SRCS})

target_link_libraries(${TARGET_NAME} Qt5::Core Qt5::Widgets)

install(FILES ${QM_FILES} DESTINATION ./locale)

# The QM files of Qt itself.
# See CMakeLists.txt in the root dir for ${Qt5_location}.
# TODO: Add qtbase_*.qm, remove qt_help_*.qm, etc.
file(GLOB_RECURSE QT_QM_FILES ${Qt5_location}/../translations/qt_*.qm)
# Install Qt QM files to <dst>/locale/qt sub-foler.
# Suppose the <dst> was configured by CMAKE_INSTALL_PREFIX as, e.g.,
#   <build_dir>\src\core\i18n\arrow_pad\Debug
install(FILES ${QT_QM_FILES} DESTINATION ./locale/qt)
