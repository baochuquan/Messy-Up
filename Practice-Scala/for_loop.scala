def forLoop {
  println("For Loop using Java Style iteration")
  for(i <- 0 until args.length) {
    println(args(i))
  }
}

forLoop
