# install.packages("class")
# library(class)

# install.packages("neuralnet")
# library(neuralnet)

# install.packages("gmodels")
# library(gmodels)

iris <- read.csv("iris.csv", header=TRUE, sep=",")

print("a)")

normalize <- function(x)
{
	num <- x - min(x)
	denom <- max(x) - min(x)
	return (num/denom)
}

iris_norm <- as.data.frame(lapply(iris[1:4], normalize))

# print(summary(iris_norm))

print("b)")
print("c)")

ind <- sample(2, nrow(iris), replace=TRUE, prob=c(0.7, 0.3))

iris_norm$setosa <- c(iris$class == "Iris-setosa")
iris_norm$versicolor <- c(iris$class == "Iris-versicolor")
iris_norm$virginica <- c(iris$class == "Iris-virginica")
# iris$class <- NULL

iris.training <- iris_norm[ind==1, 1:7]
iris.test <- iris_norm[ind==2, 1:4]

iris.testLabels <- iris[ind==2, 5]

inet <- neuralnet(setosa + versicolor + virginica ~ sepallength + sepalwidth + petallength + petalwidth, iris.training, hidden=3, lifesign="full")
plot(inet)

iris_pred <- compute(inet, iris.test)

print("d)")

scorePrecent <- function(test, pred){
    pm <- data.frame(test,pred)
	wynik <- 0
	for(i in 1:nrow(pm))
		if((pm[i,1] == "Iris-setosa" && round(pm[i,2], digits = 0)) || (pm[i,1] == "Iris-versicolor" && round(pm[i,3], digits = 0)) || (pm[i,1] == "Iris-virginica" && round(pm[i,4], digits = 0)))
			wynik <- wynik + 1
	return(paste(wynik/nrow(pm)*100, "% zostalo poprawnie sklasyfikowanych"))
}

print(scorePrecent(iris.testLabels, iris_pred$net.result))