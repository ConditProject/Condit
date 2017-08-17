#include "status.h"

Status::Status() {
  state_ = OK;
}

Status::Status(const State& state) {
  state_ = state;
}

Status::Status(const Status& other_status) {
  state_ = other_status.state_;
}

Status Status::OkStatus() {
  return Status(OK); 
}

Status Status::InvalidError() {
  return Status(INVALID); 
}
