# Brainfuck Compiler

A simple compiler for Brainfuck, which generates C code and uses GCC to compile this C code.


## Building

Clone the repo to your local machine and then run 

```bash
$ ./scripts/build.sh
```

from within the repo folder.

## Usage

You can compile any brainfuck program using the commandline:

```bash
$ ./bfc <inputFile> <outputFile>
```

**NOTE:** The GCC needs to be installed and available in your `$PATH`.

## Roadmap
    -   Generate optimized C code
    -   Use LLVM as backend