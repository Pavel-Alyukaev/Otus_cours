cmake_minimum_required ( версия 3.2)

проект (helloworld версии 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package (требуется повысить компоненты unit_test_framework)

configure_file (version.h.in версия.х)

add_executable(helloworld_cli main.СРР)
add_library(helloworld lib.СРР)
add_executable(test_version test_version.СРР)

set_target_properties (свойства helloworld_cli HelloWorld test_version
 CXX_STANDARD 14
 CXX_STANDARD_REQUIRED ON
)
target_include_directories(helloworld
    PRIVATE "${CMAKE_BINARY_DIR}"
)
set_target_properties (свойства test_version
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries (HELLOWORLD_CLI PRIVATE
 helloworld
)
target_link_libraries(test_version
    ${Boost_LIBRARIES}
 helloworld
)

если (MSVC)
    target_compile_options (HELLOWORLD_CLI PRIVATE
 /W4
    )
    target_compile_options (HelloWorld PRIVATE
 /W4
    )
    target_compile_options (TEST_VERSION PRIVATE
 /W4
    )
остальное ()
    target_compile_options (HELLOWORLD_CLI PRIVATE
 - Wall-Wextra-pedantic-Werror
    )
    target_compile_options (HelloWorld PRIVATE
 - Wall-Wextra-pedantic-Werror
    )
    target_compile_options (TEST_VERSION PRIVATE
 - Wall-Wextra-pedantic-Werror
    )
endif()



установка (целевые объекты HELLOWORLD_CLI runtime  DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

включить (CPack)

enable_testing()

add_test(test_version test_version)