obj = src/add.o src/div.o src/mul.o src/sub.o

a.out:libcalc.a
	gcc main.c -I ./include -L ./lib -lcalc

libcalc.a:$(obj)
	ar rcs lib/libcalc.a $^

src/%.o:src/%.c
	gcc $< -c -o $@

.PHONY: clean

clean:
	rm -rf $(obj)
	rm -rf lib/libcalc.a
	rm -rf a.out
