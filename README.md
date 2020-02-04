# Prime Tool

A rather dumb but fairly convenient tool for prime number related tasks (two of
them), which I coded when I started to learn programming.

## Installation

```sh
make
PREFIX=/your/prefix/ make install
```

By default it installs into `~/.usr/bin`. This is rather idiosyncratic, but
doesn't require `sudo` and doesn't interfere with `~/.local`.

If you don't need it on your `PATH` (why would you), then don't install and
just run `./primetool` from the repository root after running `make`.

## Usage

`primetool -p NUMBER` will find all prime numbers up to `NUMBER` and
print them to stdout (5 numbers on a line, duh).

`primetool -f NUMBER` will factorize the NUMBER and print the factorization
to stdout.
