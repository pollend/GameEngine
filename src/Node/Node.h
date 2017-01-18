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

		//the children nodes related to the set
		std::list<Node*>* _children;

		//list of all the nodes in a scene. used for the scenemanager
		SharedNodeInfo* _sharedNodeInfo;

		Node * _parentNode;
		SceneNode * _sceneNode;

		virtual void _onNodeAppend();
	
	public:

        Vector3f Position;
        Vector3f Scale;
		Quaternionf Rotation;

		Node(std::string ID);
		virtual ~Node(void);
		
		/**
		 * retrieves the matrix for the object
		 **/
		virtual Matrix4f GetMatrix();

		/**
		 * retrieves the ID of the node
		 **/
		std::string GetID();

		/**
		 * appends a node to the set
		 **/
		virtual void AppendNode(Node * n);

		/**
		 * retrieves all the children nodes to the current node
		 **/
		std::list<Node*>* GetChildren();
		
		/**
		 *retrieves the parent node of the current node
		 **/
		Node* GetParent();

		/**
		*deletes the child
		**/
		void DeleteChild(std::string id);

		
		/**
		 * retrieves the node with the id connected to the current
		 **/
		Node* GetNode(std::string id);

		/**
		 * delete's all the children nodes
		 **/
		void DeleteAllChildren();

		/**
		 * gets the location of the node relative to the camera
		 **/
        Matrix4f GetLocationOfNode(Camera* cam);
        
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

