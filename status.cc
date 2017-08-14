#include "status.h"

Status::Status() {
  Ok();
}

void Status::Ok() {
  state_ = State::OK; 
}
