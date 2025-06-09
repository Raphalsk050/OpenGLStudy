#include "Primitives.h"
#include <vector>
#include <gtc/type_ptr.hpp>
#include <cmath>

namespace GLStudy {

Sphere::Sphere(float radius, unsigned int sectors, unsigned int stacks)
    : radius_(radius), sectors_(sectors), stacks_(stacks) {
    Build();
}

void Sphere::SetRadius(float r) { radius_ = r; Build(); }

void Sphere::Build() {
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    for(unsigned int i=0;i<=stacks_;++i){
        float stackAngle = glm::pi<float>() * ((float)i / stacks_ - 0.5f);
        float xy = cos(stackAngle);
        float z = sin(stackAngle);
        for(unsigned int j=0;j<=sectors_;++j){
            float sectorAngle = 2.0f * glm::pi<float>() * j / sectors_;
            float x = xy * cos(sectorAngle);
            float y = xy * sin(sectorAngle);
            Vertex v{};
            v.position = glm::vec3(x * radius_, z * radius_, y * radius_);
            v.normal = glm::normalize(v.position);
            v.tangent = glm::vec3(-sin(sectorAngle), 0.0f, cos(sectorAngle));
            v.texcoord = glm::vec2((float)j/sectors_, (float)i/stacks_);
            vertices.push_back(v);
        }
    }
    for(unsigned int i=0;i<stacks_;++i){
        unsigned int k1 = i*(sectors_+1);
        unsigned int k2 = k1 + sectors_ + 1;
        for(unsigned int j=0;j<sectors_;++j){
            if(i!=0){
                indices.push_back(k1+j);
                indices.push_back(k2+j);
                indices.push_back(k1+j+1);
            }
            if(i!=(stacks_-1)){
                indices.push_back(k1+j+1);
                indices.push_back(k2+j);
                indices.push_back(k2+j+1);
            }
        }
    }
    Mesh tmp(vertices, indices, nullptr, nullptr, nullptr, nullptr);
    static_cast<Mesh&>(*this) = std::move(tmp);
}

Cylinder::Cylinder(float radius, float height, unsigned int sectors)
    : radius_(radius), height_(height), sectors_(sectors) {
    Build();
}

void Cylinder::SetRadius(float r) { radius_ = r; Build(); }
void Cylinder::SetHeight(float h) { height_ = h; Build(); }

void Cylinder::Build(){
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    for(int i=0;i<=1;++i){
        float y = (-0.5f + i)*height_;
        for(unsigned int j=0;j<=sectors_;++j){
            float ang = 2.0f*glm::pi<float>()*j/sectors_;
            float x = radius_*cos(ang);
            float z = radius_*sin(ang);
            Vertex v{};
            v.position = glm::vec3(x,y,z);
            v.normal = glm::normalize(glm::vec3(x,0.0f,z));
            v.tangent = glm::vec3(-sin(ang),0.0f,cos(ang));
            v.texcoord = glm::vec2((float)j/sectors_, (float)i);
            vertices.push_back(v);
        }
    }
    for(unsigned int i=0;i<1;++i){
        unsigned int k1 = i*(sectors_+1);
        unsigned int k2 = k1 + sectors_ + 1;
        for(unsigned int j=0;j<sectors_;++j){
            indices.push_back(k1+j);
            indices.push_back(k2+j);
            indices.push_back(k1+j+1);
            indices.push_back(k1+j+1);
            indices.push_back(k2+j);
            indices.push_back(k2+j+1);
        }
    }
    // top cap
    unsigned int base_top = vertices.size();
    vertices.push_back({glm::vec3(0.0f,0.5f*height_,0.0f), glm::vec3(0.0f,1.0f,0.0f), glm::vec3(1.0f,0.0f,0.0f), glm::vec2(0.5f,0.5f)});
    unsigned int center_top = base_top;
    for(unsigned int j=0;j<=sectors_;++j){
        float ang=2.0f*glm::pi<float>()*j/sectors_;
        float x=radius_*cos(ang); float z=radius_*sin(ang);
        vertices.push_back({glm::vec3(x,0.5f*height_,z), glm::vec3(0.0f,1.0f,0.0f), glm::vec3(1.0f,0.0f,0.0f), glm::vec2((cos(ang)+1)*0.5f,(sin(ang)+1)*0.5f)});
    }
    for(unsigned int j=0;j<sectors_;++j){
        indices.push_back(center_top);
        indices.push_back(base_top+1+j);
        indices.push_back(base_top+1+j+1);
    }
    // bottom cap
    unsigned int base_bottom = vertices.size();
    vertices.push_back({glm::vec3(0.0f,-0.5f*height_,0.0f), glm::vec3(0.0f,-1.0f,0.0f), glm::vec3(1.0f,0.0f,0.0f), glm::vec2(0.5f,0.5f)});
    unsigned int center_bottom = base_bottom;
    for(unsigned int j=0;j<=sectors_;++j){
        float ang=2.0f*glm::pi<float>()*j/sectors_;
        float x=radius_*cos(ang); float z=radius_*sin(ang);
        vertices.push_back({glm::vec3(x,-0.5f*height_,z), glm::vec3(0.0f,-1.0f,0.0f), glm::vec3(1.0f,0.0f,0.0f), glm::vec2((cos(ang)+1)*0.5f,(sin(ang)+1)*0.5f)});
    }
    for(unsigned int j=0;j<sectors_;++j){
        indices.push_back(center_bottom);
        indices.push_back(base_bottom+1+j+1);
        indices.push_back(base_bottom+1+j);
    }
    Mesh tmp(vertices, indices, nullptr, nullptr, nullptr, nullptr);
    static_cast<Mesh&>(*this) = std::move(tmp);
}

Capsule::Capsule(float radius, float height, unsigned int sectors, unsigned int stacks)
    : radius_(radius), height_(height), sectors_(sectors), stacks_(stacks) {
    Build();
}

void Capsule::SetRadius(float r){ radius_ = r; Build(); }
void Capsule::SetHeight(float h){ height_ = h; Build(); }

void Capsule::Build(){
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    for(unsigned int i=0;i<=stacks_;++i){
        float stackAngle = glm::pi<float>()/2.0f + (glm::pi<float>()/2.0f)*(float)i/stacks_;
        float xy = cos(stackAngle);
        float y = -0.5f*height_ + radius_*sin(stackAngle);
        for(unsigned int j=0;j<=sectors_;++j){
            float sectorAngle = 2.0f*glm::pi<float>()*j/sectors_;
            float x = radius_*xy*cos(sectorAngle);
            float z = radius_*xy*sin(sectorAngle);
            Vertex v{};
            v.position = glm::vec3(x,y,z);
            v.normal = glm::normalize(glm::vec3(x, y+0.5f*height_, z));
            v.tangent = glm::vec3(-sin(sectorAngle),0.0f,cos(sectorAngle));
            v.texcoord = glm::vec2((float)j/sectors_, (float)i/stacks_*0.5f);
            vertices.push_back(v);
        }
    }
    for(unsigned int i=0;i<=1;++i){
        float y = -0.5f*height_ + i*height_;
        for(unsigned int j=0;j<=sectors_;++j){
            float sectorAngle=2.0f*glm::pi<float>()*j/sectors_;
            float x=radius_*cos(sectorAngle);
            float z=radius_*sin(sectorAngle);
            Vertex v{};
            v.position=glm::vec3(x,y,z);
            v.normal=glm::normalize(glm::vec3(x,0.0f,z));
            v.tangent=glm::vec3(-sin(sectorAngle),0.0f,cos(sectorAngle));
            v.texcoord=glm::vec2((float)j/sectors_,0.5f+0.5f*i);
            vertices.push_back(v);
        }
    }
    for(unsigned int i=0;i<=stacks_;++i){
        float stackAngle = (glm::pi<float>()/2.0f)*(1.0f - (float)i/stacks_);
        float xy = cos(stackAngle);
        float y = 0.5f*height_ + radius_*sin(stackAngle);
        for(unsigned int j=0;j<=sectors_;++j){
            float sectorAngle=2.0f*glm::pi<float>()*j/sectors_;
            float x=radius_*xy*cos(sectorAngle);
            float z=radius_*xy*sin(sectorAngle);
            Vertex v{};
            v.position=glm::vec3(x,y,z);
            v.normal=glm::normalize(glm::vec3(x, y-0.5f*height_, z));
            v.tangent=glm::vec3(-sin(sectorAngle),0.0f,cos(sectorAngle));
            v.texcoord=glm::vec2((float)j/sectors_,0.5f+0.5f*i/stacks_);
            vertices.push_back(v);
        }
    }
    unsigned int rings = stacks_*2 + 1;
    for(unsigned int i=0;i<rings;i++){
        unsigned int k1=i*(sectors_+1);
        unsigned int k2=k1+(sectors_+1);
        for(unsigned int j=0;j<sectors_;j++){
            indices.push_back(k1+j);
            indices.push_back(k2+j);
            indices.push_back(k1+j+1);
            indices.push_back(k1+j+1);
            indices.push_back(k2+j);
            indices.push_back(k2+j+1);
        }
    }
    Mesh tmp2(vertices, indices, nullptr, nullptr, nullptr, nullptr);
    static_cast<Mesh&>(*this) = std::move(tmp2);
}

Plane::Plane(float size) : size_(size) { Build(); }

void Plane::SetSize(float s){ size_ = s; Build(); }

void Plane::Build(){
    float h = size_*0.5f;
    std::vector<Vertex> vertices = {
        {{-h,0.0f,-h}, {0.0f,1.0f,0.0f}, {1.0f,0.0f,0.0f}, {0.0f,0.0f}},
        {{ h,0.0f,-h}, {0.0f,1.0f,0.0f}, {1.0f,0.0f,0.0f}, {1.0f,0.0f}},
        {{ h,0.0f, h}, {0.0f,1.0f,0.0f}, {1.0f,0.0f,0.0f}, {1.0f,1.0f}},
        {{-h,0.0f, h}, {0.0f,1.0f,0.0f}, {1.0f,0.0f,0.0f}, {0.0f,1.0f}}
    };
    std::vector<unsigned int> indices = {0,1,2,2,3,0};
    Mesh tmp3(vertices, indices, nullptr, nullptr, nullptr, nullptr);
    static_cast<Mesh&>(*this) = std::move(tmp3);
}

}
