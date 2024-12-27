#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define TS_ACTIVE_MARKER @".TrollStorePersistenceHelper"
#define TS_INACTIVE_MARKER @".TrollStorePersistenceHelperInactive"
#define APP_ID @"com.opa334.TrollStore"

typedef NS_ENUM(NSUInteger, PERSISTENCE_HELPER_TYPE) {
    PERSISTENCE_HELPER_TYPE_USER = 1 << 0,
    PERSISTENCE_HELPER_TYPE_SYSTEM = 1 << 1,
    PERSISTENCE_HELPER_TYPE_ALL = PERSISTENCE_HELPER_TYPE_USER | PERSISTENCE_HELPER_TYPE_SYSTEM
};

typedef NS_ENUM(NSUInteger, EXPLOIT_TYPE) {
    EXPLOIT_TYPE_CUSTOM_ROOT_CERTIFICATE_V1 = 1 << 0,
    EXPLOIT_TYPE_CMS_SIGNERINFO_V1 = 1 << 1
};

NSString* trollStorePath(void);
NSString* trollStoreAppPath(void);
NSArray* trollStoreInstalledAppBundlePaths(void);
NSArray* trollStoreInactiveInstalledAppBundlePaths(void);
BOOL isRemovableSystemApp(NSString* appId);
LSApplicationProxy* findPersistenceHelperApp(PERSISTENCE_HELPER_TYPE allowedTypes);
void respring(void);
void fetchLatestTrollStoreVersion(void (^completionHandler)(NSString* latestVersion));
void fetchLatestLdidVersion(void (^completionHandler)(NSString* latestVersion));
NSString* rootHelperPath(void);
int spawnRoot(NSString* path, NSArray* args, NSString** stdOut, NSString** stdErr);
BOOL shouldRegisterAsUserByDefault(void);
void chineseWifiFixup(void);
