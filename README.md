# QWERTY: AGAIN!
After too many failed attempts and simplifications, QWERTY finally half-works!
## Specials
I decided that the letters in the program's name would run trivial programs. And it works!
* `q`: Hello, World!
* `w`: Cat(one line only :< how to fix?)
* `e`: Quine(logs `e`)

The other letters&#x2026;I will implement later.
## Standard
QWERTY uses 256 memcells of chars. Various operators can combine adjacent memcells.
### Memcell Movement
* `)`: move one memcell right, wraps
* `(` move one memcell left, wraps
### Constants
* `0`&#x2013`9`: Sets memcell to a one-digit number.
### Memcell Combination
* `&`: `10a + b`.
	Multiplies current cell by 10 and adds the memcell to its right, clearing it.
	Allows multi-digit numbers, eg. `5)3(&`(sets memcell to `53`).
* `+`, `-`, `*`, `/`: Self-explanatory operators on memcell and next.
	Clears next memcell.