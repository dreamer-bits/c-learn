orphan: orphan.c
	gcc orphan.c -o orphan

zoom: zoom.c
	gcc zoom.c -o zoom

wait: wait.c
	gcc wait.c -o wait

waitpid: waitpid.c
	gcc waitpid.c -o waitpid

.PHONY: orp
orp: orphan
	./orphan

.PHONY: zo
zo: zoom
	./zoom

.PHONY: wa
wa: wait
	./wait

.PHONY: wp
wp: waitpid
	./waitpid

.PHONY: clean
clean:
	rm -rf orphan
	rm -rf zoom
	rm -rf wait
	rm -rf waitpid
