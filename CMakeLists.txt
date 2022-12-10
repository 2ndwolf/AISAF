cmake_minimum_required(VERSION 3.17)
project(AISAF VERSION 1.0.0.1) 

#Compiler Stuff
set(MINGW_PATH "D:/MinGW/GCC12.2_64/bin")
set(CMAKE_C_COMPILER   "${MINGW_PATH}/gcc.exe")
set(CMAKE_CXX_COMPILER "${MINGW_PATH}/g++.exe")
set(GENERATOR_NAME "MinGW Makefiles")

set(CMAKE_CXX_STANDARD 20)

# SDL2 Stuff
set(SDL2_VERSION       "2.26.0")
set(SDL2_MIXER_VERSION "2.6.2" )

if(CMAKE_SIZEOF_VOID_P EQUAL 4)
	set(sdl_p_folder i686-w64-mingw32)
elseif(CMAKE_SIZEOF_VOID_P EQUAL 8)
	set(sdl_p_folder x86_64-w64-mingw32)
# if not compiling, just use the x86_64 includes
else()
	set(sdl_p_folder x86_64-w64-mingw32)	
endif()

# Output
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
 
include_directories(AISAF
		${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/dependencies/SDL2-${SDL2_VERSION}/${sdl_p_folder}/include/SDL2
		${PROJECT_SOURCE_DIR}/dependencies/SDL2_mixer-${SDL2_MIXER_VERSION}/${sdl_p_folder}/include/SDL2
)

file(GLOB SOURCES        ${PROJECT_SOURCE_DIR}/src/*.cpp    )
file(GLOB NESTEDSOURCES  ${PROJECT_SOURCE_DIR}/src/*/*.cpp  )
file(GLOB NESTEDSOURCES2 ${PROJECT_SOURCE_DIR}/src/*/*/*.cpp)
file(GLOB HEADERS        ${PROJECT_SOURCE_DIR}/include/*.h  )
file(GLOB NESTEDHEADERS  ${PROJECT_SOURCE_DIR}/include/*/*.h)

set(SDL2_DIR       ${PROJECT_SOURCE_DIR}/dependencies/SDL2-${SDL2_VERSION}/cmake/)
set(SDL2_mixer_DIR ${PROJECT_SOURCE_DIR}/dependencies/SDL2_mixer-${SDL2_MIXER_VERSION}/cmake/)

find_package(SDL2       REQUIRED)
find_package(SDL2_mixer REQUIRED)


if(NOT "${PROJECT_SOURCE_DIR}/ini/uPref.ini" STREQUAL "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ini/uPref.ini")
	configure_file("${PROJECT_SOURCE_DIR}/ini/uPref.ini" "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/ini/uPref.ini" COPYONLY)
endif()

if(NOT STATIC_BUILD)
	file(COPY ${PROJECT_SOURCE_DIR}/dependencies/SDL2-${SDL2_VERSION}/${sdl_p_folder}/bin/SDL2.dll                   DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)
	file(COPY ${PROJECT_SOURCE_DIR}/dependencies/SDL2_mixer-${SDL2_MIXER_VERSION}/${sdl_p_folder}/bin/SDL2_mixer.dll DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/)

	add_library(AISAF        ${SOURCES} ${NESTEDSOURCES} ${NESTEDSOURCES2} ${HEADERS} ${NESTEDHEADERS})
	target_link_libraries(AISAF SDL2::SDL2        SDL2_mixer::SDL2_mixer)
else()
	add_library(AISAF STATIC ${SOURCES} ${NESTEDSOURCES} ${NESTEDSOURCES2} ${HEADERS} ${NESTEDHEADERS})
	target_link_libraries(AISAF SDL2::SDL2-static SDL2_mixer::SDL2_mixer-static)
endif()
