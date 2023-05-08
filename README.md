<div align="center">
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/actions/workflows/codeql.yml"><img src="https://github.com/Falcion/Plusenzustandsmaschine/actions/workflows/codeql.yml/badge.svg" alt="codeql"/></a>
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/actions/workflows/build.yml"><img src="https://github.com/Falcion/Plusenzustandsmaschine/actions/workflows/build.yml/badge.svg" alt="build (sonarcloud)"/></a>
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/graphs/contributors"><img src="https://img.shields.io/github/contributors/Falcion/Plusenzustandsmaschine" alt="contributors"/></a>
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/stargazers"><img src="https://img.shields.io/github/stars/Falcion/Plusenzustandsmaschine" alt="stargazers"/></a>
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/forks"><img src="https://img.shields.io/github/forks/Falcion/Plusenzustandsmaschine" alt="forks"/></a>
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/issues"><img src="https://img.shields.io/github/issues/Falcion/Plusenzustandsmaschine" alt="issues"/></a>
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/commits"><img src="https://img.shields.io/github/last-commit/Falcion/Plusenzustandsmaschine" alt="commit-activity"/></a>
</div>

<br/>
<div align="center">
    <img src="./.github/images/icon.png" alt="icon" width="160" height="160"/>
    <h3>Plusenzustandsmaschine</h3>
    <p>Sequence your code
    <br/>
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/wiki/"><strong>«Explore the docs»</strong></a>
    <br/>
    <br/>
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/tags/">View tags</a>
    /
    <a href="https://github.com/Falcion/Plusenzustandsmaschine/issues/new?assignees=Falcion&labels=Error&template=issue-about-bug.md&title=ERROR%3A+Enter+the+header+of+an+issue">Report a bug</a>
    </p>
</div>

<!-- README introduction:
 Describe your project from unknown perspective and tell,
 what it does and try to interest contributor or user to
 your project. 
 -->

About the project
-----------------

In many other programming software, like game engines and in mathematics and animations there is a concept of a finite automaton or so-called state-machine: and its what this project does.

Ever wondered about the phasing for your method, displaying different stages and shifts by process of method, so, if there is any error you could check just by endpoint of state-machine? THIS THING DOES IT!

### Built-with

Project was created, inspired and built with this wonderfuls:

- [C++11](https://cplusplus.com/)
- https://visualstudio.microsoft.com/
- https://code.visualstudio.com/
- sophisticated with: https://github.com/angular/angular/

<p align="right"><a href="#readme-top" title="Back to the top of README">[^]</a></p>

Getting started
---------------

Before using this project or working with its source code, read this paragraph so that you wouldn't have unnecessary questions or problems.

### Prerequisites

Before using this application, ensure you met this requirements:

- Any potentional IDE or text-editor with C++11 native support (better if with support for C++ WPF);
- Downloaded at least C++11 SDK on your working machine;
- \* if you desire to contribute to the project, also downloaded [Node.js](https://nodejs.org/) on your machine for integration with commits linting and auto-changelogs;

<p align="right"><a href="#readme-top" title="Back to the top of README">[^]</a></p>

### Installation

Permission is granted for free use in any of your products.

Guide for installation of source code of the class-library:

1. clone the repository with any form of application that supports GIT;
2. initialize linterns, NPM and HUSKY for commitlintering;
3. make your changes via [contributioning policy and commit convention](#contributioning);
4. work as instructed, class-library is ready to be edited in forked repository;

Instruction about working and setting up automatically linted commits and changelog from them, read - [article about Angular.js conventions](https://mokkapps.de/blog/how-to-automatically-generate-a-helpful-changelog-from-your-git-commit-messages/).

Process of installation within DLL packaging system:

1. download DLL of this project either through Github or through some different resources;
2. inject DLL into your C++ project with help of IDEs like VS (which are supporting easy-to-use DLL packaging systems): in other cases, check documentations: see guide by this [guy](https://www.youtube.com/watch?v=ZYLKI8FxiD8).
   1. Download headers, DLL and LIB files from releases or from repository directly (seek "DEBUG" directory);
   2. Create subfolder for library: "includes" and "lib", in first, put all headers, you'll be using them through `#include` and in second, put the `.LIB` file, the DLL put in the code path of your project (within files like `.VCPROJ`);
   3. Set up them with VS Code through `Linker` and `C++/General`: for more advanced tutorial, seek the video-guide.
3. done!

If you use a different IDE without native support for NUGET, read this article: [using new commands in .NET]( https://stackoverflow.com/questions/40675162/install-a-nuget-package-in-visual-studio-code/).

<p align="right"><a href="#readme-top" title="Back to the top of README">[^]</a></p>

Usage
-----

Project, because of its simplicity in core and common overload with functionality for unknown developer, doesn't have any direct idea of usage, but it created to define some processes for your solutions:

- assembler for state-machine with you'll work through;
- inner analyzer for assembler of state-machine (check the state-shift pairs, write changes into custom message system);
- deployment: custom message system with map of key-pos and pair of hash and message, has it own "sublogic" of working;
- default enums, classes which you can use independently from state-machine concept.

If you want to use this project in your own, just install it in and reference it as namespace: nothing special.

<p align="right"><a href="#readme-top" title="Back to the top of README">[^]</a></p>

<!-- Roadmap:
 Create, design and write any roadmap you want: you
 can even delete this paragraph if you don't like big
 planning ideas in your projects.
 -->

Roadmap
-------

- [ ] Create a demo version of this package to demonstrate its future;
- [ ] Refactor the common documentation of project;
- [ ] Refactor the main functionality-code of the package;
- [ ] Implement XML-documentation into the package's code;
- [x] Write an infrastructure in the repository;
- [ ] Design and publish first completed changelog;
- [ ] Publish package as DLL.

<p align="right"><a href="#readme-top" title="Back to the top of README">[^]</a></p>

<!-- Contributioning idea:
 Contributors, contributing guidelines and other: here you can type random 
 contributors or simply write a contributing guideline/reference contributing 
 policy here.
 
 Github is an open source community, so I highly recommend you to setup this 
 block of your project.
 -->

Contributioning
---------------

Contributions are what make open source community such an interest place to be in - so any form of contribution are greatly appreciated.

If you think that you can help this project become better but think its not so important/realizable in the current situtation or for a full contribution, use issues block, otherwise there is a guideline and policy for contributing.

If you want to contribute to this project, please, read contributioning policy and commit convention, this repository works with CLA, commits convention and on automated deployment system.

- [Commit convention](./.github/COMMIT_CONVETION.md);
- [Contributioning policy](./CONTRIBUTING.md);

**For one-single file contributioning, use a more quicker way without forking the repository through website.**

More about it in this article: in [official GIT docs](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/working-with-forks/syncing-a-fork/) about syncing one-file fork.

<p align="right"><a href="#readme-top" title="Back to the top of README">[^]</a></p>

<!-- License:
 Paragraph about distribution policy in this repository and
 here, you can type any distinct references for any content.
 -->

License
-------

Project is being distributed under the [MIT License](https://choosealicense.com/licenses/mit/): see the file for more specified information.

This README was inspired by this - [best README template](https://github.com/othneildrew/Best-README-Template/).

<!-- Contact information:
 Ensure you typed atleast an abstract way to
 reach you for any interested person: in may be
 helpful for those, who are in need or in state
 of emergency.
 -->

<p align="right"><a href="#readme-top" title="Back to the top of README">[^]</a></p>


Contact
-------

Any public contact information for developer either team can be acquired here, in other case, use issues and discussions.

- DEV.TO page of developer: https://dev.to/falcion/

<p align="right"><a href="#readme-top" title="Back to the top of README">[^]</a></p>

<!-- Acknowledgements:
 Paragraph of this created for contributions and
 references to any useful web-resources which you
 could recommend in-case of project themed topic. 
 -->

Acknowledgements
----------------

- https://gitignore.io/
- https://gitattributes.io/
- [README template](https://github.com/othneildrew/Best-README-Template/)

<p align="right"><a href="#readme-top" title="Back to the top of README">[^]</a></p>
