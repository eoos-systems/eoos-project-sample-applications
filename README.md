# EOOS Automotive Sample Applications
---
**EOOS copyrights reserved in [Rospatent Federal Service for Intellectual Property]( https://www1.fips.ru/registers-doc-view/fips_servlet?DB=EVM&DocNumber=2017664105&TypeFile=html), Russian Federation**

EOOS Automotive is a system for **cross-platform development** of applications in **automotive sphere** 
which is developed within **ISO C++ standards**, complied with **MISRA C++:2008** and 
**AUTOSAR C++14 Coding Guidelines**, and relies on **ISO 26262**

EOOS provides API to develop embedded software for **real time safety-critical systems** and can be **ported** 
not only **on many MCUs and DSPs**, but also **supports POSIX and WIN32 systems**.

This **EOOS Sample Applications** give fast start for developing **safety-critical applications**. 
Using EOOS, **business-logic** of applications can be developed on **any Linux or Windows operating systems**, 
and **debuged and tested** either on **real hardware under EOOS Automotive RT**, or 
on **a safety-certified OS** like **QNX**.

The sample applications can be built within an EOOS Automotive system, which can be:
- **[EOOS Automotive WIN32](https://gitflic.ru/project/baigudin-software/eoos-project-if-win32)**
- **[EOOS Automotive POSIX](https://gitflic.ru/project/baigudin-software/eoos-project-if-posix)**
- **EOOS Automotive RT** migration soon based on [BOOS Core R3](https://gitflic.ru/project/baigudin/boos-core-rev3).

---

## 1. How-to Build Sample Applications

All the Sample Applications are built by one root CMake project, but each CMake target of each application 
can be built independly, and this project can be revised as an example that can be easily modified for 
purpose to fast start for developing a new production project.

#### 1.1. Prerequisites

Prerequisites to build the project depend on EOOS is used. Thus, to get appropriate prerequisites, 
please read Prerequisites chapters for a system you try to build the Sample Applications.

#### 1.2. Obtain Git Repository

This chapter will describe common approach for a system terminal, which can be different depending 
on operating system chosen for developing. Thus, to generalize the approach here, we will give examples 
for *Bash* that can be executed on Linux as well as on Windows.

###### 1.2.1. Create an empty directory somewhere on your disk

For instance we will create *REPOSITORY*.

```
$ mkdir REPOSITORY
$ cd REPOSITORY
REPOSITORY$
```

###### 1.2.2. Clone this repository

For instance we will clone it to *APPS* directory by SSH.

```
REPOSITORY$ git clone --branch master git@gitflic.ru:baigudin-software/eoos-project-sample-applications.git APPS
```

###### 1.2.3. Go the APPS directory

```
REPOSITORY$ cd APPS
```

#### 1.3. Source Code Build

###### 1.3.1. Script build

EOOS based applications can be built on various systems. To standardize the building process, 
we put most common steps under the hood of the `Make.py` cross-platform script that is located 
in `scripts/python` directory.

To build sample application you can execute the next commands.

```
~/REPOSITORY/EOOS$ cd scripts/python
~/REPOSITORY/EOOS/scripts/python$ python3 Make.py --clean --build --config RelWithDebInfo
```

###### 1.3.2. Manual build

**Note:** Before building, if *build* directory exists, you can remove it by executing the command below.

```
REPOSITORY/APPS$ rm -rf build
```

To build the project you have to execute the commands below.

```
REPOSITORY/APPS$ mkdir build
REPOSITORY/APPS$ cd build
REPOSITORY/APPS/build$ cmake ..
REPOSITORY/APPS/build$ cmake --build . --config RelWithDebInfo
```

**Note:** The *--config* parameter can be set *Release*, *Debug*, *RelWithDebInfo*, *MinSizeRel* configurations, but this configuration must match the EOOS configuration installed on 
your operating system.

## 2. How-to Execute Sample Applications

#### 2.1. Hello, World Application

The application is located after the project is built on 
- Linux: *REPOSITORY/APPS/build/codebase/app-hello-world* (in the examples below)
- Windows: *REPOSITORY/APPS/build/codebase/app-hello-world/RelWithDebInfo*

We need to go to the application directory by executing the command below.

```
REPOSITORY/APPS/build$ cd codebase/app-hello-world
```

The application writes its input arguments to *stdout*.

```
REPOSITORY/APPS/build/codebase/app-hello-world$ ./EoosAppHelloWorld Think Create Win
Hello, World!
Your program name is EoosAppHelloWorld
You've got the next directives from God:
Directive 1: Think
Directive 2: Create
Directive 3: Win
```

The application writes message to *stdout* if no input arguments passed.

```
REPOSITORY/APPS/build/codebase/app-hello-world$ ./EoosAppHelloWorld
Hello, World!
Your program name is EoosAppHelloWorld
God has pity on you :)
```

The application writes message to *stderr* if wrong number of input arguments passed.

```
REPOSITORY/APPS/build/codebase/app-hello-world$ ./EoosAppHelloWorld Think Create Win Destroy
Goodbye, World.
You do not want more than three God's directives given.
```
