======================================
            tmux-mem-cpu
======================================
--------------------------------------
CPU and RAM monitor for use with tmux_
--------------------------------------

Description
===========

A simple, lightweight program provided for system monitoring in the *status*
line of **tmux**.

The memory monitor displays the used and available memory.

The CPU usage monitor outputs a percent CPU usage over all processors. It also
displays a textual bar graph of the current percent usage.

Example output::

  1.1/3.8GB ▄  76.5% ▇

   ^    ^     ^    ^   ^
   |    |     |    |   |
   1    2     3    4   5

1. Currently used memory.
2. Available memory.
3. Memory usage bar graph.
4. CPU usage percentage.
5. CPU usage bar graph.

Installation
============

Dependencies
------------

Only Mac OSX is supported.

Building
~~~~~~~~

* >= CMake_ -2.6
* C++ compiler with C++11 support (e.g. gcc/g++ >= 4.6)

Download
--------

There are links to the source code at the `project homepage`_.

Build
-----

::

  cd <source dir>
  cmake .
  make

Install
-------

::

  su -
  make install
  logout

Build and Install Using tpm_
-----------------------------

Include the plugin in your ``.tmux.conf``, the same file you'll set the
configuration in, below.

::

  set -g @plugin 'svanharmelen/tmux-mem-cpu'

Configuring tmux_
=================

Edit ``$HOME/.tmux.conf`` to display the program's output in *status-left* or
*status-right*.  For example::

  set -g status-interval 2
  set -g status-left "#S #[fg=green,bg=black]#(tmux-mem-cpu --interval 2)#[default]"
  set -g status-left-length 60

If you installed using tpm, you must specify the full path to the
``tmux-mem-cpu`` script, like below::

  set -g status-right "#[fg=green]#($TMUX_PLUGIN_MANAGER_PATH/tmux-mem-cpu/tmux-mem-cpu --interval 2)#[default]"

Note that the *interval* argument to `tmux-mem-cpu` should be the same number
of seconds that *status-interval* is set at.

The full usage::

  Usage: tmux-mem-cpu [OPTIONS]

  Available options:
  -h, --help
           Prints this help message
  -i <value>, --interval <value>
          Set tmux status refresh interval in seconds. Default: 1 second

Authors
=======

Matt McCormick (thewtex) <matt@mmmccormick.com>
Sander van Harmelen (svanharmelen) sander@xanzy.io

Contributions from:

* cousine <iam@cousine.me>
* Jasper Lievisse Adriaanse <jasper@humppa.nl>
* Justin Crawford <justinc@pci-online.net>
* krieiter <krieiter@gmail.com>
* Mark Palmeri <mlp6@duke.edu>
* `Pawel 'l0ner' Soltys`_ <pwslts@gmail.com>
* Travil Heller <trav.heller@gmail.com>
* Tony Narlock <tony@git-pull.com>
* Compilenix <Compilenix@compilenix.org>
* jodavies <jodavies1010@gmail.com>
* `@nhdaly`_ (Nathan Daly) <nhdaly@gmail.com>


.. _tmux: http://tmux.sourceforge.net/
.. _CMake: http://www.cmake.org
.. _`project homepage`: http://github.com/svanharmelen/tmux-mem-cpu
.. _`tpm`: http://github.com/tmux-plugins/tpm
.. _`Pawel 'l0ner' Soltys` : http://l0ner.github.io/
.. _`@nhdaly` : http://github.com/nhdaly
