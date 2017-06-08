/**
 * @Author: Luis Holanda <luisholanda>
 * @Date:   08-Jun-2017
 * @Email:  luiscmholanda@gmail.com
 * @Last modified by:   luisholanda
 * @Last modified time: 08-Jun-2017
 */

#include "CRC.h"

namespace CRC32
{

    CRC32::CRC32()
    {
        compute_table();
    }

    CRC32::~CRC32()
    {}

    void CRC32::compute_table(void)
    {
        unsigned long c;
        int n, k;

        for (n = 0; n < 256; ++n) {
            c = static_cast<unsigned long>(n);

            for (k = 0; k < 8; ++k) {
                if (c & 1) {
                    c = 0xEDB88320L ^ (c >> 1);
                } else {
                    c = c >> 1;
                }
            }

            mTable[n] = c;
        }
    }

    unsigned long CRC32::update_crc(std::string inString)
    {
        unsigned long c = mCrc ^ 0xffffffffL;
        int n;

        for (n = 0; n < inString.length(); ++n) {
            unsigned long cast = static_cast<unsigned long> (inString[n]);
            c = mTable[(c ^ cast) & 0xff] ^ (c >> 8);
        }

        mCrc = c ^ 0xffffffffL;

        return mCrc;
    }

    unsigned long CRC32::get_crc(std::string inString)
    {
        return update_crc(inString);
    }

} /* CRC32 */
