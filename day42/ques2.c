/*The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:
MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
Example 1:
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]
Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
*/

#include <stdlib.h>
#define MAX 100000
typedef struct {
    int maxH[MAX], minH[MAX];
    int maxSize, minSize;
} MedianFinder;
void swap(int *a,int *b){int t=*a;*a=*b;*b=t;}
void pushMax(MedianFinder* o,int x){
    int i=o->maxSize++;
    o->maxH[i]=x;
    while(i && o->maxH[(i-1)/2]<o->maxH[i]){
        swap(&o->maxH[i],&o->maxH[(i-1)/2]);
        i=(i-1)/2;
    }
}
void pushMin(MedianFinder* o,int x){
    int i=o->minSize++;
    o->minH[i]=x;
    while(i && o->minH[(i-1)/2]>o->minH[i]){
        swap(&o->minH[i],&o->minH[(i-1)/2]);
        i=(i-1)/2;
    }
}
int popMax(MedianFinder* o){
    int r=o->maxH[0];
    o->maxH[0]=o->maxH[--o->maxSize];
    int i=0;
    while(1){
        int l=2*i+1,rn=2*i+2,b=i;
        if(l<o->maxSize && o->maxH[l]>o->maxH[b]) b=l;
        if(rn<o->maxSize && o->maxH[rn]>o->maxH[b]) b=rn;
        if(b==i) break;
        swap(&o->maxH[i],&o->maxH[b]);
        i=b;
    }
    return r;
}
int popMin(MedianFinder* o){
    int r=o->minH[0];
    o->minH[0]=o->minH[--o->minSize];
    int i=0;
    while(1){
        int l=2*i+1,rn=2*i+2,b=i;
        if(l<o->minSize && o->minH[l]<o->minH[b]) b=l;
        if(rn<o->minSize && o->minH[rn]<o->minH[b]) b=rn;
        if(b==i) break;
        swap(&o->minH[i],&o->minH[b]);
        i=b;
    }
    return r;
}
MedianFinder* medianFinderCreate() {
    MedianFinder* o=malloc(sizeof(MedianFinder));
    o->maxSize=o->minSize=0;
    return o;
}
void medianFinderAddNum(MedianFinder* o,int num) {
    pushMax(o,num);
    pushMin(o,popMax(o));
    if(o->maxSize < o->minSize)
    pushMax(o,popMin(o));
}
double medianFinderFindMedian(MedianFinder* o) {
    if(o->maxSize==o->minSize)
    return (o->maxH[0]+o->minH[0])/2.0;
    return o->maxH[0];
}
void medianFinderFree(MedianFinder* o) {
    free(o);
}