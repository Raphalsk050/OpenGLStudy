#include "../Core/engine.h"
#include "Layers/ProgramLayer.h"

int main() {
  GLStudy::Engine* engine = new GLStudy::Engine();

  // layers
  auto* program_layer = new GLStudy::ProgramLayer();
  engine->PushLayer(program_layer);
  engine->Setup();
  return 0;
}
