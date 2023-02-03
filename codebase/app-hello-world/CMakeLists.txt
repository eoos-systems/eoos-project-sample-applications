# EOOS Sample Application.
#
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2022, Sergey Baigudin, Baigudin Software

add_executable(target-eoos-app-hello-world
    "${CMAKE_CURRENT_LIST_DIR}/source/Program.cpp"
)

target_link_libraries(target-eoos-app-hello-world
PRIVATE
    eoos::main
)

if(UNIX)
target_link_libraries(target-eoos-app-hello-world
PRIVATE
    Threads::Threads
)
endif()


set_target_properties(target-eoos-app-hello-world PROPERTIES
    OUTPUT_NAME EoosAppHelloWorld
)
