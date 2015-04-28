#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Practica Quadtree/DoubleLinkedList.h"
#include "../Practica Quadtree/Stack.h"
#include "../Practica Quadtree/Tree.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/*namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(stack_Pop)
		{
			Stack<int> a;

			a.pushBack(1);
			a.pushBack(2);
			a.pushBack(3);

			int pop;

			a.pop(pop);

			Assert::AreEqual((int)3, pop);
		}
	};
}*/

/*namespace UnitTestQeue
{
	TEST_CLASS(UnitTestQeue)
	{
	public:
		TEST_METHOD(qeue_Pop)
		{
			Qeue<int> a;

			a.push(1);
			a.push(2);
			a.push(3);

			int pop;

			a.pop(pop);

			Assert::AreEqual((int)1, pop);
		}
		
	};
}*/

namespace UnitTestTree
{
	TEST_CLASS(UnitTestTree)
	{
	public:
		TEST_METHOD(tree_add_root)
		{
			Tree<int> tree;
			tNode<int>* a = tree.add(1, NULL);

			Assert::AreEqual((int)1, a->value);
		}

		TEST_METHOD(tree_add_tNode)
		{
			Tree<int> tree;
			tNode<int>* b = tree.add(1, NULL);
			tNode<int>* a = tree.add(2);

			Assert::AreEqual((int)1, b->value);
			Assert::AreEqual((int)2, a->value);
			Assert::AreEqual((int)2, b->sons.start->value->value);
			Assert::AreEqual((int)1, a->father->value);
		}

		TEST_METHOD(tree_clear)
		{
			Tree<int> tree;
			tNode<int>* b = tree.add(1, NULL);
			tNode<int>* a = tree.add(2, b);

			tree.clear();

			DSList<tNode<int>*> list;
			tree.preorderRecursive(&list, NULL);

			Assert::AreEqual((unsigned int)1, list.count());
		}

		TEST_METHOD(tree_preorderRecursive)
		{
			Tree<int> tree;
			tNode<int>* f = tree.add(6, NULL);
			tNode<int>* b = tree.add(2, f);
			tNode<int>* g = tree.add(7, f);
			tNode<int>* a = tree.add(1, b);
			tNode<int>* d = tree.add(4, b);
			tNode<int>* i = tree.add(9, g);
			tNode<int>* c = tree.add(3, d);
			tNode<int>* e = tree.add(5, d);
			tNode<int>* h = tree.add(8, i);
			
			
			Assert::AreEqual((int)1, a->value);
			Assert::AreEqual((int)2, b->value);
			
			DSList<tNode<int>*> checklist;
			tree.preorderRecursive(&checklist, NULL);
			
			DSLNode<tNode<int>*>* node = checklist.start;

			Assert::AreEqual((unsigned int)9, checklist.count());
			
			Assert::AreEqual((int)6, node->value->value);
			node = node->next;
			Assert::AreEqual((int)2, node->value->value);
			node = node->next;
			Assert::AreEqual((int)1, node->value->value);
			node = node->next;
			Assert::AreEqual((int)4, node->value->value);
			node = node->next;
			Assert::AreEqual((int)3, node->value->value);
			node = node->next;
			Assert::AreEqual((int)5, node->value->value);
			node = node->next;
			Assert::AreEqual((int)7, node->value->value);
			node = node->next;
			Assert::AreEqual((int)9, node->value->value);
			node = node->next;
			Assert::AreEqual((int)8, node->value->value);
			
		}
		TEST_METHOD(tree_inorderRecursive)
		{
			Tree<int> tree;
			tNode<int>* f = tree.add(6, NULL);
			tNode<int>* b = tree.add(2, f);
			tNode<int>* g = tree.add(7, f);
			tNode<int>* a = tree.add(1, b);
			tNode<int>* d = tree.add(4, b);
			tNode<int>* i = tree.add(9, g);
			tNode<int>* c = tree.add(3, d);
			tNode<int>* e = tree.add(5, d);
			tNode<int>* h = tree.add(8, i);


			Assert::AreEqual((int)1, a->value);
			Assert::AreEqual((int)2, b->value);

			DSList<tNode<int>*> checklist;
			tree.inorderRecursive(&checklist, NULL);

			DSLNode<tNode<int>*>* node = checklist.start;

			Assert::AreEqual((unsigned int)9, checklist.count());

			Assert::AreEqual((int)1, node->value->value);
			node = node->next;
			Assert::AreEqual((int)2, node->value->value);
			node = node->next;
			Assert::AreEqual((int)3, node->value->value);
			node = node->next;
			Assert::AreEqual((int)4, node->value->value);
			node = node->next;
			Assert::AreEqual((int)5, node->value->value);
			node = node->next;
			Assert::AreEqual((int)6, node->value->value);
			node = node->next;
			Assert::AreEqual((int)7, node->value->value);
			node = node->next;
			Assert::AreEqual((int)9, node->value->value);
			node = node->next;
			Assert::AreEqual((int)8, node->value->value);

		}

		TEST_METHOD(tree_postorderRecursive)
		{
			Tree<int> tree;
			tNode<int>* f = tree.add(6, NULL);
			tNode<int>* b = tree.add(2, f);
			tNode<int>* g = tree.add(7, f);
			tNode<int>* a = tree.add(1, b);
			tNode<int>* d = tree.add(4, b);
			tNode<int>* i = tree.add(9, g);
			tNode<int>* c = tree.add(3, d);
			tNode<int>* e = tree.add(5, d);
			tNode<int>* h = tree.add(8, i);


			Assert::AreEqual((int)1, a->value);
			Assert::AreEqual((int)2, b->value);

			DSList<tNode<int>*> checklist;
			tree.postorderRecursive(&checklist, NULL);

			DSLNode<tNode<int>*>* node = checklist.start;

			Assert::AreEqual((unsigned int)9, checklist.count());

			Assert::AreEqual((int)1, node->value->value);
			node = node->next;
			Assert::AreEqual((int)3, node->value->value);
			node = node->next;
			Assert::AreEqual((int)5, node->value->value);
			node = node->next;
			Assert::AreEqual((int)4, node->value->value);
			node = node->next;
			Assert::AreEqual((int)2, node->value->value);
			node = node->next;
			Assert::AreEqual((int)8, node->value->value);
			node = node->next;
			Assert::AreEqual((int)9, node->value->value);
			node = node->next;
			Assert::AreEqual((int)7, node->value->value);
			node = node->next;
			Assert::AreEqual((int)6, node->value->value);

		}

		
		TEST_METHOD(tree_preorderIterative)
		{
			Tree<int> tree;
			tNode<int>* f = tree.add(6, NULL);
			tNode<int>* b = tree.add(2, f);
			tNode<int>* g = tree.add(7, f);
			tNode<int>* a = tree.add(1, b);
			tNode<int>* d = tree.add(4, b);
			tNode<int>* i = tree.add(9, g);
			tNode<int>* c = tree.add(3, d);
			tNode<int>* e = tree.add(5, d);
			tNode<int>* h = tree.add(8, i);


			Assert::AreEqual((int)1, a->value);
			Assert::AreEqual((int)2, b->value);

			DSList<tNode<int>*> checklist;
			tree.preorderIterative(&checklist, NULL);
		
			DSLNode<tNode<int>*>* node = checklist.start;

			Assert::AreEqual((unsigned int)9, checklist.count());

			Assert::AreEqual((int)6, node->value->value);
			node = node->next;
			Assert::AreEqual((int)2, node->value->value);
			node = node->next;
			Assert::AreEqual((int)1, node->value->value);
			node = node->next;
			Assert::AreEqual((int)4, node->value->value);
			node = node->next;
			Assert::AreEqual((int)3, node->value->value);
			node = node->next;
			Assert::AreEqual((int)5, node->value->value);
			node = node->next;
			Assert::AreEqual((int)7, node->value->value);
			node = node->next;
			Assert::AreEqual((int)9, node->value->value);
			node = node->next;
			Assert::AreEqual((int)8, node->value->value);

		}
		
		TEST_METHOD(tree_inorderIterative)
		{
			Tree<int> tree;
			tNode<int>* f = tree.add(6, NULL);
			tNode<int>* b = tree.add(2, f);
			tNode<int>* g = tree.add(7, f);
			tNode<int>* a = tree.add(1, b);
			tNode<int>* d = tree.add(4, b);
			tNode<int>* i = tree.add(9, g);
			tNode<int>* c = tree.add(3, d);
			tNode<int>* e = tree.add(5, d);
			tNode<int>* h = tree.add(8, i);


			Assert::AreEqual((int)1, a->value);
			Assert::AreEqual((int)2, b->value);

			DSList<tNode<int>*> checklist;
			tree.inorderIterative(&checklist, NULL);

			DSLNode<tNode<int>*>* node = checklist.start;

			Assert::AreEqual((unsigned int)9, checklist.count());

			Assert::AreEqual((int)1, node->value->value);
			node = node->next;
			Assert::AreEqual((int)2, node->value->value);
			node = node->next;
			Assert::AreEqual((int)3, node->value->value);
			node = node->next;
			Assert::AreEqual((int)4, node->value->value);
			node = node->next;
			Assert::AreEqual((int)5, node->value->value);
			node = node->next;
			Assert::AreEqual((int)6, node->value->value);
			node = node->next;
			Assert::AreEqual((int)8, node->value->value);
			node = node->next;
			Assert::AreEqual((int)9, node->value->value);
			node = node->next;
			Assert::AreEqual((int)7, node->value->value);

		}

		TEST_METHOD(tree_postorderIterative)
		{
			Tree<int> tree;
			tNode<int>* f = tree.add(6, NULL);
			tNode<int>* b = tree.add(2, f);
			tNode<int>* g = tree.add(7, f);
			tNode<int>* a = tree.add(1, b);
			tNode<int>* d = tree.add(4, b);
			tNode<int>* i = tree.add(9, g);
			tNode<int>* c = tree.add(3, d);
			tNode<int>* e = tree.add(5, d);
			tNode<int>* h = tree.add(8, i);


			Assert::AreEqual((int)1, a->value);
			Assert::AreEqual((int)2, b->value);

			DSList<tNode<int>*> checklist;
			tree.postorderIterative(&checklist, NULL);

			DSLNode<tNode<int>*>* node = checklist.start;

			Assert::AreEqual((unsigned int)9, checklist.count());

			Assert::AreEqual((int)1, node->value->value);
			node = node->next;
			Assert::AreEqual((int)3, node->value->value);
			node = node->next;
			Assert::AreEqual((int)5, node->value->value);
			node = node->next;
			Assert::AreEqual((int)4, node->value->value);
			node = node->next;
			Assert::AreEqual((int)2, node->value->value);
			node = node->next;
			Assert::AreEqual((int)8, node->value->value);
			node = node->next;
			Assert::AreEqual((int)9, node->value->value);
			node = node->next;
			Assert::AreEqual((int)7, node->value->value);
			node = node->next;
			Assert::AreEqual((int)6, node->value->value);

		}
		
		
	};
}

