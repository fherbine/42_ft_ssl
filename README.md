ft_ssl \[md5\] \[sha256\]
===========

In this project, I have to code a program able to hash files and streams from
STDIN.

## How to build

```sh
$ make
```

## How to run

```sh
./ft_ssl <hash_algorithm> [options] [file]
./ft_ssl md5 [-p -q -r -s <string>] [file]
./ft_ssl sha256 [-p -q -r -s <string>] [file]
```

### Options:

- `-p`, echo `STDIN` to `STDOUT`, then append the checksum to `STDOUT`.
- `-q`, quiet mode.
- `-r`, reverse the output format.
- `-s`, print the sum of the given string.

### Usage with piped `STDIN`:

```sh
$ echo "Hello world" | ./ft_ssl [options]
```

## Bonuses

- [ ] Other algorithms than md5 or sha256.
- [ ] parse commands from `STDIN`.

## TODO:

**REQUIRED:**
- [x] Command parsing.
- [ ] Files reading.
- [ ] `STDIN` reading (piped).
- [x] md5 hash algorithm.
- [ ] sha256 algorithm.

**BONUSES:**
- [ ] Read from `STDIN`.
- [ ] sha512
- [ ] whirlpool
- [ ] other ?