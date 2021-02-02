sigprocmask: sigprocmask.c
	gcc sigprocmask.c util.c util.h -o sigprocmask

.PHONY: sg clean

sg: sigprocmask
	./sigprocmask

clean:
	rm -rf ./sigprocmask
