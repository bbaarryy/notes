
# - Try to find Sphinx
#
# This module defines
#  SPHINX_EXECUTABLE, the path to the sphinx-build executable
#  SPHINX_FOUND, whether sphinx-build is found
#  SPHINX_VERSION, the version of Sphinx

find_program(SPHINX_EXECUTABLE
    NAMES sphinx-build
    DOC "Path to sphinx-build executable"
)

if(SPHINX_EXECUTABLE)
    execute_process(
        COMMAND ${SPHINX_EXECUTABLE} --version
        OUTPUT_VARIABLE SPHINX_VERSION_OUTPUT
        ERROR_QUIET
        OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    # Example output: "sphinx-build 7.2.6"
    string(REGEX MATCH "([0-9]+\\.[0-9]+\\.[0-9]+)" SPHINX_VERSION "${SPHINX_VERSION_OUTPUT}")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Sphinx
    FOUND_VAR SPHINX_FOUND
    REQUIRED_VARS SPHINX_EXECUTABLE
    VERSION_VAR SPHINX_VERSION
)

mark_as_advanced(SPHINX_EXECUTABLE)
