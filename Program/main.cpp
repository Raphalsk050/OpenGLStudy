#include "../Core/engine.h"
#include "Layers/ProgramLayer.h"

int main() {
  GLStudy::Engine* engine = new GLStudy::Engine();
  engine->Setup();

  // layers
  auto* layer = new GLStudy::ProgramLayer();
  engine->PushLayer(layer);

  //engine->Pause();

  return 0;
}
