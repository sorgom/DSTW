#include <SYS/Reader.h>
#include <ifs/DataTypes.h>
#include <SYS/IL.h>

#include <fstream>
#include <algorithm>

using stype = std::streamoff;

INSTANCE_DEF(Reader)

void Reader::read(const CONST_C_STRING filename) const
{
    IL::getDispatcher().clear();
    IL::getTSW_Provider().clear();
    IL::getSIG_Provider().clear();
    IL::getLCR_Provider().clear();
    //  SEG not yet implemented

    std::ifstream is(filename, std::ios::binary);
    bool ok = is.good();
    if (ok)
    {
        constexpr static stype nCAP = 4;
        constexpr static stype hSize = nCAP * sizeof(UINT32);
        is.seekg(0, is.end);
        const stype end = is.tellg();
        is.seekg(0, is.beg);
        const stype fsize = end - is.tellg();
        ok = fsize >= hSize;
        if (ok)
        {
            union
            {
                CHAR buf[hSize];
                UINT32 vals[nCAP];
            } head;
            
            is.read(head.buf, hSize);
            auto [nTSW, nSIG, nLCR, nSEG] = head.vals;

            const stype sTSW = nTSW * sizeof(ProjItem);
            const stype sSIG = nSIG * sizeof(ProjItem);
            const stype sLCR = nLCR * sizeof(ProjItem);
            const stype sSEG = nSEG * sizeof(ProjItem);
            const stype sTOT = sTSW + sSIG + sLCR + sSEG;

            ok = (sTOT > 0) and (fsize == hSize + sTOT);

            if (ok)
            {
                const auto mxSize = std::max({sTSW, sSIG, sLCR, sSEG});

                CHAR* buf = new CHAR[static_cast<size_t>(mxSize)];
                if (sTSW > 0)
                { 
                    is.read(buf, sTSW);
                    IL::getTSW_Provider().load(reinterpret_cast<const ProjItem*>(buf), nTSW);
                }
                else
                { pass(); }

                if (sSIG > 0)
                { 
                    is.read(buf, sSIG);
                    IL::getSIG_Provider().load(reinterpret_cast<const ProjItem*>(buf), nSIG);
                }
                else
                { pass(); }

                if (sLCR > 0)
                { 
                    is.read(buf, sLCR);
                    IL::getLCR_Provider().load(reinterpret_cast<const ProjItem*>(buf), nLCR);
                }
                else
                { pass(); }

                //  SEG not yet implemented

                delete [] buf;

                IL::getDispatcher().index();
            }    
            else
            { pass(); }
        }
        else
        { pass(); }

    }
    else
    { pass(); }
    is.close();

    if (not ok)
    {
        IL::getLog().log(COMP_SYS, ERR_STARTUP);
    }
    else
    { pass(); }
}
