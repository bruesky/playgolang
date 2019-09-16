package main

import "fmt"

func printArray(arr [5]int)  {// value copy
	for i,v := range arr {
		fmt.Println(i,v)
	}
}

func printArrayByPointer(arr *[5]int)()  {
	for i,v := range arr {
		fmt.Println(i,v)
	}
}

func update(s []int)  {
	s[0] = 999
}

func demo_slice()  {
	fmt.Println("demo_slice")
	arr := [...]int{0,1,2,3,4,5,6,7,8,9}
	s := arr[2:6]
	fmt.Printf("len %d cap %d\n",len(s),cap(s))
	update(s)
	s = append(s, 222)
	fmt.Println(s)
	fmt.Println(s[1:])
	fmt.Println(arr[:3])
	fmt.Println(arr[3:])
	fmt.Println(arr[7:8])
	update(arr[7:8])
	fmt.Println(arr[7:8])
	fmt.Println(arr)
	ss := arr[:]
	ss = append(ss, 10086)
	fmt.Println(arr)
	fmt.Println(ss)
	fmt.Printf("len %d cap %d\n",len(s),cap(s))
}

func printSlice(s []int)  {
	fmt.Printf("len %d cap %d\n",len(s),cap(s))
}

func main()  {
	var arr [5]int
	arr2 := [3]int{3,4,5}
	arr3 := [...]int{1,3,5,7,9}
	var matrix [4][5]int
	fmt.Println(arr,arr2,arr3)
	fmt.Println(matrix)

	for i := 0;i < len(arr2) ;i++  {
		fmt.Println(arr2[i])
	}

	for i,v :=range arr3 {
		fmt.Println(i,v)
	}

	printArray(arr3)
	printArrayByPointer(&arr3)
	demo_slice()

	var slice []int
	for i := 0; i < 100;i++  {
		printSlice(slice)
		slice = append(slice,i)
	}

	s2 := make([]int,16)
	printSlice(s2)
	s3 := make([]int,10,40)
	printSlice(s3)
	copy(s2,slice)
	fmt.Println(s2)
	printSlice(s2)
	stack := arr3[:]
	stack = stack[:len(stack)-1]
	fmt.Println(stack)
	stack = stack[1:]
	fmt.Println(stack)
	stack = append(stack,10086)
	fmt.Println(stack)
	stack = append([]int{99},stack[:]...)//as list
	fmt.Println(stack)

}
