CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(main
	main.cpp
)

ADD_EXECUTABLE(test
	unit_test.cpp
)


TARGET_LiNK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
