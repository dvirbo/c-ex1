CC=gcc
AR=ar -rcs
FLAGS=-Wall -g
OBJECTS_MAIN=main.o

all: loops loopd recurcives recursived maindloop maindrec mains

loops: libclassloop.a
recurcives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so

libclassloop.a: basicClassification.o advancedClassificationLoop.o NumClass.h
	$(AR) libclassloop.a basicClassification.o advancedClassificationLoop.o

libclassrec.a: basicClassification.o advancedClassificationRecursion.o NumClass.h
	$(AR) libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassrec.so: basicClassification.o advancedClassificationRecursion.o NumClass.h
	$(CC) -shared -o libclassrec.so basicClassification.o advancedClassificationLoop.o -lm

libclassloops.so: basicClassification.o advancedClassificationLoop.o NumClass.h
	$(CC) -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o -lm

mainsloop: main.o libclassloop.a
	$(CC) $(FLAGS) -o mainsloop $(OBJECTS_MAIN) libclassloop.a -lm

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so -lm

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c -lm

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c -lm

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -lm
	
.PHONY: clean all	

clean:
	rm -f *.a *.o *.so mains maindrec maindloop