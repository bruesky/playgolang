package main

import (
	"fmt"
	"math"
)
//package level
var name  = "XK"
var age  = 23
//gender:= "Male"

var(
	course = "MPP"
	score = 99
	)

func variable()  {
	var a int
	var s string
	fmt.Printf("%d %q\n",a,s)
}

func variableInitValue()  {
	var a int  = 8
	var s string = "abc"
	fmt.Println(a,s)
}

func variableTypeDeduction()  {
	var a,b,s  = 999,true,"hello"
	fmt.Println(a,b,s)
}

func variableShorter()  {
	a,b,s  := 996,false,"hello2"
	fmt.Println(a,b,s)
}

func consts()  {
	const fileName = "abc.txt"
	const a,b  = 3,4
	var c int
	c = int(math.Sqrt(a*a+b*b))
	fmt.Println(c)
}

func enums(){
	const(
		cpp = iota
		java
		python
		js
		golang
	)

	const(
		b = 1<<(10*iota)
		kb
		mb
		gb
		tb
		pb
	)

	fmt.Println(cpp,java,python,js,golang)
	fmt.Println(b,kb,mb,gb,tb,pb)
}

func main()  {
	fmt.Println("Hello World")
	variable()
	variableInitValue()
	variableTypeDeduction()
	variableShorter()
	fmt.Println(name,age,course,score)
	consts()
	enums()
}

// builtin types
//bool string
//int uint int8 uint8 int16 uint16 int32 uint32 int64 unit64 uintptr
//byte(8 bit) rune(32 bit)
//float32 float64 complex64 complex128
