# Merge_Sort
Merge Sort's Algorithm and Theory

## Merge Sort란?
- 하나의 리스트를 두 개의 균등한 크기로 분할하고 분할된 부분 리스트를 정렬한 다음, 두 개의 정렬된 부분 리스트를 합하여 전체가 정렬된 리스트가 되게 하는 알고리즘
- Merge Sort는 Divide, Conquer, Combine의 3가지 과정을 거침

<img src="https://gmlwjd9405.github.io/images/algorithm-merge-sort/merge-sort-concepts.png"></img>

<img src="https://gmlwjd9405.github.io/images/algorithm-merge-sort/merge-sort.png"></img>
[출처] https://gmlwjd9405.github.io/2018/05/08/algorithm-merge-sort.html


## Merge Sort pseudocode

  MERGE-SORT(A,p,r)     ⊳A[1 . . n] , p : start point, r: end point
    if p < r
      q <- (p+r) / 2        ⊳q : second array's start point that separated from one array
      MERGE-SORT(A, p, q)
      MERGE-SORT(A, q+1, r)
      MERGE(A, p, r, q)
    
  MERGE(arr[], start, end, mid)
	  vector<int>
	  while pointer that starts from first array <= mid && pointer that starts from second array <= end
	  {
		  compare two array's value and put smaller value to vector
    }
    while (pointer that starts from first array <= mid)											//Until first array's pointer reach to end of first array
    {
      vector <- first array's remained values
    }
    while (pointer that starts from second array <= end)
    {
       vector <- second array's remained values
    }
         
  
  ## Analysis
  - 시간 복잡도 : Θ(nlgn)
  - Merge-Sort의 경우 Insertion Sort와 달리 Best, Average, Worst case이 수행시간 차이가 거의 나지 않는다
  - 일반적으로 sorting하려는 array의 길이가 30을 넘어야 insertion sort보다 성능이 좋아진다
