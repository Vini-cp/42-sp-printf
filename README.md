# Printf

This project is a recode of printf.

&nbsp;

The prototype of **ft_printf** is: 

```C
ft_printf(const char *, ...);
```

Considerations:

- It has not the buffer management like the real printf.
- It manage the following conversions: **cspdiuxX%**
- It manage any combination of the following flags: **-0.*** and minimum field width with all conversions

&nbsp;

## How to use it

1. You must compile all files with Makefile command:

```Bash
make
```

2. Create a main file at the root of the repo and compile it with:

```Bash
TEST=./main.c make test
````

