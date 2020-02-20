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

To report a bug use the github issue to create a report. Ensure that you have searched similar topics and that there are no duplicate topics pertaining to your case. Please don't use the issue tracker for support questions

### Writing a good bug report

Ensure the title is clear, short and to the point. In the body of the issue be as descriptive as possible and provide as much detail as you can. Write steps to recreate the problem you ran into and also include what behaviour you expected to see instead. Include screenshots of the issue or GIFS of you recreating the issue if possible. If you are using a pre-compiled version of the application mention the OS version. If you are compiling using release binaries mention the version of QT and the OS Verison. And finally if you are using the QT IDE to generate binaries and run the code, try running the code in debugging mode and include the debug logs or any screenshots of any notification the debugger throws.

### Template 

```
**Description**:

**QT Version**:

**OS Version**:

## Steps to reproduce

## Expected Results

## Images

## Debugger log
```

## Pull Requests

### Guidelines

- Ensure you have read the `Commit guidelines` and `Branch guidelines` sub section of this section.
- Ensure you have followed standards in the `Code Standards` seciton
- Ensure cross platform compatibility for Windows, Ubuntu and Mac
- Write a descriptive pull request title
- If there were any UI based changes please include screenshots in the pull request description
- If there were any changes to the flow please attach a video in the pull request description
- Please add tests for any new methods created
- Please add documentation for any new methods or data memebers 
- If there was a need to update exisiting tests mention why in the descrption
- Ensure all tests pass before submitting your pull request 
- If you use a hack or workarounds from the internet, attach the link
- Attach trello link or issue tracker link if relevant
- **Important** : Use `git rebase` instead of `git merge` to sync your branch
- Attach the checklist below and ensure all boxes are ticked

```
V2

- [ ] All curly braces are on a new line for multline code
- [ ] No unsued includes
- [ ] No unsued variables
- [ ] For vairables that aren't reassigned use const
- [ ] For methods that aren't mainpulating any state use const
- [ ] Used proper spacing between code
- [ ] Used QT containers where possible
- [ ] All methods are documnetated by Doxygen
- [ ] Removed asserts and qDebug
```

### Template

```
**Description**:

**Checklist**:

V2

- [ ] All curly braces are on a new line for multline code
- [ ] No unsued includes
- [ ] No unsued variables
- [ ] For vairables that aren't reassigned use const
- [ ] For methods that aren't mainpulating any state use const
- [ ] Used proper spacing between code
- [ ] Used QT containers where possible
- [ ] All methods are documnetated by Doxygen
- [ ] Removed asserts and qDebug

**Trello or github issue link**: 

**Images and videos**:

```

### Commit guidelines

- The commit message should be no more than 72 characters

- Commits should regurarly and be done for single units of work (function based instead of functionality based), do not cram too many changes into one commmit

- Capitlise the subject line

- Ensure updates to tests are on a seperate commit and follow conventions shown in below examples

    Eg for new tests: `Added new tests for foo`

    Eg for exisitng tests: `Updated exisiting test to accomodate bar`

- Ensure updates to documentation are on a seprate commit and follow convention shown in below example

    Eg: `Updated docs`

- Examples of good commit messages:

    - `Added method to determine aspect ratio of image`

    - `Code style refactor for bar`

    - `Refactor of foo method for better readability`

    - `Removed unused variablie in bar`

- Example of bad commits: 

    - `Refactor`

    - `Fixes`

    - `Added image edit method`

### Branch guidelines

When creating a branch on the github repository ensure the branch name is a short concise name which uses kebab case relative to the feature or fix being added, with last section of the name identifying what type of pull request it is.

Eg for features: `image-resize-feature`

Eg for fixes: `image-resize-crash-fix` or `unresponsive-save-button-fix`

## Maintaining Documentation

Doxygen is used to auto generate the documentation. Ensure you have the correct version of doxygen installed. Documentation can be updated using the following command.

```sh
doxygen doxyfile.cfg
```

### Guidelines

- Ensure you have read the `Documenting code` subsection
- Please add documentation for any new methods or data memebers 
- Ensure updates to documentation are on seperate commit

### Documenting code

Use the Qt style comment block to document code

- `//!` - For classes, data memebers and enums
- `/*!` - For member functions
- `/*!<` -- For enum values

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

Naming: `example_model`, with first section represeting the controller class name 

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

Code can be kept neat with linters and analysis tool. Below are recommendations: 

- [Microsoft CPP](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)

- [cppcheck](http://cppcheck.sourceforge.net/) with below arguments

```sh
cppcheck --enable=all --inconclusive --std=posix example.cpp
```

### Code Philosiphy

Here are three quotes that sum up the philosiphy for the coding style used

"Premature optimization is the root of all evil"

"Don't have architecture for the sake of architecture"

"SOLID principles sounded to me like extremely bureaucratic programming that came from the mind of somebody that has not written a lot of code, frankly" - Stack overflow chairman (Joel Spolsky)

### General guidelines

- Don't add any classes to the codebase unless absolutely needed. Best way to go about this is, don't add empty abstract classes before you implement a certain functionality, create classes if necessary as you go along 

- Use QT containers instead of cpp stl containers unless creating a custom container

- Check if QT has exisitng functionality for the problem before implementing custom functionality or adding external libraries

- Composition over inheritance

### General style guidelines

- Use proper tabulation of 4 spaces, do not to tabualte access identifiers

Eg:

```cpp
class someclass {
public:
    void someFunction();    
};

```

- Attach astrix for pointers to the variable name instead of the container name

Eg:

```cpp
// Use this 

    int *bar;

// Instead of

    int* bar;

```

- Use inline functions for code that is only one line

- Curly braces should be on a new line unless it's a inline function

- If variables aren't being reassigned use const

- If methods that aren't mainpulating any state use const

- Use cpp foreach loop instead of a incrementor unless necessary  

Eg:

```cpp
// Use this
for (const auto &e: someList ) {

}

// Intstead of 

for (int i = 0; i < someList.length(); i++) {

}

```

- No using declarations in header file

- Use include guards

- Avoid magic numbers

- Use the `define directive` when decleraing global variable where possible

### More guidelines

#### Naming conventions

**Classes**: Initial capital and then camel case

**Enums**: Initial capital and then camel case

**EnumValues**: Initial capital and then camel case

**Struct**: Initial capital and then camel case

**Functions**: Camel case

**Variables**: Camel case

**Constants**: All caps and snake case

#### Header files 

- Only add includes to header files instead of CPP files unless necessary 

- Use double quotes when incuding custom files and angled bracked when including library files

- The order is custom includes first then library includes

Eg:

```cpp

#include "example.h"
#include "someotherexample.h"


#include <vector>
#include <QObject>
```

- Have sensible for ordering members in header files

- The order priority for header file are `sub-classes`, `public`,  `protected` and then finally `private`

- The order for memebers is `enums`, `structs`, `data members` and finally `member functions`

Eg:

```cpp

class exampleClass {
private:
    class subClass {};

public:
    void somePublicFunc();

protected:
    int someVariable;

    void someProtectedFunc();

private:
    void somePrivateFunc();
}
```

#### CPP files

- Order function in cpp files according to the order in header file

#### Post increment vs Pre increment

This code base uses post increment instead of pre increment soly for styling and consistency purposes


#### Handling exception

- Avoid using asserts as they take toll on performance
- Generally try write exceptionless code and only throw exception incase of a disaster  