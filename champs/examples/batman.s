.name "s7yDFIsDRV0DgXxM2gmzs5bq3TjsJ4bqMVaKQqe4VbRxklFYlQqbEigwCcgunZfRNLxYPcVjL0Lf3ip1BK0uZKixhF8P8UXFuRhG4CeibIgZJRwEgxnDyJmtOJuDB3pL"
.comment "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"

loop:
	sti r1,%:live,%1
live:
        live%2
        ld%0, r2
        zjmp%:loop
		