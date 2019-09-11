package main

import (
	"fmt"
	"math"
	"reflect"
	"runtime"
)

func eval(a, b int, op string) int {
	var res int;
	switch op {
	case "+":
		res = a+b
	case "-":
		res = a-b
	case "*":
		res = a*b
	case "/":
		res = a+b
	default:
		panic("unsupported op: "+op)
	}
	return res
}

func div(a,b int) (int,int)  {
	return a/b,a%b;
}

func div2(a,b int) (q,r int)  {
	q = a/b
	r = a%b
	return
}

func apply(op func(int,int) int, a,b int) int  {
	p := reflect.ValueOf(op).Pointer()
	opName := runtime.FuncForPC(p).Name()
	fmt.Printf("Calling function %s with args (%d %d)",opName,a,b)
	return op(a,b);
}

func sum(numbers ...int) int  {
	s:=0
	for i:=range numbers{
		s+=numbers[i]
	}
	return s
}

func main()  {
	fmt.Println(div(8,3))
	fmt.Println(div2(8,3))
	q,_ := div(9,5)
	fmt.Println(q)
	fmt.Println(apply(func(i int, i2 int) int {
		return int(math.Pow(float64(i),float64(i2)))
	},3,4))
	fmt.Println(sum(1,2,3,4,5))
}
