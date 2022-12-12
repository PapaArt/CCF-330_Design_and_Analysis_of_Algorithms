library(magrittr)

dogHuman = read.csv("./files/dog.txthuman.txt.csv") %>% cbind(data.frame(Grupo = "Dog - Human"))
dogChimpanzee = read.csv("./files/dog.txtchimpanzee.txt.csv") %>% cbind(data.frame(Grupo = "Dog - Chimpanzee"))
humanChimpanzee = read.csv("./files/human.txtchimpanzee.txt.csv") %>% cbind(data.frame(Grupo = "Human - Chimpanzee"))

base = dogHuman %>% rbind(dogChimpanzee) %>% rbind(humanChimpanzee)

library(ggplot2)

base$Grupo <- as.factor(base$Grupo)

ggplot(data = base, aes(x = N, y = Similarity, group = Grupo)) +
	geom_line(aes(color = Grupo)) +
	geom_point(aes(color = Grupo)) +
	theme_bw() +
	scale_x_continuous(breaks = c(1:20)) +
	scale_y_continuous(breaks = seq(0.980, 1.000, 0.002))
