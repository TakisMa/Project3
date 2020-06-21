cmake_minimum_required(VERSION 3.16)
project(Project3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(Server server/server.cpp server/server_utility.cpp common/Functions.cpp server/CircularBuffer.cpp server/CircularBuffer.h server/thread_functions.cpp server/thread_functions.h server/WorkerList.cpp server/WorkerList.h)
add_executable(Client client/client.cpp client/client_utility.cpp common/Functions.cpp client/threads.cpp client/threads.h)


add_executable(Master master/main.cpp master/Functions.cpp master/Record.cpp master/RecordIDManagement.cpp master/Hashtable.cpp master/Bucket.cpp master/BucketList.cpp
        master/ListNode.cpp master/Tree.cpp master/TreeNode.cpp master/Heap.cpp master/HeapNode.cpp master/Commands.cpp master/FileManagement.cpp master/SignalHandling.cpp
        master/SummaryManagement.cpp master/SummaryList.cpp)

add_executable(Worker master/Worker.cpp master/Functions.cpp master/Record.cpp master/RecordIDManagement.cpp master/Hashtable.cpp master/Bucket.cpp master/BucketList.cpp master/ListNode.cpp
        master/Tree.cpp master/TreeNode.cpp master/Heap.cpp master/HeapNode.cpp master/Commands.cpp master/SignalHandling.cpp master/SummaryList.cpp)

