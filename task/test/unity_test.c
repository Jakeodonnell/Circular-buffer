#include<setjmp.h>
#include "../unity/unity.h"
#include "../test/test_functions.h"	
#include "../src/circular_buffer.h"

/* BUFFER_SIZE is defined in test_functions.h */


/* Create a data structure holding your circular buffer */
struct circularBuffer buffer;


void setUp(void);
void tearDown(void);
void resetTest(void);

/* Statically create data field holding your buffer */
int bufferData[BUFFER_SIZE];

int main(void) {
    
  UnityBegin("TEST");
  RUN_TEST(testAddElement);
  RUN_TEST(testRemoveHead);
  RUN_TEST(testContain);
  RUN_TEST(testRemoveValue);
  RUN_TEST(testBlackBox1);
  RUN_TEST(testBlackBox2);
  RUN_TEST(testBlackBox3);
  RUN_TEST(testBlackBox4);
  RUN_TEST(testBlackBox5);
  RUN_TEST(testBlackBox6);
  RUN_TEST(testBlackBox7);
  RUN_TEST(testBlackBox8);
  RUN_TEST(testBlackBox9);
  UnityEnd();

  
  return 0;
}
/*
 * This function will be run automatically when you call RUN_TEST
 */
void setUp(void) {
  /* 
   * Initialize your buffer data structure with the created data field
   * and max length (which might not exceed the size of the data field
   */
  initCircularBuffer(&buffer, bufferData, BUFFER_SIZE, 0);
}

void tearDown(void) {
}

void resetTest(void) {
  tearDown();
  setUp();
}

