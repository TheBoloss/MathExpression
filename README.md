# 🧮 MathExpression

_A math expression calculator_

![command](https://i.imgur.com/TARPoty.png)

----

## Usage

### Download binary

You can download the compiled binary from the [Releases](https://github.com/TheBoloss/MathExpression/releases) page.

If you encounter issues with libraries, or if you want to build your own binary, you can follow the next section [Build](#build).

### Build

To build the app, you need to have CMake and Make installed.

- Clone the repo
```
git clone https://github.com/TheBoloss/MathExpression.git
cd MathExpression
```

- Build the project
```
mkdir build && cd build
cmake ..
make
```

- _(Optional)_ Debug or Release build types

You can set the build type according to your needs:

```
cmake -DCMAKE_BUILD_TYPE=Debug ..
# or
cmake -DCMAKE_BUILD_TYPE=Release ..
```

### Run

```
./math "3 * 2 + 4 * 9"
```