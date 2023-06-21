# BallShooter SFML Game 

Check for git:

    git --version

If you don't have it, install it:

    sudo apt install git-all

Clone this repository

    git clone https://github.com/austinmhorn/BallShooter.git

Move into project source directory

    cd BallShooter

Compile source files

    cmake -S . -B build

Build objects and link executable
    
    cmake --build build --config Release

Run executable

    ./BallShooter
