.PHONY: all

all: lib decode encode

decode:	codec.h decode.c lib
	gcc decode.c -L. -l Codec -o decode

encode:  codec.h encode.c lib
	gcc encode.c -L. -l Codec -o encode

lib:	codec.h codec.c
	gcc -shared codec.c -fPIC -o libCodec.so

.PHONY: clean

clean:
	-rm -f decode encode libCodec.so 2>/dev/null