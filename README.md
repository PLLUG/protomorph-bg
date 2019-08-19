# Protomorph BG

<p align="center">
  <img src="https://github.com/Guitarheroua/protomorph-bg/blob/development/old-src/ProtomorphBG/resources/icons/protomorph-bg.ico" />
</p>

**"Protomorph BG"** is a tool, that will help board game designers to prototype games components(cards, tiles, boards etc.) and save them as a project. It will also have layouts mechanisms, to layout components for printing on standard paper formats and export entire project to PDF or other formats. Will be available for Windows/Linux/OSX (I hope :))

## Status

AppVeyor-CI: [![Build status](https://ci.appveyor.com/api/projects/status/a0qea0hrbx2evnwa/branch/development?svg=true)](https://ci.appveyor.com/project/Guitarheroua/protomorph-bg/branch/development)

Travis-CI: [![Build Status](https://travis-ci.com/PLLUG/protomorph-bg.svg?branch=development)](https://travis-ci.com/PLLUG/protomorph-bg)

Coverity Scan Build Status: <a href="https://scan.coverity.com/projects/guitarheroua-protomorph-bg">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/17969/badge.svg"/>
</a>

## Third party dependencies

Next sources are used in the project:

1. [**game-icons/icons**](https://github.com/game-icons/icons) - Game Icons.(Will be used in component editor and for application logo icon design)

2. [**google/roboto**](https://github.com/google/roboto) - The Roboto family of fonts

3. [**mitchcurtis/slate**](https://github.com/mitchcurtis/slate) - Pixel Art Editor(Collapsible panels and color scheme used from this project)

## FlatBuffers

To compile a program,  you need connect Flatbuffer library.
You can do this by editing flatbuffers.pri file or add arguments to qmake

<pre><code>FLATBUFFERS_INCLUDE_DIR - directory where flatbuffers include files are located
FLATBUFFERS_LIB_DIR - directory where flatbuffers libs are located
FLATC_SCHEME_FILES - list of flatbuffers schema files used to generate headers
</pre></code>

Example: 
<pre><code>FLATBUFFERS_INCLUDE_DIR=D:/MSYS2_Commander/msys64/mingw64/include
FLATBUFFERS_LIB_DIR=D:/MSYS2_Commander/msys64/mingw64/lib</pre></code>

## Our support

UI/UX Designer - **Anthony Hobday**

## Progress so far

<p align="center">
  <img src="https://github.com/Guitarheroua/protomorph-bg/blob/development/doc/img/ApplicationScreenToTrackProgress.png" />
</p>

   
