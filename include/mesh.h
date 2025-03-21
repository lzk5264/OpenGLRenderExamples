#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include "shader.h"
#include <vector>
using namespace std;

#define MAX_BONE_INFLUENCE 4

struct Vertex {
    glm::vec3 Position {0.0f};
    glm::vec3 Normal {0.0f};
    glm::vec2 TexCoords {0.0f};
    glm::vec3 Tangent {0.0f};
    glm::vec3 Bitangent {0.0f};
    int m_BoneIDs[MAX_BONE_INFLUENCE] {0};
    float m_Weights[MAX_BONE_INFLUENCE] {0.0f};
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};

class Mesh {
public:
    enum VertexAttribute : uint32_t {
        POSITION     = 1 << 0,
        NORMAL       = 1 << 1,
        TEXCOORDS    = 1 << 2,
        TANGENT      = 1 << 3,
        BITANGENT    = 1 << 4,
        BONE_IDS     = 1 << 5,
        BONE_WEIGHTS = 1 << 6
    };

    // 支持灵活参数的构造函数
    Mesh(vector<Vertex> vertices,
         vector<unsigned int> indices = {},
         vector<Texture> textures = {},
         uint32_t attributes = POSITION | NORMAL | TEXCOORDS)
        : vertices(move(vertices)),
          indices(move(indices)),
          textures(move(textures)),
          attributesMask(attributes)
    {
        setupMesh();
    }

    void Draw(Shader &shader) {
        bindTextures(shader);
        
        glBindVertexArray(VAO);
        if (!indices.empty()) {
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        } else {
            glDrawArrays(GL_TRIANGLES, 0, vertices.size());
        }
        glBindVertexArray(0);
    }

private:
    vector<Vertex> vertices;
    vector<unsigned int> indices;
    vector<Texture> textures;
    uint32_t attributesMask;
    unsigned int VAO, VBO, EBO;

    void setupMesh() {
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        
        // 顶点数据
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

        // 索引数据（可选）
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        setupAttributes();
        glBindVertexArray(0);
    }

    void setupAttributes() {
        // 必须属性
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

        // 可选属性
        setAttribute(1, VertexAttribute::NORMAL,    3, offsetof(Vertex, Normal));
        setAttribute(2, VertexAttribute::TEXCOORDS, 2, offsetof(Vertex, TexCoords));
        setAttribute(3, VertexAttribute::TANGENT,   3, offsetof(Vertex, Tangent));
        setAttribute(4, VertexAttribute::BITANGENT, 3, offsetof(Vertex, Bitangent));
        setAttribute(5, VertexAttribute::BONE_IDS,  4, offsetof(Vertex, m_BoneIDs), true);
        setAttribute(6, VertexAttribute::BONE_WEIGHTS,4, offsetof(Vertex, m_Weights));
    }

    void setAttribute(int index, VertexAttribute attr, int size, size_t offset, bool intType = false) {
        if (attributesMask & attr) {
            glEnableVertexAttribArray(index);
            if(intType) {
                glVertexAttribIPointer(index, size, GL_INT, sizeof(Vertex), (void*)offset);
            } else {
                glVertexAttribPointer(index, size, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offset);
            }
        } else {
            glDisableVertexAttribArray(index);
        }
    }

    void bindTextures(Shader &shader) {
        if(textures.empty()) {
            // 无纹理时设置默认颜色
            shader.setBool("hasTexture", false);
            return;
        }

        shader.setBool("hasTexture", true);
        for(size_t i = 0; i < textures.size(); ++i) {
            glActiveTexture(GL_TEXTURE0 + i);
            string name = "texture_" + textures[i].type + to_string(i+1);
            shader.setInt(name.c_str(), i);
            glBindTexture(GL_TEXTURE_2D, textures[i].id);
        }
    }
};
#endif