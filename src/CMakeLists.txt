set(X_SOURCE_FILES "")

file(GLOB X_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*")

foreach(xi ${X_SOURCE_FILES})
    # Skip the CMakeLists file
    set(is_cmakelists "")

    string(COMPARE EQUAL "${xi_filename}" "CMakeLists.txt" is_cmakelists)
    if(is_cmakelists)
        continue()
    endif()

    message(STATUS "Processing '${xi}'...")

    set(xi_filename "")
    set(xi_targetname "")

    string(REGEX REPLACE "^\/(.+\/)+" "" xi_filename ${xi})
    string(REGEX MATCH "[A-Za-z]+" xi_targetname ${xi_filename})

    # Grab the hash of the source file to make the target name unique
    file(SHA256 ${xi} xi_hash)
    string(SUBSTRING "${xi_hash}" 0 6 xi_hash_1)
    string(APPEND xi_targetname "${xi_hash_1}")

    message(DEBUG "xi_hash_1 ${xi_hash_1}")
    message(DEBUG "xi_filename ${xi_filename}")
    message(DEBUG "xi_targetname ${xi_targetname}")

    add_executable(${xi_targetname} ${CMAKE_CURRENT_SOURCE_DIR}/${xi_filename})
endforeach()
