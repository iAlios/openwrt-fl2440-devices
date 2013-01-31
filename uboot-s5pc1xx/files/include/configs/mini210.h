/*
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Gary Jennejohn <gj@denx.de>
 * David Mueller <d.mueller@elsoft.ch>
 *
 * Configuation settings for the SAMSUNG SMDK6400(mDirac-III) board.
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_H
#define __CONFIG_H

/* High Level Configuration Options */
#define CONFIG_SAMSUNG		1	/* SAMSUNG Core */
#define CONFIG_S5P		1	/* S5P Family */
#define CONFIG_S5PC110		1	/* which is in a S5PC110 SoC */
#define CONFIG_MINI210		1

#include <asm/arch/cpu.h>		/* get chip and board defs */

#define CONFIG_ARCH_CPU_INIT
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_MCP_SINGLE	1
#define CONFIG_EVT1		1		/* EVT1 */

/*
 * FASTBOOT
 */
#if 0
#define CONFIG_FASTBOOT		1
#define CONFIG_FUSED		1		/* Fused chip */
#define CONFIG_SECURE		1		/* secure booting */
#endif
#define CONFIG_FASTBOOT		1

#ifdef CONFIG_FASTBOOT
/* Fastboot variables */
#define CFG_FASTBOOT_ADDR_KERNEL		(0x20008000)
#define CFG_FASTBOOT_ADDR_RAMDISK		(0x20A00000)
#define CFG_FASTBOOT_TRANSFER_BUFFER		(0x30000000)
#define CFG_FASTBOOT_TRANSFER_BUFFER_SIZE	(0x8000000) /* 128MB */
#define CFG_FASTBOOT_PAGESIZE			(2048) /* Page size */
#define CFG_FASTBOOT_SDMMC_BLOCKSIZE		(512) /* Block size of sdmmc */

/* Just one BSP type should be defined. */
#define CFG_FASTBOOT_NANDBSP
/* #define CFG_FASTBOOT_ONENANDBSP */
/* #define CFG_FASTBOOT_SDMMCBSP */
#endif

#define BOOT_ONENAND		0x1
#define BOOT_NAND		0x2
#define BOOT_MMCSD		0x3
#define BOOT_NOR		0x4
#define BOOT_SEC_DEV		0x5

#define CONFIG_ZIMAGE_BOOT
#define CONFIG_IMAGE_BOOT

/* 2456 is SMDKV210's mach-types, 3466 is MINI210's mach-types. */
#define MACH_TYPE_MINI210		3466
#define CONFIG_MACH_TYPE		MACH_TYPE_MINI210

/*-------------------- Command definition --------------------*/
#include <config_cmd_default.h>

#define CONFIG_CMD_PING
#define CONFIG_CMD_ELF
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_MMC
/* #define CONFIG_CMD_DATE */ /* compiled error */

/*
 * File system
 */
#define CONFIG_DOS_PARTITION		1	/* vfat and dos */
#define CONFIG_CMD_FAT				/* FAT Support */
#define CONFIG_CMD_EXT2				/* EXT2 Support */

/* YAFFS2 Support*/
#if 1
#define CONFIG_YAFFS2
#define CONFIG_YAFFS_YAFFS1	/* 512b page in 'YAFFS1 compatibility' mode */
#define CONFIG_YAFFS_YAFFS2	/* 2K or larger page NAND in YAFFS2 mode */
#endif

/* JFFS2 Support*/
#if 1
#define CONFIG_CMD_JFFS2
/* Configuration of JFFS2 Partitions */
#define CONFIG_JFFS2_NAND 1
#define CONFIG_JFFS2_DEV        "nand0"
#define CONFIG_JFFS2_PART_SIZE		0x8000000 /* same as (system) */
#define CONFIG_JFFS2_PART_OFFSET	0xE00000
#define CONFIG_JFFS2_CMDLINE 1
#endif

/* UbiFS Support*/
#if 1
#define CONFIG_CMD_UBIFS           
#define CONFIG_CMD_UBI    
#define CONFIG_LZO 
#define CONFIG_RBTREE 
#endif

/* Dynamic MTD partition support */
#define CONFIG_CMD_MTDPARTS
#define CONFIG_MTD_DEVICE  /* needed for mtd parts commands */
#define CONFIG_MTD_PARTITIONS

/* MTD default configuration */
#define MTDIDS_DEFAULT		"nand0=s5p-nand"
#define MTDPARTS_DEFAULT	"mtdparts=s5p-nand:" \
"768k(bootloader)," \
"5m@0x100000(recovery)," \
"5m@0x600000(kernel)," \
"3m@0xB00000(ramdisk)," \
"128m@0xE00000(system)," \
"64m@0x8E00000(cache)," \
"-(userdata)"


/*------------- Miscellaneous configurable options -------------*/
#define CONFIG_INCLUDE_TEST
#define CONFIG_SYS_LONGHELP		/* undef to save memory */
#define CONFIG_SYS_HUSH_PARSER		/* use "hush" command parser    */
#define CONFIG_SYS_PROMPT_HUSH_PS2	"> "
#define CONFIG_SYS_PROMPT		"[u-boot@s5pc1xx]# "
#define CONFIG_SYS_CBSIZE		256 /* Console I/O Buffer Size*/
#define CONFIG_SYS_PBSIZE		384 /* Print Buffer Size */
#define CONFIG_SYS_MAXARGS		16  /* max number of command args */
/* Boot Argument Buffer Size */
#define CONFIG_SYS_BARGSIZE		CONFIG_SYS_CBSIZE
/* valid baudrates */
#define CONFIG_SYS_BAUDRATE_TABLE	{9600, 19200, 38400, 57600, 115200}
/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(CONFIG_ENV_SIZE + 896*1024)

/* commandline and auto complete */
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_CMDLINE_TAG
#define CONFIG_INITRD_TAG
#define CONFIG_CMDLINE_EDITING
#define CONFIG_AUTO_COMPLETE	/* auto complete command */
#define CONFIG_OVERWRITE_ETHADDR_ONCE

/* default boot configurations */
#define CONFIG_ETHADDR			00:40:5c:26:0a:5b
#define CONFIG_NETMASK			255.255.255.0
#define CONFIG_IPADDR			192.168.0.200
#define CONFIG_SERVERIP			192.168.0.100
#define CONFIG_GATEWAYIP		192.168.0.1
#define CONFIG_BOOTDELAY		3
#define CONFIG_ZERO_BOOTDELAY_CHECK
#define CONFIG_BOOTFILE			"uImage"
#define CONFIG_BOOTCOMMAND		"tftp; bootm"
#define CONFIG_BOOTARGS			"root=/dev/mtdblock4 console=ttySAC0,115200 init=/linuxrc"

/*------------------ NAND SD/MMC FLASH ENV and BOOT ---------------*/

/* ENV size */
#define CONFIG_ENV_OVERWRITE  /* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_SIZE		0x20000	/* 128KB */

/* ENV default in nand */
#if 1
#ifndef CONFIG_ENV_IN_NAND_NOT_MMC
#define CONFIG_ENV_IN_NAND_NOT_MMC
#endif
#endif

/* ENV in NAND. default */
#if defined(CONFIG_ENV_IN_NAND_NOT_MMC)
#define CONFIG_ENV_IS_IN_NAND	1
#define CONFIG_ENV_OFFSET	((1<<20) - (CONFIG_ENV_SIZE)) /*for NAND. ENV in 1MB-128K*/

#else /* ENV in SD/MMC */
#define CONFIG_ENV_IS_IN_MMC	1
#define CONFIG_SYS_MMC_ENV_DEV	0
#define RESERVE_BLOCK_SIZE	(512)
#define BL1_SIZE		(8 << 10) /*8 K reserved for BL1*/
#define CONFIG_ENV_OFFSET	((1<<20) - (CONFIG_ENV_SIZE)) /* ENV offset: 1M-128K */
/* #define CONFIG_ENV_OFFSET	(RESERVE_BLOCK_SIZE + BL1_SIZE + ((16 + 512) * 1024)) */

#endif /* CONFIG_ENV_IN_NAND_NOT_MMC */



/************* 1 FLASH *************/
#define CONFIG_SYS_NO_FLASH		1

#ifndef CONFIG_SYS_NO_FLASH
#define CONFIG_CMD_FLASH		/* flinfo, erase, protect */
#define CONFIG_CMD_IMLS			/* List all found images */
#else
#undef CONFIG_CMD_FLASH
#undef CONFIG_CMD_IMLS
#endif

/************* 2 SD/MMC Configuration *************/
#define CONFIG_SPL			/* MMC SPL */
#define CONFIG_GENERIC_MMC		1
#define CONFIG_MMC			1
#define CONFIG_S5P_MMC			1

/************* 3 NAND *************/
#define CONFIG_CMD_NAND
#if defined(CONFIG_CMD_NAND)
#define CONFIG_CMD_NAND_YAFFS
#define CONFIG_CMD_NAND_YAFFS_SKIPFB

#define CONFIG_SYS_MAX_NAND_DEVICE		1
#define CONFIG_SYS_NAND_BASE			(0xB0E000000)
#define CONFIG_NAND_USE_CHIP_NAME		1
#define NAND_MAX_CHIPS				1

#define NAND_DISABLE_CE()		(NFCONT_REG |= (1 << 1))
#define NAND_ENABLE_CE()		(NFCONT_REG &= ~(1 << 1))
#define NF_TRANSRnB()			do { while(!(NFSTAT_REG & (1 << 0))); } while(0)

/* TODO: NOW, NAND and SD/MMC all support Hardware ECC for auto booting */
#define CFG_NAND_HWECC
#define CONFIG_NAND_BL1_8BIT_ECC
#define CONFIG_8BIT_HW_ECC_SLC      1

#undef  CFG_NAND_FLASH_BBT
#endif

/*------------------- memory distribution -------------------*/
#define CONFIG_SYS_SDRAM_BASE           0x20000000
#define CONFIG_SYS_TEXT_BASE            0x23E00000
#define MEMORY_BASE_ADDRESS		CONFIG_SYS_SDRAM_BASE
/* memtest works on */
#define CONFIG_SYS_MEMTEST_START	MEMORY_BASE_ADDRESS
#define CONFIG_SYS_MEMTEST_END		(MEMORY_BASE_ADDRESS + 0x3E00000)  /* 256 MB in DRAM */

/* ONLY 1 Bank of DDRAM USED */
#define CONFIG_NR_DRAM_BANKS	2
#define SDRAM_BANK_SIZE		0x10000000	/* 256+256 MB */
#define PHYS_SDRAM_1		MEMORY_BASE_ADDRESS
#define PHYS_SDRAM_1_SIZE	SDRAM_BANK_SIZE
#if 1
#define PHYS_SDRAM_2		(MEMORY_BASE_ADDRESS + 0x20000000) /* SDRAM Bank #2 */
#define PHYS_SDRAM_2_SIZE	SDRAM_BANK_SIZE
#endif

/* uboot and linux kernel memory distribution */
#define CFG_PHY_UBOOT_BASE	MEMORY_BASE_ADDRESS + 0x3E00000
#define CFG_PHY_KERNEL_BASE	MEMORY_BASE_ADDRESS + 0x8000
/* default load address, as same as CFG_PHY_KERNEL_BASE ??*/
#define CONFIG_SYS_LOAD_ADDR	(PHYS_SDRAM_1 + 0x8000)
#define CONFIG_SYS_INIT_SP_ADDR	(CONFIG_SYS_LOAD_ADDR - GENERATED_GBL_DATA_SIZE)


/* Stack sizes */
#define CONFIG_STACKSIZE	0x40000  /* regular stack 256KB */

/* #define CONFIG_USB_DEVICE	1 */
#ifdef CONFIG_USB_DEVICE
#define CONFIG_USE_IRQ		1
#else
#undef CONFIG_USE_IRQ		/* we don't need IRQ/FIQ stuff */
#endif

#ifdef CONFIG_USE_IRQ
#define CONFIG_STACKSIZE_IRQ	(4*1024)	/* IRQ stack */
#define CONFIG_STACKSIZE_FIQ	(4*1024)	/* FIQ stack */
#endif


/*----------------- board configuration --------------------*/
/* Keep L2 Cache Disabled */
#define CONFIG_L2_OFF                   1
#define CONFIG_SYS_DCACHE_OFF           1

#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_ENABLE_MMU
#endif

#define CONFIG_MEMORY_UPPER_CODE

#define BOARD_LATE_INIT

/* select serial console configuration */
#define CONFIG_SERIAL_MULTI		1
#define CONFIG_SERIAL0			1	/* use SERIAL 0 */
#define CONFIG_BAUDRATE			115200
#define S5PC210_DEFAULT_UART_OFFSET	0x020000

/* PWM */
#define CONFIG_PWM			1

/* input clock of PLL: MINI210 has 24MHz input clock */
#define CONFIG_SYS_CLK_FREQ		24000000

/* the PWM TImer 4 uses a counter of 41687 for 10 ms, so we need */
/* it to wrap 100 times (total 4168750) to get 1 sec. */
#define CONFIG_SYS_HZ			1000		// at PCLK 66MHz


/* DM9000 Ethernet */
#define DM9000_16BIT_DATA
#define CONFIG_CMD_NET
#define CONFIG_CMD_NFS
#define CONFIG_DRIVER_DM9000		1
#define CONFIG_NET_MULTI		1
#define CONFIG_NET_RETRY_COUNT		1
#define CONFIG_DM9000_NO_SROM		1
#ifdef CONFIG_DRIVER_DM9000
#define CONFIG_DM9000_BUGGY_PHY		1
#define CONFIG_DM9000_BASE		(0x88000000)
#define DM9000_IO			(CONFIG_DM9000_BASE)
#define DM9000_DATA			(CONFIG_DM9000_BASE+0x8)
#endif /* CONFIG_DRIVER_DM9000 */

/* USB OTG DNW */
#define CONFIG_S3C_USBD
#define USBD_DOWN_ADDR			(CONFIG_SYS_LOAD_ADDR) /* other: 0x30000000 */

/* USB Support */
#if 0
#ifdef CONFIG_USB_DEVICE
#define CONFIG_CMD_USB
#define CONFIG_USB_OHCI
#define CONFIG_USB_STORAGE
#define CONFIG_USB_KEYBOARD 1
#define CONFIG_DOS_PARTITION
#define CONFIG_SYS_DEVICE_DEREGISTER
#define CONFIG_SUPPORT_VFAT
#define LITTLEENDIAN
#endif
#endif

/* LCD Support*/
#if 0
#define CONFIG_VIDEO
#define CONFIG_CFB_CONSOLE
#define CONFIG_VIDEO_LOGO 1
#endif


/*----------------------------- system clock ----------------------------*/
#if 0
//#define CONFIG_CLK_667_166_166_133
//#define CONFIG_CLK_533_133_100_100
//#define CONFIG_CLK_800_200_166_133
//#define CONFIG_CLK_800_100_166_133
#endif
#define CONFIG_CLK_1000_200_166_133
#if 0
//#define CONFIG_CLK_400_200_166_133
//#define CONFIG_CLK_400_100_166_133
#endif

#if defined(CONFIG_CLK_667_166_166_133)
#define APLL_MDIV       0xfa
#define APLL_PDIV       0x6
#define APLL_SDIV       0x1
#elif defined(CONFIG_CLK_533_133_100_100)
#define APLL_MDIV       0x215
#define APLL_PDIV       0x18
#define APLL_SDIV       0x1
#elif defined(CONFIG_CLK_800_200_166_133) || \
	defined(CONFIG_CLK_800_100_166_133) || \
	defined(CONFIG_CLK_400_200_166_133) || \
	defined(CONFIG_CLK_400_100_166_133)
#define APLL_MDIV       0x64
#define APLL_PDIV       0x3
#define APLL_SDIV       0x1
#elif defined(CONFIG_CLK_1000_200_166_133)
#define APLL_MDIV       0x7d
#define APLL_PDIV       0x3
#define APLL_SDIV       0x1
#endif

#define APLL_LOCKTIME_VAL	0x2cf

#if defined(CONFIG_EVT1)
/* Set AFC value */
#define AFC_ON		0x00000000
#define AFC_OFF		0x10000010
#endif

#if defined(CONFIG_CLK_533_133_100_100)
#define MPLL_MDIV	0x190
#define MPLL_PDIV	0x6
#define MPLL_SDIV	0x2
#else
#define MPLL_MDIV	0x29b
#define MPLL_PDIV	0xc
#define MPLL_SDIV	0x1
#endif

#define EPLL_MDIV	0x60
#define EPLL_PDIV	0x6
#define EPLL_SDIV	0x2

#define VPLL_MDIV	0x6c
#define VPLL_PDIV	0x6
#define VPLL_SDIV	0x3

/* CLK_DIV0 */
#define APLL_RATIO	0
#define A2M_RATIO	4
#define HCLK_MSYS_RATIO	8
#define PCLK_MSYS_RATIO	12
#define HCLK_DSYS_RATIO	16
#define PCLK_DSYS_RATIO 20
#define HCLK_PSYS_RATIO	24
#define PCLK_PSYS_RATIO 28

#define CLK_DIV0_MASK	0x7fffffff

#define set_pll(mdiv, pdiv, sdiv)	(1<<31 | mdiv<<16 | pdiv<<8 | sdiv)

#define APLL_VAL	set_pll(APLL_MDIV,APLL_PDIV,APLL_SDIV)
#define MPLL_VAL	set_pll(MPLL_MDIV,MPLL_PDIV,MPLL_SDIV)
#define EPLL_VAL	set_pll(EPLL_MDIV,EPLL_PDIV,EPLL_SDIV)
#define VPLL_VAL	set_pll(VPLL_MDIV,VPLL_PDIV,VPLL_SDIV)

#if defined(CONFIG_CLK_667_166_166_133)
#define CLK_DIV0_VAL    ((0<<APLL_RATIO)|(3<<A2M_RATIO)|(3<<HCLK_MSYS_RATIO)|(1<<PCLK_MSYS_RATIO)\
			|(3<<HCLK_DSYS_RATIO)|(1<<PCLK_DSYS_RATIO)|(4<<HCLK_PSYS_RATIO)|(1<<PCLK_PSYS_RATIO))
#elif defined(CONFIG_CLK_533_133_100_100)
#define CLK_DIV0_VAL    ((0<<APLL_RATIO)|(3<<A2M_RATIO)|(3<<HCLK_MSYS_RATIO)|(1<<PCLK_MSYS_RATIO)\
			|(3<<HCLK_DSYS_RATIO)|(1<<PCLK_DSYS_RATIO)|(3<<HCLK_PSYS_RATIO)|(1<<PCLK_PSYS_RATIO))
#elif defined(CONFIG_CLK_800_200_166_133)
#define CLK_DIV0_VAL    ((0<<APLL_RATIO)|(3<<A2M_RATIO)|(3<<HCLK_MSYS_RATIO)|(1<<PCLK_MSYS_RATIO)\
			|(3<<HCLK_DSYS_RATIO)|(1<<PCLK_DSYS_RATIO)|(4<<HCLK_PSYS_RATIO)|(1<<PCLK_PSYS_RATIO))
#elif defined(CONFIG_CLK_800_100_166_133)
#define CLK_DIV0_VAL    ((0<<APLL_RATIO)|(7<<A2M_RATIO)|(7<<HCLK_MSYS_RATIO)|(1<<PCLK_MSYS_RATIO)\
			|(3<<HCLK_DSYS_RATIO)|(1<<PCLK_DSYS_RATIO)|(4<<HCLK_PSYS_RATIO)|(1<<PCLK_PSYS_RATIO))
#elif defined(CONFIG_CLK_400_200_166_133)
#define CLK_DIV0_VAL    ((1<<APLL_RATIO)|(3<<A2M_RATIO)|(1<<HCLK_MSYS_RATIO)|(1<<PCLK_MSYS_RATIO)\
			|(3<<HCLK_DSYS_RATIO)|(1<<PCLK_DSYS_RATIO)|(4<<HCLK_PSYS_RATIO)|(1<<PCLK_PSYS_RATIO))
#elif defined(CONFIG_CLK_400_100_166_133)
#define CLK_DIV0_VAL    ((1<<APLL_RATIO)|(7<<A2M_RATIO)|(3<<HCLK_MSYS_RATIO)|(1<<PCLK_MSYS_RATIO)\
			|(3<<HCLK_DSYS_RATIO)|(1<<PCLK_DSYS_RATIO)|(4<<HCLK_PSYS_RATIO)|(1<<PCLK_PSYS_RATIO))
#elif defined(CONFIG_CLK_1000_200_166_133)
#define CLK_DIV0_VAL    ((0<<APLL_RATIO)|(4<<A2M_RATIO)|(4<<HCLK_MSYS_RATIO)|(1<<PCLK_MSYS_RATIO)\
			|(3<<HCLK_DSYS_RATIO)|(1<<PCLK_DSYS_RATIO)|(4<<HCLK_PSYS_RATIO)|(1<<PCLK_PSYS_RATIO))
#endif

#define CLK_DIV1_VAL	((1<<16)|(1<<12)|(1<<8)|(1<<4))
#define CLK_DIV2_VAL	(1<<0)

#if defined(CONFIG_CLK_533_133_100_100)

#if defined(CONFIG_MCP_SINGLE)

#define DMC0_TIMINGA_REF	0x40e
#define DMC0_TIMING_ROW		0x10233206
#define DMC0_TIMING_DATA	0x12130005
#define	DMC0_TIMING_PWR		0x0E100222

#define DMC1_TIMINGA_REF	0x40e
#define DMC1_TIMING_ROW		0x10233206
#define DMC1_TIMING_DATA	0x12130005
#define	DMC1_TIMING_PWR		0x0E100222

#else

#error "You should define memory type (AC type or H type or B type)"

#endif

#elif defined(CONFIG_CLK_800_200_166_133) || \
	defined(CONFIG_CLK_1000_200_166_133) || \
	defined(CONFIG_CLK_800_100_166_133) || \
	defined(CONFIG_CLK_400_200_166_133) || \
	defined(CONFIG_CLK_400_100_166_133)

#if defined(CONFIG_MCP_SINGLE)

#define DMC0_MEMCONTROL		0x00202400	// MemControl	BL=4, 1Chip, DDR2 Type, dynamic self refresh, force precharge, dynamic power down off
#define DMC0_MEMCONFIG_0	0x20F00313	// MemConfig0	256MB config, 8 banks,Mapping Method[12:15]0:linear, 1:linterleaved, 2:Mixed
#define DMC0_MEMCONFIG_1	0x00F00313	// MemConfig1
#if 0
#define DMC0_TIMINGA_REF	0x00000618	// TimingAref	7.8us*133MHz=1038(0x40E), 100MHz=780(0x30C), 20MHz=156(0x9C), 10MHz=78(0x4E)
#define DMC0_TIMING_ROW		0x28233287	// TimingRow	for @200MHz
#define DMC0_TIMING_DATA	0x23240304	// TimingData	CL=3
#define	DMC0_TIMING_PWR		0x09C80232	// TimingPower
#else
#define DMC0_TIMINGA_REF        0x00000618      // TimingAref   7.8us*133MHz=1038(0x40E), 100MHz=780(0x30C), 20MHz=156(0x9C), 10MHz=78(0x4E)
#define DMC0_TIMING_ROW         0x2B34438A      // TimingRow    for @200MHz
#define DMC0_TIMING_DATA        0x24240000      // TimingData   CL=3
#define DMC0_TIMING_PWR         0x0BDC0343      // TimingPower
#endif

#define	DMC1_MEMCONTROL		0x00202400	// MemControl	BL=4, 2 chip, DDR2 type, dynamic self refresh, force precharge, dynamic power down off
#define DMC1_MEMCONFIG_0	0x40F00313	// MemConfig0	512MB config, 8 banks,Mapping Method[12:15]0:linear, 1:linterleaved, 2:Mixed
#define DMC1_MEMCONFIG_1	0x00F00313	// MemConfig1
#if 0
#define DMC1_TIMINGA_REF	0x00000618	// TimingAref	7.8us*133MHz=1038(0x40E), 100MHz=780(0x30C), 20MHz=156(0x9C), 10MHz=78(0x4
#define DMC1_TIMING_ROW		0x28233289	// TimingRow	for @200MHz
#define DMC1_TIMING_DATA	0x23240304	// TimingData	CL=3
#define	DMC1_TIMING_PWR		0x08280232	// TimingPower
#else
#define DMC1_TIMINGA_REF        0x00000618      // TimingAref   7.8us*133MHz=1038(0x40E), 100MHz=780(0x30C), 20MHz=156(0x9C), 10MHz=78(0x4E)
#define DMC1_TIMING_ROW         0x2B34438A      // TimingRow    for @200MHz
#define DMC1_TIMING_DATA        0x24240000      // TimingData   CL=3
#define DMC1_TIMING_PWR         0x0BDC0343      // TimingPower
#endif
#if defined(CONFIG_CLK_800_100_166_133) || defined(CONFIG_CLK_400_100_166_133)
#define DMC0_MEMCONFIG_0	0x20E01323	// MemConfig0	256MB config, 8 banks,Mapping Method[12:15]0:linear, 1:linterleaved, 2:Mixed
#define DMC0_MEMCONFIG_1	0x40F01323	// MemConfig1
#define DMC0_TIMINGA_REF	0x0000030C	// TimingAref	7.8us*133MHz=1038(0x40E), 100MHz=780(0x30C), 20MHz=156(0x9C), 10MHz=78(0x4E)
#define DMC0_TIMING_ROW		0x28233287	// TimingRow	for @200MHz
#define DMC0_TIMING_DATA	0x23240304	// TimingData	CL=3
#define	DMC0_TIMING_PWR		0x09C80232	// TimingPower

#define	DMC1_MEMCONTROL		0x00202400	// MemControl	BL=4, 2 chip, DDR2 type, dynamic self refresh, force precharge, dynamic power down off
#define DMC1_MEMCONFIG_0	0x40C01323	// MemConfig0	512MB config, 8 banks,Mapping Method[12:15]0:linear, 1:linterleaved, 2:Mixed
#define DMC1_MEMCONFIG_1	0x00E01323	// MemConfig1
#define DMC1_TIMINGA_REF	0x0000030C	// TimingAref	7.8us*133MHz=1038(0x40E), 100MHz=780(0x30C), 20MHz=156(0x9C), 10MHz=78(0x4
#define DMC1_TIMING_ROW		0x28233289	// TimingRow	for @200MHz
#define DMC1_TIMING_DATA	0x23240304	// TimingData	CL=3
#define	DMC1_TIMING_PWR		0x08280232	// TimingPower
#endif

#else

#error "You should define memory type (AC type or H type)"

#endif

#else

#define DMC0_TIMINGA_REF	0x50e
#define DMC0_TIMING_ROW		0x14233287
#define DMC0_TIMING_DATA	0x12130005
#define	DMC0_TIMING_PWR		0x0E140222

#define DMC1_TIMINGA_REF	0x618
#define DMC1_TIMING_ROW		0x11344309
#define DMC1_TIMING_DATA	0x12130005
#define	DMC1_TIMING_PWR		0x0E190222

#endif


#if defined(CONFIG_CLK_533_133_100_100)
#define UART_UBRDIV_VAL		26
#define UART_UDIVSLOT_VAL	0x0808
#else
#define UART_UBRDIV_VAL		34
#define UART_UDIVSLOT_VAL	0xDDDD
#endif

#endif	/* __CONFIG_H */


