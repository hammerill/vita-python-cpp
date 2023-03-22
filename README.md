# Vita Python C++
Test project to run Python 2.7 in C++ on PS Vita.

## Build
Build for PS Vita should be performed in Linux environment (or in MSYS2 in Windows, see step 1).
1. Install [VITASDK](https://vitasdk.org/).
2. Clone repo:
  ```bash
  git clone https://github.com/Hammerill/vita-python-cpp && cd vita-python-cpp
  ```
3. Build:
  ```bash
  mkdir build
  cd build
  cmake ..
  make -j4
  ```
4. VPK file should appear. It does nothing. You just should be happy it compiled.

If you experience error related to `undefined "uint"`, run:
```bash
  sed -i 's/uint _x/uint64_t _x/g' /usr/local/vitasdk/arm-vita-eabi/include/sys/time.h
  make -j4
```
I hope your headers at `/usr/local/vitasdk/arm-vita-eabi/include/` so you won't have to edit the command.
