project(scq)

set(SCQ_ANTLR_DIR "${CMAKE_CURRENT_LIST_DIR}/thirdparty/antlr")
set(SCQ_DIR "${CMAKE_CURRENT_LIST_DIR}/scq")

find_package(Java)
add_custom_command(OUTPUT "${SCQ_DIR}/scqLexer.cpp"
		"${SCQ_DIR}/scqLexer.h"
		"${SCQ_DIR}/sqqParser.cpp"
		"${SCQ_DIR}/scqParser.h"
		COMMAND "${Java_JAVA_EXECUTABLE}" -jar "${SCQ_ANTLR_DIR}/antlr-4.7.1-complete.jar" scq.g4 -no-listener -package scq
		WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/scq"
		DEPENDS scq/scq.g4
		)

add_custom_target(SCqParser ALL
		DEPENDS "${CMAKE_CURRENT_LIST_DIR}"
		SOURCES "scq/scq.g4"
		)

set(SOURCES_PARSER
		"${SCQ_DIR}/scqLexer.cpp"
		"${SCQ_DIR}/scqLexer.h"
		"${SCQ_DIR}/scqParser.cpp"
		"${SCQ_DIR}/scqParser.h"
		)

include_directories(
		${CMAKE_CURRENT_LIST_DIR}
		${SCQ_ANTLR_DIR}
		${SCQ_DIR}
		)

add_executable(scq main.cpp ${SOURCES_PARSER} thirdparty)
add_subdirectory(thirdparty)
target_include_directories(scq PRIVATE ${SCQ_ANTLR_DIR}/runtime/src)

target_link_libraries(scq
		antlr4_static
		)
add_dependencies(scq antlr4_static SCqParser)
