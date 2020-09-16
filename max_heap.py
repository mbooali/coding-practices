def get_left(parent_index):
  return 2 * parent_index  + 1

def get_right(parent_index):
  return 2 * parent_index  + 2

def get_parent(child_index):
  return (child_index - 1) // 2

def swap(arr, i, j):
  arr[i], arr[j] = arr[j], arr[i]

def insert_max_heap(heap, x):
  heap.append(x)
  
  child_index = len(heap) - 1
  parent_index = (child_index - 1) // 2
  
  while child_index != 0 and parent_index >= 0:  
    if heap[parent_index] < heap[child_index]:
      swap(heap, parent_index, child_index)
      
    child_index = parent_index
    parent_index = get_parent(child_index)

def heapify(heap, root):
  n = len(heap)
  left = get_left(root)
  right = get_right(root)
  
  if left < n and heap[root] < heap[left]:
    swap(heap, root, left)
    heapify(heap, left)
  if right < n and heap[root] < heap[right]:
    swap(heap, root, right)
    heapify(heap, right)
    
  
  
  
def extract_max(heap):
  n = len(heap)
  
  if n == 1:
    return heap.pop()
  
  max_val = heap.pop(0)
  heap.insert(0, heap.pop())
  
  n += 1
  # now we should see left or right which one is bigger and needed to be heapified
  
  parent_index = 0
  left_child = get_left(parent_index)
  right_child = get_right(parent_index)
  
  heapify(heap, parent_index)
    
  
  return max_val
  


