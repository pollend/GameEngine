#ifndef _NODE_H_
#define _NODE_H_


#include <list>
#include <map>
#include <string>
#include <Eigen/Dense>

using Eigen::Vector3f;
using Eigen::Matrix4f;
using Eigen::Quaternionf;

class SharedNodeInfo;
class Camera;
class SceneNode;
class Node
{
	private:

	protected:

		std::string _id;

		//list of all the nodes in a scene. used for the scenemanager
		SharedNodeInfo* _sharedNodeInfo;

		Node * _parentNode;

		virtual void _onNodeAppend();
	
	public:

        Vector3f Position;
        Vector3f Scale;
		Quaternionf Rotation;

		Node(std::string ID);
		virtual ~Node(void);

		Matrix4f GetTransformation();
		
		/**
		 * retrieves the matrix for the object
		 **/
		virtual Matrix4f GetLocalTransform();

		/**
		 * retrieves the ID of the node
		 **/
		std::string GetID();

		/**
		 * appends a node to the set
		 **/
		virtual void SetParent(Node *n);

		/**
		 *retrieves the parent node of the current node
		 **/
		Node* GetParent();


		/**
		 * gets the node type
		 **/
		virtual std::string GetType();

		/**
		 *updates the curren node
		 **/
		virtual void Update();
};

#endif

