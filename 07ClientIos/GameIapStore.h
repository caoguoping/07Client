//
//  GameIapStore.h
//  appStoreKit
//
//  Created by wwl on 13-12-5.
//
//

#import  <o4games/gamesEntrenceViewController.h>
#import  <o4games/PassValueDelegate.h>

@interface GameIapStore : NSObject <PassValueDelegate>
{
    NSString*  strUid;  //userid
    NSString*  strOrderNum;   
}


-(id)init;
- (void) SDKLogin;
- (void)activeCharge;
- (void)ChargeHandle:(int)goodsId;

@end
