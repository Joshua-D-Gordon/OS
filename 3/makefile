# .PHONY: all
	
# all: codec

# debug: codec.c codec.h
# 	gcc -g codec.c -o codec -lm
# codec: codec.c codec.h
# 	gcc codec.c -o codec -lm

# clean:
# 	rm -f codec



all: lib decode encode

codec:  codec.c codec.h
	gcc -o codec.c

decode:	codec.h decode.c lib
	gcc decode.c -L.  -o decode

encode:  codec.h encode.c lib
	gcc encode.c -fPIC -ldl -o encode

lib:	codec.h codec.c
	gcc -shared codec.c -fPIC -o libCodec.so

.PHONY: clean
clean:
	-rm codec decode encode libCodec.so 2>/dev/null
