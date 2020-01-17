#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	int mid=0;
	if(startIndex<=lastIndex)
	{
		mid=(startIndex+lastIndex)/2;
		if(element==array[mid])
		{
			return true;
		}
		else if(element<array[mid])
		{
			return binarySearchReacursive(array,startIndex,mid-1,element);
		}
		else
		{
			return binarySearchReacursive(array,mid+1,lastIndex,element);
		}
	}
	else
	{
		return false;
	}
	

}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
	int mid=0;
	mid=(startIndex+lastIndex)/2;
	while(startIndex<=lastIndex)
	{
		if(array[mid]==element)
		{
			return true;
		}
		else if(array[mid]<element)
		{
			startIndex=mid+1;
		}
		else
		{
			lastIndex=mid-1;
		}
		mid=(startIndex+lastIndex)/2;	
	}
	if(startIndex>lastIndex)
	{
		return false;
	}

}

int main()
{
	int size=0,search=0;
	cout<<"Enter size of array ";
	cin>>size;
	int A[size];
	cout<<"Enter elements of array \n";
	for(int i=0;i<size;i++)
	{
		cin>>A[i];
	}
	sort(A,A+size);
	cout<<"Enter element to be searched in array ";
	cin>>search;
	cout<<"Searching by recursive method.....";
	if(binarySearchReacursive(A,0,size-1,search))
	cout<<"Element found"<<endl;
	else
	cout<<"Element not found"<<endl;
	cout<<"Searching by iterative method.....";
	if(binarySearchIterative(A,0,size-1,search))
	cout<<"Element found";
	else
	cout<<"Element not found";



  return 0;
}
