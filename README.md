<<<<<<< HEAD
# Compiling C programs

The compiling of a C program takes place in three steps. Each carried out by CMake. In the following couple of exercises you will look at each step and how they work. This will hopefully mean I have less questions to answer later in semester.

The three steps are:
1. Preprocessing
  Handling of preprocessor directives to produce completed C files for compilation.
2. Compilation
  The creation of object files from C files.
3. Linking
  The compiled object files are linked together to form a binary file that represents the built program.

## Preprocessor

A big advantage that C has over interpreter based languages as well as other compiled languages, such as Java, is its precompiler. This preprocessor allows a programmer to use certain directives to simplify coding. The most basic analogy for what a lot of the preprocessor does can be thought of as "cut and paste", where chunks of code are pasted around to minimize the amount of manual code copying and/or search and replace the programmer must perform.

<<<<<<< HEAD
Please note that if you're reading these instruction whilst doing the tutorial they may dissapear if you change branch or do some git trickery that causes them to move/change. As such, while you get to grips with Git I would reccomend moving these README.md files, as they become available, somewhere outside of the current Git repo while you complete the challenge. 
=======
There are specific preprocessor directives, such as `#include` and `#define` which you should all be familiar with. One can also create conditional statements that allow for the preprocessor to either include or not include code sections. This is done with the directives `#if`, `#ifdef` and `#ifndef`. A common example of these directives would be when performing "feature inclusion" via compiled flags.
<<<<<<< HEAD
>>>>>>> main-function
=======
>>>>>>> compiling
>>>>>>> merging

``` C
#ifdef USE_AMAZING_FEATURE
device_t dev = amazing_device
#else
device_t dev = NULL
#endif
```

### Include and Define Directives

#### Includes

The include directive should be one that everyone is familiar with (if you don't know it this tutorial is going to be extra fun for you). This directive is found at the top of most C files. Includes enable the inclusions (funny that) of header files that contain required function *declarations* (function prototypes) and any other data that is required to interact with the API that the header file exposes from the relevant `.c` file, eg. constant values. This is achieved by the preprocessor pasting the contents of the header file wherever the relevant `#include <filename>` directive is found. Remember this when trying to debug include errors.

#### Defines

The define directive is used for text substitution, allowing for few nifty little tricks when writing C code. Firstly the `#define` allows the programmer to set a flag or give a certain text literal a value, which is then substituted during the preprocessing step of the build process. Commonly called a "hash define". This gives a few advantages, outlines below are the key, and most common, advantages.

 * Setting flags.

  Using the `ifdef` conditional preprocessor statements one can set flags. For example a "debug" mode could be enabled using a Boolean debug flag that then allows for the inclusion of debug code, such as print statements

  ``` C
#define DEBUG_MA_CODEZ	1
...
#if DEBUG_MA_CODEZ
printf("Value waz %d", da_value);
#endif
...
```
 * Human readability.

 By using hash defines instead of magic numbers (should be avoided whenever possible) code is able to be a more easily read as it will real more like actual text. This is important when sharing code or developing with others. Your code should read like a book.

 ``` C
#define SMILEY_X_LOCATION   12
#define SMILEY_Y_LOCATION   34
void function_that_draws_smiley ( int x_position, int y_position ) {
  ...
}
...
void main( int argc, char **argv ) {
    ...
    function_that_draws_smiley( SMILEY_X_LOCATION, SMILEY_Y_LOCATION);
    return 0;
}
 ```
 * Centralizes frequently used variable values in one locations, making changing widely used value very easy.

  For example, if the smiley drawn in the previous example is drawn many times in your program and you need to shift its location a hash define allows for the smiley to be moved for all cases where its location's value is used. By changing one centralized value. Simply put, hash defined are slightly better magic numbers. A good example of this would be using the following

 ``` C
 #define PI   3.14
 ```
 should you decide that PI is better as 3.15 then you would be quickly and easily able to break your code by changing just one value :)

#### Macros

Now a more advanced use for defines is macros. Macros use the substitution of tokens with other tokens to allow for the generation of code. Macros are beneficial when the use of a function would be trivial and/or executionally slower.

  ``` C
#define CIRCLE_AREA(RADIUS)   (PI * RADIUS * RADIUS)
```
<<<<<<< HEAD
master ----- merging ----- feature A
                     |---- feature B
```

Thus any complicated merge conflicts will be contained to the merging branch and can be resolved there before being merge (via a less complex merge as the complex problems have now been resolved) into the master branch. We will cover merge errors and the likes later as your perform your own merges.

Let us now go to the merging branch. To check the branches that exist in the repository one can use the `git branch` command. A new repository might not show all of the branches as Git does not download all information when not required, to try and minimize the data required locally. `man git fetch` will detail how Git fetch can be used.

When no remote is specified the default `origin` is used. Run `git fetch` to thus retrieve all the branches and tags on the origin remote. Now run `git branch --all` to list all of the branches on the origin. We want a branch called `merging` where we will perform our merges before merging to master. To do this we need to first create a branch and then swap to this branch. To create a new branch simply use

``` bash
git branch merging
```
now if we list our branches using `git branch` you should now see that there is a `merging` branch. We now need to change to this branch so our modifications that we perform are done there. It should be noted that the new branch is a copy of this current branch, although if we were to continue modifying master then the merging branch would fall behind and would need to be brought back up to speed with master. But for now just checkout `merging` using the checkout command.
=======
The use of the above macro produces more easily read code that is then evaluated into inline C code during precompilation. The precompiler would do the following, via substitution
<<<<<<< HEAD
>>>>>>> main-function
=======
>>>>>>> compiling
>>>>>>> merging

  ```C
#define MY_CIRCLE_RADIUS  2
...
my_circle_area = CIRCLE_AREA(MY_CIRCLE_RADIUS)
```
<<<<<<< HEAD
It is also good to note that this action of branching and checking out can be done in a single command by using the `-b` option with the `checkout` command.

``` bash
git checkout -b merging
```

# Merge Basics

Now that you have checked out your merging branch we are going to perform some merges. As this tutorial will also look into building C projects, using CMake specifically, we will using merging and other Git tools to pull a basic CMake project together.
=======
# Merge Conflicts

When merging two branches there are sometimes changes that Git cannot automatically resolve. Git prefers then to flag the conflict as something it cannot resolve instead of intervening and potentially causing even larger errors. Errors that require human intervention usually result from changes to the same file, for example two people modify the same line of a file. Git would then require the person merging the files to decide which one it should keep.

It is important to note that during a merge process if you choose the wrong line or mess up the merge you can revert the merge. Meaning you must only commit the merge once you are happy that everything has been merged properly. At any time you can use the `git reset --hard HEAD` command to reset your HEAD to the last commit before the merge (if you didn't pick up on what this is then read [this](http://www.gitguys.com/topics/head-where-are-we-where-were-we/)).

## Resolving a conflict

When there is a merge conflict Git will tell you that there is unmerged paths and it will give you a list of the files involved. This can be found using `git status`.

``` bash
Unmerged paths:
  (use "git add <file>..." to mark resolution)

	both modified:   src/main.c
```

Inside each conflict file Git places markers that indicate the area of conflict. Let's take the simple example where two changes affected the same line of code in a file. This means that Git needs you to decide which change to keep. You will manually need to edit the code to integrate both solutions into your project. Choosing how to fix your code will be up to your discretion.
>>>>>>> conflicts

Now in this example I have branched my original code, then on the new branch **and** on my current branch created commits that modify the same line of code. On the current branch I added "Result:" to a `printf` statement while on the branch I added "Output:".

``` bash
<<<<<<< HEAD
git push ______ ______
=======
Would become
``` C
my_circle_area = 3.14 * 2 * 2
<<<<<<< HEAD
>>>>>>> main-function
=======
>>>>>>> compiling
>>>>>>> merging
```
To see some much more involved macros that are used in the auto generation of data structures in a state machine, look [here](https://github.com/alxhoff/Application_Interfacing_Governor/blob/master/AI_gov_phases.c).

<<<<<<< HEAD
Now back to the problem. You should be able to find a branch called `make`, check it out using your newly learnt checkout command. On this branch is the skeleton for our CMake project. Now to merge the `CMakeLists.txt` file, which is the core CMake file for any CMake build, into our merging branch. We need to use the `git merge` command. Details of this can be found in the manual, you should be able to run the correct `man` command yourself now to do this.
=======
## Compilation
<<<<<<< HEAD
>>>>>>> main-function
=======
>>>>>>> compiling
>>>>>>> merging

Now the compilation of code is only one step in the process of building a program. After each C file is run through the preprocessor, so that all the preprocessor directives have been handled, the completed C files must then compiled into assembly code. This is done using a compiler, such as the GNU C Compiler (GCC). The assembly code must then be made into machine code that is actually usable by the target device. This is done by the assembler, which creates machine code from the assembly code. By modifying these pieces of software, collectively called a toolchain, you can change how the code is compiled. Various toolchains are available for different hardware architectures, such that the compiled code is compiled with regards to how the code executes on the target architecture. Compiling for a different architecture, such as compiling on an x86 laptop for a ARM based micro-controller, is known as cross compiling.

The file produced by the assembler is a binary file, the formats can vary (ELF, a.out, ...) but the idea is the same. The binary files are called objects, each object file contains the compiled code and exposes the symbols contained within the binary code. Symbols are the addresses of the variables and functions contained within a binary, they can be thought of as the "API" to the object file. The addresses of all the symbols within an object file are stored within a symbol table.

At this point all of your source files have been compiled into separate objects which are unaware of each other. Function calls to functions found in other object files are at this point pointing to an unknown memory locations, in an unknown binary file. These calls are stored as references to undefined addresses which are to be resolved in the last step of building a program, linking. If the completed program binary is to be able to execute, each function call needs to know where the pointed to code actually resides in memory. This is done by the third step in building a program, linking. Common errors pop up along the lines of "undefined reference" when a symbol cannot be resolved, meaning that the linking step was not able to be completed.

I should also mention that libraries, with which you are hopefully familiar with, are simply object files that can be reused by multiple programs such that the same code is not rewritten and/or recompiled unnecessarily.

<<<<<<< HEAD
``` bash
CMakeLists.txt | 12 ++++++++++++
1 file changed, 12 insertions(+)
create mode 100644 CMakeLists.txt
=======
Original code (shared commit) ------ + "Result:"
                              |----- + "Output:"
```

This has caused a merge conflict as the commit which they both share now has two different diffs when compared with the HEAD of both branches.

Looking into the file `src/main.c`, as shown by `git status`, we would see the following around the line of interest.

``` C
<<<<<<< HEAD                                                                     
        printf("Result: %s", tmp);                                               
=======                                                                          
        printf("Output: %s", tmp);                                               
>>>>>>> bar      
>>>>>>> conflicts
```

This tells use that on our current branch (our current HEAD) the line containing "Result", where as on the branch we wish to merge into our current branch (bar) the line contains "Output". Git does not know which one we wish to use and as such we must decide. Let's say that we wish the have the line contain output and not result, then we must manually delete the markers from Git as well as the line. Using our new patch knowledge we can see the what needs to be done below.

``` bash
<<<<<<< HEAD
(HEAD -> merging, origin/make, make)
```
to
``` bash
(HEAD -> merging, origin/merging, origin/make, make)
```
meaning that this commit can now found be found in origin/merging and not just merging, origin/make and make. This annotation (`origin/`) signifies the remote branch (ie. the branch on the server). The branch merging is your local branch while the branch origin/merging is that on the remote.
=======
## Linking

So we know now that our program is compiled into a number of object files (binary blobs) we need to resolve all of the references to the symbols that are pointed to and found in other object files. As the name implies, linking is the process of linking these references to the actual memory addresses in the appropriate object files. Linking to files within the same source code chunk is usually not that error prone. Most errors come from having to link against static libraries or source code found else where on a system or in another project. Common errors will be those that complain of either missing definitions (cannot find appropriate symbols to link against) or duplicate errors (multiple objects exposing the same symbol).
<<<<<<< HEAD
>>>>>>> main-function
=======
>>>>>>> compiling
>>>>>>> merging

# CMake

So now that I have outlined a bit for you what happens when building a program, we will go through and build a demo program by using a program called CMake. CMake just helps in automating the build process a little, while not abstracting the process so much that one looses touch with what is happening. Using your newly discovered Git skills we will piece together a basic project and get it compiled and linked. You may have to apply some Git trickery along the way to get all the pieces ;).

So now that you have an idea of what goes into building a C project lets see how you can accomplish this using CMake. If we open the CMake file in this branch you should see the following

``` bash                                                         
project(git_tutorial)                                                            
cmake_minimum_required(VERSION 3.4 FATAL_ERROR)                                  

<<<<<<< HEAD
``` bash
cmake -B build
```
To execute the CMake script whilst specifying the `build` directory as our build directory. Running `git status` you can now see that the build directory is now untracked and has had changes done to it. Running `git status build` shows us that the build directory now includes a `CMakeCache.txt` and a directory `CMakeFiles`. These are the temporary files generated by CMake. Instead of using the '-B' option one can also first navigate into the build director and then execute `cmake ..` where `..` specifies the folder in which the CMake script can be found while the current directory (build) is used as the build directory. We will see that the `cmake` command did not run correctly right now, lets ignore this for now.
=======
set(CMAKE_BUILD_TYPE Debug)                                                      
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)                   
<<<<<<< HEAD
>>>>>>> main-function
=======
>>>>>>> compiling
>>>>>>> merging

include_directories(include)                                                     

file(GLOB SOURCES "src/*.c")                                                     

add_executable(foo ${SOURCES})    
```

Now the first few lines should be quite self-explanatory. On the fourth line we set the output directory for our binary. Meaning we will need to create a `bin` directory in our repo's root. Do this now. The fifth line is where we tell CMake which directories we want to use as include directories. In the directories here is where make will then look for files that you include using `#include`. This CMake line equates then to the `-I` make build option. Another good common practice is to separate your `.c` source files from your `.h` source files. As can be seen in the CMake, we use a folder called `include` for the header files and a folder called `src` for the source files. Create the `include` folder so it sits alongside the bin and build directories. Following this we can see the `file` command. The file command is a file manipulation command used to achieve lots of different things. In this case it is used with `GLOB`. Glob is used to generate a list of files given one or more globbing expressions, storing the results in a variable, in this case `SOURCES`. From the provided globbing expression we can see that in this case the file command generates a list of all `.c` files that can be found in the `src` folder. Since we do not have this you will also need to create it.

The final line in the CMake lets CMake know that an executable should be built from the provided source files, in this case those stored in the `SOURCES` variable. This will also perform the required linking should there be more than one source file found, as there are going to be no object files external to our source files' directory.

Now we are almost there. We have the folder structure set up for our project but we are missing some code! We want to merge the new folder structures that we created back to our merging branch. The problem is that Git only tracks the contents of a folder and not folders themselves. As all of our folders are empty they would not be able to be tracked, commited and then merged to our `merging` branch. A convention of Git to keep Git directories that are empty are to add a `.gitkeep` file to them. This is a hack way of creating a reason for Git to track the folder. In this case we are in need of this folder structure for CMake and as such it is important that Git is able to track our folders. Let's touch a `.gitkeep` into each folder that is empty. `man touch` should help you understand what touching does.

Checking the status of your repo you should now see that you can track your empty `src`, `bin` and `include` directories as they all have `.gitkeep` files in them. Add and commit your folders with a meaningful commit message and then checkout your merging branch and merge the folders to your `merging` branch. Come back to this branch (`compiling`) when you have done that.

## Coding Challenge I

Now we are in need of the most the most fundamental of fundamentals to compile our project, a main function. As we will consider the main function a new feature you must perform the following steps:

<<<<<<< HEAD
``` bash
git rm -r --cached .
```
This will recursively remove tracked files from the staging cache. Running `git status` again will now show us that all of the files in the repo have been deleted, meaning deleted from the staging area. In the untracked files section you will now only see the README, CMakeLists and .gitignore as these files have not been ignored via the gitignore. Now we can add these files back and commit them using something such as "Actualizing gitignore" as the commit message. After pushing the new commit, if we look at the repo through the web interface, looking specifically at the files on the merging branch, you will see that the build files are not included. It is important to add all files that you do not want included in the repository to be added to the gitignore so that there is no way for them to become accidentally included in a commit, this makes you look like a Git noob if you are committing build files.
=======
 * Checkout a new branch to implement your features, branching from this branch.
 * Write a main function in an appropriate file in your project, that is to output "Hello ESPL" to the terminal.
 * Add, commit and PUSH the work you have done to the origin remote.
 * Merge the changes back to `merging`, pushing the result.
 * Come back to this branch to continue with the instructions below.
<<<<<<< HEAD
>>>>>>> main-function
=======
>>>>>>> compiling
>>>>>>> merging

Now you should have at least one source file and be able to rerun your CMake command to generate the required make files for your project. If all went well in your build folder you should now see a Makefile that was generated from CMake. To then build your project you need to run the command `make` from within your build directory. If all went well you should now find a built binary in your bin directory with the same name as the executable specified in you `CMakeLists.txt`.

Navigate to your bin directory and execute the binary by using the `./` Linux convention. You should be greeted with "Hello ESPL".

Now we know roughly how to navigate around a Git repo, create, add and commit files as well as build a basic C project with an idea of what is happening behind the scenes. Before we look into the more advanced CMake features, such as linking libraries, you should merge your current project to master as it is now in a stable state. Binary files should not be included in your commits and should be left untracked. Modify your repository accordingly such the the binaries can never be accidentally added. Once that is done you will need to go to the `exercise` branch where you will need to use the Git logs, merging and the `git cherry-pick` command to get your exercise requirements and the library code. Useful articles can be found [here](https://www.git-tower.com/learn/git/faq/detached-head-when-checkout-commit) and [here](https://www.hacksparrow.com/how-to-merge-a-specific-commit-in-git.html) to explain the process.

<<<<<<< HEAD
To do so jump to the branch `compiling`.

In your web browser, if you select the branch `compiling` you can read the README directly in the browser. 
=======
One commit will contain the necessary `.h` and `.c` files for a static library that we will build called `espl_lib`. Another commit will contain a `.patch` for your CMake script to link the library. Checkout the commits, find the files, verify their contents and then use cherry pick to merge them to your merging branch. The instructions (in a separate `.md` file) to continue can also be found in a seperate commit.
<<<<<<< HEAD
>>>>>>> main-function
=======
>>>>>>> compiling
<<<<<<< HEAD
>>>>>>> merging
=======
=======
--- src/main.c	2019-03-20 11:47:22.947753390 +0100
+++ src/main.c	2019-03-20 11:47:34.777753931 +0100
@@ -8,11 +8,7 @@
     char *tmp = NULL;
     tmp = num_to_words(123);
     if (tmp)
-<<<<<<< HEAD
-        printf("Result: %s", tmp);
-=======
         printf("Output: %s", tmp);
->>>>>>> bar
     else
         return 1;
    return 0;
```

Once you have resolved the merge conflict you can then add the resolved file and finalize the merge with a normal commit. The commit message should summarize the changes during the merge.

Now that you has seen the basic ideas of how merging works, lets see if you can handle some more complex merge problem yourself. You will find a branch called "unknown_features" which has diverged from this current branch at the previous commit. Your job now is to merge this branch into this current branch and resolve the conflicts presented. The project is a self-contained CMake project inside the `merge_exercise` folder and you will need to apply you C knowledge and CMake knowledge to merge the files correctly to get the project building properly. Please note that there are other tricks and errors hidden in the code. The code should not complile with warnings as warnings should almost always be treated as errors. Warnings will be cause for deducted marks throughout this course. 

The program should be a POSIX thread based state machine that counts to a number specified in the programs options. See the `--help` of the compiled binary to see how to use the program. Once your binary performs this then you have the project merged and building correctly. Merge the project into `merging` and finally into `master`, if both projects are stable and working as expected. Finally create another tag with the annotation "Exercise 1.2 Submission".

If all of that is done then you have completed this tutorial. Please be wary that the use of Git is a requirement in this course and will be part of the project's assessment. Inform yourself on proper use of Git commit messages and make sure that you and your team partner establish a Git workflow that you will use throughout the course. A fun tool to use to make sure your workflow has been used properly is `git log --graph --all` which will give you a graphical representation of your repo's logs.

# Future Reading

There are a number of other features in Git that are useful to know. If you are motivated then I would recommend reading up on these features so that during semester you are able to overcome some problems you will no doubt encounter.

 * `git stash`
 * `git pull`
 * `git show`
 * `git revert`
 * `git clean`
>>>>>>> conflicts
>>>>>>> merging
