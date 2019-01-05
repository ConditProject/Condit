cmake_minimum_required(VERSION 3.3)

enable_testing()

# Status Library Test
add_executable(status_test status_test.cc)

target_link_libraries(status_test PUBLIC
        gtest_main
        libstatus
)

add_test(
        NAME status_test
        COMMAND status_test
)

# StatusOr Library Test
add_executable(status_or_test status_or_test.cc)

target_link_libraries(status_or_test PUBLIC
	gtest_main
	libstatus
)

add_test(
	NAME status_or_test
	COMMAND status_or_test
)
