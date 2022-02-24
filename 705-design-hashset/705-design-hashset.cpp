class MyHashSet {
public:
     ListNode* head ;
     MyHashSet() {
	   // creating a linked list
        head = new ListNode(-1);
    }
    
    void add(int key) {
        ListNode *temp = head;
        while(temp->next != NULL) 
        {  
            // condtion for duplicates
            if(temp->next->val == key) 
                return ;		
            temp=temp->next;
        }     
        ListNode* newnode = new ListNode(key);
        temp->next = newnode;
    }
    
    void remove(int key) {
        ListNode *temp = head;    
        while( temp->next != NULL) 
        {   
            if(temp->next->val == key)
            {
              temp->next = temp->next->next;
              break;
             }   
         
            temp=temp->next;
        }
    }
    
    bool contains(int key) { 
        ListNode *temp = head->next; 
        while(temp != NULL)
        {   
            if(temp->val == key) 
                return true;
            temp=temp->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */