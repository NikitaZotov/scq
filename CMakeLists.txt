set(SC_MACHINE_ANTRL_DIR "${SC_MACHINE_THIRDPARTY_PATH}/antlr")
set(SCQ_LANG_DIR "${CMAKE_CURRENT_LIST_DIR}/scq")

add_custom_command(OUTPUT "${SCQ_DIR}/scqLexer.cpp"
		"${SCQ_DIR}/scqLexer.h"
		"${SCQ_DIR}/sqqParser.cpp"
		"${SCQ_DIR}/scqParser.h"
		COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${SC_MACHINE_ANTRL_DIR}/antlr-4.7.1-complete.jar" scq.g4 -no-listener -package scq
		WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/scq"
		DEPENDS scq/scq.g4
		)

add_custom_target(SCqParser ALL
		DEPENDS "${CMAKE_CURRENT_LIST_DIR}"
		SOURCES "scq/scq.g4"
		)

set(SOURCES_PARSER
		"${SCQ_LANG_DIR}/scqLexer.cpp"
		"${SCQ_LANG_DIR}/scqLexer.h"
		"${SCQ_LANG_DIR}/scqParser.cpp"
		"${SCQ_LANG_DIR}/scqParser.h"
		"${SCQ_LANG_DIR}/scqCompiler.cpp"
		"${SCQ_LANG_DIR}/scqCompiler.hpp"
		)

file(GLOB_RECURSE SOURCES "*.cpp" "*.hpp")

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.71.0 COMPONENTS filesystem program_options)

include_directories(${Boost_INCLUDE_DIRS})

add_library(scq SHARED ${SOURCES} ${SOURCES_PARSER})

target_include_directories(scq
		PRIVATE ${GLIB2_INCLUDE_DIRS}
		PRIVATE ${Boost_LIBRARIES}
		PRIVATE ${SC_MACHINE_ANTRL_DIR}/runtime/src
		PRIVATE ${SC_MEMORY_SRC}
		PRIVATE ${PYTHON_INCLUDE_DIRS}
		)

add_executable(scqc main.cpp ${SOURCES_PARSER} ${SOURCES} ${Boost_INCLUDE_DIRS} "${SC_MACHINE_ANTRL_DIR}/runtime/src")

target_include_directories(scqc PRIVATE ${SC_MACHINE_ANTRL_DIR}/runtime/src ${SC_MEMORY_SRC})

target_link_libraries(scqc antlr4_static ${Boost_LIBRARIES} sc-memory)

add_dependencies(scqc antlr4_static SCqParser sc-memory)

target_link_libraries(scq
		sc-core
		sc-memory
		antlr4_static
		${LIBCURL_LIBRARIES}
		${PYTHON_LIBRARIES}
		${Boost_LIBRARIES}
		)

sc_codegen_ex(scq ${CMAKE_CURRENT_SOURCE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/generated" sc-memory)
add_dependencies(scq
		sc-core
		sc-memory
		sc-code-generator
		antlr4_static
		SCqParser
		)
target_compile_definitions(scq PRIVATE "-DSC_MEMORY_SELF_BUILD")
