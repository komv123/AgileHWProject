import chisel3._
import chisel3.util.log2Ceil

package object Videobuffer {

  case class Configuration(
    bufferSize: Int,
    bufferWidth: Int, 
    sourceCount: Int
  ){
    val busWidth = 8 * bufferWidth
    val maskWidth = bufferWidth
    val addrWidth = log2Ceil(bufferSize)
  }

  object Configuration {
    def default(): Configuration = {
      Configuration(
        1028, // bufferSize
        3, // bufferWidth 3 bytes
        10 // sourceCount
      )
    }
  }
}
