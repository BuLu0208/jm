#import <Foundation/Foundation.h>

@interface TSListControllerShared : NSObject

- (BOOL)isTrollStore;
- (NSString*)getTrollStoreVersion;
- (void)downloadTrollStoreAndRun:(void (^)(NSString* localTrollStoreTarPath))doHandler;
- (void)installTrollStorePressed;
- (void)updateTrollStorePressed;
- (void)rebuildIconCachePressed;
- (void)refreshAppRegistrationsPressed;
- (void)uninstallPersistenceHelperPressed;
- (void)uninstallTrollStorePressed;

@end