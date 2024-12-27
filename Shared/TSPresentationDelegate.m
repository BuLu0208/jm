#import "TSPresentationDelegate.h"

static UIViewController* _presentationViewController;
static UIAlertController* _activityController;

@implementation TSPresentationDelegate

+ (void)presentViewController:(UIViewController*)viewController animated:(BOOL)animated completion:(void (^)(void))completion
{
	if(_presentationViewController)
	{
		[_presentationViewController presentViewController:viewController animated:animated completion:completion];
	}
}

+ (void)startActivity:(NSString*)text
{
	[self startActivity:text withCancelHandler:nil];
}

+ (void)startActivity:(NSString*)text withCancelHandler:(void (^)(void))cancelHandler
{
	dispatch_async(dispatch_get_main_queue(), ^{
		if(_activityController)
		{
			[_activityController dismissViewControllerAnimated:NO completion:nil];
		}

		_activityController = [UIAlertController alertControllerWithTitle:text message:@"" preferredStyle:UIAlertControllerStyleAlert];
		
		if(cancelHandler)
		{
			UIAlertAction* cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction* action)
			{
				cancelHandler();
			}];
			[_activityController addAction:cancelAction];
		}

		UIActivityIndicatorView* activityIndicator = [[UIActivityIndicatorView alloc] initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleMedium];
		activityIndicator.translatesAutoresizingMaskIntoConstraints = NO;
		[_activityController.view addSubview:activityIndicator];
		
		[NSLayoutConstraint activateConstraints:@[
			[activityIndicator.centerXAnchor constraintEqualToAnchor:_activityController.view.centerXAnchor],
			[activityIndicator.bottomAnchor constraintEqualToAnchor:_activityController.view.bottomAnchor constant:-16]
		]];
		
		[activityIndicator startAnimating];
		
		[self presentViewController:_activityController animated:YES completion:nil];
	});
}

+ (void)stopActivityWithCompletion:(void (^)(void))completion
{
	dispatch_async(dispatch_get_main_queue(), ^{
		if(_activityController)
		{
			[_activityController dismissViewControllerAnimated:YES completion:completion];
			_activityController = nil;
		}
		else
		{
			if(completion) completion();
		}
	});
}

@end