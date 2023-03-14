#ifndef TIMER_H_
#define TIMER_H_

#include <chrono>   // for measuring runtimes

// This class can be used to time any block of code.
//
// With a Timer object named t (for example),
// call t.go() before the code you want to time,
// and call t.end() right after that code.  The
// return value of t.end() is the running time in
// seconds.
class Timer {
  public:
    Timer() : start_() {}
    void go() {
      this->start_ = std::chrono::system_clock::now();
    }
    double end() {
      auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::system_clock::now() - this->start_
      );
      return elapsed.count() / 1000000.0;
    }

  private:
    std::chrono::system_clock::time_point start_;
};

#endif