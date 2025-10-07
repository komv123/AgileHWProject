import chisel3._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.flatspec.AnyFlatSpec

class HelloSpec extends AnyFlatSpec {
  "Hello" should "pass" in {
    simulate(new Hello()) { dut =>
      var ledStatus = -1
      println("Start the blinking LED")
      for (i <- 0 until 100) {
        dut.clock.step(10000)
        val ledNow = dut.io.led.peek().litValue.toInt
        val s = if (ledNow == 0) "o" else "*"
        if (ledStatus != ledNow) {
          System.out.println(s)
          ledStatus = ledNow
        }
      }
      println("End the blinking LED")
    }
  }
}
