# install.packages("editrules")
# library(editrules)

dirty.iris <- read.csv("dirty_iris.csv", header=TRUE, sep=",")

print("a)")

print(dirty.iris)
print(nrow(subset(dirty.iris, is.finite(Sepal.Length) & is.finite(Sepal.Width) & is.finite(Petal.Length) & is.finite(Petal.Width))))

print("b)")

E <- editset(c("Sepal.Length <= 30"))

ve <- violatedEdits(E, dirty.iris)

summary(ve)
plot(ve)

print("c)")

E <- editfile("exedits.txt")

print(E)

print("d)")

ve <- violatedEdits(E, dirty.iris)

summary(ve)
