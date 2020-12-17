orphan: orphan.c
	gcc orphan.c -o orphan

zoom: zoom.c
	gcc zoom.c -o zoom

wait: wait.c
	gcc wait.c -o wait

.PHONY: orp
orp: orphan
	./orphan

.PHONY: zo
zo: zoom
	./zoom

.PHONY: wa
wa: wait
	./wait

.PHONY: clean
clean:
	rm -rf orphan
	rm -rf zoom
	rm -rf wait
