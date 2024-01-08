set(X_SOURCE_FILES "")

file(GLOB X_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*")

foreach(xi ${X_SOURCE_FILES})
    message("Processing '${xi}'...")

    set(xi_filename "")
    set(xi_targetname "")

    string(REGEX REPLACE "^\/(.+\/)+" "" xi_filename ${xi})
    string(REGEX MATCH "[A-Za-z]+" xi_targetname ${xi_filename})

    # Skip the CMakeLists file
    set(is_cmakelists "")

    string(COMPARE EQUAL "${xi_filename}" "CMakeLists.txt" is_cmakelists)
    if(is_cmakelists)
        continue()
    endif()

    message("xi_filename ${xi_filename}")
    message("xi_targetname ${xi_targetname}")

    add_executable(${xi_targetname} ${CMAKE_CURRENT_SOURCE_DIR}/${xi_filename})
endforeach()
