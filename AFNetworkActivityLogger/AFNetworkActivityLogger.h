// AFNetworkActivityLogger.h
//
// Copyright (c) 2013 AFNetworking (http://afnetworking.com/)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

// Defines "levels" of logging that will be used as values in a bitmask that filters log messages.
typedef NS_ENUM (NSUInteger, AFNetworkingLoggingMask)
{
	/** Log all errors */
	AFNetworkingLoggingMaskError = 1 << 0,
	
	/** Log warnings, and all errors */
	AFNetworkingLoggingMaskWarn = 1 << 1,
	
	/** Log informative messagess, warnings and all errors */
	AFNetworkingLoggingMaskInfo = 1 << 2,
	
	/** Log debugging messages, informative messages, warnings and all errors */
	AFNetworkingLoggingMaskDebug = 1 << 3,
	
	/** Log verbose diagnostic information, debugging messages, informative messages, messages, warnings and all errors */
	AFNetworkingLoggingMaskVerbose = 1 << 4,
};

/**
 Defines a mask for logging that will be used by to filter log messages.
 */
typedef NS_ENUM (NSUInteger, AFNetworkingLoggingLevel)
{
	/** Don't log anything */
	AFNetworkingLoggingLevelOff = 0,
	
	/** Log all errors and fatal messages */
	AFNetworkingLoggingLevelError = (AFNetworkingLoggingMaskError),
	
	/** Log warnings, errors and fatal messages */
	AFNetworkingLoggingLevelWarn = (AFNetworkingLoggingLevelError | AFNetworkingLoggingMaskWarn),
	
	/** Log informative, warning and error messages */
	AFNetworkingLoggingLevelInfo = (AFNetworkingLoggingLevelWarn | AFNetworkingLoggingMaskInfo),
	
	/** Log all debugging, informative, warning and error messages */
	AFNetworkingLoggingLevelDebug = (AFNetworkingLoggingLevelInfo | AFNetworkingLoggingMaskDebug),
	
	/** Log verbose diagnostic, debugging, informative, warning and error messages */
	AFNetworkingLoggingLevelVerbose = (AFNetworkingLoggingLevelDebug | AFNetworkingLoggingMaskVerbose),
	
	/** Log everything */
	AFNetworkingLoggingLevelAll = NSUIntegerMax
};

/**
 `AFNetworkActivityLogger` logs requests and responses made by AFNetworking, with an adjustable level of detail.
 
 Applications should enable the shared instance of `AFNetworkActivityLogger` in `AppDelegate -application:didFinishLaunchingWithOptions:`:

        [[AFNetworkActivityLogger sharedLogger] startLogging];
 
 `AFNetworkActivityLogger` listens for `AFNetworkingOperationDidStartNotification` and `AFNetworkingOperationDidFinishNotification` notifications, which are posted by AFNetworking as request operations are started and finish. For further customization of logging output, users are encouraged to implement desired functionality by listening for these notifications.
 */
@interface AFNetworkActivityLogger : NSObject

/**
 The level of logging detail. See "Logging Levels" for possible values. `AFLoggerLevelInfo` by default.
 */
@property (nonatomic, assign) AFNetworkingLoggingLevel level;

/**
 Omit requests which match the specified predicate, if provided. `nil` by default.
 
 @discussion Each notification has an associated `NSURLRequest`. To filter out request and response logging, such as all network activity made to a particular domain, this predicate can be set to match against the appropriate URL string pattern.
 */
@property (nonatomic, strong) NSPredicate *filterPredicate;

/**
 Returns the shared logger instance.
 */
+ (instancetype)sharedLogger;

/**
 Start logging requests and responses.
 */
- (void)startLogging;

/**
 Stop logging requests and responses.
 */
- (void)stopLogging;

@end

///----------------
/// @name Constants
///----------------

/**
 ## Logging Levels

 The following constants specify the available logging levels for `AFNetworkActivityLogger`:

 enum {
 AFNetworkingLoggingLevelOff,
 AFNetworkingLoggingLevelVerbose,
 AFNetworkingLoggingLevelDebug,
 AFNetworkingLoggingLevelInfo,
 AFNetworkingLoggingLevelWarn,
 AFNetworkingLoggingLevelError
 }

 `AFNetworkingLoggingLevelOff`
 Do not log requests or responses.

 `AFNetworkingLoggingLevelDebug`
 Logs HTTP method, URL, header fields, & request body for requests, and status code, URL, header fields, response string, & elapsed time for responses.
 
 `AFNetworkingLoggingLevelInfo`
 Logs HTTP method & URL for requests, and status code, URL, & elapsed time for responses.

 `AFNetworkingLoggingLevelWarn`
 Logs HTTP method & URL for requests, and status code, URL, & elapsed time for responses, but only for failed requests.
 
 `AFNetworkingLoggingLevelError`
 Equivalent to `AFNetworkingLoggingLevelWarn`
*/
