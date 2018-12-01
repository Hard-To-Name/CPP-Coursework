template<class T>
TN<T>* find (TN<T>* t, T to_find) {
  if (t == nullptr || to_find == t->value)
     return t;
  else
     return find( (to_find < t->value ? t->left : t->right), to_find);
}

template<class T>
TN<T>* insert (TN<T>* t, T to_insert) {
  if (t == nullptr)
    return new TN<T>(to_insert); //nullptr implicit for left/right subtrees
  else {
    if (to_insert < t->value)
      t->left = insert(t->left, to_insert);
    else if (to_insert > t->value)
      t->right = insert(t->right, to_insert);
  /*else,  for == case
      ;*/

    return t;
  }
}
