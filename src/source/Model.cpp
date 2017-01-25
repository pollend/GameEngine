#include <Node/SceneNode.h>
#include "Render/Model.h"
#include <boost/log/trivial.hpp>


Model::Model(SceneNode* sceneNode,VertexBufferObjectWithSubData* vertexBufferObject,VertexElementBuffer* vertexArrayObject,Source* vertexSource, Source* Fragmentsource) : RenderObject(sceneNode)
{
	vertexBufferObject->IntalizeBuffer();

	mShader->AttachSource(vertexSource);
	mShader->AttachSource(Fragmentsource);

	for(int x = 0; x < vertexBufferObject->GetSize(); x++)
	{
		if((*vertexBufferObject)[x]->GetListedType() == VERTEX)
		{
			mShader->SetAttrib(x,"in_Verts");
		}
		else if((*vertexBufferObject)[x]->GetListedType() == NORMALS)
		{
			mShader->SetAttrib(x,"in_Normals");
		}
		else if((*vertexBufferObject)[x]->GetListedType() == TEX_COORDS)
		{
			mShader->SetAttrib(x,"in_TexCoords");
		}
	}
    mShader->IntalizeShader();


	mShader->SetMatrix4x4("in_Transform",Matrix4f::Identity());
	mShader->SetMatrix4x4("in_View",Matrix4f::Identity());

	_vertexArrayObject = vertexArrayObject;
	_vertexBufferObject = vertexBufferObject;

}


Model::~Model(void)
{
}

void Model::Draw(Matrix4f transform, Matrix4f view)
{
	mShader->BindShader();
    _vertexArrayObject->Bind();
    _vertexBufferObject->Bind();

	mShader->SetMatrix4x4("in_Transform",transform);
	mShader->SetMatrix4x4("in_View",view);
	glDrawElements(GL_TRIANGLES,_vertexArrayObject->GetNumberOfIndecies(),GL_UNSIGNED_SHORT,0);

}

void Model::DepthDraw(Matrix4f transform, Matrix4f view)
{
	/*_depthShader->BindShader();

	_depthShader->SetMatrix4x4("in_Transform",transform);
	_depthShader->SetMatrix4x4("in_View",view);

	_vertexArrayObject->Bind();
	_vertexBufferObject->Bind();

	glDrawElements(GL_TRIANGLES,_vertexArrayObject->GetNumberOfIndecies(),GL_UNSIGNED_SHORT,0);
	*/
}
