void HeapPriorityQueue<T,tgt>::percolate_down(int i) {
 for (int l = left_child(i); in_heap(l); l = left_child(i)) {
   int r = right_child(i);
   int max_child = (!in_heap(r) || gt(pq[l],pq[r]) ? l : r);
   if ( gt(pq[i],pq[max_child]) )
      break;
   std::swap(pq[i],pq[max_child]);
   i = max_child;
 }
}
