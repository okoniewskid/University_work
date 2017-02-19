# install.packages("neuralnet")
# library(neuralnet)

siatk.dane <- read.csv("siatk.csv", header=TRUE, sep=",")

siatk.nn <- neuralnet(gra~wiek+waga+wzrost, siatk.dane, hidden=2, lifesign="full")
plot(siatk.nn)

siatk.predict <- compute(siatk.nn, siatk.dane[1:3])

print(siatk.predict$neurons[[1]])
print(siatk.predict$net.result)

funk.siatk <- function(wiek, waga, wzrost)
{
	x1 <- wiek * siatk.nn$weights[[1]][[1]][2,1] + waga * siatk.nn$weights[[1]][[1]][3,1] + wzrost  * siatk.nn$weights[[1]][[1]][4,1] + siatk.nn$weights[[1]][[1]][1,1]
	x2 <- wiek * siatk.nn$weights[[1]][[1]][2,2] + waga * siatk.nn$weights[[1]][[1]][3,2] + wzrost  * siatk.nn$weights[[1]][[1]][4,2] + siatk.nn$weights[[1]][[1]][1,2]
	w1 <- 1/(1+exp(-x1))
	w2 <- 1/(1+exp(-x2))
	x3 <- w1 * siatk.nn$weights[[1]][[2]][2,1] + w2 * siatk.nn$weights[[1]][[2]][3,1] + siatk.nn$weights[[1]][[2]][1,1]
	return (x3)
}