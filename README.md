# Condit

<div align="center">
<img src = https://raw.githubusercontent.com/samiurkh1n/Condit/master/resources/logo.png>
</div>

[![Build Status](https://travis-ci.org/samiurkh1n/Condit.svg?branch=master)](https://travis-ci.org/samiurkh1n/Condit) [![Join the chat at https://gitter.im/condit-status-tracker/Lobby](https://badges.gitter.im/condit-status-tracker/Lobby.svg)](https://gitter.im/condit-status-tracker/Lobby?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge) [![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)

A status tracking object. The library was inspired by the Status library found in the core library of Google's Tensorflow and gRPC and protocol buffer repos. 

## Purpose
Condit is a status tracking type. Libraries and software developers often
return different integers (-1, 0, 1) to track the status of a binary. However,
that doesn't provide any useful information to a developer trying to debug a
broken binary. The Status object packages two pieces of information: a program state and a description of that state. 

Condit is a C++ library that provides two types: Status and StatusOr which helps you write more
defensive programs. A lot of legacy code often returns an integer to track the state of a binary.
However, integers aren't that clear of an indicator of error. 
Condit attempts to provide a type that makes debugging and error handling clearer.

## Status Library Example
```cpp
Status SomeComputation(const double& result, int x, int y) {
  if (!IsInputValid(x) || !IsInputValid(y)) {
    return InvalidStatus("Input is invalid");
  }
  result = x + y;
  return OkStatus();
}
```

## StatusOr Library Example
```cpp
StautsOr<Server*> StartServer(int port) {
	// Do stuff
	if (!status_of_computation_from_before.IsOk()) {
		std::cerr << "An error occurred, check logs\n";
		return status_of_computation_from_before;
	}
	return new_port;
}

StatusOr<Server*> server_or_status = StartServer(0);
if (!server_or_status.IsOk()) {
	log << "Error: " << server_or_status.GetStatus();
	return -1;
}
Server* s = server_or_status.GetValue();
std::cout << "Serving at port " << s->PortNumber();
```
or if you wish to use ASSIGN_OR_RETURN...
```cpp
ASSIGN_OR_RETURN(Server* s, StartServer(port));
```

## Build and Test Instructions
```bash
$ git clone https://github.com/samiurkh1n/Condit
$ git submodule update --init --recursive  # To get all third party dependencies
$ mkdir build
$ cd build
$ cmake ..
```
Testing on Linux:
```bash
# if you want to run tests
$ ./tests/status_test
$ ./tests/status_or_test
```
Testing on Windows: CMake should've generated an ALL_BUILD solution file. Open
that with Visual Studio and run the Debug build of any desired target with an
executable.

## License
The project is under the Apache License. Please read [LICENSE](LICENSE) for more information. 

## Documentation
Check out the documentation in the header files located in the include directory.

## Contact
My email is samiurkh1n@gmail.com. Email me if you would like to contribute
or if you see something off with the documentation, code, anything...
