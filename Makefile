CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB_LP=libclassloops.o basicClassification.o
OBJECTS_LIB_RC=libclassrec.o basicClassification.o
OBJECTS_LIB_LP_D=dinloops.o dinBasic.o
OBJECTS_LIB_RC_D=dinrec.o dinBasic.o
FLAGS= -Wall -g

all: mains maindloop maindrec libclassloops.a libclassrec.a libclassrec.so libclassloops.so

#runable targets

mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm
	
maindloop: $(OBJECTS_MAIN) libclassloops.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloops.so -lm
	
maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so -lm


# targets for static and dynamic libraries

loops: libclassloops.a						# static
recursives: libclassrec.a					# static
recursived: libclassrec.so					# dynamic
loopd: libclassloops.so						# dynamic


#creating the libraries

libclassloops.a: $(OBJECTS_LIB_LP)
	$(AR) rcs libclassloops.a $(OBJECTS_LIB_LP)
	
libclassrec.a: $(OBJECTS_LIB_RC)
	$(AR) rcs libclassrec.a $(OBJECTS_LIB_RC)
	
libclassrec.so: $(OBJECTS_LIB_RC_D)
	$(CC) -shared -o libclassrec.so $(OBJECTS_LIB_RC_D)
	
libclassloops.so: $(OBJECTS_LIB_LP_D)
	$(CC) -shared -o libclassloops.so $(OBJECTS_LIB_LP_D)
	


#create the regular o files:

libclassloops.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm -o libclassloops.o
	
libclassrec.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -lm -o libclassrec.o

basicClassification.o : basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c -lm



#create the fPIC files - for dynamic libs:

dinrec.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationRecursion.c -lm -o dinrec.o

dinloops.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c advancedClassificationLoop.c -lm -o dinloops.o

dinBasic.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -fPIC -c basicClassification.c -lm -o dinBasic.o
	


#main object

main.o: main.c NumClass.h  
	$(CC) $(FLAGS) -c main.c -lm


#phony declare
.PHONY: clean all loops recursives recursived loopd

clean:
	rm -f *.o *.a *.so mains maindloop maindrec

