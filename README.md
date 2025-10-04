# TorchCS RakNet

TorchCS RakNet is a fork of [facebookarchive/RakNet](https://github.com/facebookarchive/RakNet), modernized for C++20 and optimized for cross-platform builds (Windows and Linux).  
It is part of the TorchCS project but can also be used as a standalone library.

## Integration with CMake (FetchContent)

```cmake
include(FetchContent)

FetchContent_Declare(
  torchcs_raknet
  GIT_REPOSITORY https://github.com/TorchCS-MC/RakNet.git
  GIT_TAG X.X.X
)

FetchContent_MakeAvailable(torchcs_raknet)

target_link_libraries(${PROJECT_NAME} PRIVATE torchcs::RakNet)
```

## Features

- Modern C++20 compatible codebase  
- Cross-platform support (Windows, Linux)  
- Modern CMake build system  
- Optional static or shared library build  

## License
[LICENSE](LICENSE)
