#include <stdio.h>
#include <limits.h>
#include "circular_buffer.h"


void initCircularBuffer(struct circularBuffer* bufferPtr, int* data, int maxLength, int size) {
  bufferPtr->data = data;
  bufferPtr->head = 0;
  bufferPtr->tail = 0;
  bufferPtr->maxLength = maxLength;
  bufferPtr->size = 0;
}

int contains(struct circularBuffer* bufferPtr, int value) {
	for(int i = 0; i<= bufferPtr->size; i++){
		if(bufferPtr->data[i] == value){
			return value;
		}
	}
		return INT_MIN;
}
	
int addElement(struct circularBuffer* bufferPtr, int value){
	int next = ((bufferPtr->tail + 1) % bufferPtr->maxLength);
	if(bufferPtr->size < bufferPtr->maxLength){
		bufferPtr->data[bufferPtr->tail] = value;
		bufferPtr->tail = next;
		bufferPtr->size++;
		return value;
	}
	return INT_MIN;
}

int removeValue(struct circularBuffer* bufferPtr, int value){
	int next = ((bufferPtr->tail - 1) % bufferPtr->maxLength);
	while(contains(bufferPtr, value) == value){
		for(int i = 0; i <= bufferPtr->maxLength; i++){
			if(bufferPtr->data[i] == value){
				bufferPtr->data[i] = INT_MIN;
				bufferPtr->size--;
				if(next == -1){
					next = 3;
					bufferPtr->tail = next;
				} else {
					bufferPtr->tail = next;
				}
			}
		}
		for(int o=0; o <= bufferPtr->size; o++){
			if(bufferPtr->data[o] == INT_MIN){
				while(o <= bufferPtr->size){
					bufferPtr->data[o] = bufferPtr->data[o + 1];
					o++;
				}
			}
		}
		return value; 
	}
	return INT_MIN;
}

int removeHead(struct circularBuffer* bufferPtr) {
	int value = bufferPtr->data[bufferPtr->head];
	int next = ((bufferPtr->head + 1) % bufferPtr->maxLength);
	bufferPtr->data[bufferPtr->head] = 0;
	bufferPtr->head = next;
	bufferPtr->size --;
	return value;
}

int print(struct circularBuffer* bufferPtr){
	printf("\nHead %i \n", bufferPtr->head);
	printf("Tail %i \n", bufferPtr->tail);
	printf("Maxlength %i \n", bufferPtr->maxLength);
	printf("Data ");
	for (int i = 0; i < bufferPtr->maxLength; ++i)
	{
		printf(" - %i", bufferPtr->data[i]);
	}
	printf("\nSize %i \n\n", bufferPtr->size);
}
	