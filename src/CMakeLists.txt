include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/scribus
    ${FREETYPE_INCLUDE_DIRS} # we need those if we want to scribusdoc
    ${HARFBUZZ_INCLUDE_DIRS}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_FPIC}")

set(SCRIBUS_API_LIB_MOC_CLASSES
  # document.h
  # item.h
)

set(SCRIBUS_API_LIB_SOURCES
  # api.cpp
  document.cpp
  # section.cpp
  # page.cpp
  item.cpp
  textframe.cpp
  # imageframe.cpp
)

QT5_WRAP_CPP(SCRIBUS_API_LIB_MOC_SOURCES ${SCRIBUS_API_LIB_MOC_CLASSES})

set(SCRIBUS_API_LIB "scribus_api_lib")
add_library(${SCRIBUS_API_LIB} STATIC ${SCRIBUS_API_LIB_SOURCES} ${SCRIBUS_API_LIB_MOC_SOURCES})

set_target_properties(${SCRIBUS_API_LIB}
	PROPERTIES
	COMPILE_FLAGS -DCOMPILE_SCRIBUS_MAIN_APP
)
