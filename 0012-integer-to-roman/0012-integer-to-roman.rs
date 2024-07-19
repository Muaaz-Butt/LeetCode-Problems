impl Solution {
    pub fn int_to_roman(num: i32) -> String {
        let val_to_roman = [
            (1000, "M"), (900, "CM"), (500, "D"), (400, "CD"),
            (100, "C"), (90, "XC"), (50, "L"), (40, "XL"),
            (10, "X"), (9, "IX"), (5, "V"), (4, "IV"), (1, "I")
        ];
        let mut num = num;
        let mut roman = String::new();

        for &(val, numeral) in &val_to_roman {
            while num >= val {
                roman += numeral;
                num -= val;
            }
        }
        roman
    }
}