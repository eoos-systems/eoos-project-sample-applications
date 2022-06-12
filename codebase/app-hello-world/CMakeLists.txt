# EOOS Sample Application.
#
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2022, Sergey Baigudin, Baigudin Software

add_executable(target-eoos-app-hello-world)

target_sources(target-eoos-app-hello-world
PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/source/main.cpp"
)

target_link_libraries(target-eoos-app-hello-world
PRIVATE
    eoos::eoos
)

set_target_properties(target-eoos-app-hello-world PROPERTIES
    OUTPUT_NAME EoosAppHelloWorld
)
