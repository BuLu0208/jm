#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TSPresentationDelegate : NSObject
+ (void)presentViewController:(UIViewController*)viewController animated:(BOOL)animated completion:(void (^)(void))completion;
+ (void)startActivity:(NSString*)text;
+ (void)startActivity:(NSString*)text withCancelHandler:(void (^)(void))cancelHandler;
+ (void)stopActivityWithCompletion:(void (^)(void))completion;
@end