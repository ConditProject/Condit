// StatusOr Library
//
// StatusOr is a type for wrapping the value of a computation with a status. A
// function can return StatusOr<T>. You can use the status value to determine
// where your program should continue.
//
// Example use case:
//   StatusOr<Server*> ConstructServer(int port_number) {
//     Do some stuff
//     if (!internal_status.ok()) { return internal_status; }
//     return server_ptr;
//   }
//
//   StatusOr<Server*> server_or_status = ConstructServer(0);  // port 0
//   if (!server_or_status.IsOk()) {
//     std::cerr << "Server failed to initialize." << std::endl;
//     return server_or_status.GetStatus();
//   }
//   Server* s = server_or_status.GetValue();
//   std::cout << "Server listening at port " << s->port_number() << "\n";
//
// Or you can use the ASSIGN_OR_RETURN macro
// Example:
//   (assuming ConstructServer(int) exists...
//   ASSIGN_OR_RETURN(Server* s, ConstructServer(0));

// TODO document expected arg types and when status or will explcitly crash

#ifndef _STATUS_OR_H_
#define _STATUS_OR_H_

#include "status.h"

template <class T>
class StatusOr {
public:  
  StatusOr() = delete;
  StatusOr(const T& value);
  StatusOr(const Status& status);

  StatusOr(const StatusOr<T>& other);
  StatusOr& operator=(const StatusOr<T>& other);

  T GetValue();
  Status GetStatus();
  bool IsOk();
private:
  T* value_;
  Status status_;
};

#define ASSIGN_OR_RETURN(lvalue, statusor)			\
  if (!statusor.IsOk()) { return statusor.GetStatus(); }	\
    lvalue = statusor.GetValue();

// Implementation

template <class T>
StatusOr<T>::StatusOr(const T& value) {
  value_ = new T(value);
  status_ = Status::OkStatus();
}

template <class T>
StatusOr<T>::StatusOr(const Status& status) {
  status_ = status;
  value_ = nullptr;
}

template <class T>
StatusOr<T>::StatusOr(const StatusOr<T>& other) {
  value_ = new T(other.GetValue());
  status_ = other.GetStatus();
}

template <class T>
StatusOr<T>& StatusOr<T>::operator=(const StatusOr<T>& other) {
  return StatusOr<T>(other);
}

template <class T>
T StatusOr<T>::GetValue() {
  if (!IsOk() || !value_) {
    exit(1);
  }
  return *value_;
}

template <class T>
Status StatusOr<T>::GetStatus() {
  return status_;
}

template <class T>
bool StatusOr<T>::IsOk() {
  return status_ == Status::OkStatus();
}

#endif  // _STATUS_OR_H_
