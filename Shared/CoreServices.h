#import <Foundation/Foundation.h>

@interface LSApplicationProxy : NSObject
@property (nonatomic, readonly) NSString *bundleIdentifier;
@property (nonatomic, readonly) NSURL *bundleURL;
@property (nonatomic, readonly) NSString *bundleType;
@property (nonatomic, readonly) NSArray *claimedURLSchemes;
@property (nonatomic, readonly) BOOL installed;
@property (nonatomic, readonly) BOOL restricted;

+ (instancetype)applicationProxyForIdentifier:(NSString*)identifier;
@end

@interface LSApplicationWorkspace : NSObject
+ (instancetype)defaultWorkspace;
- (BOOL)openApplicationWithBundleID:(NSString*)bundleID;
- (void)enumerateApplicationsOfType:(unsigned long long)type block:(void (^)(LSApplicationProxy*))block;
@end

@interface MCMAppContainer : NSObject
@property (nonatomic, readonly) NSURL *url;
+ (instancetype)containerWithIdentifier:(NSString*)identifier createIfNecessary:(BOOL)createIfNecessary existed:(BOOL*)existed error:(NSError**)error;
@end