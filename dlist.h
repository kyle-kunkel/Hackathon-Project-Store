#ifndef __DLIST_H__
#define __DLIST_H__


/***************************************
 * Do not modify the class declarations!
 ***************************************/
class emptyList {
  // OVERVIEW: an exception class
};

template <typename T>
class Dlist {
  // OVERVIEW: contains a double-ended list of Objects

 public:
  void printTest();
  // Operational methods

  bool IsEmpty() const;
  // EFFECTS: returns true if list is empty, false otherwise

  void InsertFront(const T& o);
  // MODIFIES this
  // EFFECTS inserts o at the front of the list

  void InsertBack(const T& o);
  // MODIFIES this
  // EFFECTS inserts o at the back of the list

  T RemoveFront();
  // MODIFIES this
  // EFFECTS removes and returns first object from non-empty list
  //         throws an instance of emptyList if empty

  T RemoveBack();
  // MODIFIES this
  // EFFECTS removes and returns last object from non-empty list
  //         throws an instance of emptyList if empty

  // Maintenance methods
  Dlist();                                   // ctor
  Dlist(const Dlist& l);                     // copy ctor
  Dlist& operator=(const Dlist& l);          // assignment
  ~Dlist();                                  // dtor

 private:
  // A private type
  struct node {
    node* next;
    node* prev;
    T      o;
  };

  node* first; // The pointer to the first node (0 if none)
  node* last;  // The pointer to the last node (0 if none)
  //How us this different than the doubly linked list in class?

  // Utility methods

  void MakeEmpty();
  // EFFECT: called by constructors to establish empty
  // list invariant

  void RemoveAll();
  // EFFECT: called by destructor and operator= to remove and destroy
  // all list nodes

  void CopyAll(const Dlist& l);
  // EFFECT: called by copy constructor/operator= to copy nodes
  // from a source instance l to this instance
};

/**** DO NOT MODIFY ABOVE THIS LINE *****/

/***************************************
 *ADD  Member function implementations here
 ***************************************/
template <typename T>
bool Dlist<T>::IsEmpty() const {
  return (first == 0 && last == 0);
}
template <typename T>
void Dlist<T>::InsertFront(const T& o) {
  node* nodeNew = new node;
  nodeNew->o = o;
  if (IsEmpty()) {
    first = nodeNew;
    first->next = 0;
    first->prev = 0;
    last = nodeNew;
  }
  else {
    node* temp = first;
    first = nodeNew;
    first->prev = 0;
    first->next = temp;
    temp->prev = first;

  }
}
template<typename T>
void Dlist<T>::InsertBack(const T& o) {
  node* newNode = new node;
  newNode->o = o;
  if (IsEmpty()) {
    first = newNode;
    first->next = 0;
    first->prev = 0;
    last=newNode;
  }
  else
  {
    last->next = newNode;
    newNode->prev = last;
    newNode->next = 0;
    last = newNode;
  }
}
template<typename T>
T Dlist<T>::RemoveFront(){
  if(!IsEmpty()){
    if(last==first){
      T data = first->o;
      node *temp = first;
      first = 0;
      last = 0;
      delete temp;
      return data;
    }else{
      T data = first->o;
      node *temp = first;
      first=first->next;
      first->prev = 0;
      delete temp;
      return data;
    }
  }
  else{
    throw "Exception:Nothing to return/list is empty";
  }
}
template<typename T>
T Dlist<T>::RemoveBack(){
  if(!IsEmpty()){
    if(last==first){
      T data = last->o;
      node* temp = last;
      delete temp;
      last = 0;
      first=0;
      return data;
    }
    else{
      T data = last->o;
      node *temp = last;
      last = last->prev;
      last->next = 0;
      delete temp;
      return data;
    }
  }
  else{
    throw "Exception:Nothing to return/list is empty";
  }
}
/***************************************
 *Helper Fucntions
 ***************************************/
template<typename T>
void Dlist<T>::RemoveAll() {
  node* temp = first;
  //std::cout<<"Destruct"<<std::endl;
  while (first != nullptr) {
    temp = first;
    first = first->next;
    delete temp;
  }
  // std::cout << "Destruct" << std::endl;
}
template<typename T>
void Dlist<T>::MakeEmpty(){
  first = 0;
  last = 0;
}

/***************************************
 *Constructor Funtions
 ***************************************/
template<typename T>
Dlist<T>::Dlist() {
  MakeEmpty();
  //std::cout << "Construct" << std::endl;
}
template<typename T>
Dlist<T>::~Dlist() {
  RemoveAll();
}
template<typename T>
void Dlist<T>::printTest() {

}
template<typename T>
void Dlist<T>::CopyAll(const Dlist& l){
  if(l.first != nullptr){
    node *temp = l.first;

    while (temp != 0 ) {
      InsertFront(temp->o);
      temp = temp->next;
    }
  }
}
template<typename T>
Dlist<T>&Dlist<T>:: operator=(const Dlist& l){
  if(!l.IsEmpty()){
    CopyAll(l);
  }
}
template<typename T>
Dlist<T>::Dlist(const Dlist& l){
  if(!l.IsEmpty()){
    CopyAll(l);
  }
}
/* this must be at the end of the file */
#endif /* __DLIST_H__ */