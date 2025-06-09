#include "../Core/engine.h"
#include "Layers/ProgramLayer.h"

int main() {
  GLStudy::Engine& engine = GLStudy::Engine::Get();

  // layers
  auto* program_layer = new GLStudy::ProgramLayer(&engine);
  engine.PushLayer(program_layer);
  engine.Setup();
  return 0;
}
