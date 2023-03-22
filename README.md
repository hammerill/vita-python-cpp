# Vita Python C++
Test project to run Python 2.7 in C++ on PS Vita.
Based on [cpython-vita](https://github.com/SonicMastr/cpython-vita/) but adapted to be compiled in C++ and by newbies.

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
4. VPK file should appear. Copy this file to your hacked PS Vita and install via VitaShell.
5. Launch installed program. It'll create `ux0:data/sample.txt`.

If you experience error related to `undefined "uint"`, run:
```bash
  sed -i 's/uint _x/uint64_t _x/g' $VITASDK/arm-vita-eabi/include/sys/time.h
  make -j4
```
