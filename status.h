#ifndef STATUS_H_
#define STATUS_H_

#include "state.h"

class Status {
public:
  Status();
  void Ok();

  operator bool() const { return state_ == State::OK; }
private:
  State state_; 
};

#endif  // STATUS_H
