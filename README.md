[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/ypSuXy9I)
# Laboratory 1

## Laboratory Objectives
1. Reserve a Tuffix instance through Titanium's "Virtual Computing Lab" App OR install Tuffix on your own machine.
1. Navigate and explore Tuffix and the Linux environment using a command line interface (CLI).
1. Clone the assignment from GitHub to your Tuffix instance.
1. Write Python code using the Atom editor.
1. Execute the program from the command line.
1. Unit test the program.
1. Push your Tuffix local code repository back to GitHub.

## Start a Tuffix Instance
Cal State Fullerton Computer Science Department recommends the use of the Titanium's "Virtual Computing Lab" App as the primary source of a Tuffix instance.  The downside is that the code you develop during a reservation will be lost after that reservation, so you must ensure the code is copied off of the reservation instance.  An alternative is to install Tuffix on your own machine.  I strongly suggest you are very familiar and use both methods extensively throughout the course, to help in situations where one method may not be accessible when you need it.
1. To reserve a Tuffix instance on Titanium's "Virtual Computing Lab" App, view the following video: https://youtu.be/1EuNyBvmfXY
1. To install Tuffix on your own machine, follow the below instructions:
     1. Download VirtualBox 6.1.16 from https://www.virtualbox.org/wiki/Download_Old_Builds_6_1
     1. Download Tuffix 2020 Edition .ova file from https://drive.google.com/file/d/1mbF4Y2sfWe7m409p0ejrof3kOmNJflVI/view
     1. Install VirtualBox.  Be sure to follow the instructions at the end to allow the proper security settings.
     1. Load VirtualBox.
     1. From the main menu, select `File` - `Import Appliance...`.
     1. Set the source file (using the folder to browse) to the downloaded Tuffix .ova file.
     1. Press the `Import` button.
     1. Highlight the `Tuffix 2020 Edition` virtual machine on the left pane and press the green arrow `Start` button.
     1. Select the user name `student` and use the password `student`.

Reference: https://github.com/kevinwortman/tuffix/blob/master/install.md

## Navigate Tuffix and Linux
1. Running Tuffix using Virtual Box (https://youtu.be/otB9FPC86a8?t=1m54s)
1. Intro to Tuffix (https://youtu.be/c0ZrWmarSwI)
1. Intro to the Linux command line (https://youtu.be/bQm8TUTDK7E)
1. Intro to Atom and clang++ compilation (https://youtu.be/TYlg3Ka8Mos) (Replace all the g++ commands with clang++)

## Getting Started
1. Open the Terminal program in Tuffix.
1. Change the present working directory to the `Documents` directory by typing the following command at the command prompt:

    ```
    cd Documents
    ```

1. Make a copy of this Github repository on your computer using the `git` and `clone` commands that you will input to the terminal. The commands take a URL as a parameter to specify where it can get a copy of the repository. You can find the URL by clicking on the green *Clone or download* button at the top right part of this page. Copy the URL and replace the example text shown below. Note that `username` should be replaced with your own Github username. When you hit <kbd>Enter</kbd> it will ask you to provide your Github username and token. Once done, you will have a copy of the repository on your computer.
    ```
    git clone https://github.com/CSUF-CPSC223P-NILAYJAIN12/Lab-01.git
    ```
1. Navigate into the new directory using the command line. Note that `username` should be replaced with your own Github username.  As a shortcut, you can type the first few letters of the folder name and press <kbd>Tab</kbd> so that it auto completes the folder name for you.

     ```
     cd lab01-username
     ```
     
## Program Instructions
1. Write a Python program that performs as a Tuffy Titan Hello Program which simply contains two functions that return *Hello ...* strings and are then outputted to the screen.

1. Create a `hello` module to meet the following requirements:
     1. Create a file named `hello.py`.
     1. Add a comment at the top of your code.
          ```
          # Name: Nilay Jain
          # Date: 8/24/2023
          # File Purpose: Multiple hello functions
          ```
     1. Define a function named `helloworld` which takes no parameters and returns the string `Hello World!`.
          ```
          def helloworld():
              return "Hello World!"
          ```
     1. Define a function named `helloname` which takes one string parameter and returns the string `Hello xxx!` where xxx is the value of the string parameter.
          ```
          def helloname(name):
              return "Hello " + name + "!"
          ```
1. Create a `main` driver program to meet the following requirements:
     1. Create a file named `main.py`.
     1. Add a comment at the top of your code.
          ```
          # Name: Nilay Jain
          # Date: 8/24/2023
          # File Purpose: Lab01 main program driver program
          ```
     1. Import the `hello` module.
          ```
          from hello import *
          ```
     1. Output a program header to the standard output.
          ```
          print("*** TUFFY TITAN HELLO PROGRAM ***")
          ```
     1. Call the `helloworld` function and output the return value to the standard output.
          ```
          print(helloworld())
          ```
     1. Call the `helloname` function passing a string parameter and output the return value to the standard output.
          ```
          print(helloname("Steve"))
          ```

1. Run the program using the command below and repeat the steps above until you are satisfied your program output meets the above requirements.

    ```
    python3 -m main
    ```


1. Typical output for the program:
     ```
    *** TUFFY TITAN HELLO PROGRAM ***
    Hello World!
    Hello Steve!
     ```

1. Run the unit testing program to ensure that your program runs as expected.

    ```
    ./test.sh
    ```
       
    The unit testing will output the results of a series of tests using specific input and expected output.  Any error will provide information on where the expected output is different from the actual output.  You will need to edit your source code to fix the error and run `./test.sh` repeatedly until it passes all the test.

## Submission
Periodically throughout the exercise, and when you have completed the exercise, **submit the complete repository to Github**.

   <pre>git add .<br>git commit -m "<i>your comment</i>"<br>git push</pre>

In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github token.

   <pre>git config --global user.email "<i>tuffy@csu.fullerton.edu</i>"<br>git config --global user.name "<i>Tuffy Titan</i>"<br>git commit -m "<i>your comment</i>"<br>git push</pre>

When you completed the final Github push, go back into github.com through the browser interface and ensure all your files have been correctly updated.  You should have the following files:
```
main.py
hello.py
test.txt
```
    
## Grading
All requirements met = 100 points.
