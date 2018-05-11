# Systems
[Stanford CS107](http://cs107.stanford.edu/) cheat sheet

### Questions
- [ ] signed vs unsigned differences in comparison, right shift, assignment, ...
- [ ] "signed/unsigned char important when promoting to larger type???"
- [ ] `int my_isxdigit(int ch) return my_isdigit(ch) || ((unsigned)ch | 32) - ‘a’ < 6`
- [ ] example of subverting CT check

### Bit manipulation
- byte is the smallest addressable unit
- `char` is 1 byte
- `unsigned char a`
- `x >> 1` divide by 2
- `x << 1` multiply by 2
- 1 byte = 8 bits = 2 hex digits, e.g. 0xff = 1111 1111 = 255
- char: 1 byte, short: 2 bytes 0 to 65k, int: 4 bytes 0 to 4B, long 8 bytes 0 to big number
-
	```
	ASCII
	48    0x30    ‘0’
	...
	65    0x41    ‘A'
	...
	97    0x61    ‘a’
	```
- half adder, full adder requires handling of carries
- `a + b = ((a & b) << 1) | (a ^ b)` only when a and b are 1-bit
- LSB looks like XOR, next bit looks like AND
- overflow `255 + 0 = 0`, `0x100 % 256 = 0`
- -1 is 0xff
- 2’s complement, works on all int types  `-n = 0 - n = 0x100 - n = (0xff + 1) - n = (0xff - n) + 1 = ~n + 1`

![Number circle](https://ilyasbek.files.wordpress.com/2011/06/num_clk-21.gif?w=438&zoom=2)

### C-Strings
- C-strings are arrays of char
- segmentation fault is access to INVALID memory location
- address is a memory location, represented as `unsigned long`
- pointer is a variable that holds an address
- `&` is the address of, `&var` is the location in memory where `var` is being stored
- addresses can be compared and added/subtracted
- pointer arithmetic on `int *` scales by `sizeof(int)` and `char *` scales by `sizeof(char)` == 1
- types are compile-time (no runtime checking), if CT is subverted no RT errors are raised
- `int arr[2]` and then `arr[10]` has no array out of bounds or other safety, just grabs the memory
- `int *ptr = arr`; "decays" to address of first element (same as `&arr[0]`)
- ...

```
![Memory address space](https://i.stack.imgur.com/CvITh.png)

### void*
...
