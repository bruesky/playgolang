package main

import "fmt"

func main()  {
	m1 := map[string]string{
		"name":"KG",
		"age":"40",
	}

	m2 := make(map[string]string)
	fmt.Println(m1)
	fmt.Println(m2)

	for k,v := range m1{
		fmt.Println(k,v)
	}
	if name,ok := m1["nam"]; ok  {
		fmt.Println(name)
	}else {
		fmt.Println("not found")
	}

	delete(m1,"name")
	fmt.Println(m1)
}