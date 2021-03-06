cmake_minimum_required(VERSION 3.2)

################################
# Версионность
################################

if(PROJECT_VERSION_PATCH GREATER 0)
    set(CUR_VERSION $ENV{PROJECT_VERSION_PATCH})
    project(helloworld VERSION 0.0.${CUR_VERSION})
else()
    project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER} )
endif()

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

################################
# GTest
################################
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})


configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)
add_library(helloworld lib.cpp)
add_executable(test_version test_version.cpp)
add_executable( Gtest_version Gtest_version.cpp)

set_target_properties(helloworld_cli helloworld test_version PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)
target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)

set_target_properties(helloworld_cli helloworld Gtest_version PROPERTIES
 CXX_STANDARD 14
 CXX_STANDARD_REQUIRED ON
)

set_target_properties(test_version PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(helloworld_cli PRIVATE
    helloworld
)
target_link_libraries(test_version
    ${Boost_LIBRARIES}
    helloworld
)

target_link_libraries(Gtest_version ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} helloworld)


if (MSVC)
    target_compile_options(helloworld_cli PRIVATE
        /W4
    )
    target_compile_options(helloworld PRIVATE
        /W4
    )
    target_compile_options(test_version PRIVATE
        /W4
    )
    target_compile_options(Gtest_version PRIVATE
    /W4
       )
else ()
    target_compile_options(helloworld_cli PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(helloworld PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(test_version PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(Gtest_version PRIVATE
    -Wall -Wextra -pedantic -Werror
)

endif()



install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)


add_test(test_version test_version)
add_test(Gtest_version Gtest_version)