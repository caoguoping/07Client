
//
//  GameIapStore.m
//  appStoreKit
//
//  Created by wwl on 13-12-5.
//
//

#import "GameIapStore.h"
#import  <o4games/GamesManager.h>
#import  <o4games/singleton.h>
#include "CallCppHelper.h"


@implementation GameIapStore
-(id)init
{
    if (self = [super init]) {


    }
    
    return self;
}


//登陆ui调用接口
- (void)SDKLogin
{
    GamesManager *manager =[GamesManager shardFactory];
    [manager entranceforo4gamesGame:self];
  
}

//登陆返回代理
- (void)loginPassValue:(NSDictionary *)value
{
    NSDictionary *valuesDic = value;
    
   // NSString *str =[NSString stringWithFormat:@"sessionid:%@      userid:%@    uname%@ ",[valuesDic objectForKey:@"sessionid"],[valuesDic objectForKey:@"userid"],[valuesDic objectForKey:@"uname"]];
    //NSLog(@"fanhuizhi  %@",str);
    strUid = [valuesDic objectForKey:@"userid"];
    CallCppHelper::getInstance()->iosSetUserId([strUid UTF8String]);
    CallCppHelper::getInstance()->sendLoginData();
  
    
}

/*
//激活调用接口

 */
- (void)activeCharge
{
    GamesManager *manager =[GamesManager shardFactory];
    [manager activeforo4gamesGame:@"1" delegate:self];
}

//激活返回代理
- (void)activePassValue:(NSString *)value
{
    
    NSLog(@"activeBuyPassValue  %@",value);
    
}

/**
//充值调用接口
-(IBAction)buttonClick3:(id)sender
{
    
    GamesManager *manager =[GamesManager shardFactory];
    [manager entranceforpurchaseCommodity:@"knightsagamonthlyv1_480_16" role:@"100002" delegate:self];
    
}
 */

- (void)ChargeHandle:(int)goodsId
{
    GamesManager *manager =[GamesManager shardFactory];
    NSString  *role, *skuId;
    int randomNum = arc4random() % 100000000 + 1;
    strOrderNum = [NSString stringWithFormat:@"%d%@123456789012345678901234567890", randomNum, strUid];
    strOrderNum = [strOrderNum substringToIndex:32];
    CallCppHelper::getInstance()->iosSetOrderNum([strOrderNum UTF8String]);
    
    switch (goodsId)
    {
        case 8403:
            role = [NSString stringWithFormat:@"8403#%@#",strOrderNum];
            skuId = @"guandanShj_160_12";

            break;
        case 8404:
            role = [NSString stringWithFormat:@"8404#%@#",strOrderNum];
            skuId = @"guandanShj_100_10";
            break;
        case 8405:
            role = [NSString stringWithFormat:@"8405#%@#",strOrderNum];
            skuId = @"guandanShj_300_30";
            break;
        case 8406:
            role = [NSString stringWithFormat:@"8406#%@#",strOrderNum];
            skuId = @"guandanShj_500_50";
            break;
        case 8407:
            role = [NSString stringWithFormat:@"8407#%@#",strOrderNum];
            skuId = @"guandanShj_1000_100";
            break;
        case 8408:
            role = [NSString stringWithFormat:@"8408#%@#",strOrderNum];
            skuId = @"guandanShj_100000_6 ";
            break;
        case 8409:
            role = [NSString stringWithFormat:@"8409#%@#",strOrderNum];
            skuId = @"guandanShj_100000_10";
            break;
        case 8410:
            role = [NSString stringWithFormat:@"8410#%@#",strOrderNum];
            skuId = @"guandanShj_300000_30";
            break;
        case 8411:
            role = [NSString stringWithFormat:@"8411#%@#",strOrderNum];
            skuId = @"guandanShj_500000_50";
            break;
        case 8412:
            role = [NSString stringWithFormat:@"8412#%@#",strOrderNum];
            skuId = @"guandanShj_1000000_100";
            break;
        default:
            break;
            
    }
    NSLog(@"\nrole %@",role);
    NSLog(@"\nskuid %@",skuId);
    [manager entranceforpurchaseCommodity:skuId role:role delegate:self];
}


//充值返回代理
- (void)iapPassValue:(NSString *)value
{
    
    NSLog(@"inGamesBuyPassValue  %@",value);
    CallCppHelper::getInstance()->sendOrderNum();
    
}

@end
