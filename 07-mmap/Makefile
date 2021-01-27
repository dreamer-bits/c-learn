motify: motify.c
	gcc motify.c -o motify
	./motify

share_w: share_w.c
	gcc share_w.c -o share_w

share_r: share_r.c
	gcc share_r.c -o share_r

.PHONY: clean sw

clean:
	rm -rf motify
	rm -rf sharefile
	rm -rf share_w
	rm -rf share_r

sw: share_w
	./share_w

sr: share_r
	./share_r
