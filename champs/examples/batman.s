.name "s7yDFIsDRV0DgXxmzs5bq3TjsadJ4bqMVaKQqe4VbRxklFYlQqbEigwCcgunZfRNLxYPcVjL0Lf3ip1BK0uZKixhF8P8UXFuRhG4CeibIgZJRwEgxnDyJmtOJuDB3pL"
.comment "ERx5PaPrIs"

loop:
	sti r1,%:live,%1
live:
        live%2
        ld%0, r2
        zjmp%:loop
