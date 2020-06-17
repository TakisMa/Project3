cmake_minimum_required(VERSION 3.16)
project(Project3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(Server server/server.cpp server/server_utility.cpp Functions.cpp server/CircularBuffer.cpp server/CircularBuffer.h server/thread_functions.cpp server/thread_functions.h)
add_executable(Client client/client.cpp client/client_utility.cpp Functions.cpp)

add_executable(test_Server server/testServer.cpp)
add_executable(test_Client client/testClient.cpp)
add_executable(mutex_test thread/mutex_test.cpp)
add_executable(sumSquares thread/sumSquares.cpp)