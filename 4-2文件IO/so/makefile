libfun.a: fun.o
	gcc -c fun.c -I .
	gcc -shared -fPIC -o libfun.so fun.o
	#cp libfun.so /usr/lib/

ex:
	gcc libuse_example.c -L. -lfun