sigprocmask: sigprocmask.c
	gcc sigprocmask.c util.c util.h -o sigprocmask

sigaction: sigaction.c
	gcc sigaction.c util.c util.h -o sigaction

.PHONY: sg sa clean

sg: sigprocmask
	./sigprocmask

sa: sigaction
	./sigaction

clean:
	rm -rf ./sigprocmask
	rm -rf ./sigaction
