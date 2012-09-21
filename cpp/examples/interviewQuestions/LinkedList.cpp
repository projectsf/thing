#include <vector>
#include <iostream>
#include <cmath>
#include <stdexcept>

template<typename T>
class Element
{
public:
	Element(T value)
	  : m_value(value),
	    m_next(NULL)
	{
	}
	
	T getValue()
	{
		return m_value;
	}
	
	void setNext(Element* next)
	{
		m_next = next;
	}
	
	Element* getNext()
	{
		return m_next;
	}
	
private:
  T m_value;
  Element* m_next;
};

 
template<typename T>
class LinkedList
{
public:
	LinkedList()
	  : m_head(NULL),
	    m_tail(NULL)
	{
	}
	
	void addElement(T newValue)
	{
		if(!m_head) {
		  m_head = new Element<T>(newValue);
		  m_tail = m_head;
		}
		else {
			Element<T>* newElement = new Element<T>(newValue);
			m_tail->setNext(newElement);
			m_tail = newElement;
		}
	}
	
	void printList()
	{
		Element<T>* pElement = m_head;
		while(pElement != NULL) {
			std::cout << "Value: " << pElement->getValue() << std::endl;
			pElement = pElement->getNext();
		}
	}	
	
	~LinkedList()
	{
		Element<T>* pNext = m_head->getNext();
		Element<T>* pCurrent = m_head;
		while(pNext != NULL) {
			std::cout << "Deleting node with value: " << pCurrent->getValue() << std::endl;
			pNext = pCurrent->getNext();
			delete pCurrent;
			pCurrent = pNext;
		}
	}
			
	
	

private:
  Element<T>* m_head;
  Element<T>* m_tail;
	
};



int main()
{
	LinkedList<int> myList;
	myList.addElement(2);
	myList.addElement(3);
	myList.addElement(4);
	myList.addElement(5);
  myList.addElement(6);
	myList.printList();
  
}
