#The yoda-project.

[wiki](https://github.com/devchild/yoda-project/wiki)

The yoda-project is my attempt to build a compiler for my very own invented programming language.

In lack of a final (better) name for this language I name this the yoda-project. If you have a proposition for a cool new name for this language, please let me know.

The programming language that is being designed here is a mixture of python and c#. The compiler itself is written in c++ and uses llvm for the low level code generation. The parser bits are generated using bison and flex.

The goal of this project, is the get a better understanding on the internals of a compiler without making this a life's work.

Initially I was building this on a Linux system, but these days I find myself programming more on Mac, so currently I am not really looking to support many platforms. I am sure this won't compile on a windows machine, it might/should compile on a Linux, but nothing is guaranteed.


#How to compile this project.
##1. Compile llvm.
This project uses llvm as a library but it depends on some cmake files that come with the llvm source package.

First of all you will need to download the llvm source from http://llvm.org/releases/download.html.
I am currently using llvm 3.6.2 for this project, but I think newer versions should work as well.
Just download the LLVM source code and extract it using following command. 
(Just replace the X.X.X with the version you ended up downloading) 
```
tar -xf llvm-X.X.X.src.tar.xz
```
Then create a directory for building llvm.
```
mkdir llvm-X.X.X.obj
```
Move into the newly created directory.
```
cd llvm-X.X.X.obj
```
Then generate the makefiles for building llvm.
If you are planning to install llvm on your system after compiling you can omit the -DCMAKE_INSTALL_PREFIX option.
```
cmake -DCMAKE_INSTALL_PREFIX={PATH_TO_WHERE_YOU_WANT_TO_INSTALL_LLVM} ../llvm-X.X.X.src/
```
Start builing llvm (this can take a while, if you have multiple cores or processors you might want to pass the optional "-j" switch eg. make -j6)
```
make
```
If everything compiled correctly you can finaly install llvm on your system.
```
make install
```

##2. Compile the yoda project.
If you have cloned or downloaded a version of this project you should be fine.
First let us create a folder for building this project.
```
mkdir yoda.obj
```
move into the the new folder.
```
cd yoda.obj
```
First we will need to generate the makefile for this project on your system.
For this cmake needs to know where it can find the installed version of llvm.
Replace PATH_TO_WHERE_YOU_WANT_TO_INSTALL_LLVM with where you the llvm bin files are located 
```
cmake -DLLVM_DIR={PATH_TO_WHERE_YOU_WANT_TO_INSTALL_LLVM}/share/llvm/cmake/ ../yoda.src/
```
And finaly build the project.
```
make
```

This is it. 
You should now have a binary version of the yoda compiler.
Currently the compiler itself is called mlang and is located in ./tools/mlang/

Compiling files can be done by executing following command.
```
./mlang --out=helloworld inputfile.ml
```

Compiling multiple files into a single executable can be done by executing following command.
```
./mlang --out=helloworld *.ml
```





