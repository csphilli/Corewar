# Corewar
Group project with https://github.com/lev9 and https://github.com/osalmine/

> In this project, you will create a virtual “arena” in which programs will fight against one another (the “Champions”). You will also create an assembler to compile those Champions as well as a Champion to show the world that you can create life from coffee.

This is the third algorithm branch project at Hive.

Grade:

[![Corewar Score](https://badge42.herokuapp.com/api/project/osalmine/Corewar)](https://github.com/JaeSeoKim/badge42)

**SEE [SUBJECT](corewar.en.pdf) FOR MORE DETAILS**

## Usage

After cloning, you can compile both asm (assembler) and corewar (virtual machine) with

```make```

You can clean .o files with

```make clean```

Remove all compiled files with

```make fclean```

And fclean + compile with

```make re```

After compiling run ```./asm``` and ```./corewar``` for more detalis on usage.

We have two champions of our own, dud.s and leroy.s. You can compile them with asm into .cor files that the vm can use.

To have them compete, run ```./corewar -l dud.cor leroy.cor``` To see the game progress, you can use `-v` flag with the corewar. Be sure to make the terminal window small enough for the visualizer to fit.

## Resources
[The Cookbook](https://github.com/avocadohooman/42-Corewar/wiki)
