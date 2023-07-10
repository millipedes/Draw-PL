canvas(                 \
  color(255, 255, 255), \
  "test_name.png",      \
  height(1000),         \
  width(1000)           \
) {
  ell = ellipse(           \
    minor_axis(15.0 + 15), \
    major_axis(17.0),      \
    point(1.0, 1.0)        \
  )
  the_point = point(10.0, 30.0)
  x = line(          \
    from(the_point), \
    to(rect)         \
  )
  for i in range(8 + -3) {
    x = line(          \
      from(the_point), \
      to(rect)         \
    )
  }
  for i in range(8 - -3, 16) {
    x = line(          \
      from(the_point), \
      to(rect)         \
    )
  }
  x = 15 * 8 + 32 * 9
  if(x > (x + 2)) {
    x = line(          \
      from(the_point), \
      to(rect)         \
    )
  }
  z = x[13]
  z = []
  z = [x]
  z = [13 - -3, 42.0, "string"]
  rect = rectangle(   \
    height(1.0),      \
    width(1.0),       \
    point(30.0, 30.0) \
  )
  x = line(                   \
    from(                     \
      ellipse(                \
        major_axis(15.0),     \
        minor_axis(17.0),     \
        color(255, 255, 255), \
        point(1.0, 1.0),      \
        thickness(10 + 13)    \
      )                       \
    ),                        \
    to(                       \
      rectangle(              \
        width(1.0),           \
        height(1.0),          \
        color(255, 255, 255), \
        point(30.0, 30.0)     \
      )                       \
    )                         \
  )
}
