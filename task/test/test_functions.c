#include "../unity/unity.h"
#include "test_functions.h"
#include "../src/circular_buffer.h"

extern struct circularBuffer buffer;

void testInitCircularBuffer(void) {
  TEST_ASSERT_EQUAL_INT(BUFFER_SIZE, buffer.maxLength);
  TEST_ASSERT_EQUAL_INT(0, buffer.head);
  TEST_ASSERT_EQUAL_INT(0, buffer.tail);
  TEST_ASSERT_EQUAL_INT(0, buffer.size);
}
  
void testAddElement(void){
	TEST_ASSERT_EQUAL_INT(1, addElement(&buffer,1));
}

void testRemoveHead(void){
	addElement(&buffer,1);
	TEST_ASSERT_EQUAL_INT(1,removeHead(&buffer));
}

void testContain(void) {
	addElement(&buffer,1);
	TEST_ASSERT_EQUAL_INT(1,contains(&buffer,1));
}

void testRemoveValue(void) {
	addElement(&buffer, 1);
	TEST_ASSERT_EQUAL_INT(1, removeValue(&buffer, 1));
}

void testBlackBox1(void) {
	int value = addElement(&buffer,1);
	int remove = removeHead(&buffer);
	TEST_ASSERT_EQUAL_INT(value, remove);
}

void testBlackBox2(void) {
	int value1 = addElement(&buffer,1);
	int value2 = addElement(&buffer,2);
	int remove1 = removeHead(&buffer);
	int remove2 = removeHead(&buffer);
	TEST_ASSERT_EQUAL_INT(value1, remove1);
	TEST_ASSERT_EQUAL_INT(value2, remove2);
}

void testBlackBox3(void) {
	for(int i = 0; i < BUFFER_SIZE; i++){
		addElement(&buffer,i);
	}
	for(int i = 0; i < BUFFER_SIZE; i++){
		TEST_ASSERT_EQUAL_INT(i,removeHead(&buffer));
	}
}

void testBlackBox4(void) {
	for(int i = 0; i < BUFFER_SIZE + 1; i++){
		addElement(&buffer,i);
		if(i == BUFFER_SIZE + 1){
			TEST_ASSERT_EQUAL_INT(INT_MIN, addElement(&buffer,i));
		}
	}
}

void testBlackBox5(void){
	for(int i = 0; i < BUFFER_SIZE + 1; i++){
		addElement(&buffer,i);
		TEST_ASSERT_EQUAL_INT(i,removeHead(&buffer));
	}
}

void testBlackBox6(void){
	TEST_ASSERT_EQUAL_INT(INT_MIN, (contains(&buffer, 1)));
}

void testBlackBox7(void){
	addElement(&buffer, 1);
	TEST_ASSERT_EQUAL_INT(1, contains(&buffer,1));
}

void testBlackBox8(void){
	addElement(&buffer, 1);
	addElement(&buffer, 2);
	TEST_ASSERT_EQUAL_INT(2, contains(&buffer,2));
}

void testBlackBox9(void){
	for(int i = 0; i < BUFFER_SIZE; i++){
		addElement(&buffer,i);
	}
	int last = BUFFER_SIZE - 1;
	TEST_ASSERT_EQUAL_INT(buffer.data[last], contains(&buffer,buffer.data[last]));
}
	


	
