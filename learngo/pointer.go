package main

import "fmt"

func main()  {
	var a int   = 2
	var p *int  = &a
	*p = 3;
	fmt.Println(a)
}