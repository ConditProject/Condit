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
// The library was inspired by the Status library found in the core library
// of Google's Tensorflow and gRPC and protocol buffer repos. 
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
enum State {
  OK = 0,  
  CANCELLED = 1,  
  INVALID = 2,  
  NOT_FOUND = 3, 
  ALREADY_EXISTS = 4, 
  OUT_OF_RANGE = 5,  
  FAILED_PRECONDITION = 6, 
  UNIMPLEMENTED = 7, 
  UNKNOWN = 8  
};

class Status {
public:
  // Default constructor creates an object with an Ok state
  Status();

  Status(const enum State& state, std::string message); 
  Status(const Status& other_status) = default;
  Status& operator=(const Status& status) = default;
  ~Status() = default;

  // Method that returns states - you can call these from anywhere.
  static Status OkStatus();
  static Status CancelledError(std::string message);
  static Status InvalidError(std::string message);
  static Status NotFoundError(std::string message);
  static Status AlreadyExistsError(std::string message);
  static Status OutOfRangeError(std::string message);
  static Status FailedPreconditionError(std::string message);
  static Status UnimplementedError(std::string message);
  static Status UnknownError(std::string message);

  // Getters
  enum State State() const { return state_; }
  std::string Message() const { return message_; }
  bool IsOk() const { return state_ == OK; }

  operator bool() const { return state_ == OK; }
private:
  enum State state_;
  std::string message_;
};

#endif  // STATUS_H
