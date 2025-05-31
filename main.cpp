#include "Core/engine.h"

int main() {
  GLStudy::Engine* engine = new GLStudy::Engine();
  engine->Setup();
  engine->Pause();

  return 0;
}
