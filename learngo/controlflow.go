package main

import (
	"bufio"
	"fmt"
	"io/ioutil"
	"os"
	"strconv"
)

func grade(score int) string  {
	g := ""
	switch{
	case score<60:
		g = "F"
	case score<100:
		g = "A"
	default:
		panic("Not Good!")
	}
	return g
}

func loop()  {
	sum := 0
	for i:=1; i<=100;i++  {
		sum+=i
	}
}

func convertToBin(n int) string{
	ret := ""
	for ;n>0;n/=2{
		lsb := n%2
		ret = strconv.Itoa(lsb)+ret
	}
	return ret
}

func printFile(fileName string)  {
	file,err := os.Open(fileName)
	if err!=nil {
		panic(err)
	}

	scanner := bufio.NewScanner(file)

	for scanner.Scan(){
		fmt.Println(scanner.Text())
	}
}

func forever()  {
	for{
		fmt.Println("abc")
	}
}

func main()  {
	const fileName  = "abc.txt"
	if contents,err := ioutil.ReadFile(fileName);err!=nil {
		fmt.Println(err)
	}else {
		fmt.Printf("%s\n",contents)
	}
	fmt.Println(grade(99))
	fmt.Println(convertToBin(13))
	printFile("abc.txt")
	//forever()
}