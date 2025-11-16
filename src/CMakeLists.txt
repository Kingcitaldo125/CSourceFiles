set(X_SOURCE_FILES "")

file(GLOB X_SOURCE_FILES "${CMAKE_CURRENT_SOURCE_DIR}/*")

foreach(xi ${X_SOURCE_FILES})
    set(xi_filename "")
    string(REGEX REPLACE "^\/(.+\/)+" "" xi_filename ${xi})
    message(DEBUG "xi_filename ${xi_filename}")

    # Skip the CMakeLists file
    set(is_cmakelists "")

    string(COMPARE EQUAL "${xi_filename}" "CMakeLists.txt" is_cmakelists)
    if(is_cmakelists)
        message(DEBUG "skipping ${xi}")
        continue()
    endif()

    message(STATUS "Processing '${xi}'...")

    set(xi_targetname "")
    set(xi_hash "")
    set(xi_hash_1 "")

    string(REGEX MATCH "[A-Za-z]+" xi_targetname ${xi_filename})

    # Grab the hash of the source file to make the target name unique
    file(SHA256 ${xi} xi_hash)
    string(SUBSTRING "${xi_hash}" 0 6 xi_hash_1)
    string(APPEND xi_targetname "_${xi_hash_1}")

    message(DEBUG "xi_hash_1 ${xi_hash_1}")
    message(DEBUG "xi_targetname ${xi_targetname}")

    add_executable(${xi_targetname} ${CMAKE_CURRENT_SOURCE_DIR}/${xi_filename})
endforeach()
