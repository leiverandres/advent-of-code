package main

import (
	"fmt"
	"io"
	"strconv"
	"unicode"
)

func main() {
	var input string
	sum := 0
	for {
		_, err := fmt.Scan(&input)
		if err != nil {
			if err == io.EOF {
				fmt.Println("Bye bye")
				break
			}
			fmt.Println("Erro: ", err)
		}

		var digits []rune
		for _, char := range input {
			if unicode.IsDigit(char) {
				// fmt.Printf("Found a number: %c\n", char)
				if len(digits) >= 2 {
					digits[1] = char
				} else {
					digits = append(digits, char)
				}
			}
		}

		if len(digits) == 1 {
			digits = append(digits, digits[0])
		}
		digits_s := string(digits)
		val, _ := strconv.Atoi(digits_s)
		sum += val
	}
	fmt.Printf("Sum: %d\n", sum)
}
