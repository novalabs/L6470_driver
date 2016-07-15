/* COPYRIGHT (c) 2016 Nova Labs SRL
 *
 * All rights reserved. All use of this software and documentation is
 * subject to the License Agreement located in the file LICENSE.
 */

#pragma once

#include <core/hw/EXT.hpp>
#include <core/hw/GPIO.hpp>
#include <core/hw/SPI.hpp>

namespace core {
namespace L6470_driver {
class L6470
{
public:
   L6470(
      core::hw::SPIDevice&  spi,
      core::hw::EXTChannel& ext,
      core::hw::Pad&        stby,
      core::hw::Pad&        flag
   );

   virtual
   ~L6470();

   bool
   probe();

   uint16_t
   getStatus();

   void
   run(
      int32_t speed
   );

   void
   move(
      int32_t steps
   );

   void
   moveto(
      int32_t position
   );

   void
   resetPosition();


protected:
   core::hw::SPIDevice&  _spi;
   core::hw::EXTChannel& _ext;
   core::hw::Pad&        _stby;
   core::hw::Pad&        _flag;

private:
   void
   transfer(
      uint16_t n,
      uint8_t* txbuf,
      uint8_t* rxbuf
   );

   uint32_t
   getParam(
      uint8_t param
   );

   void
   setParam(
      uint8_t  param,
      uint32_t value
   );
};
}
}
