# SFML-Template

This template provides a quick and easy way to start a new project with SFML. It is designed to help you set up a basic SFML project structure so you can jump straight into development.

## Usage

To use this template effectively, you'll need to make a few quick adjustments to tailor it to your project:

### Configure Project Settings

1. **Edit Project Configuration**
   - Open `premake5.lua` with a text editor.
   - Update the `solutionName` variable to your desired solution name.
   - Modify the `projectName` variable to reflect your project's name.
   - Adjust the `libraries` variable to point to the folder containing your SFML library files.

2. **Set Up Project Generation Script**
   - Open `GenerateProjects.bat` in a text editor.
   - Change the script to point to the location of your `premake5.exe` file. This is necessary for the script to generate project files correctly.

### Prepare Project Directory

After configuring the project settings, follow these steps to prepare your project directory:

1. **Create Project Folder**
   - Create a new folder with the same name as your `projectName`.
   
2. **Add Source Code Folder**
   - Inside your project folder, create another folder named `src`.
   - Use this `src` folder to store all your `.cpp` (C++ source) and `.hpp`/`.h` (C++ header) files.

This directory structure will help organize your project's source code and make it easier to manage as your project grows.

By following these setup instructions, you'll have a basic SFML project structure ready, allowing you to focus on developing your game or application.

Happy coding!

## Dependencies

Before starting your SFML project, ensure you have the following dependencies installed:

- **Premake**: Premake is a command-line utility that reads a scripted definition of a software project and generates project files for Visual Studio, GNU Make, Xcode, and more. Download and install Premake from [https://premake.github.io/](https://premake.github.io/).

- **SFML (Simple and Fast Multimedia Library)**: SFML provides a simple interface to the various components of your PC, to ease the development of games and multimedia applications. It is composed of five modules: system, window, graphics, audio, and network. Download SFML from [https://www.sfml-dev.org/](https://www.sfml-dev.org/).

Make sure these dependencies are correctly installed and configured on your system before proceeding with the project setup as described in the Usage section.
