#file(GLOB SOURCES LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
file(GLOB HEADERS LIST_DIRECTORIES false CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.h")

set(SOURCES Song.cpp PlayList.cpp main.cpp)

add_executable(project3 ${SOURCES} ${HEADERS})
format(FILES ${SOURCES} ${HEADERS})
lint(FILES ${SOURCES})