
#ifndef ULTRAHAPTICS_AMPLITUDE_MODULATION_API_HPP__
#define ULTRAHAPTICS_AMPLITUDE_MODULATION_API_HPP__

#define DEFAULT_CONTROL_POINT_FREQUENCY 125

#include "Ultrahaptics.hpp"
#include "UltrahapticsDeviceInfo.hpp"

namespace Ultrahaptics
{
  /** \cond EXCLUDE_FROM_DOCS */
  class DriverDevice;
  /** \endcond */

  /// \brief AmplitudeModulation is the simplest way to create haptic feedback using a default 200 Hz modulation signal.
  ///
  /// See \ref AmplitudeModulation.md for an introduction to the Amplitude Modulation API, and
  /// AmplitudeModulation::Emitter for API details.
  namespace AmplitudeModulation
  {
    class ControlPointImplementation;

    /** \brief Point at which the air pressure is controlled, with position,
     * intensity and frequency.
     *
     * A control point is simply a point in space at which you can specify
     * the desired SPL (Sound Pressure Level) modulation. In almost all cases
     * the control point will coincide with the focal point of the ultrasound.
     * This class supports describing a sine modulation with a given frequency and intensity.
     *
     * The strength and smoothness of the haptic sensation varies with the modulation
     * frequency. If the modulation is unmodulated (0 Hz) then the haptic point cannot be felt at all.
     * We find the strongest sensations are around 100-200 Hz and recommend you experiment
     * to find the best frequency.
     *
     * The modulation intensity is given in arbitrary units varying from 0 to 1.
     *
     */
    class UH_API_CLASS_DECORATION ControlPoint
    {
      public:
     /** Control point constructor that constructs a control point with the
      * specified position and intensity.
      *
      * @param x Control point position in x (metres)
      *
      * @param y Control point position in y (metres)
      *
      * @param z Control point position in z (metres)
      *
      * @param intensity Control point intensity between 0 and 1
      *
      * @param frequency Modulation frequency of this control point (Hertz) */
     UH_API_DECORATION ControlPoint(const float x, const float y, const float z,
        const float intensity, const float frequency = DEFAULT_CONTROL_POINT_FREQUENCY);

     /** Control point constructor that constructs a control point with the
      * specified position and intensity.
      *
      * @param position Control point position (metres)
      *
      * @param intensity Control point intensity between 0 and 1
      *
      * @param frequency Modulation frequency of this control point (Hertz) */
     UH_API_DECORATION ControlPoint(const Ultrahaptics::Vector3 &position,
        const float intensity, const float frequency = DEFAULT_CONTROL_POINT_FREQUENCY);

     /** @deprecated The phase angle has never actually been used. This function will be removed in a future release. */
     UH_API_DECORATION ControlPoint(const float x, const float y, const float z,
        const float intensity, const float frequency, const float phase_angle);

     /** @deprecated The phase angle has never actually been used. This function will be removed in a future release. */
     UH_API_DECORATION ControlPoint(const Ultrahaptics::Vector3 &position,
        const float intensity, const float frequency, const float phase_angle);

     /** Control point copy constructor.
      *
      * @param other The other control point to copy */
     UH_API_DECORATION ControlPoint(const ControlPoint &other);

     /** Control point copy assignment operator.
      *
      * @param other The other control point to copy
      *
      * @return Itself */
     UH_API_DECORATION ControlPoint &operator=(const ControlPoint &other);

     /** Control point destructor. */
     UH_API_DECORATION ~ControlPoint();

     /** @return Control point position (metres) */
     UH_API_DECORATION Ultrahaptics::Vector3 getPosition() const;

     /** Change control point position.
      *
      * @param position New position vector (metres) */
     UH_API_DECORATION void setPosition(const Ultrahaptics::Vector3 &position);

     /** Get the control point modulation intensity.
      *
      * @return Control point intensity */
     UH_API_DECORATION float getIntensity() const;

     /** Change control point intensity.
      *
      * @param intensity New control point intensity between 0 and 1 */
     UH_API_DECORATION void setIntensity(const float intensity);

     /** Get the control point modulation frequncy.
      *
      * @return The frequency of this control point (Hertz). */
     UH_API_DECORATION float getFrequency() const;

     /** Set the frequency of this control point set.
      *
      * @param frequency New control point modulation frequency */
     UH_API_DECORATION void setFrequency(const float frequency);

     /** @deprecated The phase angle has never actually been used. This function will be removed in a future release. */
     UH_API_DECORATION void setPhaseAngle(const float phase_angle);

     /** @deprecated The phase angle has never actually been used. This function will be removed in a future release. */
     UH_API_DECORATION void autoPhaseAngle();

     /** @deprecated The phase angle has never actually been used. This function will be removed in a future release. */
     UH_API_DECORATION float getPhaseAngle() const;

    private:

     /** The control point data. */
     ControlPointImplementation *control_point;
    };

    /** \cond EXCLUDE_FROM_DOCS */
    /** Forward declaration of implementation class */
    class EmitterImplementation;
    /** \endcond */

    /** \brief Emit haptic points using a simple interface and automatic sine-wave amplitude modulation.
     *
     * The simplest way to create haptic sensations is to create an instance of this class, and call update(),
     * passing it one or more ControlPoint%s that specify the location, intensity and modulation frequency
     * of haptic points that you wish to create.
     *
     * The array will continue emitting ultrasound to create these haptic points until you call update() again
     * or call stop(). Here is an example of using Ultrahaptics::AmplitudeModulation::Emitter.
     *
     * ```
     * // Create an emitter.
     * Ultrahaptics::AmplitudeModulation::Emitter emitter;
     *
     * // Set frequency to 200 Hertz and maximum intensity
     * const float frequency = 200.f * Ultrahaptics::Units::hertz;
     * const float intensity = 1.0f;
     *
     * // Position the focal point at 20 centimeters above the array.
     * float distance = 20.0 * Ultrahaptics::Units::centimetres;
     * const Ultrahaptics::Vector3 position1(0.f, 0.f, distance);
     * const Ultrahaptics::ControlPoint point1(position1, intensity, frequency);
     *
     * // Emit the point.
     * emitter.update(point1);
     * ```
     *
     * It is not necessary to perform any other initialisation before creating the Emitter. When one
     * is created for the first time it will initialise the UltrhapticsLibrary and connect to the array.
     *
     * See \ref AmplitudeModulation.md for more information, and the \ref Examples.md section for more examples.
     * */
    class UH_API_CLASS_DECORATION Emitter
    {
      public:
         /** Construct a new emitter. If it has not been done already
          * this will initialise the %Ultrahaptics library and try to
          * connect to an array.
          */
         UH_API_DECORATION Emitter();

         /** Construct a new emitter. If it has not been done already
          * this will initialise the %Ultrahaptics library and try to
          * connect to the specified array. If an array is already connected
          * then it will not try to connect to another, even if a different
          * device identifier is used.
          *
          * See [Board Identification](BoardIdentification.md).
          *
          * @param idevice_identifier `model:serial` or just `model`. E.g. "Dragonfly:0123".
          */
         UH_API_DECORATION Emitter(const char *idevice_identifier);

         /** Destructor for the emitter. This will stop the device emitting
          * and disconnect from it.
          */
         UH_API_DECORATION virtual ~Emitter();

         /** Deleted copy constructor. */
         UH_API_DECORATION Emitter(const Emitter &other) = delete;

         /** Deleted copy assignment operator. */
         UH_API_DECORATION Emitter &operator=(const Emitter &other) = delete;

         /** @deprecated Not required; all relevant functionality is performed by constructor and Emitter::isConnected
          *
          * We do not recommend calling initialize directly and it should not be necessary
          * to call it yourself. When an emitter is constructed, initialize will be called
          * automatically if an %Ultrahaptics device is connected.
          *
          * If you need to check for device connection after emitter construction, we recommend
          * using Emitter::isConnected, which will check for the presence of an %Ultrahaptics device,
          * connect to it if it is present, and then will call initialize for you once it has successfully
          * connected to an %Ultrahaptics device. */
         UH_API_DECORATION virtual void initialize();

         /** Checks for the presence of a suitable %Ultrahaptics device. If one is
          * found, will connect to it and initialize it.
          *
          * @return True if a suitable device is connected after checks */
         UH_API_DECORATION bool isConnected();

         /** Emit one or more control points from the device. Calling this update method with an
          * empty array of ControlPoints is equivalent to calling stop().
          *
          * We recommend not calling update more often than once every 10ms,
          * as calling it too often may cause the device to perform poorly.
          *
          * @param controlpoint Array of control points
          *
          * @param controlpointcount Number of control points in the array.
          *
          * @return True if the update was successful, false if we failed to update a device, e.g. because none is connected.
          */
         UH_API_DECORATION bool update(const ControlPoint *controlpoint, const size_t controlpointcount);

         /** Emit one or more control points from the device. Calling this update method with controlpointcount
          * set to zero is equivalent to calling stop().
          *
          * Although the first parameter is a reference rather than a pointer, internally its address is
          * taken. The following code samples are equivalent.
          *
          * ```
          * ControlPoint pts[4] = ...;
          * emitter.update(pts, 4);
          * // ...
          * emitter.update(&(pts[2]), 1);
          * ```
          *
          * ```
          * ControlPoint pts[4] = ...;
          * emitter.update(pts[0], 4);
          * // ...
          * emitter.update(pts[2]);
          * ```
          *
          * We recommend not calling update more often than once every 10ms,
          * as calling it too often may cause the device to perform poorly.
          *
          * @param controlpoint Reference to the first element in an array of ControlPoint%s.
          *
          * @param controlpointcount Number of control points in the array.
          *
          * @return True if the update was successful, false if we failed to update a device, e.g. because none is connected.
          */
         UH_API_DECORATION bool update(const ControlPoint &controlpoint, const size_t controlpointcount = 1);

         /** Stop emitting.
          *
          * @return True if the update was successful, false if we failed to update a device. */
         UH_API_DECORATION bool stop();

         /** @return Width of the device (metres). */
         UH_API_DECORATION float arrayWidth() const;

         /** @return Depth of the device (metres). */
         UH_API_DECORATION float arrayDepth() const;

         /** @return Addressable width (metres). */
         UH_API_DECORATION float interactionSpaceWidth() const;

         /** @return Addressable height (metres). */
         UH_API_DECORATION float interactionSpaceHeight() const;

         /** @return Addressable depth (metres). */
         UH_API_DECORATION float interactionSpaceDepth() const;

         /** @return The maximum number of control points the connected device supports emitting, or 0 if no device is connected. */
         UH_API_DECORATION unsigned int getMaximumControlPointLimit() const;

         /** Sets the rate at which control points are sent to the emitter's device. Please note that not all devices support this query.
          *
          * Setting this rate above its default may limit how many control points may be sent to the device, and setting it too low may cause degraded performance.
          *
          * If the currently connected device does not support operating at the requested rate, the rate will be unchanged
          * (and thus the return value of this method will be the previous rate, not the requested one).
          *
          * If the currently connected device does not support this operation at all, the method will return 0.
          *
          * @param rate_hz the update rate for the device to operate at, in Hz
          *
          * @return The update rate of the device after attempting to set the rate, or 0 if the device does not support this operation or is not connected. */
         UH_API_DECORATION unsigned setSampleRate(unsigned int rate_hz);

         /** Get the current rate at which updates are sent to the device. Please note that not all devices support this query.
          *
          * If the currently connected device does not support this query, it will return 0.
          * 
          * @return The update rate in Hz currently used by this emitter to send data, or 0 if the device does not support this query or is not connected. */
         UH_API_DECORATION unsigned int getSampleRate() const;

         /** Get the maximum rate at which updates are sent to the device. Please note that not all devices support this query.
          *
          * If the currently connected device does not support this query, it will return 0.
          * 
          * @return The maximum update rate in Hz available for this emitter, or 0 if the device does not support this query or is not connected. */
         UH_API_DECORATION unsigned int getSampleRateLimit() const;

         /** Extensions interface to set extended attributes on the emitter.
          *
          * @param configuration_option The configuration option to set
          *
          * @param configuration_value The configuration setting value
          *
          * @return True if this was recognised as a valid configuration option and setting it succeeded */
         UH_API_DECORATION bool setExtendedOption(const char *configuration_option, const char *configuration_value);

         /** Extensions interface to get extended attributes on the emitter.
          *
          * @param configuration_option The configuration option to get
          *
          * @param buffer The buffer to place the result into
          *
          * @param length The length of the buffer
          *
          * @return The size of the result, regardless of the buffer state */
         UH_API_DECORATION size_t getExtendedOption(const char *configuration_option, char *buffer, const size_t length) const;

         /** Resets the device this emitter is using.
         *
         * @warning Do not attempt to reconnect to a device which has been reset for two seconds.
         * Attempting to reconnect too quickly may result in the device being incorrectly detected. */
         UH_API_DECORATION bool reset();

         /** @return An object containing information about the device backing this emitter, if it is currently connected */
         UH_API_DECORATION DeviceInfo getDeviceInfo() const;

         /** \cond EXCLUDE_FROM_DOCS */
         /** @return The internal device object backing this emitter, if it is currently connected */
         UH_API_DECORATION const DriverDevice* getDriverDevice() const;

         /** @return The internal device object backing this emitter, if it is currently connected */
         UH_API_DECORATION DriverDevice* getDriverDevice();

         /** @return The internal emitter object backing this emitter, if it is currently connected */
         UH_API_DECORATION void* getStateEmitter();
         /** \endcond */

      private:
         /** \cond EXCLUDE_FROM_DOCS */
         /** Internal implementation pointer */
         EmitterImplementation *emitter_impl;
         /** \endcond */
    };
  }
}

#endif
