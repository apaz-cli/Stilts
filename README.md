# What is Daisho?

The goal of this project is to create a language that's nice to work with, leaves no performance on the table, but maps to low level C code with manual memory management.

The language is currently still in a planning stage. I'm writing multiple parts of the language at the same time to get a feel for how things are supposed to work, and thinking through how I'm going to accomplish everything I want to accomplish. I'm currently going down the rabbit hole of generic type validation semantics and implicit conversions of generic types, with how that's going to map to C. Type checking and control flow analysis are going to be the hardest part of this project. Parsing and code generation are the easy parts.

I've also been writing the standard library. I'm going to use the language's own standard library to bootstrap the compiler. What I've done so far is already an incredibly useful collection of C libraries. You can find them in `stdlib/`.

<br>

# How can I get involved?

<a href="https://discord.gg/yM8ZBDHGdR">
<p align="center">
<img src="https://github.com/apaz-cli/apaz-cli.github.io/blob/7c2d224aae86f228347dadbdcd22c159cfcfcb52/Join%20Our%20Discord.png?raw=true">
</p>
</a>

If you want some input into the direction of the language, or have suggestions, or want to talk, <a href="https://discord.gg/yM8ZBDHGdR">come on over to our Discord</a>.

Regardless of if the language gains popularity or not, I want to share the results of my work because writing compilers is hard. There are also some unique ideas here. A publication about named lifetimes, one of my language's features, is forthcoming.

<br>

# Getting Started

## System Requirements

* A POSIX-compliant operating system (Like Linux, MacOS, BSD)
* A working C toolchain that supports C11 (Including some "optional" headers).
* Python 3 (optional, to support inline python library interop)
* GTK+3.0 (optional, to support GUI applications)
* Reasonable hardware. If it's made after the 90s, you're probably fine. If you're not, the install will fail and you'll get an error message as to why.


## Install

```bash
./install.sh release
```

Now you have the compiler, `daic`. You can check to make sure everything installed correctly by trying to run it. It should spit out a help message.

```bash
daic
```

If you're not on a POSIX operating system (If you're on Windows), I recommend switching to one. PopOS is a good beginner distro, and is quickly getting better and better. It's possible that Daisho gets ported to Windows, but I don't want to be the one who does it. If you want to be the one that does it, please contact me on Discord.


<br>


# Design Vision:

## List of inspiring languages:
|  Lang  |                   Inspiration |
| :----: | ----------------------------: |
|   C    | Simplicity, flat memory model |
|  C++   |     Templates, language goals |
|  Java  |      Collections/Streams APIs |
| Python |          List comprehensions, |
|  Rust  |             static/dyn Traits |
|  Vala  |    Compilation model, interop |


## Daisho is:
* C, with modern high level language features
* Fast to execute (like C), but also fast to write (unlike C)
* Easy to use, mixing C, Python, and Daisho code in the same file.
* Focused on tooling and user experience
* A passion project


## Daisho is not:
* Memory safe
  * Just like the C that it's based on and compiles to.
  * In practice, you should be fine. Unsafety can be solved through tooling.
    * Memory and UB sanitizer tooling is being built, and will be available as compile flags.
* Usable in production
  * For now. Unless you're a masochist like me.
* Fast at compiling programs
  * This is a goal, but not a priority.
  * For now, having a compiler at all is a higher priority.
* Supported on platforms other than POSIX
  * I only want to write the standard library and compiler once. However, I will never make the task harder than it needs to be.
  * If you're on Windows and want to port some of it, <a href="https://discord.gg/yM8ZBDHGdR">let me know</a>.
* A full time job
  * I already have one of those.
  * I don't have the time to not make progress. That means careful planning and a focus on simplicity.


# Sub-Projects:
* Daisho Compiler  (`daic` folder)
* Standard Library (`stdlib` folder)
* Memory Sanitizer (coming soon)
* Undefined Behavior Sanitizer (coming soon)
* Language Server  (coming eventually)
* VSCode Extension (coming eventually)
* Code Formatter   (coming eventually)
