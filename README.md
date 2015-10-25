# os

While reading 
[*the little book about OS development*](https://littleosbook.github.io/), I 
worked through the exercises they posed and put together pieces of an operating 
system as they suggested. This is the result of working through those exercises.

## Purpose

The final product of this repository is intended to be a minimally working toy 
operating system as a simple kernel written in **ANSI C** and **Assembly** with 
absolutely no assumption of a standard library or any other preceding code, 
i.e. an operating system built from scratch. As part of its implementation, a 
subset of the *C standard library* will be rewritten.

There is *no* presumption for any elements of a computer apart from it being an 
x86 architecture, possessing your usual hardware such as a framebuffer to allow 
writing to the screen, and any such other devices. Thus far, this operating 
system has been written for a *32-bit architecture*.

## References

All references read and used while performing these exercises are found in 
[a file in the repository](refs.txt).

## Disclaimer

This is not a truly working or productive operating system for any reasonable 
development environment. This operating system is for educational purposes only.

