# Bit manipulation
[Stanford CS107](http://cs107.stanford.edu/) notes

```
byte is the smallest addressable unit
char is 1 byte
unsigned char a
x >> 1, divide by 2
x << 1, multiply by 2
1 byte = 8 bits = 2 hex digits, e.g. 0xff = 1111 1111 = 255
char: 1 byte, short: 2 bytes 0 to 65k, int: 4 bytes 0 to 4B, long 8 bytes 0 to big number
ASCII
48    0x30    ‘0’
65    0x41    ‘A'
...
97    0x61    ‘a’

half adder, full adder requires handling of carries
a + b = ((a & b) << 1) | (a ^ b) only when a and b are 1-bit
LSB looks like XOR, next bit looks like AND
overflow 255 + 0 = 0, 0x100 % 256 = 0
-1 is 0xff
2’s complement, works on all int types  -n = 0 - n = 0x100 - n = (0xff + 1) - n = (0xff - n) + 1 = ~n + 1


```

![Number circle](https://ilyasbek.files.wordpress.com/2011/06/num_clk-21.gif?w=438&zoom=2)
