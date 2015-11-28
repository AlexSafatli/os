# os

While reading 
[*the little book about OS development*](https://littleosbook.github.io/), I 
worked through some of the exercises they presented and put together pieces 
of my own operating system. This repository contains the code that has come 
from working through those exercises and subsequently building upon them 
with the use of other resources (see below).

## Environment

This has only been performed on a Debian-based system. Similar packages could be 
downloaded on other platforms but that has not been tested. Development has been 
performed on both **Ubuntu 15.10** and **elementary OS Freya**.

    sudo apt-get install build-essential nasm genisoimage bochs bochs-sdl

For those systems that have not been tested or are more difficult to setup, a 
`Vagrantfile` is included for creating a vagrant box to perform testing of the 
system. Simply run

    vagrant up

Followed by

    vagrant ssh
    cd /vagrant/

To get a shell into the folder.

## Languages Used

Loading of the operating system and incredibly low-level tasks are 
delegated to **Assembly** code. Otherwise, the rest of the kernel and other 
pieces of this operating system are written in Standard **C**.

Plans are to eventually use **Go** to construct the *user space* modules.

## Purpose

When completed, I hope to have a working toy operating system with a 
minimal implementation, i.e. an operating system built from scratch. As part 
of its implementation, a subset of the *C standard library* will be rewritten.

This operating system is intended for use on 32-bit x86 architecture.

## References

All references read and used while performing these exercises are found in 
[a file in the repository](refs.txt).

## Disclaimer

This is not a truly working or productive operating system for any reasonable 
development environment. This operating system is for educational purposes only.
