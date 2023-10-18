# OpenGL-CrossOnPentagon
Use OpenGL to draw a pentagon with a center cross effortlessly. Simple graphics programming for visually engaging results.

# Setting Up OpenGL

## Overview

This guide will help you set up OpenGL on your system for graphics programming.

## Prerequisites

- **Operating System:**
  - Ensure compatibility with your OS (Windows, Linux, macOS).

- **OpenGL Drivers:**
  - Install the latest OpenGL drivers for your graphics card.

## Setup Steps

1. **Windows:**

   - **MinGW Compiler:**
     - Install the MinGW compiler suite.

   - **GLEW and GLFW:**
     - Download GLEW and GLFW libraries.
     - Link them to your project.

   - **Setting Up Environment:**
     - Add MinGW and library paths to your system's PATH variable.

2. **Linux:**

   - **Update Repositories:**
     - Run `sudo apt update` or equivalent for your package manager.

   - **Install Libraries:**
     - Install essential libraries:
       ```bash
       sudo apt-get install build-essential libgl1-mesa-dev libglfw3-dev libglew-dev
       ```

3. **macOS:**

   - **Xcode Command Line Tools:**
     - Install Xcode from the App Store.
     - Install command line tools: `xcode-select --install`.

   - **Homebrew (Optional):**
     - Install Homebrew: `/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"`.

   - **Install Libraries:**
     - Install necessary libraries:
       ```bash
       brew install glfw glew
       ```

## Verification

1. **Compile and Run Test:**

   - Create a simple OpenGL program, compile, and run to verify the setup.

   - For example, using the following C code:

     ```c
     #include <GL/glut.h>
     int main(int argc, char** argv) {
         glutInit(&argc, argv);
         glutCreateWindow("OpenGL Test");
         glutMainLoop();
         return 0;
     }
     ```

   - Compile: `gcc test.c -o test -lGL -lGLU -lglut`.

   - Run: `./test`.

# Running an OpenGL Program from File

## Prerequisites

- **OpenGL Setup:**
  - Ensure you have successfully set up OpenGL on your system using the provided guide ([Setting Up OpenGL](SETTING_UP_OPENGL.md)).

## Running the OpenGL Program

1. **Open the OpenGL Program File:**

   - Open your preferred code editor and load the OpenGL program file you want to run.

2. **Compile the Program:**

   - Compile the program using an appropriate compiler.

     - **Linux or macOS:**
       ```bash
       gcc -o your_program_name your_program_file.c -lGL -lGLU -lglut
       ```

     - **Windows (MinGW):**
       ```bash
       gcc -o your_program_name.exe your_program_file.c -lGL -lGLU -lglut
       ```

3. **Run the Executable:**

   - Execute the compiled program.

     - **Linux or macOS:**
       ```bash
       ./your_program_name
       ```

     - **Windows:**
       ```bash
       your_program_name.exe
       ```

4. **Explore the Visual Output:**

   - The program will display the visual output according to the OpenGL code in the file.

## Troubleshooting

- If you encounter issues, double-check your OpenGL setup and ensure the necessary libraries are linked.


Congratulations! You've successfully set up OpenGL for graphics programming on your system!
