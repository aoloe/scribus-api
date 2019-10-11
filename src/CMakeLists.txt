include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/scribus
    ${FREETYPE_INCLUDE_DIRS} # we need those if we want to scribusdoc
    ${HARFBUZZ_INCLUDE_DIRS}
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CMAKE_CXX_FLAGS_FPIC}")

set(SCRIBUS_PLUGINAPI_LIB_MOC_CLASSES
  # document.h
  # item.h
)

set(SCRIBUS_PLUGINAPI_LIB_SOURCES
  # api.cpp
  document.cpp
  # section.cpp
  # page.cpp
  item.cpp
  textframe.cpp
  # imageframe.cpp
)

QT5_WRAP_CPP(SCRIBUS_PLUGINAPI_LIB_MOC_SOURCES ${SCRIBUS_PLUGINAPI_LIB_MOC_CLASSES})

set(SCRIBUS_PLUGINAPI_LIB "scribus_pluginapi_lib")
add_library(${SCRIBUS_PLUGINAPI_LIB} STATIC ${SCRIBUS_PLUGINAPI_LIB_SOURCES} ${SCRIBUS_PLUGINAPI_LIB_MOC_SOURCES})

set_target_properties(${SCRIBUS_PLUGINAPI_LIB}
	PROPERTIES
	COMPILE_FLAGS -DCOMPILE_SCRIBUS_MAIN_APP
)
