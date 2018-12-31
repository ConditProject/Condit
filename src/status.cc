#include "../includes/status.h"

Status::Status() {
  state_ = OK;
}

Status::Status(const enum State& state, std::string message)
  : state_(state), message_(message) {} 

Status Status::OkStatus() {
  return Status(OK, ""); 
}

Status Status::CancelledError(std::string message) {
  return Status(CANCELLED, message); 
}
Status Status::InvalidError(std::string message) {
  return Status(INVALID, message); 
}
Status Status::NotFoundError(std::string message) {
  return Status(NOT_FOUND, message); 
}
Status Status::AlreadyExistsError(std::string message) {
  return Status(ALREADY_EXISTS, message); 
}
Status Status::OutOfRangeError(std::string message) {
  return Status(OUT_OF_RANGE, message); 
}
Status Status::FailedPreconditionError(std::string message) {
  return Status(FAILED_PRECONDITION, message); 
}
Status Status::UnimplementedError(std::string message) {
  return Status(UNIMPLEMENTED, message); 
}
Status Status::UnknownError(std::string message) {
  return Status(UNKNOWN, message); 
}
