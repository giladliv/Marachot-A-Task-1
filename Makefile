CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB_LP=libclassloops.o basicClassification.o
OBJECTS_LIB_RC=libclassrec.o basicClassification.o
FLAGS= -Wall -g

all: mains maindloop maindrec libclassloops.a libclassrec.a libclassrec.so libclassloops.so

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm
	
maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so -lm
	
maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so -lm
	
loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so


libclassloops.a: $(OBJECTS_LIB_LP)
	$(AR) -rcs libclassloops.a $(OBJECTS_LIB_LP)
	
libclassrec.a: $(OBJECTS_LIB_RC)
	$(AR) -rcs libclassrec.a $(OBJECTS_LIB_RC)
	
libclassrec.so: $(OBJECTS_LIB_RC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_LIB_RC)
	
libclassloops.so: $(OBJECTS_LIB_LP)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LIB_LP)
	


	
libclassloops.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm -o libclassloops.o
	
libclassrec.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -lm -o libclassrec.o

basicClassification.o : basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c -lm

main.o: main.c NumClass.h  
	$(CC) $(FLAGS) -c main.c -lm

.PHONY: clean all loops recursives recursived loopd

clean:
	rm -f *.o *.a *.so mains maindloop maindrec

