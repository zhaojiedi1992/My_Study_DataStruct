#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// 交换
void swap(int *arr, i, j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

// 打印
void print_arr_item(int *str, int size) {
    assert(str != NULL);
    printf("size=%d\n",size);
    for (int i = 0; i < size; i++) {
        printf("%d\t", str[i]);
    }
    printf("\n");

}

/// 查找arr有序数组中（0-lastIndex）有序部分item应该插入那个位置。
int find_pos_quick(int *arr, int start, int end, int item) {
    // int pos = end +1 ;
    int left = start;
    int right = end;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (item > arr[mid]) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return left;
}

/// 查找arr有序数组中（0-lastIndex）有序部分item应该插入那个位置。
int find_pos(int *arr, int start, int end, int item) {
    int pos = end + 1;
    for (int j = end; j >= 0 && arr[j] > item; --j) {
        pos = j;
    }
    return pos;
}

// 移动元素。
int move_pos(int *arr, int start, int end) {
    for (int i = end; i >= start; --i) {
        arr[i + 1] = arr[i];
    }
}

void insert_sort(int *arr, int size) {
    if (size <= 1) {
        return;
    }
    // 先认定i=0 这个是有序的， 第一个要插入的就从第二个元素（index=1）开始。
    for (int i = 1; i < size; ++i) {
        // 记录当前值和索引位置。 因为可能发生移动， 会覆盖了这个值，需要暂存下。
        // 暂存的这个值要插入那个位置，最终呢， 需要pos这个标示下。
        int temp = arr[i];
        int pos = i;

        // (0=>i-1) 都是有序的当前， 当前要做的就是将i插入进去，让0=>i是有序的。
        // 应该优先给有序的最后一个元素j=i-1比较，然后再给倒数第二个比较。
        // 如果temp值小于最后一个元素的话， 那就移动一次，插入位置就从移动后腾出来的位置啦。
//        for (int j = i-1; j >=0 && arr[j] > temp  ; --j) {
//            arr[j+1] = arr[j] ;
//            pos = j ;
//        }
        pos = find_pos_quick(arr, 0, i - 1, temp);
        //printf("%d\t", pos);
//        pos= find_pos(arr,0,i-1,temp);
//        printf("%d\t",pos);
        //printf("\n");
        move_pos(arr, pos, i - 1);
        arr[pos] = temp;

    }
    return;
}

void shell_sort(int *arr, int size ){
    if (size<=1){
        return ;
    }
    for (int d=size/2 ; d>=1;d=d/2){
        for (int i = d; i <size ; i+=1) {
            int pos =i ;
            int temp = arr[i] ;

            for (int j = i-d; j >=0 && arr[j] >temp ; j-=d) {
                arr[j+d] = arr[j];
                pos = j;
            }
            arr[pos] = temp;
        }
        printf("\n%d===start==\n",d);
        print_arr_item(arr, size);
        printf("\n%d==end===\n",d);
    }
    return ;
}

void bubble_sort(int *arr, int size ){
    for (int i = 0; i <size ; ++i) {
        for (int j = 0; j <size-1 ; ++j) {
            if (arr[j] > arr[j+1]){
                swap(arr,j,j+1) ;
            }
        }
    }
}

void bubble_sort_quick(int *arr, int size ){
    int exchange = size -1 ;
    int bound ;
    // 边界为0 的时候，退出的。
    while (exchange) {
        bound = exchange;
        exchange = 0 ;
        for (int j = 0; j <bound ; ++j) {
            if (arr[j] > arr[j+1]){
                swap(arr,j,j+1) ;
                // 记录最后一个交换的位置， 说明之后的都是有序的啦。 前面无序。 方便后面缩减边界。
                exchange = j ;
            }
        }
    }
}

int partition(int* arr, int start, int end ){
    int left =start ;
    int right = end;
    int value = arr[start];


    while (left <right){
        while(left<right && arr[right] >=value){
            right -=1 ;
        }
        if (left<right){
            swap(arr,left,right) ;
            left   +=1;
        }

        while(left<right && arr[left]<value){
            left +=1;
        }
        if (left <right){
            swap(arr,left,right) ;
            right-=1;
        }

    }
    return left ;
}
void quick_sort_v1(int *arr,int start,int end){
    if (end -start <=0){
        return;
    }
    int pos = partition(arr,start,end);
    quick_sort_v1(arr,start,pos-1);
    quick_sort_v1(arr,pos+1,end);

    return;
}

void quick_sort(int *arr, int size ){
    if (size <=1){
        return ;
    }
    return quick_sort_v1(arr,0,size-1);
}

// 选择排序
select_sort(int *arr ,int size){
    for (int i = 0; i < size-1; ++i) {
        int minIndex =i  ; 
        int minValue = arr[i] ;
        for (int j = i+1; j <size ; ++j) {
            if (arr[j] < minValue){
                minIndex = j ; 
                minValue = arr[j] ; 
            }
        }
        swap(arr,i,minIndex);
    }
}

int main() {
    int str1[12] = {12, 4, 53, 3, 2, 34, 6, 35, 1, 132, 324, 12};
    int str2[12] = {12, 4, 53, 3, 2, 34, 6, 35, 1, 132, 324, 12};
    int str3[12] = {12, 4, 53, 3, 2, 34, 6, 35, 1, 132, 324, 12};
    int str4[12] = {12, 4, 53, 3, 2, 34, 6, 35, 1, 132, 324, 12};
    int str5[12] = {12, 4, 53, 3, 2, 34, 6, 35, 1, 132, 324, 12};
    int str6[12] = {12, 4, 53, 3, 2, 34, 6, 35, 1, 132, 324, 12};

    printf("打印排序前的原始结果：\n");
    print_arr_item(str1, sizeof(str1) / sizeof(*str1));
    insert_sort(str1, sizeof(str1) / sizeof(*str1));
    printf("打印排序插入排序的结果：\n");
    print_arr_item(str1, sizeof(str1) / sizeof(*str1));


    printf("打印排序前的原始结果：\n");
    print_arr_item(str2, sizeof(str2) / sizeof(*str2));
    shell_sort(str2, sizeof(str2) / sizeof(*str2));
    printf("打印排序希尔排序的结果：\n");
    print_arr_item(str2, sizeof(str2) / sizeof(*str2));

    printf("打印排序前的原始结果：\n");
    print_arr_item(str3, sizeof(str3) / sizeof(*str3));
    bubble_sort_quick(str3, sizeof(str3) / sizeof(*str3));
    printf("打印排序冒泡排序的结果：\n");
    print_arr_item(str3, sizeof(str3) / sizeof(*str3));

    printf("打印排序前的原始结果：\n");
    print_arr_item(str4, sizeof(str4) / sizeof(*str4));
    quick_sort(str4, sizeof(str4) / sizeof(*str4));
    printf("打印排序快速排序的结果：\n");
    print_arr_item(str4, sizeof(str4) / sizeof(*str4));

    printf("打印排序前的原始结果：\n");
    print_arr_item(str5, sizeof(str5) / sizeof(*str5));
    select_sort(str5, sizeof(str5) / sizeof(*str5));
    printf("打印排序选择排序的结果：\n");
    print_arr_item(str5, sizeof(str5) / sizeof(*str5));
}