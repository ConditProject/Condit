#include "status.h"

Status::Status() {
  state_ = OK;
}

Status::Status(const enum State& state, std::string message) {
  state_ = state;
  message_ = message;
}

Status::Status(const Status& other_status) {
  state_ = other_status.state_;
}

Status Status::OkStatus() {
  return Status(OK, ""); 
}

Status Status::InvalidError(std::string message) {
  return Status(INVALID, message); 
}
