CC=g++
CFLAGS=-Wall -std=c++11 -O3 -pg -std=c++0x

all: diseaseAggregator worker

diseaseAggregator: main.o Bucket.o BucketList.o Functions.o Hashtable.o Heap.o HeapNode.o ListNode.o Record.o RecordIDManagement.o Tree.o TreeNode.o Commands.o FileManagement.o SignalHandling.o SummaryList.o SummaryManagement.o
	$(CC) $(CFLAGS) -o diseaseMonitor main.o Bucket.o BucketList.o Functions.o Hashtable.o Heap.o HeapNode.o ListNode.o Record.o RecordIDManagement.o Tree.o TreeNode.o Commands.o FileManagement.o SignalHandling.o SummaryList.o SummaryManagement.o

worker: Worker.o Bucket.o BucketList.o Functions.o Hashtable.o Heap.o HeapNode.o ListNode.o Record.o RecordIDManagement.o Tree.o TreeNode.o Commands.o FileManagement.o SignalHandling.o SummaryList.o SummaryManagement.o
	$(CC) $(CFLAGS) -o worker Worker.o Bucket.o BucketList.o Functions.o Hashtable.o Heap.o HeapNode.o ListNode.o Record.o RecordIDManagement.o Tree.o TreeNode.o Commands.o FileManagement.o SignalHandling.o SummaryList.o SummaryManagement.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp
Bucket.o: Bucket.cpp
	$(CC) $(CFLAGS) -c Bucket.cpp
BucketList.o: BucketList.cpp
	$(CC) $(CFLAGS) -c BucketList.cpp
Functions.o: Functions.cpp
	$(CC) $(CFLAGS) -c Functions.cpp
Hashtable.o: Hashtable.cpp
	$(CC) $(CFLAGS) -c Hashtable.cpp
Heap.o: Heap.cpp
	$(CC) $(CFLAGS) -c Heap.cpp
HeapNode.o: HeapNode.cpp
	$(CC) $(CFLAGS) -c HeapNode.cpp
ListNode.o: ListNode.cpp
	$(CC) $(CFLAGS) -c ListNode.cpp
Record.o: Record.cpp
	$(CC) $(CFLAGS) -c Record.cpp
RecordIDManagement.o: RecordIDManagement.cpp
	$(CC) $(CFLAGS) -c RecordIDManagement.cpp
Tree.o: Tree.cpp
	$(CC) $(CFLAGS) -c Tree.cpp
TreeNode.o: TreeNode.cpp
	$(CC) $(CFLAGS) -c TreeNode.cpp
Commands.o: Commands.cpp
	$(CC) $(CFLAGS) -c Commands.cpp
FileManagement.o: FileManagement.cpp
	$(CC) $(CFLAGS) -c FileManagement.cpp
SignalHandling.o: SignalHandling.cpp
	$(CC) $(CFLAGS) -c SignalHandling.cpp
SummaryList.o: SummaryList.cpp
	$(CC) $(CFLAGS) -c SummaryList.cpp
SummaryManagement.o: SummaryManagement.cpp
	$(CC) $(CFLAGS) -c SummaryManagement.cpp
Worker.o: Worker.cpp
	$(CC) $(CFLAGS) -c Worker.cpp

.PHONY: clean

clean:
	rm -f diseaseAggregator worker *.o
