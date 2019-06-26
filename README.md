# Scribus API

A stable, high level and documented interface to the Scribus core that plugin developers can use to access the Scribus features.


## Install

Clone the `scribus-api` repository and put – or symlink – its `src` directory into `scribus/plugins/` as `api`. Then add to `CMakeLists.txt` file in `scribus/`.

    add_subdirectory(api)

just after `add_subdirectory(third_party)`


and add

	${CMAKE_CURRENT_BINARY_DIR}/api

	set(SCRIBUS_API_LIB "scribus_api_lib")

	${SCRIBUS_API_LIB}

after each similar line containing the `zip` string.



In the [Getting started](https://github.com/aoloe/scribus-manual-development/blob/master/content/getting-started/getting-started.md) manual for Scribus developers, you'll find [more in details instructions](https://github.com/aoloe/scribus-manual-development/blob/master/content/getting-started/getting-started.md#adding-a-plugin-from-a-github-repository).

## Roadmap

- [x] setup the plugin
- [x] activate a first class and method and try to call it from another plugin
- [ ] add lot of doxygen comments
  - each file
  - each class
  - each public method
- [ ] move the epub's plugin `ScribusDocument` class to the `ScribusAPI`
- [ ] make more publicity for this project and find out how to improve its architecture / add more coverage of Scribus features.

## Doxygen documentation

An older a Doxygen documentation of the code is published here:

<http://impagina.org/dox/api/>

The documentation can be created by running (at the root of this repository):

```
doxygen documentation/config.doxygen
```

This creates the html documentation in the `documentation` directory.

You can enable, generate and use the latex files to then create a Pdf version of the documentation with `pdflatex`.
