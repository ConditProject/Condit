// Status, a status-tracking object for C++ binaries
//
// An instance of the Status class holds two pieces of data.
//  1. The state of the program (ex: Ok, Invalid, Unknown, NotFound, etc...)
//  2. A description of the state
//
// The Status object packages the information together to allow for robust
//  software (where the paths an executable can take are well defined) that
//  is more readable. The status object is an alternative to using integers
//  or bools for tracking the state of a program.
//
// Use cases:
// 
// (_) Status can be the return type of a program -
// Status SomeComputation(...) {
//   do_some_computing()
//   something something 42
//   return Status::OkStatus();
// }
//
// (_) Status can be used in program decision making -
// Status program_state;
// if (program_state) {
//   do_this_set_of_computation();
// }

#ifndef STATUS_H_
#define STATUS_H_

#include <string>

// Enum to hold possible states
// TODO(samiurkh1n): Include more states when available
enum State {
  OK = 0,
  INVALID = 1,
};

class Status {
public:
  // Default constructor creates an object with an Ok state
  Status();

  Status(const enum State& state, std::string message); 
  Status(const Status& other_status);
  Status& operator=(const Status& status) = default;
  ~Status() = default;
  
  // Method that returns states
  static Status OkStatus();
  static Status InvalidError(std::string message);

  enum State State() const { return state_; }
  std::string Message() const { return message_; }
  
  operator bool() const { return state_ == OK; }
private:
  enum State state_;
  std::string message_;
};

#endif  // STATUS_H
