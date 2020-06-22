CC=g++
CFLAGS=-Wall -std=c++11 -O3 -pg -std=c++0x 
TFLAGS=-lpthread

all: Server Client Master Worker

Server: server/server.o server/server_utility.o common/Functions.o server/CircularBuffer.o server/thread_functions.o server/WorkerList.cpp
	$(CC) -o Server server/server.o server/server_utility.o common/Functions.o server/CircularBuffer.o server/thread_functions.o server/WorkerList.o $(CFLAGS) $(TFLAGS)

Client: client/client.o client/client_utility.o common/Functions.o client/threads.o
	$(CC) -o Client client/client.o client/client_utility.o common/Functions.o client/threads.o $(CFLAGS) $(TFLAGS)

server.o: server/server.cpp
	$(CC) $(CFLAGS) -c server/server.cpp
server_utility.o: server/server_utility.cpp
	$(CC) $(CFLAGS) -c server/server_utility.cpp
CircularBuffer.o: server/CircularBuffer.cpp
	$(CC) $(CFLAGS) -c server/CircularBuffer.cpp
Functions.o: common/Functions.cpp
	$(CC) $(CFLAGS) -c Functions.cpp
thread_functions.o: server/thread_functions.cpp
	$(CC) $(CFLAGS) -c server/thread_functions.cpp
WorkerList.o: server/WorkerList.cpp
	$(CC) $(CFLAGS) -c server/WorkerList.cpp




client.o: client/client.cpp
	$(CC) $(CFLAGS) -c client/client.cpp
client_utility.o: client/client_utility.cpp
	$(CC) $(CFLAGS) -c client/client_utility.cpp
threads.o: client/threads.cpp
	$(CC) $(CFLAGS) -c client/threads.cpp



Master: master/main.o master/Bucket.o master/BucketList.o master/functions.o master/Hashtable.o master/Heap.o master/HeapNode.o master/ListNode.o master/Record.o master/RecordIDManagement.o master/Tree.o master/TreeNode.o master/Commands.o master/FileManagement.o master/SignalHandling.o master/SummaryList.o master/SummaryManagement.o
	$(CC) $(CFLAGS) -o master/Master master/main.o master/Bucket.o master/BucketList.o master/functions.o master/Hashtable.o master/Heap.o master/HeapNode.o master/ListNode.o master/Record.o master/RecordIDManagement.o master/Tree.o master/TreeNode.o master/Commands.o master/FileManagement.o master/SignalHandling.o master/SummaryList.o master/SummaryManagement.o

Worker: master/worker.o master/Bucket.o master/BucketList.o master/functions.o master/Hashtable.o master/Heap.o master/HeapNode.o master/ListNode.o master/Record.o master/RecordIDManagement.o master/Tree.o master/TreeNode.o master/Commands.o master/FileManagement.o master/SignalHandling.o master/SummaryList.o master/SummaryManagement.o
	$(CC) $(CFLAGS) -o master/Worker master/worker.o master/Bucket.o master/BucketList.o master/functions.o master/Hashtable.o master/Heap.o master/HeapNode.o master/ListNode.o master/Record.o master/RecordIDManagement.o master/Tree.o master/TreeNode.o master/Commands.o master/FileManagement.o master/SignalHandling.o master/SummaryList.o master/SummaryManagement.o

main.o: master/main.cpp
	$(CC) $(CFLAGS) -c master/main.cpp
Bucket.o: master/Bucket.cpp
	$(CC) $(CFLAGS) -c master/Bucket.cpp
BucketList.o: master/BucketList.cpp
	$(CC) $(CFLAGS) -c master/BucketList.cpp
functions.o: master/functions.cpp
	$(CC) $(CFLAGS) -c master/functions.cpp
Hashtable.o: master/Hashtable.cpp
	$(CC) $(CFLAGS) -c master/Hashtable.cpp
Heap.o: master/Heap.cpp
	$(CC) $(CFLAGS) -c master/Heap.cpp
HeapNode.o: master/HeapNode.cpp
	$(CC) $(CFLAGS) -c master/HeapNode.cpp
ListNode.o: master/ListNode.cpp
	$(CC) $(CFLAGS) -c master/ListNode.cpp
Record.o: master/Record.cpp
	$(CC) $(CFLAGS) -c master/Record.cpp
RecordIDManagement.o: master/RecordIDManagement.cpp
	$(CC) $(CFLAGS) -c master/RecordIDManagement.cpp
Tree.o: master/Tree.cpp
	$(CC) $(CFLAGS) -c master/Tree.cpp
TreeNode.o: master/TreeNode.cpp
	$(CC) $(CFLAGS) -c master/TreeNode.cpp
Commands.o: master/Commands.cpp
	$(CC) $(CFLAGS) -c master/Commands.cpp
FileManagement.o: master/FileManagement.cpp
	$(CC) $(CFLAGS) -c master/FileManagement.cpp
SignalHandling.o: master/SignalHandling.cpp
	$(CC) $(CFLAGS) -c master/SignalHandling.cpp
SummaryList.o: master/SummaryList.cpp
	$(CC) $(CFLAGS) -c master/SummaryList.cpp
SummaryManagement.o: master/SummaryManagement.cpp
	$(CC) $(CFLAGS) -c master/SummaryManagement.cpp
Worker.o: master/Worker.cpp
	$(CC) $(CFLAGS) -c master/Worker.cpp



.PHONY: clean

clean:
	rm -f Server Client Worker Master *.o server/*.o client/*.o common/*.o master/*.o
