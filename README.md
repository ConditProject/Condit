# Condit
A status tracking library for C++ binaries.

## Purpose
Condit is a C++ status tracking type. Libraries and software developers often
return different integers (-1, 0, 1) to track the status of a binary. However,
that doesn't provide any useful information to a developer trying to debug a
broken binary.

## Design Doc and Choices
Here is the [design doc](https://goo.gl/LGaKtz). Any suggestions welcome!

## Example
```cpp
Status SomeComputation(const double& result, int x, int y) {
  if (!IsInputValid(x) || !IsInputValid(y)) {
    return InvalidStatus("Input is invalid");
  }
  result = x + y;
  return Ok();
}
```

## License
The project is under the GNU General Public License (version 3). Please read
LICENSE for more information. 

## Documentation
TODO(samiurkh1n): Add documentation when available. 

## Installation and Testing
TODO(samiurkh1n): Add installation and testing guide when available. 