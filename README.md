# Condit
<div align="center">
<img src = https://raw.githubusercontent.com/samiurkh1n/Condit/master/resources/logo.png>
</div>

[![Build Status](https://travis-ci.org/samiurkh1n/Condit.svg?branch=master)](https://travis-ci.org/samiurkh1n/Condit)

[![Coverage Status](https://coveralls.io/repos/github/samiurkh1n/Condit/badge.svg?branch=master)](https://coveralls.io/github/samiurkh1n/Condit?branch=master)

A status tracking library for C++ binaries. The library was inspired by the Status library found in the core library of Google's Tensorflow and gRPC and protocol buffer repos. 

## Purpose
Condit is a C++ status tracking type. Libraries and software developers often
return different integers (-1, 0, 1) to track the status of a binary. However,
that doesn't provide any useful information to a developer trying to debug a
broken binary.

## Design Doc and Decisions
Here is the [design doc](https://goo.gl/LGaKtz). Any suggestions welcome!

## Example
```cpp
Status SomeComputation(const double& result, int x, int y) {
  if (!IsInputValid(x) || !IsInputValid(y)) {
    return InvalidStatus("Input is invalid");
  }
  result = x + y;
  return OkStatus();
}
```

## License
The project is under the Apache License. Please read [LICENSE](LICENSE) for more information. 

## Documentation
Check out the documentation in the [header](status.h) file.

## Contributing
Check [CONTRIBUTING.md](CONTRIBUTING.md) for more information about contributing.

## Contact
My email is samiurkh1n@gmail.com. Email me if you would like to contribute
or if you see something off with the documentation, code, anything...
