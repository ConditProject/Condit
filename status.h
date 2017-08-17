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

  Status(const State& state); 
  Status(const Status& other_status);
  Status& operator=(const Status& status) = default;
  ~Status() = default;
  
  // Method that returns a Status object with an Ok state
  static Status OkStatus();

  // Methods that returns a Status object with an Invalid state
  static Status InvalidError();
  
  operator bool() const { return state_ == OK; }
private:
  State state_;
};

#endif  // STATUS_H
