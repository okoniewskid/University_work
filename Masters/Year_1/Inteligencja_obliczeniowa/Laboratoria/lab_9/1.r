kSrednich <- function(dane, centroid)
{
	dl <- nrow(dane)
	cl <- nrow(centroid)
	if(dl != 0 && cl != 0)
		grupy <- sample(centroid$nr[1]:centroid$nr[1], size = dl, replace = TRUE)
	else
		grupy <- NULL
	repeat
	{
		ile <- 0
		pm2 <- centroid
		for(i in 1:10)
		{
			min <- sqrt((dane$x[i]-centroid$x[1])^2)+sqrt((dane$y[i]-centroid$y[1])^2)
			for(j in 2:cl)
			{
				pm <- sqrt((dane$x[i]-centroid$x[j])^2)+sqrt((dane$y[i]-centroid$y[j])^2)
				if(min > pm)
				{
					min <- pm
					grupy[i] <- centroid$nr[j]
				}
			}
		}
		for(i in 1:cl)
		{
			if(nrow(dane[grupy == centroid$nr[i], 1:2]) != 0)
			{
				centroid$x[i] <- mean(dane[grupy == centroid$nr[i], 1:2]$x)
				centroid$y[i] <- mean(dane[grupy == centroid$nr[i], 1:2]$y)
			}
			else
			{
				centroid$x[i] <- 0
				centroid$y[i] <- 0
			}				
			if(centroid$x[i] == pm2$x[i] && centroid$y[i] == pm2$y[i])
				ile <- ile + 1
		}
		if(ile == cl)
			break
	}
	return (grupy);
}

k <- 2
ilosc <- 10
zakres <- 10

dane <- data.frame(x = sample(zakres, size = ilosc, replace = TRUE), y = sample(zakres, size = ilosc, replace = TRUE))

print("Dane: ")
print(dane)

centroid <- data.frame(nr = 1:k, x = sample(10, size = k, replace = TRUE), y = sample(10, size = k, replace = TRUE))

print("Centroid: ")
print(centroid)

dane$grupa <- kSrednich(dane, centroid)

print("Dane przydzielone do grup: ")
print(dane)