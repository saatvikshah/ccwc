


# ccwc

A simple C++ project with CMake, clang-format, clang-tidy, and GoogleTest integration.

## Dependencies

- CMake >= 3.10
- A C++ compiler that supports C++23 (e.g., GCC 13+, Clang 16+)
- clang-format (optional, for code formatting)
- clang-tidy (optional, for static analysis)
- pre-commit (optional, for automated formatting during commits)

## Building the Project

From the project root:

```bash
cmake -Bbuild -H.
cmake --build build
```

This will build the main `ccwc` binary and any test executables.

## Running the Binary

After building:

```bash
./build/ccwc
```

## Running Tests

From the project root:

```bash
ctest --test-dir build --output-on-failure
```

This will run all tests under the `test/` directory using GoogleTest.

Alternatively, you can run individual test binaries directly, for example:

```bash
./build/test/WordCountTest
```

## Code Formatting and Linting

To format code according to `.clang-format`:

```bash
clang-format -i path/to/file.cpp
```

To manually run clang-tidy checks:

```bash
clang-tidy path/to/file.cpp -- -std=c++23
```

## Pre-commit Hook

Install pre-commit and set up the hook:

```bash
pip install pre-commit
pre-commit install
```

Run `pre-commit run --all-files` to apply formatting and linting checks.

This ensures code is automatically formatted before each commit.