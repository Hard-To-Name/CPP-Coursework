template(class T>
void print (TN<T>* t) {  //Preorder, Inorder, Postorder form
  if (t == nullptr)
    return;
  else {
    //Uncomment for preorder traversals:  std::cout << t->value << std::endl;
    print(t->left);
    //Uncomment for inorder traversals:   std::cout << t->value << std::endl;
    print(t->right);
    //Uncomment for postorder traversals: std::cout << t->value << std::endl;
  }
}

template<class T>
void print_breadthfirst (TN<T>* t) { //Breadth-First
  ics::ArrayQueue<TN<T>*> q;
  q.enqueue(t);                           //Initialize with the root

  while (!q.empty()) {
    TN<T>* next = q.dequeue();
    std::cout << next->value << " ";
    if (next->left != nullptr)     //Only non-nullptr values added
      q.enqueue(next->left);
    if (next->right != nullptr)
      q.enqueue(next->right);
  }
}
