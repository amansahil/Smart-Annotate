# Code Contribution and Maintenance Guide

## Quick Start

The project requires:

- `Qmake version >= 3.0`
- `Qt version >= 4.0` with `Core`, `Gui` enabled.
- `c++11`
- `doxygen v1.8.17`

### Resources

- [Qt](https://doc.qt.io)
- [qmake](https://doc.qt.io/qt-5/qmake-manual.html)
- [doxygen](http://www.doxygen.nl)

## Reporting Issues

To report a bug, use the GitHub issue tracker to create a report. Ensure that you have searched similar topics and that there are no duplicate topics pertaining to your case. Please don't use the issue tracker for support questions.

### Writing a good bug report

Ensure the title is clear, short and to the point. In the body of the issue be as descriptive as possible and provide as much detail as you can. Write steps to recreate the problem you ran into and also include what behaviour you expected to see instead. Include screenshots of the issue or GIFS of you recreating the issue if possible. If you are using a pre-compiled version of the application mention the OS version and name. If you are compiling using release binaries mention the version of QT and the OS Verison and name. And finally, if you are using the QT IDE to generate binaries and run the code, try running the code in debugging mode and include the debug logs or any screenshots of any notification the debugger throws.

### Template

```
## Description:

**QT Version**:

**OS Name and Version**:

## Steps to reproduce

## Expected Results

## Images

## Debugger log
```

## Suggesting a feature or enhancement

To suggest a feature or enhancement use the GitHub issue tracker to create a report. Ensure that you have searched similar topics and that there are no duplicate topics pertaining to your suggestion. If it is a small enhancement to the code, simply open a pull request with details on the enhancement in the pull request description (Please follow the [PR guidelines](https://github.com/amansahil/Group_24_SDI_SOFT20091/blob/master/DOCS/CONTRIBUTION.md#pull-requests) when doing so).

### Writing a good suggestion

When suggesting a feature/enhancement ensure the description is clear. Include why the feature/enhancement is needed and how it would be implemented/used. If the feature/enhancement requires changes to the UI please provide if possible a GUI mockup of such an implementation.

## Pull Requests

### Guidelines

- Ensure you have read the [Commit guidelines](https://github.com/amansahil/Group_24_SDI_SOFT20091/blob/master/DOCS/CONTRIBUTION.md#commit-guidelines) and [Branch guidelines](https://github.com/amansahil/Group_24_SDI_SOFT20091/blob/master/DOCS/CONTRIBUTION.md#branch-guidelines) subsection of this section.
- Ensure you have followed standards in the [Code Standards](https://github.com/amansahil/Group_24_SDI_SOFT20091/blob/master/DOCS/CONTRIBUTION.md#code-standards) section
- Ensure cross-platform compatibility for Windows, Ubuntu and Mac
- Write a descriptive pull request title
- If there were any UI based changes please include screenshots in the pull request description
- If there were any changes to the flow please attach a video in the pull request description
- Please add tests for any new methods created
- Please add documentation for any new methods or data members
- If there was a need to update existing tests mention why in the description
- Ensure all tests pass before submitting your pull request
- If you use a hack or workarounds from the internet, attach the link
- Attach Trello link or Github issue tracker link if relevant
- **Important** : Use `git rebase` instead of `git merge` to sync your branch
- Attach the checklist below and ensure all boxes are ticked

```
V2

- [ ] All curly braces are on a new line for multiline code
- [ ] No unsued includes
- [ ] No unsued variables
- [ ] For variables that aren't reassigned use const
- [ ] For methods that aren't manipulating any state use const
- [ ] Used proper spacing between code
- [ ] Used QT containers where possible
- [ ] All methods are documented by Doxygen
- [ ] Removed asserts and qDebug
```

### Template

```
**Description**:

**Checklist**:

V2

- [ ] All curly braces are on a new line for multiline code
- [ ] No unsued includes
- [ ] No unsued variables
- [ ] For variables that aren't reassigned use const
- [ ] For methods that aren't manipulating any state use const
- [ ] Used proper spacing between code
- [ ] Used QT containers where possible
- [ ] All methods are documented by Doxygen
- [ ] Removed asserts and qDebug

**Trello or github issue link**:

**Images and videos**:

```

### Commit guidelines

- The commit message should be no more than 72 characters

- Commits should regularly be done for single units of work (function-based instead of functionality based), do not cram too many changes into one commit

- Capitalise the subject line

- Ensure updates to tests are on a separate commit and follow conventions shown in below examples

  Eg for new tests: `Added new tests for foo`

  Eg for existing tests: `Updated existing test to accommodate bar`

- Ensure updates to documentation are on a separate commit and follow convention shown in below example

  Eg: `Updated docs`

- Examples of good commit messages:

  - `Added method to determine the aspect ratio of an image`

  - `Code style refactor for bar`

  - `Refactor of foo method for better readability`

  - `Removed unused variable in bar`

- Example of bad commits:

  - `Refactor`

  - `Fixes`

  - `Added image edit method`

### Branch guidelines

When creating a branch on the GitHub repository ensure the branch name is a short concise name which uses kebab case relative to the feature or fixes being added, with the last section of the name identifying what type of pull request it is.

Eg for features: `image-resize-feature`

Eg for enhancement: `resize-method-enhancement`

Eg for fixes: `image-resize-crash-fix` or `unresponsive-save-button-fix`

## Maintaining Documentation

Doxygen is used to auto-generate the documentation. Ensure you have the correct version of doxygen installed. Documentation can be updated using the following command.

```sh
doxygen doxyfile.cfg
```

### Guidelines

- Ensure you have read the [Documenting code](https://github.com/amansahil/Group_24_SDI_SOFT20091/blob/master/DOCS/CONTRIBUTION.md#documenting-code) subsection
- Please add documentation for any new methods or data members
- Ensure updates to documentation are on separate commit

### Documenting code

Use the Qt style comment block to document code

- `//!` - For classes, data memebers and enums
- `/*!` - For member functions
- `/*!<` - For enum values

Eg:

```cpp

//! A nice short description of what the class is responsible for
class someClass;

//! A nice short description of what state the enum is used to identify
enum someEnum {
    SomeValue /*!< A short descrition of what the value means */
};

//! A nice short description of what information the container holds
int someValue;

/*!
 *  A nice short description of the function does, two spaces away from the astrix
 */
void sumeFunc();

```

## Code Templates

### Model

Naming: `example_model`, with first section sharing the same name as the controller class name

```cpp
class ExampleModel : public QObject
{

    Q_OBJECT

public:
    explicit ExampleModel(QObject *parent = 0);
}
```

### Controller

Naming: `example`

```cpp
class Example : public QMainWindow
{
    Q_OBJECT;

    // Listeners & UI Methods

public:
    explicit Example(QWidget *parent = nullptr);
    ~Example();

    // Controller Methods
}
```

### Custom container

Naming: `string_containertype.cpp`

```cpp
class ContainerTypeNode {};

class StringContainerType {};
```

## Code Standards

Follow [google guidelines](https://google.github.io/styleguide/cppguide.html) unless explicitly mentioned below

Code can be kept neat with linters and analysis tool. Below are some recommendations:

- [Microsoft CPP](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

- [cppcheck](http://cppcheck.sourceforge.net/) with below arguments

```sh
cppcheck --enable=all --inconclusive --std=posix example.cpp
```

### Code Philosiphy

_"SOLID principles sounded to me like extremely bureaucratic programming that came from the mind of somebody that has not written a lot of code, frankly"_ - Stack Overflow chairman (Joel Spolsky)

**Note :** We think SOLID is great but know when not to use it.

### General guidelines

- Don't add any classes to the codebase unless absolutely needed. Best way to go about this is, don't add empty abstract classes before you implement certain functionality, create classes if necessary as you go along

- Use QT containers instead of CPP STL containers unless it's being used in a custom container

- Check if QT has existing functionality for the problem before implementing custom functionality or adding external libraries

- Composition over inheritance

### General style guidelines

- Use proper tabulation of 4 spaces, do not to tabulate access identifiers

Eg:

```cpp
class someclass
{
public:
    void someFunction();
};

```

- Attach asterisk or ampersand to the variable name instead of the container name

Eg:

```cpp
// Use this
    int *bar;

// Instead of
    int* bar;

```

- Use inline functions for code that is only one line

- Curly braces should be on a new line unless it's an inline function

- If variables aren't being reassigned use const

- If methods that aren't manipulating any state use const

- Use CPP foreach loop instead of an incrementor unless necessary

Eg:

```cpp
// Use this
for (const auto &e: someList )
{

}

// Intstead of
for (int i = 0; i < someList.length(); i++)
{

}

```

- Do not use declarations in a header file

- Use include guards

- Avoid magic numbers

- Use the `define directive` when declaring a global variable where possible

### Naming guidelines

**File Names**: Snake case

**Classes**: Initial capital and then camel case

**Enums**: Initial capital and then camel case

**EnumValues**: Initial capital and then camel case

**Struct**: Initial capital and then camel case

**Functions**: Camel case

**Variables**: Camel case

**Constants**: All caps and snake case

### Header file guidelines

- Only add includes to header files instead of CPP files unless necessary

- Use double quotes when including custom files and angled brackets when including library files

- The order is custom includes first then library includes

Eg:

```cpp

#include "example.h"
#include "someotherexample.h"


#include <vector>
#include <QObject>
```

- Have sensible for ordering members in header files

- The order priority for header file is `sub-classes`, `public`, `protected` and then finally `private`

- The order for members is `enums`, `structs`, `data members` and finally `member functions`

Eg:

```cpp

class exampleClass
{
private:
    class subClass
    {
        //...
    };

public:
    void somePublicFunc();

protected:
    int someVariable;

    void someProtectedFunc();

private:
    void somePrivateFunc();
}
```

### CPP file guidelines

- Order function in CPP files according to the order in the header file

### Post-increment vs Pre-increment

- This codebase uses post-increment instead of pre-increment solely for styling and consistency purposes

### Exceptions guidelines

- Avoid using asserts as they take a toll on performance, remove all asserts before submitting a pull request

- Generally, try to write exceptionless code and only throw an exception in case of a disaster
