# oneAPI Level Zero

This repository contains the following components of oneAPI:

- Copies of the Level Zero Specification API C/C++ header files
- Level Zero Loader
- Level Zero Validation Layer

This project is part of the larger [oneAPI](https://www.oneapi.com/) project.

See the [oneAPI specification](https://spec.oneapi.com/versions/latest/introduction.html) for more information about the oneAPI project.

See the [Level Zero specification](https://spec.oneapi.com/level-zero/latest/index.html) for more information about Level Zero.

Level Zero API versions are listed in the `ze_api_version_t` enumeration, located in the
[ze_api.h](./include/ze_api.h) file.

# Building and Installing

Project is defined using [CMake](https://cmake.org/).

## Linux

### General

```
mkdir build
cd build
cmake ..
cmake --build . --config Release
cmake --build . --config Release --target package
cmake --build . --config Release --target install
```

### Ubuntu with Docker

```bash
mkdir build
mkdir -p .ccache

docker run \
  --rm \
  -v $PWD:$PWD \
  -w $PWD/build \
  -e CCACHE_DIR=$PWD/.ccache \
  -e CCACHE_BASEDIR=$PWD \
  $(docker build -q \
      --build-arg UID=$(id -u) \
      --build-arg GID=$(id -g) \
      --build-arg IMAGE_VERSION=eoan \
      - < docker/build-ubuntu.Dockerfile) \
  cmake \
    -G Ninja \
    -D CMAKE_C_COMPILER_LAUNCHER=ccache \
    -D CMAKE_CXX_COMPILER_LAUNCHER=ccache \
    -D CMAKE_BUILD_TYPE=Release \
    ..

docker run \
  --rm \
  -v $PWD:$PWD \
  -w $PWD/build \
  -e CCACHE_DIR=$PWD/.ccache \
  -e CCACHE_BASEDIR=$PWD \
  $(docker build -q \
      --build-arg UID=$(id -u) \
      --build-arg GID=$(id -g) \
      --build-arg IMAGE_VERSION=eoan \
      - < docker/build-ubuntu.Dockerfile) \
  cmake --build . --config Release
```

## Windows
Use Microsoft* Visual Studio x64 command prompt to run the following commands and build the project:
```sh
mkdir build
cd build
cmake -G "NMake Makefiles" CMAKE_CXX_FLAGS="/EHsc" ..
nmake
```


# Contributing

See [CONTRIBUTING](CONTRIBUTING.md) for more information.

# License

Distributed under the MIT license. See [LICENSE](LICENSE) for more information.

# Security

See Intel's [Security Center](https://www.intel.com/content/www/us/en/security-center/default.html) for information on how to report a potential security issue or vulnerability.

See also [SECURITY](SECURITY.md).
