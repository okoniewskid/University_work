# install.packages("class")
# library(class)

# install.packages('e1071')
# library(e1071) 

# install.packages('party')
# library(party)

# install.packages("neuralnet")
# library(neuralnet)

# install.packages("gmodels")
# library(gmodels)

diabetes.original <- read.csv(file="diabetes.csv", head=TRUE, sep=",")

normalize <- function(x)
{
	num <- x - min(x)
	denom <- max(x) - min(x)
	return (num/denom)
}

diabetes_norm <- as.data.frame(lapply(diabetes.original[1:8], normalize))

# print(summary(diabetes_norm))

ind <- sample(2, nrow(diabetes_norm), replace=TRUE, prob=c(0.7, 0.3))

diabetes_norm$positive <- c(diabetes.original$class == "tested_positive")
diabetes_norm$negative <- c(diabetes.original$class == "tested_negative")

diabetes.training <- diabetes_norm[ind==1, 1:8]
diabetes.test <- diabetes_norm[ind==2, 1:8]
diabetes.training2 <- diabetes_norm[ind==1, 1:10]

diabetes.trainLabels <- diabetes.original[ind==1, 9]
diabetes.testLabels <- diabetes.original[ind==2, 9]

dnet <- neuralnet(positive + negative ~ pregnant.times + glucose.concentr + blood.pressure + skin.thickness + insulin + mass.index + pedigree.func + age, diabetes.training2, hidden=3, rep=1, stepmax=100000, lifesign="full")

diabetes_knn <- knn(train = diabetes.training, test = diabetes.test, cl = diabetes.trainLabels, k=5)
diabetes_naiveBayes <- predict(naiveBayes(diabetes.training, diabetes.trainLabels), diabetes.test)
diabetes_ctree <- predict(ctree(diabetes.trainLabels ~ pregnant.times + glucose.concentr + blood.pressure + skin.thickness + insulin + mass.index + pedigree.func + age, data=diabetes.training), diabetes.test)
diabetes_net <- compute(dnet, diabetes.test)

scorePrecent <- function(test, pred){
    pm <- data.frame(test,pred)
	wynik <- 0
	for(i in 1:nrow(pm))
		if((pm[i,1] == "tested_positive" && round(pm[i,2], digits = 0)) || (pm[i,1] == "tested_negative" && round(pm[i,3], digits = 0)))
			wynik <- wynik + 1
	return(paste(wynik/nrow(pm)*100, "% zostalo poprawnie sklasyfikowanych"))
}

print(scorePrecent(diabetes.testLabels, diabetes_net$net.result))

scoreRateT <- function(test, pred){
    pm <- data.frame(test,pred)
	wynikTP <- 0
	wynikP <- 0
	if(pm[1,2] == "tested_positive" || pm[1,2] == "tested_negative")
		for(i in 1:nrow(pm))
		{
			if(pm[i,2] == "tested_positive")
			{
				if(pm[i,1] == "tested_positive")
					wynikTP <- wynikTP + 1
				wynikP <- wynikP + 1
			}
		}
	else
		for(i in 1:nrow(pm))
		{
			if(round(pm[i,2], digits = 0) == 1)
			{
				if(pm[i,1] == "tested_positive")
					wynikTP <- wynikTP + 1
				wynikP <- wynikP + 1
			}
		}
	return (wynikTP/wynikP)
}

scoreRateF <- function(test, pred){
    pm <- data.frame(test,pred)
	wynikTN <- 0
	wynikN <- 0
	if(pm[1,2] == "tested_positive" || pm[1,2] == "tested_negative")
		for(i in 1:nrow(pm))
		{
			if(pm[i,2] == "tested_negative")
			{
				if(pm[i,1] == "tested_negative")
					wynikTN <- wynikTN + 1
				wynikN <- wynikN + 1
			}
		}
	else
		for(i in 1:nrow(pm))
		{
			if(round(pm[i,3], digits = 0) == 1)
			{
				if(pm[i,1] == "tested_negative")
					wynikTN <- wynikTN + 1
				wynikN <- wynikN + 1
			}
		}
	return (wynikTN/wynikN)
}

plot(scoreRateT(diabetes.testLabels, diabetes_knn), scoreRateF(diabetes.testLabels, diabetes_knn), xlab = "TPR", ylab = "FPR", xlim=c(0,1), ylim=c(0,1), col="black", bg="red", pch=21)
par(new=TRUE)
plot(scoreRateT(diabetes.testLabels, diabetes_naiveBayes), scoreRateF(diabetes.testLabels, diabetes_naiveBayes), xlab = "TPR", ylab = "FPR", xlim=c(0,1), ylim=c(0,1), col="black", bg="green", pch=21)
par(new=TRUE)
plot(scoreRateT(diabetes.testLabels, diabetes_ctree), scoreRateF(diabetes.testLabels, diabetes_ctree), xlab = "TPR", ylab = "FPR", xlim=c(0,1), ylim=c(0,1), col="black", bg="cyan", pch=21)
par(new=TRUE)
plot(scoreRateT(diabetes.testLabels, diabetes_net$net.result), scoreRateF(diabetes.testLabels, diabetes_net$net.result), xlab = "TPR", ylab = "FPR", xlim=c(0,1), ylim=c(0,1), col="black", bg="purple", pch=21)

legend("topleft", c("knn","naive bayes","ctree","neuralnet"), fill = rainbow(4), cex = 0.75)

# plot(dnet)
