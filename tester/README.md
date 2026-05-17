# Tester

This tester requires [LIBFT](https://github.com/ZaaiiZ/LIBFT) to compile.

## Setup

Clone LIBFT into this directory:

```bash
cd tester
git clone https://github.com/ZaaiiZ/LIBFT.git LIBFT
cd LIBFT && make && cd ..
```

## Compile and Run

```bash
cd ..
make
gcc tester/*.c -L. -lftprintf -Ltester/LIBFT -lft -o test_runner
./test_runner
```
