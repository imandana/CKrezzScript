cmake_minimum_required(VERSION 3.10)
project(CKrezzScript)

########################################################################################

# Get all header in remorse lib header
#file(GLOB LIB
#	"Include/*.cpp")

# Get all files inside source for engine
file(GLOB SRC
	"src/Core.c"
    "src/MyClass.c"
    "src/main.c" )
	
#########LINKING LIB AREA###############################################################


    
#file(GLOB LUASCRIPT
#	"Dependencies/LuaScript/lib")
########################################################################################

##### Remorse Team Lib
#add_library(REMORSE_MATH ${LIB})

##### SFML Lib
include_directories("src")
include_directories("include")
include_directories("Depedencies/Klib")


# Set project output path, so it won't defaulted into project.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

########################################################################################

# specify the headers location
#target_include_directories(REMORSE_MATH PUBLIC include)

# executeable that use the libraries, with it own source file in a different directory
add_executable(${PROJECT_NAME} ${SRC})

# set startup project inside solution
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})


# remove ZERO_CHECK solution because i hate it
set(CMAKE_SUPPRESS_REGENERATION true)

