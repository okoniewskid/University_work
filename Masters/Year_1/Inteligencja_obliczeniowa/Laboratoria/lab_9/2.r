iris <- read.csv("iris.csv", header=TRUE, sep=",")

iris.numeric <- iris[1:4]

iris.preproc <- scale(log(iris.numeric))

iris.pca <- prcomp(iris.preproc, retx=TRUE, center=TRUE, scale=TRUE)

iris.data <- predict(iris.pca)[,c(1, 2)]

iris.groups <- kmeans(iris.data, 3)

iris.result <- data.frame(iris, iris.groups$cluster)
colnames(iris.result)[6] <- "cluster"

print("grupy")
print(iris.result)
print("centroidy")
print(iris.groups$centers)

plot(iris.data[iris.groups$cluster == 1, "PC1"], iris.data[iris.groups$cluster == 1, "PC2"], xlab = "PC1", ylab = "PC2", xlim=c(-3.5,2.5), ylim=c(-2.5,3.5), col="black", bg="red", pch=21)
par(new=TRUE)
plot(iris.data[iris.groups$cluster == 2, "PC1"], iris.data[iris.groups$cluster == 2, "PC2"], xlab = "PC1", ylab = "PC2", xlim=c(-3.5,2.5), ylim=c(-2.5,3.5), col="black", bg="green", pch=21)
par(new=TRUE)
plot(iris.data[iris.groups$cluster == 3, "PC1"], iris.data[iris.groups$cluster == 3, "PC2"], xlab = "PC1", ylab = "PC2", xlim=c(-3.5,2.5), ylim=c(-2.5,3.5), col="black", bg="blue", pch=21)
par(new=TRUE)
plot(iris.groups$centers[1, "PC1"], iris.groups$centers[1, "PC2"], xlab = "PC1", ylab = "PC2", xlim=c(-3.5,2.5), ylim=c(-2.5,3.5), col="black", bg="yellow", pch=21, cex=1.5)
par(new=TRUE)
plot(iris.groups$centers[2, "PC1"], iris.groups$centers[2, "PC2"], xlab = "PC1", ylab = "PC2", xlim=c(-3.5,2.5), ylim=c(-2.5,3.5), col="black", bg="cyan", pch=21, cex=1.5)
par(new=TRUE)
plot(iris.groups$centers[3, "PC1"], iris.groups$centers[3, "PC2"], xlab = "PC1", ylab = "PC2", xlim=c(-3.5,2.5), ylim=c(-2.5,3.5), col="black", bg="magenta", pch=21, cex=1.5)

legend("topleft", c("grupa 1" ,"centroid 1", "grupa 2", "centroid 2", "grupa 3" ,"centroid 3"), fill = rainbow(6), cex = 0.75)