#ifndef _LinkedList_
#define _LinkedList_

#include <stdio.h>

template<class TYPE>
struct DSLNode
{
	TYPE value;
	DSLNode<TYPE>* next;
	DSLNode<TYPE>* previous;

	inline DSLNode(const TYPE& _value)
	{
		value = _value;
		next = previous = NULL;
	}

	~DSLNode(){}
};

template<class TYPE>
class DSList
{
public:

	DSLNode<TYPE>* start;
	DSLNode<TYPE>* end;

private:

	unsigned int size;

public:

	//Constructor
	DSList() : start(NULL), end(NULL), size(0){}

	//Destructor
	~DSList()
	{
		delAll();
	}

	//Get Size
	unsigned int count()
	{
		return size;
	}

	//find node
	int find(const TYPE& value)
	{
		DSLNode<TYPE>* tmp = start;
		int index = 0;

		while (tmp != NULL)
		{
			if (tmp->value == value)
				return(index);

			index++;
			tmp = tmp->next;
		}
		return (-1);
	}

	//Add new item
	unsigned int add(const TYPE& value)
	{
		DSLNode<TYPE>* newDSLNode;
		newDSLNode = new DSLNode<TYPE>(value);

		if (start == NULL)
		{
			start = end = newDSLNode;
		}
		else
		{
			newDSLNode->previous = end;
			end->next = newDSLNode;
			end = newDSLNode;
		}
		return(++size);
	}

	//Deletes an item from the list
	bool del(DSLNode<TYPE>* delDSLNode)
	{
		if (delDSLNode == NULL || start == NULL || end == NULL)
		{
			return false;
		}
		else
		{
			if (delDSLNode != start || delDSLNode != end)
			{
				DSLNode* tmp = start;
				while (tmp->next != delDSLNode)
				{
					if (tmp == NULL)
					{
						delete delDSLNode;
						return;
					}
					tmp = tmp->next;
				}
				tmp->next = delDSLNode->next;
				tmp = tmp->next;
				tmp->previous = delDSLNode->previous;
			}
			else if (delDSLNode == start)
			{
				start = start->next;
				start->previous = NULL;
			}
			else
			{
				end = end->previous;
				end->next = NULL;
			}
			delete delDSLNode;
			--size;
			return(true);
		}
	}

	bool del(unsigned int x)
	{
		if (start == NULL || end == NULL)
		{
			return false;
		}
		else
		{
			if (x == 0)
			{
				start = start->next;
				return(true);
			}

			DSLNode* tmp = start;
			DSLNode* tmp2;
			
			for (unsigned int i = 1; i < x; i++)
			{
				if (tmp == NULL)
				{
					return(false);
				}
				tmp = tmp->next;
			}
			tmp2 = tmp->next;
			if (tmp2->next != NULL)
			{
				tmp->next = tmp2->next;
				tmp = tmp2->next;
				tmp->previous = tmp2->previous;
			}
			else
			{
				end = end->previous;
				end->next = NULL;
			}
		}
		delete tmp2;
		--size;
		return(true)
	}

	//delNodes
	void delNodes(unsigned int position, unsigned int quantity)
	{
		DSLNode<TYPE>*   p_value;
		DSLNode<TYPE>*   p_next;
		p_value = start;

		unsigned int pos = 0;
		unsigned int q = 0;
		while (p_value != NULL)
		{
			p_next = p_value->next;
			if (pos >= position || q <= quantity)
			{
				delete p_value;
				q++;
			}
			pos++;
			p_value = p_next;
		}
		if (position == 0)
		{
			start = end = p_value->previous;
		}

		start = end = NULL;
		size -= quantity;
	}


	//Destroy and free all mem
	void delAll()
	{
		if (start != NULL)
		{
			DSLNode<TYPE>* tmp;
			while (start != NULL)
			{
				tmp = start;
				start = start->next;
				delete tmp;
			}
			start = end = NULL;
			size = 0;
		}
	}

};



#endif