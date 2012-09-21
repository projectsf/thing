#include <cstdio>
#include <iostream>

typedef void (*TpCallback)(void);

struct CallbackNode{
	TpCallback callback;
	CallbackNode* next;
};

struct Node{
	CallbackNode* callbackList;
	int alarmTickCount;
	Node* left;
	Node* right;
};



Node* head = NULL;

void listInsert(CallbackNode* cbHead, void (*callback)(void))
{
	CallbackNode* temp = new CallbackNode;
	temp->callback = callback;
	temp->next = NULL;
	
	
	if(cbHead == NULL) {
	  cbHead = temp;
	}
	  
	else {
	  CallbackNode *curr = cbHead;
	  CallbackNode *prev = cbHead;
	  while(curr) {
	  	prev = curr;
	    curr = curr->next;
	  }
	  prev->next = temp;
	}
	  
}


void bstInsert(void (*callback)(void), int alarm_tick_count)
{
	Node* parent;
	Node* temp = new Node;
	temp->callbackList = new CallbackNode;
	temp->callbackList->callback = callback;
	temp->callbackList->next = NULL;
	temp->alarmTickCount = alarm_tick_count;
	temp->left = NULL;
	temp->right = NULL;
	
	if(head == NULL) {
	  head = temp;
	}
	  
	else {
    Node* curr;
    curr = head;
    // Find the Node's parent
    while(curr)
    {
        parent = curr;
        if(alarm_tick_count == curr->alarmTickCount) {
          listInsert(curr->callbackList, callback);
          delete temp->callbackList;
          delete temp;
          break;
        }
        else if(alarm_tick_count > curr->alarmTickCount) 
          curr = curr->right;
        else curr = curr->left;
    }

    if(alarm_tick_count < parent->alarmTickCount) 
      parent->left = temp;
    else if(alarm_tick_count > parent->alarmTickCount) 
      parent->right = temp;
	}
	  
}
/**
 * Function performs an inorder traversal of list.
 */
void lookup(int system_tick_count)
{
    Node* curr;
    curr = head;
    // Find the Node's parent
    while(curr)
    {
        if(system_tick_count == curr->alarmTickCount) {
          CallbackNode* cbCurr = curr->callbackList;
	        while(cbCurr != NULL) {
	          cbCurr->callback();
	          cbCurr = cbCurr->next;
	        }
          break;
        }
        else if(system_tick_count > curr->alarmTickCount) 
          curr = curr->right;
        else curr = curr->left;
    }
}

/**
 * alarm_set forwards call to linked list insert function
 */
void alarm_set (TpCallback callback, int alarm_tick_count)
{
	bstInsert(callback, alarm_tick_count);
}

/**
 * alarm_check forwards call to linked list lookup function
 */
void alarm_check (int system_tick_count)
{
  lookup(system_tick_count);
}


void alarmCalledBird()
{
	std::cout << "Alarm Called Bird Song" << std::endl;
}

void alarmCalledRadio()
{
	std::cout << "Alarm Called Radio" << std::endl;
}


int main()
{
	void (*birdCallback)(void) = &alarmCalledBird;
	void (*radioCallback)(void) = &alarmCalledRadio;
	alarm_set(birdCallback, 3);
	alarm_set(radioCallback, 6);
	alarm_set(birdCallback, 6);
	alarm_set(birdCallback, 6);
	alarm_set(birdCallback, 6);
	alarm_set(birdCallback, 6);

	
	for (unsigned int ii=0;ii<10;++ii) {
		std::cout << "Checking at : " << ii << std::endl;
		alarm_check(ii);
		sleep(1);
	}

  
		
}
