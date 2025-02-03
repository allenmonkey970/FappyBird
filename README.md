# Fappy Bird Game

Welcome to the Fappy Bird game! This project is my own clone of the popular Flappy Bird game, built using C++ and the SFML library. This is my first real project using the SFML library.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [File Structure](#file-structure)
- [Building the Project](#building-the-project)
- [Acknowledgements](#acknowledgements)
- [Future Plans](#future-plans)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Fappy Bird is a simple yet addictive game where you control a bird to navigate through obstacles (pipes) without crashing.

## Features

- Smooth and responsive gameplay
- Randomly generated pipes
- Collision detection with pipes and ground
- Sound effects for jumps, points, and collisions
- Scalable background and bird textures

## Installation

1. Clone the repository:

```bash
git clone https://github.com/yourusername/fappybird.git
cd fappybird
```

2. Ensure you have SFML installed on your system. You can download SFML from [here](https://www.sfml-dev.org/download.php).

3. Build the project using your preferred method. If you're using CMake, follow these steps:

```bash
mkdir build
cd build
cmake ..
make
```

## How to Play

- Press the spacebar or left mouse button to make the bird fly.
- Navigate through the pipes without hitting them or the ground.
- Enjoy the game and try to beat your high score!

## File Structure

```
fappybird/
├── src/
│   ├── assets/
│   │   ├── background-night.png
│   │   ├── FappyBirdUp.png
│   │   ├── FappyBirdDown.png
│   │   ├── pipe-green.png
│   │   ├── jump.wav
│   │   ├── point.wav
│   │   ├── hit.wav
│   │   └── icon.png
│   ├── FappyBirdGame.h
│   ├── FappyBird.h
│   ├── Icon.h
│   ├── Pipe.h
│   ├── SoundEffects.h
│   ├── Background.h
│   └── main.cpp
├── CMakeLists.txt
├── LICENSE
└── README.md
```
## Building the Project

The project uses CMake to manage the build process. Below is the provided `CMakeLists.txt` file:

```cmake
cmake_minimum_required(VERSION 3.28)
project(FappyBird LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(main
        src/main.cpp
        src/icon.h
        src/background.h
        src/FappyBird.h
        src/Pipe.h
        src/soundEffects.h
        src/fappyBirdGame.h
)

target_compile_features(main PRIVATE cxx_std_17)
target_link_libraries(main PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)
```

### Explanation

- **Project Setup:** The `CMakeLists.txt` file sets the minimum required version of CMake to 3.28 and defines the project name as "FappyBird" using C++.
- **Output Directory:** The `CMAKE_RUNTIME_OUTPUT_DIRECTORY` is set to output all binaries to the `bin` directory within the build directory.
- **Fetching SFML:** The `FetchContent` module is used to fetch and configure the SFML library from its GitHub repository. The specific version fetched is 3.0.0.
- **Executable and Source Files:** The `add_executable` command creates an executable named `main` and includes all necessary source and header files for the project.
- **Compiler Features:** The project is set to use the C++17 standard.
- **Linking Libraries:** The `target_link_libraries` command links the executable with the SFML libraries for graphics, window management, system functionality, and audio.

### Building Instructions

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/yourusername/fappybird.git
   cd fappybird
   ```

2. **Create a Build Directory:**
   ```bash
   mkdir build
   cd build
   ```

3. **Configure the Project:**
   ```bash
   cmake ..
   ```

4. **Build the Project:**
   ```bash
   make
   ```

This will compile the game and place the executable in the `bin` directory.

## Acknowledgements

- This project is inspired by the original Flappy Bird game.
- Special thanks to Samuelcust for his [Flappy Bird Assets](https://github.com/samuelcust/flappy-bird-assets)

## Future Plans

- **End Screen:** Implement an end screen to display the final score and offer a restart option.
- **Start Screen:** Add a start screen with options to start the game, view instructions, and access settings.
- **Additional Features:** Consider finishing the sound effects, animations, and difficulty levels.

## Contributing

Contributions are welcome! If you have any ideas or improvements, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
