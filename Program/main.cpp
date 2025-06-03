#include "../Core/engine.h"
#include "Layers/ProgramLayer.h"

int main() {
  GLStudy::Engine* engine = new GLStudy::Engine();

  // layers
  auto* layer = new GLStudy::ProgramLayer();
  engine->PushLayer(layer);

  engine->Setup();

  //engine->Pause();

  return 0;
}
