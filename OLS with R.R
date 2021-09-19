
library(tidyverse)
library(lmtest)
library(AER)
library(car)
library(MASS)
library(ggplot2)
data("CPS1988")
help("CPS1988")
str(CPS1988)
head(CPS1988)
with(data = CPS1988, boxplot(wage ~ education))
with(data = CPS1988, boxplot(log(wage) ~ education))
ggplot(data = CPS1988, mapping = aes(x = factor(education), y = log(wage))) +
  geom_boxplot() +
  theme_minimal()
data_cps <- with(data = CPS1988,
                 subset(x = CPS1988, subset = experience > 1 & education > 1))
summary(data_cps)
hist(data_cps$education)

