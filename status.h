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

  State State() const;
  std::string Message() const;
  operator bool() const { return state_ == OK; }
private:
  enum State state_;
  std::string message_;
};

#endif  // STATUS_H
