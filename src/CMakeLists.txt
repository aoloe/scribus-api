include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/scribus
    ${FREETYPE_INCLUDE_DIRS} # we need those if we want to scribusdoc
    ${HARFBUZZ_INCLUDE_DIRS}
)

set(SCRIBUS_API_LIB_MOC_CLASSES
  document.h
)

set(SCRIBUS_API_LIB_SOURCES
  # api.cpp
  document.cpp
  # section.cpp
  # page.cpp
  item.cpp
  # textFrame.cpp
  # imageFrame.cpp
)

set(SCRIBUS_API_LIB "scribus_api_lib")

QT5_WRAP_CPP(SCRIBUS_API_LIB_MOC_SOURCES ${SCRIBUS_API_LIB_MOC_CLASSES})

add_library(${SCRIBUS_API_LIB} STATIC ${SCRIBUS_API_LIB_SOURCES} ${SCRIBUS_API_LIB_MOC_SOURCES})

# This is a convenience library that for linkage purposes is part of Scribus's
# main API.
set_target_properties(${SCRIBUS_API_LIB}
	PROPERTIES
	COMPILE_FLAGS -DCOMPILE_SCRIBUS_MAIN_APP
)

add_dependencies(${SCRIBUS_API_LIB} ${EXE_NAME})
