project(tests LANGUAGES CXX)
enable_testing(true)

find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(car_test car_test_src/main.cpp car_test_src/car_test.h car_test_src/car_test.cpp)
add_test(NAME car_test COMMAND car_test)
target_link_libraries(car_test PRIVATE Qt6::Test car_lib)

add_executable(plane_test plane_test_src/main.cpp plane_test_src/plane_test.h plane_test_src/plane_test.cpp)
add_test(NAME plane_test COMMAND plane_test)
target_link_libraries(plane_test PRIVATE Qt6::Test plane_lib)
