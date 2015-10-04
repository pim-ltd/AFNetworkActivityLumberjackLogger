//
//  AFNetworkingLogging.h
//  AFNetworking
//
//  Created by Tim Robb on 05/10/15.
//  Copyright (c) 2015 Personal Information Management Ltd. All rights reserved.
//

#import "AFNetworkActivityLogger.h"

#if AF_LOGGING_DISABLED

#define AFLogError(frmt, ...) ((void)0)
#define AFLogWarn(frmt, ...) ((void)0)
#define AFLogInfo(frmt, ...) ((void)0)
#define AFLogDebug(frmt, ...) ((void)0)
#define AFLogVerbose(frmt, ...) ((void)0)

#else

#ifndef AF_LOGGING_CONTEXT
#define AF_LOGGING_CONTEXT 0

#endif

#if __has_include("CocoaLumberjack.h")
    #define AF_LOG_LEVEL_DEF (DDLogLevel)[AFNetworkActivityLogger loggingLevel]
    #define CAST (DDLogFlag)
    #import <CocoaLumberjack/CocoaLumberjack.h>
#else
    #define AF_LOG_LEVEL_DEF [AFNetworkActivityLogger loggingLevel]
    #define LOG_ASYNC_ENABLED YES
    #define CAST
    #define LOG_MAYBE(async, lvl, flg, ctx, tag, fnct, frmt, ...) \
        do                                                        \
        {                                                         \
            if ((lvl & flg) == flg)                               \
            {                                                     \
                NSLog(frmt, ##__VA_ARGS__);                       \
            }                                                     \
        } while (0)
#endif

#define AFLogError(frmt, ...) LOG_MAYBE(NO, AF_LOG_LEVEL_DEF, CAST AFNetworkingLoggingMaskError, AF_LOGGING_CONTEXT, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AFLogWarn(frmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, AF_LOG_LEVEL_DEF, CAST AFNetworkingLoggingMaskWarn, AF_LOGGING_CONTEXT, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AFLogInfo(frmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, AF_LOG_LEVEL_DEF, CAST AFNetworkingLoggingMaskInfo, AF_LOGGING_CONTEXT, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AFLogDebug(frmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, AF_LOG_LEVEL_DEF, CAST AFNetworkingLoggingMaskDebug, AF_LOGGING_CONTEXT, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define AFLogVerbose(frmt, ...) LOG_MAYBE(LOG_ASYNC_ENABLED, AF_LOG_LEVEL_DEF, CAST AFNetworkingLoggingMaskVerbose, AF_LOGGING_CONTEXT, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)

#endif
