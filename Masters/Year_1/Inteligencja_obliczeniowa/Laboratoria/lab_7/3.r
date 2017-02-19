 install.packages("deducorrect")
 library(deducorrect)

 install.packages("VIM")
 library(VIM)

dirty.iris <- read.csv("dirty_iris.csv", header=TRUE, sep=",")

R <- correctionRules("excorrections.txt")

cor <- correctWithRules(R, dirty.iris)

print('a)')

clean.iris.mean <- cor$corrected

clean.iris.mean$Sepal.Length[is.na(clean.iris.mean$Sepal.Length)] <- mean(clean.iris.mean$Sepal.Length, na.rm = TRUE)
clean.iris.mean$Sepal.Width[is.na(clean.iris.mean$Sepal.Width)] <- mean(clean.iris.mean$Sepal.Width, na.rm = TRUE)
clean.iris.mean$Petal.Length[is.na(clean.iris.mean$Petal.Length)] <- mean(clean.iris.mean$Petal.Length, na.rm = TRUE)
clean.iris.mean$Petal.Width[is.na(clean.iris.mean$Petal.Width)] <- mean(clean.iris.mean$Petal.Width, na.rm = TRUE)

print(clean.iris.mean)

print('b)')

clean.iris.knn <- cor$corrected

clean.iris.knn <- kNN(clean.iris.knn)

print(clean.iris.knn)