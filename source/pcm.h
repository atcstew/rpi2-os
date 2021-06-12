#include "pi2.h"

#ifndef pcm_h
#define pcm_h
#define PCMBASE (PI2BASE + 0x203000)

#define PCM_CS      (unsigned int *)(PCMBASE + 0x0)
#define PCM_FIFO    (unsigned int *)(PCMBASE + 0x4)
#define PCM_MODE    (unsigned int *)(PCMBASE + 0x8)
#define PCM_RXC     (unsigned int *)(PCMBASE + 0xc)
#define PCM_TXC     (unsigned int *)(PCMBASE + 0x10)
#define PCM_DREQ    (unsigned int *)(PCMBASE + 0x14)
#define PCM_INTEN   (unsigned int *)(PCMBASE + 0x18)
#define PCM_INTSTC  (unsigned int *)(PCMBASE + 0x1c)
#define PCM_GRAY    (unsigned int *)(PCMBASE + 0x20)

/*PCM Control and Status Register */ 
#define PCM_CS_EN       BIT0        //PCM Enable
#define PCM_CS_RXON     BIT1        //Receive Enable
#define PCM_CS_TXON     BIT2        //Transmit Enable
#define PCM_CS_TXCLR    BIT3        //Transmit Clear Fifo
#define PCM_CS_RXCLR    BIT4        //Receive Clear Fifo
/*CS BITs 5-6 are TXW threshold */
/*CS BITs 7-8 are RXR threshold */
#define PCM_CS_DMAEN    BIT9        //DMA DREQ Enable
/*CS BITs 10-12 are reserved */
#define PCM_CS_TXSYNC   BIT13       //TX Fifo Out of Sync
#define PCM_CS_RXSYNC   BIT14       //RX Fifo Out of Sync
#define PCM_CS_TXERR    BIT15       //TX (Over|Under)flow Error
#define PCM_CS_RXERR    BIT16       //RX (Over|Under)flow Error
#define PCM_CS_TXW      BIT17       //TX Fifo Needs Writing
#define PCM_CS_RXR      BIT18       //RX Fifo Needs Reading
#define PCM_CS_TXD      BIT19       //TX Fifo Can Accept Data
#define PCM_CS_RXD      BIT20       //RX Fifo Contains Data
#define PCM_CS_TXE      BIT21       //TX Fifo Is Empty
#define PCM_CS_RXF      BIT22       //RX Fifo Is Full
#define PCM_CS_RXSEX    BIT23       //RX Sign Extend
#define PCM_CS_SYNC     BIT24       //PCM Clock Sync Helper
#define PCM_CS_STBY     BIT25       //RAM Standby
/*CS BITs 26-31 are reserved*/ 


/*PCM Mode Register*/
/*MODE BITs 0-9 are frame sync length*/
/*MODE BITs 10-19 are frame length*/
#define PCM_MODE_FSI        BIT20   //PCM Frame Sync Invert
#define PCM_MODE_FSM        BIT21   //PCM Frame Sync Mode
#define PCM_MODE_CLKI       BIT22   //PCM Clock Invert
#define PCM_MODE_CLKM       BIT23   //PCM Clock Mode
#define PCM_MODE_FTXP		BIT24   //Transmit Frame Packed Mode
#define PCM_MODE_FRXP       BIT25   //Receive Frame Packed Mode
#define PCM_PDME            BIT26   //PDM Input Mode Enable
#define PCM_PDMN            BIT27   //PDM Decimation Factor
#define PCM_MODE_CLK_DIS    BIT28   //PCM Clock Disable
/*MODE BITs 29-31 are reserved*/


/*PCM Receive Configuration Register */
/*RXC BITs 0-3  are channel 2 width*/
/*RXC BITs 4-13 are channel 2 position*/
#define PCM_RXC_CH2EN       BIT14    //RX Channel 2 Enable
#define PCM_RXC_CH2WEX      BIT15    //RX Channel 2 Width Extension BIT
/*RXC BITs 16-19 are channel 1 width */
/*RXC BITs 20-29 are channel 1 position */
#define PCM_RXC_CH1EN       BIT30   //RX Channel 1 Enable
#define PCM_RXC_CH1WEX      BIT31   //RX Channel 1 Width Extension BIT


/*PCM Transmit Configuration Register */
/*TXC BITs 0-3 are channel 2 width */
/*TXC BITs 4-13 are channel 2 position */
#define PCM_TXC_CH2EN        BIT14  //TX Channel 2 Enable
#define PCM_TXC_CH2WEX       BIT15  //TX Channel 2 Width Extension BIT
/*TXC BITs 16-19 are channel 1 width */
/*TXC BITs 20-29 are channel 1 position */
#define	PCM_TXC_CH1EN		 BIT30  //TX Channel 1 Enable
#define PCM_TXC_CH1WEX		 BIT31  //TX Channel 1 Width Extension BIT

/*PCM DMA Request Level Register */
/*DREQ BITs 0-6 are RX request level */
/*DREQ BIT 7 is reserved */
/*DREQ BITs 8-14 are TX request level */
/*DREQ BIT 15 is reserved */
/*DREQ BITs 16-22 are RX panic level */
/*DREQ BIT 23 is reserved */
/*DREQ BITs 24-30 are TX panic level */
/*DREQ BIT is reserved */


/*PCM Interrupt Enable Register */
#define PCM_INTEN_TXW       BIT0    //TX Write Interrupt Enable
#define PCM_INTEN_RXR       BIT1    //RX Read Interrupt Enable
#define PCM_INTEN_TXERR     BIT2    //TX Error Interrupt Enable
#define PCM_INTEN_RXERR     BIT3    //RX Error Interrupt Enable
/*INTEN BITs 4-31 are reserved*/


/*PCM Interrupt Status And Clear Register */
#define PCM_INTSTC_TXW       BIT0   //TX Write Interrupt Status/Clear
#define PCM_INTSTC_RXR       BIT1   //RX Read Interrupt Status/Clear
#define PCM_INTSTC_TXERR     BIT2   //TX Error Interrupt Status/Clear
#define PCM_INTSTC_RXERR     BIT3   //RX Error Interrupt Status/Clear
/*INTSTC BITs 4-31 are reserved*/


/*PCM Gray Mode Control Register */
#define PCM_GRAY_EN         BIT0    //GRAY Mode Enable
#define PCM_GRAY_CLR        BIT1    //GRAY Mode Clear Logic
#define PCM_GRAY_FLUSH      BIT2    //GRAY Mode Flush RX Buffer into Fifo
/*GRAY BIT 3 is reserved */
/*GRAY BITs 4-9 are RX level */
/*GRAY BITs 10-15 are RX flushed number */
/*GRAY BITs 16-22 are RX FIFO level */
/*GRAY BITs 22-31 are reserved*/

#endif

