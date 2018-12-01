template<class T>
TN<T>* find (TN<T>* t, T to_find) {
  if (t == nullptr || to_find == t->value)
     return t;
  else
     return find( (to_find < t->value ? t->left : t->right), to_find);
}
