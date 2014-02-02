password-pronounce
==================

password-pronounce is an alphanumeric pronounceable password generator.

On inputting a length as an argument, it generates a customizable number of random strings that are human-pronounceable.



Author:   Puranjay Sharma

Contact:  puranjay.usict@gmail.com

Version:  0.1.0




Installation
============

In the main project directory, use:

        ./configure
        sudo make && make install

If you don't have sudo access, but do have root access, the following will work:

        ./configure
        su -c "make && make install"
        
To build locally, without installing

        make

You may want to run
        
        make clean

afterwards, to remove object and build files.

Uninstallation
=============

In the main project directory, use:
        
        make uninstall

