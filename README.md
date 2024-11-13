# Sorts
fun for sort your mass on C

# SYNOPSIS
```code
#include "BASE.H"<br>
#include "SORTS.H"<br>
int sort(void *mass,int size,int sortChoice,int creverse,int elemsize,int(comp)(void * , void * ))<br>
```
# DESCRIPTION
The sort() sorts any type of mass.<br>
	sort_Choice defines method of sort.<br>
	creverse defines direction of sort, if 1 it will sort in reverse direction<br>
	elemsize is size of 1 element in mass<br>
	function comp returns 1(-1) if the first element is larger than the second, -1(1) if the first is smaller, and 0 if the elements are equal <br>
	it has constants: BUBBLE COMB SHELL QUICK MERGE HEAP SELECT INSERTION<br>
# RETURN VALUE 
1, if function have worked correctly, 0 if not<br>
# EXAMPLE
For example we can call sort() for array of integers using qsort:<br>
```code
int main(){
  int mass[] = {1,4,2};
  sort(mass,3,QUICK,0,sizeof(int),compInt);
}
```
