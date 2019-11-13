#pragma once

#include <vector>
#include <string>

#include <GL\glew.h>
#include <GLFW\glfw3.h>

#include <assimp\Importer.hpp>
#include <assimp\scene.h>
#include <assimp\postprocess.h>

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

#include "Mesh.h"
#include "Texture.h"

class Model
{
public:
	Model();

	void LoadModel(const std::string& fileName);
	void RenderModel();
	void ClearModel();
	void keyControl(bool * keys, GLfloat deltaTime, glm::vec3 pos_xwing, GLfloat velo_xwing);

	~Model();

private:

	void LoadNode(aiNode *node, const aiScene *scene);
	void LoadMesh(aiMesh *mesh, const aiScene *scene);
	void LoadMaterials(const aiScene *scene);

	std::vector<Mesh*> meshList;
	std::vector<Texture*> textureList;
	std::vector<unsigned int> meshToTex;
};

