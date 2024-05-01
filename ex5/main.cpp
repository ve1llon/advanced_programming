#include <iostream>
#include "log.h"

int main(void) {

      Log* log = Log::Instance();

      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_REMARK, "Unused variables");
      log->message(Log::Importance_level::LOG_ERROR, "error happens! help me!");
      log->message(Log::Importance_level::LOG_ERROR, "error happens! help me!");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_REMARK, "Unused variables");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_ERROR, "error happens! help me!");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_ERROR, "Strange behavior");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_REMARK, "Possible memory loss");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_ERROR, "error happens! help me!");
      log->message(Log::Importance_level::LOG_ERROR, "error happens! help me!");
      log->message(Log::Importance_level::LOG_ERROR, "сrocodile in the toilet");
      log->message(Log::Importance_level::LOG_ERROR, "error happens! help me!");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_REMARK, "Unused variables");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_REMARK, "Unused variables");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_REMARK, "Unused variables");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_ERROR, "Strange behavior");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_REMARK, "Possible memory loss");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_ERROR, "Strange behavior");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_REMARK, "Unused variables");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_ERROR, "error happens! help me!");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->message(Log::Importance_level::LOG_NORMAL, "program loaded");
      log->print();
}

