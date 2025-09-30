import chisel3._
import chiseltest._
import org.scalatest.flatspec.AnyFlatSpec
import org.scalatest.matchers.should.Matchers

class DeviceTest extends AnyFlatSpec with ChiselScalatestTester with Matchers {
  "Device" should "Do stuff" in {
    test(new Device()) { dut =>      

    }
  }
}
