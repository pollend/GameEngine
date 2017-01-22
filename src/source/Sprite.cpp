#include "Render/Sprite.h"
#include "VertexObject/VertexElementBuffer.h"
#include "VertexObject/VertexBufferObjectWithSubData.h"
#include "SmokeEngine.h"

Sprite::Sprite(SceneNode * sceneNode,Source * fragmentShader) : RenderObject(sceneNode)
{
	_sceneNode = sceneNode;

	_vertexSource = new Source(SPRITE_VERTEX_SHADER,GL_VERTEX_SHADER);
	this->mShader->AttachSource(_vertexSource);
	this->mShader->AttachSource(fragmentShader);


	_initialize(sceneNode);
}

Sprite::Sprite(SceneNode * sceneNode,Texture * texture) :  RenderObject(sceneNode)
{
	_sceneNode = sceneNode;

	_vertexSource = new Source(SPRITE_VERTEX_SHADER,GL_VERTEX_SHADER);
	_fragmentSource = new Source(SPRITE_FRAGMENT_SHADER,GL_FRAGMENT_SHADER);

	this->mShader->AttachSource(_vertexSource);
	this->mShader->AttachSource(_fragmentSource);
	
	//set the base image of the sprite
	this->mShader->SetTexture("in_BaseImage",texture,0);

	//set up the other fixed variables for the sprite
	_initialize(sceneNode);
}

void Sprite::_initialize(SceneNode * sceneNode)
{
	GLushort ldata[] = SPRITE_INDECIES;
	this->mVertexArrayObject = new VertexElementBuffer(ldata, SPRITE_INDECIES_SIZE);

	VertexBufferObjectWithSubData * lvertexObject = new VertexBufferObjectWithSubData();
	{
		GLfloat ldata [] = SPRITE_VERTICIES;
		lvertexObject->AddSubData(new VertexBufferObjectWithSubData::SubData(ldata,SPRITE_VERTICIES_SIZE,3));
	}

	{
		GLfloat ldata [] = {0,1,2,3};
		lvertexObject->AddSubData(new VertexBufferObjectWithSubData::SubData(ldata,4,1));
	}
	lvertexObject->IntalizeBuffer();
	this->mVertexSubData = lvertexObject;

	this->mShader->SetAttrib(0,"in_Verts");
	this->mShader->SetAttrib(1,"in_Index");

	this->mShader->IntalizeShader();

	//sets uniforms
	this->mShader->SetMatrix4x4("in_View",Matrix4f::Identity());
	this->mShader->SetMatrix4x4("in_Transform",Matrix4f::Identity());

	SetClippingRectangle(Vector2f(0,0),Vector2f(1,1));

	
}

void Sprite::SetClippingRectangle(Vector2f pos, Vector2f size)
{
	this->mShader->SetUniform2("in_Clipping_Position",pos);
	this->mShader->SetUniform2("in_Clipping_Size",size);
}

Sprite::~Sprite(void)
{

}

void Sprite::Draw(Matrix4f transform, Matrix4f view)
{

	glEnable(GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	this->mShader->BindShader();

	this->mVertexSubData->Bind();
	this->mVertexArrayObject->Bind();

	this->mShader->SetMatrix4x4("in_Transform",transform);
	this->mShader->SetMatrix4x4("in_View",view);

	glDrawElements(GL_TRIANGLES,mVertexArrayObject->GetNumberOfIndecies(),GL_UNSIGNED_SHORT,NULL);
	glDisable(GL_BLEND);
}

void Sprite::DepthDraw(Matrix4f transform, Matrix4f view)
{
}