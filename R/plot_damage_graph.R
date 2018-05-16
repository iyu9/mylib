calc_damage <- function(atk, def)
{
	rand_def <- runif(1, min=0.25, max=1) * def
	return (0.7 * atk) - (0.7 * def + rand_def)
}

sampleAtks <- seq(0, 200, length=20)
sampleDefs <- seq(0, 200, length=20)

#正比例
damages <- c(0)
for(i in 1:20)
{
	node <- calc_damage(sampleAtks[i], sampleDefs[i])
  damages <- append(damages, node)
}
print(damages);

#攻撃のみ比例
atkDamages <- c(0)
for(i in 1:20)
{
	node <- calc_damage(sampleAtks[i], sampleDefs[i])
  atkDamages <- append(atkDamages, node)
}

#防御のみ比例
defDamages <- c(0)
for(i in 1:20)
{
	node <- calc_damage(sampleAtks[i], sampleDefs[i])
  defDamages <- append(defDamages, node)
}

plot(defDamages)
