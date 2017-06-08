/**
 * @Author: Luis Holanda <luisholanda>
 * @Date:   08-Jun-2017
 * @Email:  luiscmholanda@gmail.com
 * @Last modified by:   luisholanda
 * @Last modified time: 08-Jun-2017
 */

#ifndef ROSETTA_CODE_CRC_H
#define ROSETTA_CODE_CRC_H

#include <string>

namespace CRC32
{

   class CRC32
   {
   private:
       unsigned long mTable[256];
       unsigned long mCrc = 0x00000000L;

       void compute_table (void);

   public:
       CRC32 ();
       virtual ~CRC32 ();

       unsigned long update_crc (std::string);
       unsigned long get_crc(std::string);
   };

} /* CRC32 */

#endif // ROSETTA_CODE_CRC_H
