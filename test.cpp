template<class T>
T remove_closest(TN<T>*& t) {
  if (t->right == nullptr) {
    T to_return = t->value;
    TN<T>* to_delete = t;
    t = t->left;
    delete to_delete;
    return to_return;
  }else
    return remove_closest(t->right);
}

template<class T>
void remove (TN<T>*& t, T to_remove) {
  if (t == nullptr)
    return;
  else
    if (to_remove == t->value) {
      if (t->left == nullptr) {
        TN<T>* to_delete = t;
        t = t->right;
        delete to_delete;
      }else if (t->right == nullptr) {
        TN<T>* to_delete = t;
        t = t->left;
        delete to_delete;
      }else                   //Removes biggest value less than to_remove
        t->value = remove_closest(t->left);
    }else
      remove( (to_remove < t->value ? t->left : t->right), to_remove);
}
