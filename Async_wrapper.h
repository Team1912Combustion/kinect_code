
#include "libfreenect.h"
#include <stdint.h>

typedef void * kinectDeviceHandle_t;
typedef void * kinectContextHandle_t;


/* Initialise the kinect 

    Returns:
        handle to context.
*/
kinectContextHandle_t kinect_init(void);

/* Closes kinect 
*/
int kinect_shutdown(kinectContextHandle_t context_handle);
/**
 * Answer which subdevices this library supports.  This is most useful for
 * wrappers trying to determine whether the underlying library was built with
 * audio support or not, so the wrapper can avoid calling functions that do not
 * exist.
 *
 * @return Flags representing the subdevices that the library supports opening (see freenect_device_flags)
 */
int kinect_supported_subdevices(void);
/*Set the log level for the specified freenect context
 
  @param context_handle context to set log level for
  log level set to debug.
 */
void kinect_set_log_level(kinectContextHandle_t context_handle, freenect_loglevel log_lev);
/*opens a kinect device via a context. Index specifies the index of
 * the device on the current state of the bus. Bus resets may cause
 * indexes to shift.
 *
 * @param context_handle Context to open device through
 * @param index Index of the device on the bus
 *
 * @return handle to the device
*/
kinectDeviceHandle_t kinect_open_device(kinectContextHandle_t context_handle, int index, freenect_resolution res, freenect_video_format video_format, freenect_depth_format depth_format);
/**
 * Set the tilt state of the device, in degrees with respect to the
 * horizon.
 * @param handle Device to set tilt state
 * @param freenect_angle Angle the device should tilt to
 *
 * @return 0 on success, < 0 on error.
 */
int kinect_set_tilt_degs(kinectDeviceHandle_t handle,double freenect_angle);
/**
 * Set the state of the LED. Uses blocking control message call to
 * update device.
 * @return 0 on success, < 0 on error
 */
int kinect_set_led(kinectDeviceHandle_t handle,uint32_t option);
/**
 * Closes a device that is currently open
 * @return 0 on success
 */
int kinect_close_device(kinectDeviceHandle_t handle);
/**
 * Start the video information stream for a device.
 * @return 0 on success, < 0 on error
 */
int kinect_start_video(kinectDeviceHandle_t handle);

/* Reads video data and puts it in the video buffer
*/
void kinect_read_video(void *video);

/** Reads video data at low resolution and puts it in the
 *	video buffer
 */
void kinect_read_video_low_res(void *video);
/**
 * Stop the video information stream for a device
 * @return 0 on success, < 0 on error
 */
int kinect_stop_video(kinectDeviceHandle_t handle);
/**
 * Start the video information stream for a device.
 * @return 0 on success, < 0 on error
 */
int kinect_start_depth(kinectDeviceHandle_t handle);

/* Reads depth data and puts it in the depth buffer
 * in (160 x 120) resolution.


/* Reads depth data and puts it in the depth buffer
 * in low resolution (320 x 240) if factor=2
 * or (160 x 120) if factor=4;
*/
void kinect_read_depth_low_res(void *depth, int factor);

/* Reads depth data and puts it in the video buffer
*/
void kinect_read_depth(void *depth);

/**
 * Stop the depth information stream for a device
 * @return 0 on success, < 0 on error
 */
int kinect_stop_depth(kinectDeviceHandle_t handle);