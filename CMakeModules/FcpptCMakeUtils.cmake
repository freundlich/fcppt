SET (CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS ON)

#Disallow in source builds everywhere
IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles")
ENDIF()

#Has to be kept in sync with boost releases
SET(
	Boost_ADDITIONAL_VERSIONS
	"1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0" "1.44" "1.44.0" "1.45" "1.45.0" "1.46" "1.46.0" "1.46.1"
)

# Setup default compiler flags
INCLUDE(CMakeDetermineCXXCompiler)
INCLUDE(CheckCXXCompilerFlag)

IF(
	"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang"
)
	SET(
		FCPPT_UTILS_COMPILER_IS_CLANGPP ON
	)
ENDIF()

IF(
	CMAKE_COMPILER_IS_GNUCXX OR FCPPT_UTILS_COMPILER_IS_CLANGPP
)
	SET(
		CMAKE_CXX_FLAGS_RELEASE
		"-O3 -fomit-frame-pointer -DNDEBUG"
	)

	# cmake tries to grep for warning messages which will fails in a lot of cases
	SET(
		CMAKE_REQUIRED_FLAGS "-Wall -Werror -pedantic"
	)

	CHECK_CXX_COMPILER_FLAG(
		"-fvisibility=hidden"
		FCPPT_UTILS_HAVE_GCC_VISIBILITY
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wmissing-declarations"
		FCPPT_UTILS_HAVE_MISSING_DECLARATIONS_FLAG
	)

	CHECK_CXX_COMPILER_FLAG(
		"-Wsign-conversion"
		FCPPT_UTILS_HAVE_SIGN_CONVERSION_FLAG
	)

	UNSET(CMAKE_REQUIRED_FLAGS)

	# activate common warning options
	# use -Wno-long-long because too much stuff uses it
	ADD_DEFINITIONS (
		"-pedantic-errors -Wall -Wextra -Wconversion"
		"-Wfloat-equal -Wredundant-decls -Winit-self"
		"-Woverloaded-virtual -Wnon-virtual-dtor -Wshadow"
		"-Wsign-promo -Wstrict-aliasing=1 -Wold-style-cast"
		"-Wno-long-long -ansi"
	)

	IF(FCPPT_HAVE_MISSING_DECLARATIONS_FLAG)
		ADD_DEFINITIONS ("-Wmissing-declarations")
	ENDIF()

	IF(FCPPT_UTILS_HAVE_SIGN_CONVERSION_FLAG)
		ADD_DEFINITIONS ("-Wsign-conversion")
	ENDIF()
ELSEIF(
	MSVC
)
	ADD_DEFINITIONS ("/W4 /wd4996 /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1")
	#4996 - unsafe standard C++ functions
ENDIF()

# Reject libraries with undefined symbols
# VC++ does this by default
IF(UNIX)
	SET(CMAKE_SHARED_LINKER_FLAGS -Wl,--no-undefined)
ENDIF()

# configure standard CMake build paths
SET(
	EXECUTABLE_OUTPUT_PATH
	${CMAKE_BINARY_DIR}/bin
)

SET(
	LIBRARY_OUTPUT_PATH
	${CMAKE_BINARY_DIR}/lib
)

#macro for adding source groups
MACRO(
	FCPPT_UTILS_ADD_SOURCE_GROUPS
	ALL_FILES
)
	FOREACH(
		CURFILE
		${ALL_FILES}
	)
		GET_FILENAME_COMPONENT(
			REL_PATH
			${CURFILE}
			PATH
		)

		STRING(REPLACE "/" "\\" GROUPFOLDER ${REL_PATH})

		SOURCE_GROUP(
			${GROUPFOLDER}
			FILES
			${CURFILE}
		)
	ENDFOREACH()
ENDMACRO()
