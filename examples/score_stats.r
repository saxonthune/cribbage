data <- unlist(read.csv("hand_values.csv", header=FALSE))
paste("mean:",mean(data))
paste("std err:",sqrt(var(data)))
table(data)
hist(data, breaks = rep(0:29), xlab="Score", 
     main=paste("Cribbage Hand Values, N =", length(data)))