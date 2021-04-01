SWIFFT Performance
==================

To obtain a measurement of the maximum single-threaded SWIFFT performance
achievble using this repository, run the following:

```sh
cmake -Bbuild -H. -DCMAKE_BUILD_TYPE=Release
cd build
make
./tester
```

For performance testing purposes, warnings produced by `make` can be ignored.

This was tested on Linux Ubuntu 20.04 LTS using

- `GCC 9.3.0`: GCC is normally installed using `sudo apt-get install gcc g++`.
- `cmake 3.16.3`: CMake is normally installed using `sudo apt-get install cmake`.

The following results were obtained on an Intel Skylake microarchitecture
(Intel(R) Core(TM) i7-10875H CPU @ 2.30GHz):

```
1000000 SWIFFT16 rounds: cycles/round=737.363098 cycles/byte=5.760649
```

Only the binary SWIFFT 16-bit (not general nor 8-bit) function is tested, which
it is the fastest one provided in this repository.
