run {
	some r: univ -> univ {
		-- niepusta
		some r
		-- przechodniość
		r = ^r
		-- symetria
		r = ~r
		-- funkcyjność
		all u: univ | lone u.r
		-- różnowartościowość
		all disj x: univ, y: univ | no (x.r - y.r)
	}
}
