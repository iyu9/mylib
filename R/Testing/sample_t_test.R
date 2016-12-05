a <- c(70, 67, 81, 92, 78, 62, 85, 73)
b <- c(60, 75, 48, 58, 80, 57, 50)

# one-sample t-testing
t.test(a)
# two-sample t-testing
t.test(x=a, y=b, conf.level=0.95, var.equal=TRUE)
