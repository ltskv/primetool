# Prime Tool

A dead simple but surprisingly effective tool for finding prime numbers
and factorizing integers which I coded when I started to learn programming.

This tool is probably full of small bugs and out of memory perils and
whatnot, but I am kinda too lazy to squash them all.

## Installation

```sh
make
PREFIX=/your/prefix/ make install
```

By default it installs into `~/.usr/bin`. This is rather idiosyncratic, but
doesn't require `sudo` and doesn't interfere with `~/.local`, which is managed
by `pip` on my machine(s).

If you don't need it on your `PATH` (why would you), then don't install and
just run `./primetool` from the repository root after `make`ing.

## Usage

`primetool -p NUMBER` will find all prime numbers up to `NUMBER` and
print them to stdout.

`primetool -f NUMBER` will factorize the NUMBER and print the factorization
to stdout.
