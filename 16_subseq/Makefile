CFLAGS = -ggdb3 -Wall -Werror -pedantic -std=gnu99

test_maxSeq: test-subseq.o maxSeq.o
	gcc -o test_maxSeq test-subseq.o maxSeq.o

maxSeq.o: maxSeq.c
	gcc ${CFLAGS} -c maxSeq.c

test-subseq.o: test-subseq.c
	gcc ${CFLAGS} -c test-subseq.c
