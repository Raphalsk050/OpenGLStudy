#pragma once
#include "Mesh.h"
#include <glm.hpp>
#include <memory>

namespace GLStudy {

class Sphere : public Mesh {
public:
    Sphere(float radius = 0.5f, unsigned int sectors = 16, unsigned int stacks = 16);
    void SetRadius(float r);
    float GetRadius() const { return radius_; }
private:
    void Build();
    float radius_;
    unsigned int sectors_;
    unsigned int stacks_;
};

class Cube : public Mesh {
public:
    Cube(float size = 1.0f);
    void SetSize(float s);

private:
    void Build();
    float size_;
};

class Cylinder : public Mesh {
public:
    Cylinder(float radius = 0.5f, float height = 1.0f, unsigned int sectors = 16);
    void SetRadius(float r);
    void SetHeight(float h);
private:
    void Build();
    float radius_;
    float height_;
    unsigned int sectors_;
};

class Capsule : public Mesh {
public:
    Capsule(float radius = 0.5f, float height = 1.0f, unsigned int sectors = 16, unsigned int stacks = 8);
    void SetRadius(float r);
    void SetHeight(float h);
private:
    void Build();
    float radius_;
    float height_;
    unsigned int sectors_;
    unsigned int stacks_;
};

class Plane : public Mesh {
public:
    Plane(float size = 1.0f);
    void SetSize(float s);
private:
    void Build();
    float size_;
};

}
