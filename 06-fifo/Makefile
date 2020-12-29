fifo_r: fifo_r.c
	@gcc fifo_r.c -o fifo_r

fifo_w: fifo_w.c
	@gcc fifo_w.c -o fifo_w

.PHONY: w r

w: fifo_w
	@./fifo_w
	@rm -rf fifo_w

r: fifo_r
	@./fifo_r
	@rm -rf fifo_r
	@rm -rf myfifo.sock

clean:
	@rm -rf myfifo.sock
	@rm -rf fifo_w
	@rm -rf fifo_r
