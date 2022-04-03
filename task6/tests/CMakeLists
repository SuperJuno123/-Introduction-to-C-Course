cmake_minimum_required(VERSION 3.0)
project(tests)

add_executable(test_1 "AddByValue.cpp")
target_link_libraries(test_1 LinkedList)
add_test(NAME AddByValueFunc COMMAND test_1)

add_executable(test_2 "DeleteByValue.cpp" )
target_link_libraries(test_2 LinkedList)
add_test(NAME DeleteByValueFunc COMMAND test_2)

add_executable(test_3 "DeleteByName.cpp")
target_link_libraries(test_3 LinkedList)
add_test(NAME DeleteByNameFunc COMMAND test_3)

add_executable(test_4 "Count.cpp")
target_link_libraries(test_4 LinkedList)
add_test(NAME CountFunc COMMAND test_4)

add_executable(test_5 "FindByName.cpp")
target_link_libraries(test_5 LinkedList)
add_test(NAME FindByNameFunc COMMAND test_5)

add_executable(test_6 "FindByValue.cpp")
target_link_libraries(test_6 LinkedList)
add_test(NAME FindByValueFunc COMMAND test_6)
