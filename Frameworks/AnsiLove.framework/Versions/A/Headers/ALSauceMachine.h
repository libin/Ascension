//
//  ALSauceMachine.h
//  AnsiLove.framework
//
//  Copyright (c) 2011-2012, Stefan Vogt. All rights reserved.
//  http://byteproject.net
//
//  Use of this source code is governed by a MIT-style license.
//  See the file LICENSE for details.
//
//  Based on libsauce. Copyright (c) 2010, Brian Cassidy. 
//

#import <Foundation/Foundation.h>

// better readability for strcmp() methods
#define IDENTICAL 0

// internal defines and typedefs
#define RECORD_SIZE  128
#define COMMENT_SIZE 64
#define SAUCE_ID     "SAUCE"
#define COMMENT_ID   "COMNT"

typedef struct {
    char             ID[6];
    char             version[3];
    char             title[36];
    char             author[21];
    char             group[21];
    char             date[9];
    int              fileSize;
    unsigned char    dataType;
    unsigned char    fileType;
    unsigned short   tinfo1;
    unsigned short   tinfo2;
    unsigned short   tinfo3;
    unsigned short   tinfo4;
    unsigned char    comments;
    unsigned char    flags;
    char             filler[23];
    char             **comment_lines;
} sauce;

@interface ALSauceMachine : NSObject

// SAUCE record properties
@property (nonatomic, weak)   NSString  *ID;
@property (nonatomic, weak)   NSString  *version;
@property (nonatomic, weak)   NSString  *title;
@property (nonatomic, weak)   NSString  *author;
@property (nonatomic, weak)   NSString  *group;
@property (nonatomic, weak)   NSString  *date;
@property (nonatomic, assign) NSInteger dataType;
@property (nonatomic, assign) NSInteger fileType;
@property (nonatomic, assign) NSInteger tinfo1;
@property (nonatomic, assign) NSInteger tinfo2;
@property (nonatomic, assign) NSInteger tinfo3;
@property (nonatomic, assign) NSInteger tinfo4;
@property (nonatomic, weak)   NSString  *comments;
@property (nonatomic, assign) NSInteger flags;

// SAUCE record BOOL properties
@property (nonatomic, assign) BOOL fileHasRecord;
@property (nonatomic, assign) BOOL fileHasComments;
@property (nonatomic, assign) BOOL fileHasFlags;

// bridge methods (Cocoa)
- (void)readRecordFromFile:(NSString *)inputFile;

// class internal (ye good olde C)
sauce     *sauceReadFileName(char *fileName);
sauce     *sauceReadFile(FILE *file);
void      readRecord(FILE *file, sauce *record);
void      readComments(FILE *file, char **comment_lines, NSInteger comments);
NSInteger sauceWriteFileName(char *fileName, sauce *record);
NSInteger sauceWriteFile(FILE *file, sauce *record);
NSInteger writeRecord(FILE *file, sauce *record);
NSInteger sauceRemoveFileName(char *fileName);
NSInteger sauceRemoveFile(FILE *file);

@end
