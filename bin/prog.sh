#!/usr/bin/env bash
# TODO:  Grab the "cable" number from jtagconfig and bail if no blaster found.
# Maybe restart jtagd and retry if no blater found?
#/opt/intelFPGA_lite/21.1/quartus/bin/jtagconfig -n | grep "USB-Blaster" |

QUARTUS_PGM="/opt/intelFPGA_lite/21.1/quartus/bin/quartus_pgm"
BLASTER_ID="-c 1"
CHAIN_SOF="../../../bin/chain_sof.cdf"
CHAIN_POF_ALL="../../../bin/chain_pof.cdf"
#CHAIN_POF_UFM="../../../bin/chain_sof.cdf"
DEFAULT_CDF=$CHAIN_SOF

if [ -z $1 ]; then 
    #${QUARTUS_PGM} ${BLASTER_ID} ${DEFAULT_CDF};
      echo "Available options:"
      echo "flash       -- flash CFM, UFM and reset device"
      echo "reconfigure -- write only configuration SRAM"
else 
    case $1 in

  flash)
    ${QUARTUS_PGM} ${BLASTER_ID} ${CHAIN_POF_ALL};
    ;;

  reconfigure)
    ${QUARTUS_PGM} ${BLASTER_ID} ${CHAIN_SOF};
    ;;

  #ufm)
  #  ;;

  *)
      echo "Available options:"
      echo "flash       -- flash CFM, UFM and reset device"
      echo "reconfigure -- write only configuration SRAM"
    ;;
    esac
fi

