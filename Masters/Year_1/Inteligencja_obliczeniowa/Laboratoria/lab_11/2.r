# install.packages("sets")
# library(sets)

przeksztalcenie <- function(w, z, p)
{
	return ((w/z)*p)
}

sets_options("universe", seq(from = 0, to = 100, by = 0.1))

variables <- set(
	temp = fuzzy_variable(
		niska = fuzzy_triangular(corners = c(przeksztalcenie(-12.5,45,100), przeksztalcenie(0,45,100), przeksztalcenie(12.5,45,100)), height = 1),
		srednia = fuzzy_triangular(corners = c(przeksztalcenie(10,45,100), przeksztalcenie(20,45,100), przeksztalcenie(30,45,100)), height = 1),
		wysoka = fuzzy_triangular(corners = c(przeksztalcenie(25,45,100), przeksztalcenie(30,45,100), przeksztalcenie(35.5,45,100)), height = 1),
		b_wysoka = fuzzy_triangular(corners = c(przeksztalcenie(30,45,100), przeksztalcenie(45,45,100), przeksztalcenie(60,45,100)), height = 1)
	),
	wilg = fuzzy_variable(
		sucho = fuzzy_triangular(corners = c(-30, 0, 30), height = 1),
		przyjemnie = fuzzy_triangular(corners = c(20, 35, 50), height = 1),
		wilgotno = fuzzy_triangular(corners = c(40, 60, 70), height = 1),
		mokro = fuzzy_triangular(corners = c(60, 100, 140), height = 1)
	),
	sz_spr = fuzzy_variable(
		wyl = fuzzy_triangular(corners = c(-1, 0, 1), height = 1),
		niska = fuzzy_triangular(corners = c(30, 45, 60), height = 1),
		srednia = fuzzy_triangular(corners = c(50, 65, 80), height = 1),
		wysoka = fuzzy_triangular(corners = c(70, 100, 130), height = 1)
	)
)

rules <- set(
	fuzzy_rule(temp %is% niska && wilg %is% sucho, sz_spr %is% wyl),
	fuzzy_rule(temp %is% niska && wilg %is% przyjemnie, sz_spr %is% wyl),
	fuzzy_rule(temp %is% niska && wilg %is% wilgotno, sz_spr %is% wyl),
	fuzzy_rule(temp %is% niska && wilg %is% mokro, sz_spr %is% niska),
	fuzzy_rule(temp %is% srednia && wilg %is% sucho, sz_spr %is% wyl),
	fuzzy_rule(temp %is% srednia && wilg %is% przyjemnie, sz_spr %is% wyl),
	fuzzy_rule(temp %is% srednia && wilg %is% wilgotno, sz_spr %is% niska),
	fuzzy_rule(temp %is% srednia && wilg %is% mokro, sz_spr %is% srednia),
	fuzzy_rule(temp %is% wysoka && wilg %is% sucho, sz_spr %is% niska),
	fuzzy_rule(temp %is% wysoka && wilg %is% przyjemnie, sz_spr %is% srednia),
	fuzzy_rule(temp %is% wysoka && wilg %is% wilgotno, sz_spr %is% wysoka),
	fuzzy_rule(temp %is% wysoka && wilg %is% mokro, sz_spr %is% wysoka),
	fuzzy_rule(temp %is% b_wysoka && wilg %is% sucho, sz_spr %is% srednia),
	fuzzy_rule(temp %is% b_wysoka && wilg %is% przyjemnie, sz_spr %is% wysoka),
	fuzzy_rule(temp %is% b_wysoka && wilg %is% wilgotno, sz_spr %is% wysoka),
	fuzzy_rule(temp %is% b_wysoka && wilg %is% mokro, sz_spr %is% wysoka)
)

system <- fuzzy_system(variables, rules)
plot(system) 

fi <- fuzzy_inference(system, list(temp = 5, wilg = 30))
print(gset_defuzzify(fi, "centroid"))

fi <- fuzzy_inference(system, list(temp = 23, wilg = 65))
print(gset_defuzzify(fi, "centroid"))

fi <- fuzzy_inference(system, list(temp = 23, wilg = 85))
print(gset_defuzzify(fi, "centroid"))

fi <- fuzzy_inference(system, list(temp = 35, wilg = 35))
print(gset_defuzzify(fi, "centroid"))
