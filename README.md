# librgb 

**C/C++ Library for RGB color manipulation, and a sample project utilizing CMake and gTest.


[![build status](https://travis-ci.org/kigster/librgb.svg?branch=master)](https://travis-ci.org/kigster/librgb)

## Building It

```bash
  git clone git@github.com:kigster/librgb.git
  cd librgb
  git submodule init && git submodule update
  cmake .
  make
```

You, even simpler, after submodule init/update:

```bash
./.travis.sh
```

The build produces three artifacts:

 * `./test/src/runColorFaderTests` (Google Tests which you can run)
 * `./ColorFader_run` (Example using the library)
 * `./librgb/librgb.dylib` (shared library)


## Contributing

Bug reports and pull requests are welcome on GitHub at [https://github.com/kigster/librgb](https://github.com/kigster/librgb).

## License

The gem is available as open source under the terms of the [MIT License](http://opensource.org/licenses/MIT).
