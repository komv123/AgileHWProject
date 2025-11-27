package ComputeModule

/**
 * Configuration for ComputeModule parameters
 * Can be instantiated inline similar to TLXbarConfig
 */
case class ComputeConfig(
  width: Int,
  height: Int,
  maxiter: Int
)

object ComputeConfig {
  /** Default configuration: 320x240 resolution, 1000 iterations */
  def default(): ComputeConfig = ComputeConfig(
    width = 320,
    height = 240,
    maxiter = 1000
  )
}
