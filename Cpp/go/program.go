package main

import (
	"fmt"
	"unicode"
)

func main() {
	var str string;
	fmt.Scan(&str);
	ch := rune(str[0]);
	if(unicode.IsUpper(ch)){
		fmt.Printf("%c\n", unicode.ToLower(ch));
	} else {
		fmt.Printf("%c\n", unicode.ToUpper(ch));
	}
}