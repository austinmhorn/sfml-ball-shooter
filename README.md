<h1>
    <p align="center">sfml-ball-shooter</p>
</h1>

Check for <a href="https://brew.sh">Homebrew</a> (a multifarious package manager for macOS or Linux):

    brew --version

If you don't have it, install it:

    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"

You will also need <a href="https://cmake.org">CMake</a> (an open-source, cross-platform, build system generator):

    brew install cmake

Clone this repository

    git clone https://github.com/austinmhorn/sfml-ball-shooter.git

Move into project source directory

    cd sfml-ball-shooter

Compile source files

     cmake -S . -B build

Build objects and link executable
    
     cmake --build build --config Release

Run executable

    ./sfml-ball-shooter

---

If you run into any errors building the SFML library, run this command to install its dependencies:

    sudo apt-get install build-essential libx11-dev libgl1-mesa-dev libxrandr-dev libxcursor-dev libudev-dev libopenal-dev libvorbis-dev libflac-dev libfreetype6-dev
