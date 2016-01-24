# librgb – C/C++ Library for RGB color manipulation

## Building It

```bash
  git clone git@github.com:kigster/librgb.git
  cd librgb
  git submodule init && git submodule update
  cmake .
  make
```

This produces three artifacts:

 * ./test/src/runColorFaderTests (Google Tests which you can run)
 * ./ColorFader_run (Example using the library)
 * ./librgb/librgb.dylib (shared library)

