OBJ = bin/circular_buffer.o
OBJ_UNITY = bin/unity.o bin/test_functions.o
CC = gcc


build_unity_test: test/unity_test.c $(OBJ) $(OBJ_UNITY)
	$(CC) test/unity_test.c -o bin/unity_test.exe -Lbin $(OBJ) $(OBJ_UNITY)

bin/circular_buffer.o: src/circular_buffer.c src/circular_buffer.h
	$(CC) -c src/circular_buffer.c -o bin/circular_buffer.o 

bin/test_functions.o: test/test_functions.c test/test_functions.h
	$(CC) -c test/test_functions.c -o bin/test_functions.o 

bin/unity.o: unity/unity.c unity/unity.h unity/unity_internals.h
	$(CC) -c unity/unity.c -o bin/unity.o 

clean:
	rm -f bin/*
