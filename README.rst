Taisei
======

.. contents::

Introduction
------------

Taisei Project is an original open source fan-game set in the world of Tōho
Project. It is a top-down vertical-scrolling curtain fire shooting game (STG),
also known as a "bullet hell" or "danmaku," with an original soundtrack,
character art, and story.

Taisei Project is highly portable, and is written in C (specifically, C11),
using SDL2 with an OpenGL renderer. It is officially supported on Windows,
Linux, macOS, and through WebGL-enabled browsers such as Firefox and
Chromium-based browsers (Chrome, Edge, etc). It also has experimental native
support for a number of other operating sytems.

For gameplay instructions, read `this <doc/GAME.rst>`__.

For the story, read `this <doc/STORY.txt>`__. (Warning: spoilers!)

For more information on Tōhō Project, the series this fan-game is originally
based on, `click here <https://en.wikipedia.org/wiki/Touhou_Project>`__.

Installation
------------

You can find precompiled binaries of the complete game on the
`Releases <https://github.com/taisei-project/taisei/releases>`__ page on
GitHub, available for Windows (x86/x64), Linux, and macOS. An experimental
build for Nintendo Switch (homebrew) also exists (use at your own risk).

You can also play our experimental WebGL build through your web browser
`here <https://play.taisei-project.org/>`__.

Source Code & Development
-------------------------

You can obtain the source code of the stable releases from the
`Releases <https://github.com/taisei-project/taisei/releases>`__ page on
GitHub, alongside the binaries.

You can also grab the latest code from git using the following commands:

::

    git clone --recurse-submodules https://github.com/taisei-project/taisei

The ``--recursive-submodules`` option is important as the subprojects are
necessary to compile the project correctly.

If you want to pull them in manually, be sure to use the following:

::

    cd taisei
    git submodule init
    git submodule update

**Important:** You should also run ``git submodule update`` whenever you pull in
new code, checkout another branch, etc. The ``pull`` and ``checkout`` helper
scripts can do that for you automatically.

**Important:** as of v1.3, you cannot download GitHub's automatically-generated
source archives, as they don't contain the necessary submodules for compiling
the game. Make sure you either download the release tarball, or use `git clone`.

For more in-depth development and compiling instructions, see:
`Development Guide <doc/DEVELOPMENT.rst>`__.

Dependencies
^^^^^^^^^^^^

-  OpenGL >= 3.3, or OpenGL ES >= 3.0, or OpenGL ES >= 2.0 (with extensions)
-  SDL2 >= 2.0.6
-  SDL2_mixer >= 2.0.4
-  freetype2
-  libpng >= 1.5.0
-  libwebpdecoder >= 0.5 or libwebp >= 0.5
-  libzip >= 1.2
-  opusfile
-  zlib

Optional:

-  OpenSSL (for a better SHA-256 implementation; used in shader cache)
-  SPIRV-Cross >= 2019-03-22 (for OpenGL ES backends)
-  libshaderc (for OpenGL ES backends)


Replays, Screenshots, and Settings Locations
--------------------------------------------

Taisei stores all data in a platform-specific directory:

-  On **Windows**, this will probably be ``%APPDATA%\taisei``
-  On **macOS**, it's ``$HOME/Library/Application Support/taisei``
-  On **Linux**, **\*BSD**, and most other **Unix**-like systems, it's
   ``$XDG_DATA_HOME/taisei`` or ``$HOME/.local/share/taisei``

This is referred to as the **Storage Directory**. You can set the environment
variable ``TAISEI_STORAGE_PATH`` to override this behaviour.


Troubleshooting
---------------

If you're having issues with low framerates, sound playback issues, or gamepad
support, please see the `Troubleshooting Guide <doc/TROUBLESHOOTING.rst>`__.

If you find any other bug not covered in that, feel free to
`open up an issue <https://github.com/taisei-project/taisei/issues>`__.

Contact
-------

-  https://taisei-project.org/

-  `#taisei-project on Freenode <irc://irc.freenode.org/taisei-project>`__

-  `Our server on Discord <https://discord.gg/JEHCMzW>`__
