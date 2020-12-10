obj = src/add.o src/div.o src/mul.o src/sub.o

a.out:lib/libcalc.so
	gcc main.c -I ./include -L ./lib -lcalc

lib/libcalc.so:$(obj)
	gcc --shared $^ -o lib/libcalc.so
	cp lib/libcalc.so /usr/local/lib/libcalc.so
	ldconfig

src/%.o:src/%.c
	gcc $< -c -fpic -o $@

.PHONY: clean

clean:
	rm -rf $(obj)
	rm -rf lib/libcalc.so
	rm -rf a.out
	rm -rf /usr/local/lib/libcalc.so
	ldconfig
