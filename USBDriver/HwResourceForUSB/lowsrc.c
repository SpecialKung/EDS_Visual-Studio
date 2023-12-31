/***********************************************************************/
/*                                                                     */
/*  FILE        :lowsrc.c                                              */
/*  DATE        :Mon, Jul 06, 2009                                     */
/*  DESCRIPTION :Program of I/O Stream                                 */
/*  CPU TYPE    :Other                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.13).    */
/*                                                                     */
/***********************************************************************/

/* $Id: lowsrc.c 143 2012-05-07 09:16:46Z tmura $ */
#include "USB_CDC.h"
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include "lowsrc.h"
//#include "r_usb_ctypedef.h"     /* Type define */
//#include "r_usb_control.h"
//#include "r_usb_ansi.h"

/* file number */
#define STDIN  0                    /* Standard input (console)        */
#define STDOUT 1                    /* Standard output (console)       */
#define STDERR 2                    /* Standard error output (console) */

#define USB_OFFSET  0x10

#define FLMIN  0                    /* Minimum file number     */
#define _MOPENR 0x1
#define _MOPENW 0x2
#define _MOPENA 0x4
#define _MTRUNC 0x8
#define _MCREAT 0x10
#define _MBIN   0x20
#define _MEXCL  0x40
#define _MALBUF 0x40
#define _MALFIL 0x80
#define _MEOF   0x100
#define _MERR   0x200
#define _MLBF   0x400
#define _MNBF   0x800
#define _MREAD  0x1000
#define _MWRITE 0x2000
#define _MBYTE  0x4000
#define _MWIDE  0x8000
/* File Flags */
#define O_RDONLY 0x0001 /* Read only                                       */
#define O_WRONLY 0x0002 /* Write only                                      */
#define O_RDWR   0x0004 /* Both read and Write                             */
#define O_CREAT  0x0008 /* A file is created if it is not existed          */
#define O_TRUNC  0x0010 /* The file size is changed to 0 if it is existed. */
#define O_APPEND 0x0020 /* The position is set for next reading/writing    */
                        /* 0: Top of the file 1: End of file               */

/* Special character code */
#define CR 0x0d                     /* Carriage return */
#define LF 0x0a                     /* Line feed       */

const int low_nfiles = IOSTREAM;  /* The number of files for input/output files */
char flmod[IOSTREAM];          /* The location for the mode of opened file.  */

unsigned char sml_buf[IOSTREAM];

//#define FPATH_STDIN     "C:\\stdin"
//#define FPATH_STDOUT    "C:\\stdout"
//#define FPATH_STDERR    "C:\\stderr"
#define FPATH_STDIN     "stdin"
#define FPATH_STDOUT    "stdout"
#define FPATH_STDERR    "stderr"

/* H8 Normal mode ,SH and RX */
#if defined( __2000N__ ) || defined( __2600N__ ) || defined( __300HN__ ) || defined( _SH ) || defined( __RX )
/* Output one character to standard output */
extern void charput(char);
/* Input one character from standard input */
extern char charget(void);
/* Output one character to the file        */
extern char fcharput(char, unsigned char);
/* Input one character from the file       */
extern char fcharget(char*, unsigned char);
/* Open the file */
extern char fileopen(char*, unsigned char, unsigned char*);
/* Close the file */
extern char fileclose(unsigned char);
/* Move the file offset */
extern char fpseek(unsigned char, long, unsigned char);
/* Get the file offset */
extern char fptell(unsigned char, long*);

/* H8 Advanced mode */
#elif defined( __2000A__ ) || defined( __2600A__ ) || defined( __300HA__ ) || defined( __H8SXN__ ) || defined( __H8SXA__ ) || defined( __H8SXM__ ) || defined( __H8SXX__ )
/* Output one character to standard output */
extern void charput(char);
/* Input one character from standard input */
extern char charget(void);
/* Output one character to the file        */
extern char fcharput(char, unsigned char);
/* Input one character from the file       */
extern char fcharget(char*, unsigned char);
/* Open the file */
/* Specified as the number of register which stored paramter is 3 */
extern char __regparam3 fileopen(char*, unsigned char, unsigned char*);
/* Close the file */
extern char fileclose(unsigned char);
/* Move the file offset */
extern char fpseek(unsigned char, long, unsigned char);
/* Get the file offset */
extern char fptell(unsigned char, long*);

/* H8300 and H8300L */
#elif defined( __300__ ) || defined( __300L__ )
/* Output one character to standard output */
extern void charput(char);
/* Input one character from standard input */
extern char charget(void);
/* Output one character to the file        */
extern char fcharput(char, unsigned char);
/* Input one character from the file       */
extern char fcharget(char*, unsigned char);
/* Open the file */
/* Specified as the number of register which stored paramter is 3 */
extern char __regparam3 fileopen(char*, unsigned char, unsigned char*);
/* Close the file */
extern char fileclose(unsigned char);
/* Move the file offset */
/* Move the file offset */
extern char __regparam3 fpseek(unsigned char, long, unsigned char);
/* Get the file offset */
extern char fptell(unsigned char, long*);
#endif

#include <stdio.h>
FILE *_Files[IOSTREAM]; // structure for FILE
char *env_list[] = {            // Array for environment variables(**environ)
    "ENV1=temp01",
    "ENV2=temp02",
    "ENV9=end",
    '\0'                        // Terminal for environment variables
};

char **environ = env_list;

/****************************************************************************/
/* _INIT_IOLIB                                                              */
/*  Initialize C library Functions, if necessary.                           */
/*  Define USES_SIMIO on Assembler Option.                                  */
/****************************************************************************/
void _INIT_IOLIB( void )
{
    /* A file for standard input/output is opened or created. Each FILE     */
    /* structure members are initialized by the library. Each _Buf member   */
    /* in it is re-set the end of buffer pointer.                           */

    /* Standard Input File                                                  */
    if( freopen( FPATH_STDIN, "r", stdin ) == NULL )
        stdin->_Mode = 0xffff;  /* Not allow the access if it fails to open */
    stdin->_Mode  = _MOPENR;            /* Read only attribute              */
    stdin->_Mode |= _MNBF;              /* Non-buffering for data           */
    stdin->_Bend = stdin->_Buf + 1;  /* Re-set pointer to the end of buffer */

    /* Standard Output File                                                 */
    if( freopen( FPATH_STDOUT, "w", stdout ) == NULL ) 
        stdout->_Mode = 0xffff; /* Not allow the access if it fails to open */
    stdout->_Mode |= _MNBF;             /* Non-buffering for data           */
    stdout->_Bend = stdout->_Buf + 1;/* Re-set pointer to the end of buffer */
    
    /* Standard Error File                                                  */
    if( freopen( FPATH_STDERR, "w", stderr ) == NULL )
        stderr->_Mode = 0xffff; /* Not allow the access if it fails to open */
    stderr->_Mode |= _MNBF;             /* Non-buffering for data           */
    stderr->_Bend = stderr->_Buf + 1;/* Re-set pointer to the end of buffer */
}

/****************************************************************************/
/* _CLOSEALL                                                                */
/****************************************************************************/
void _CLOSEALL( void )
{
    int i;

    for( i=0; i < low_nfiles; i++ )
    {
        /* Checks if the file is opened or not                               */
        if( _Files[i]->_Mode & (_MOPENR | _MOPENW | _MOPENA ) )
        fclose( _Files[i] );    /* Closes the file                           */
    }
}

/**************************************************************************/
/*       open:file open                                                   */
/*          Return value:File number (Pass)                               */
/*                       -1          (Failure)                            */
/**************************************************************************/
int16_t open(int8_t *name,                  /* File name                      */
     uint16_t  mode,                         /* Open mode                      */
     uint16_t  flg)                          /* Open flag                      */
{
#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    int16_t ret;
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */

    if( strcmp( (const char *)name, FPATH_STDIN ) == 0 )      /* Standard Input file?   */
    {
        if( ( mode & O_RDONLY ) == 0 ) return -1;
        flmod[STDIN] = mode;
        return STDIN;
    }
    else if( strcmp( (const char *)name, FPATH_STDOUT ) == 0 )/* Standard Output file?  */
    {
        if( ( mode & O_WRONLY ) == 0 ) return -1;
        flmod[STDOUT] = mode;
        return STDOUT;
    }
    else if(strcmp( (const char *)name, FPATH_STDERR ) == 0 )  /* Standard Error file?   */
    {
        if( ( mode & O_WRONLY ) == 0 ) return -1;
        flmod[STDERR] = mode;
        return STDERR;
    }
#if USB_ANSIIO_PP != USB_ANSIIO_USE_PP
    else return -1;                             /*Others                  */
#else   /* USB_ANSIIO_PP != USB_ANSIIO_USE_PP */
    else 
    {
        ret = (int16_t)usb_open( (USB_CLASS_ENUM_t)name );
        if( ret != -1 )
        {
            return( (int16_t)(ret + USB_OFFSET) );
        }
    }
    return -1;
#endif  /* USB_ANSIIO_PP != USB_ANSIIO_USE_PP */
}

int16_t close( int16_t fileno )
{
#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    if( fileno >= USB_OFFSET )
    {
        return (int16_t)usb_close( (int16_t)(fileno - USB_OFFSET) );
    }
    else
    {
        return 1;
    }
#else   /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
    return 1;
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
}

/**************************************************************************/
/* write:Data write                                                       */
/*  Return value:Number of write characters (Pass)                        */
/*               -1                         (Failure)                     */
/**************************************************************************/
int32_t write(int16_t  fileno,                  /* File number                    */
      uint8_t *buf,                        /* The address of destination buffer */
      int32_t  count)                       /* The number of chacter to write */
{
    unsigned int    i;                  /* A variable for counter         */
    char             c;                 /* An output character            */

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    if( fileno >= USB_OFFSET )
    {
        return (int32_t)usb_write( (fileno - USB_OFFSET), buf, count );
    }
    else
    {
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
        /* Checking the mode of file , output each character                  */
        /* Checking the attribute for Write-Only, Read-Only or Read-Write     */
        if(flmod[fileno]&O_WRONLY || flmod[fileno]&O_RDWR)
        {
            if( fileno == STDIN ) return -1;            /* Standard Input     */
            else if( (fileno == STDOUT) || (fileno == STDERR) ) 
                                                    /* Standard Error/output   */
            {
                for( i = count; i > 0; --i )
                {
                    c = *buf++;
                    charput(c);
                }
                return count;        /*Return the number of written characters */
            }
            else return -1;                  /* Incorrect file number          */
        }
        else return -1;                      /* An error                       */
#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    }
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
}

int32_t read( int16_t fileno, uint8_t *buf, int32_t count )
{
    unsigned int i;

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    if( fileno >= USB_OFFSET )
    {
        return (int32_t)usb_read( (fileno - USB_OFFSET), buf, count );
    }
    else
    {
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
        /* Checking the file mode with the file number, each character is input and stored the buffer */

       if((flmod[fileno]&_MOPENR) || (flmod[fileno]&O_RDWR)){
             for(i = count; i > 0u; i--){
                   *buf = charget();
                   if(*buf==CR){              /* Replace the new line character */
                         *buf = LF;
                   }
                   buf++;
             }
             return count;
       }
       else {
             return -1;
       }
#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
    }
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */
}

#if USB_ANSIIO_PP == USB_ANSIIO_USE_PP
int16_t control( int16_t fileno, CTLCODE code, void *data )
{
    int16_t err;

    err = usb_control( (uint16_t)(fileno - USB_OFFSET),(USB_CTRLCODE_t) code, data );

    return err;
}
#endif  /* USB_ANSIIO_PP == USB_ANSIIO_USE_PP */

long lseek( short fileno, short offset, short base )
{
    return -1L;
}


/**************************************************************************/

/*void charput(char x)
{
    char    xxx;
    char    *ssr, *tdr;

    ssr = (char *)0x00088254;
    tdr = (char *)0x00088253;

    do {
        xxx = *ssr & 0x04;          // SCI2.SSR.BIT.TEND;
    } while( xxx == 0 );

    if( x == '\n' ) {               // '\n' -> "\r\n"
        *tdr = '\r';                // SCI2.TDR

        do {
            xxx = *ssr & 0x04;      // SCI2.SSR.BIT.TEND;
        } while( xxx == 0 );
    }
    *tdr = x;                       // SCI2.TDR
}

*/
