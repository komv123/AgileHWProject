import chisel3._
import chisel3.util.log2Ceil
import Common._

package object MMU {
  // Re-export Configuration from Common package
  type Configuration = Common.Configuration
  val Configuration = Common.Configuration
}
