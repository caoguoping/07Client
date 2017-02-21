/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import org.cocos2dx.lib.Cocos2dxActivity;
import android.view.WindowManager;

//import com.example.tbltestsdk.R;
//import com.tbl.tbltestsdk.CrashThread;
import com.tongbulv.sdk.ITBLCallback;
import com.tongbulv.sdk.TBLUserCenter;
import com.tongbulv.sdk.models.TBLResultMsg;
import com.tongbulv.sdk.models.TBLTransferParams;

import android.content.Context;
import android.os.Bundle;
import android.util.Log;




//import android.os.Bundle;
//import android.app.Activity;
//import android.content.Intent;
//import android.view.View;
//import android.view.View.OnClickListener;
//import android.widget.Button;
//import android.widget.Toast;

//import android.os.Bundle;

public class AppActivity extends Cocos2dxActivity implements ITBLCallback {
	
	private static Context mContext;
	private static String mUid;
	private static String mOrderNum; 
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON, WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
		mContext = this;
	}
	
//	public static String createOrderId(String uid, int goodsId, int payAmount)
//	{
//		int iuid = Integer.parseInt(uid);
//		long start_time = System.currentTimeMillis();
//		
//		return "1234455";
//	}
	
	public static void login()
	{
		TBLTransferParams params = new TBLTransferParams();
		params.frm = "tianTianAiGuandan";
		params.fdata = "nothing";
		TBLUserCenter.initClient(mContext, TBLUserCenter.ACTION_TYPE_LOGIN, (AppActivity) mContext, params);
	}
	
	
	public static void payHandle(int igoodsId, int orderNum, int a, int b)
	{
		TBLTransferParams params = new TBLTransferParams();
		
		params.uid =  getmUid();              
		params.cp_param = "1";                
		
		String tempString = String.valueOf((int)(1+Math.random()*100000000)) + getmUid() + "123456789012345678901234567890";
		params.ordernum = tempString.substring(0,32);
		setmOrderNum(params.ordernum);
		
		params.sid = 1; 
		params.gameName = "天天爱掼蛋";   

		params.goodsId = igoodsId;        
		switch(igoodsId)
		{
			case 8401:  
				params.goodsItem = "10钻石";  
				params.pay_amount = 1;       
				params.gold = 10;             
				params.frm = "mall";                
				params.fdata = "mallTestActivity0";    
				break;
				
			case 8403:
				params.goodsItem = "160钻石"; 
				params.pay_amount = 12;        
				params.gold = 160;            
				params.frm = "mall";                 
				params.fdata = "mallTestActivity0";   
				break;
				
			case 8404:
				params.goodsItem = "100钻石"; 
				params.pay_amount = 10;       
				params.gold = 100;            
				params.frm = "mall";          
				params.fdata = "mallzuanshi0";
				break;
				
			case 8405:
				params.goodsItem = "300钻石";  
				params.pay_amount = 30;        
				params.gold = 300;             
				params.frm = "mall";           
				params.fdata = "mallTestActivity0";   
				break;
				
			case 8406:
				params.goodsItem = "500钻石";  
				params.pay_amount = 50;        
				params.gold = 500;             
				params.frm = "mall";           
				params.fdata = "mallTestActivity0";    
				break;
				
			case 8407:
//				params.goodsItem = "1000闁借崵鐓�";  //"20妫版鎹囬惌锟�"
//				params.pay_amount = 100;        //娴滅儤鐨敮渚�鍣炬０锟�(閸忥拷)
//				params.gold = 1000;             //濞撳憡鍨欐稉顓犳畱闁叉垵绔甸妴浣虹埦閻偨锟戒礁鍘撶�规繃鏆�
//				params.frm = "mall";                 //閺夈儲绨�
//				params.fdata = "mallTestActivity0";    //閺夈儲绨幓蹇氬牚
//				break;
				
				//test
				params.goodsId = 8401;
				params.goodsItem = "10钻石";  
				params.pay_amount = 1;        
				params.gold = 10;             
				params.frm = "mall";          
				params.fdata = "mallTestActivity0";  
				break;
				
			case 8408:
				params.goodsItem = "10万金币";  
				params.pay_amount = 6;       
				params.gold = 100000;            
				params.frm = "mall";                
				params.fdata = "mallTestActivity0";    
				break;
				
			case 8409:
				params.goodsItem = "10万金币"; 
				params.pay_amount = 10;        
				params.gold = 100000;          
				params.frm = "mall";           
				params.fdata = "mallTestActivity0";   
				break;
				
			case 8410:
				params.goodsItem = "30万金币";
				params.pay_amount = 30;       
				params.gold = 300000;         
				params.frm = "mall";          
				params.fdata = "mallTestActivity0"; 
				break;
				
			case 8411:
				params.goodsItem = "50万金币";
				params.pay_amount = 50;       
				params.gold = 500000;         
				params.frm = "mall";          
				params.fdata = "mallTestActivity0";  
				break;
				
			case 8412:
				params.goodsItem = "100万金币";
				params.pay_amount = 100;       
				params.gold = 1000000;         
				params.frm = "mall";           
				params.fdata = "mallTestActivity0"; 
				break;
				
			default:
					break;
				
				
		}
		TBLUserCenter.initClient(mContext, TBLUserCenter.ACTION_TYPE_CHARGE, (AppActivity) mContext, params);
		Log.d("callback", "cocos2d-x payhandle " + getmOrderNum());
	}
	
	@Override
	public void failLoginCallBack(int arg0) {
		// TODO Auto-generated method stub
		Log.d("callback","##cocos2d-x failLoginCallBack");
		
	}

	@Override
	public void failPayCallBack(int arg0) {
		// TODO Auto-generated method stub
		Log.d("callback","##cocos2d-x failPayCallBack");
	}

	@Override
	public void loginCallBack(TBLResultMsg arg0) {
		// TODO Auto-generated method stub
		Log.d("callback","##cocos2d-x loginCallBack : " + arg0.code );
		Log.d("callback", "cocos2d-x loginCallBack uid = " + arg0.uid );
		Log.d("callback", "cocos2d-x loginCallBack tocken = " + arg0.access_token );
		setmUid(arg0.uid);
		SDKPlugin.LoginCallback(arg0.uid, arg0.access_token );

	}

	@Override
	public void payCallBack(TBLResultMsg arg0) {

		Log.d("callback","##cocos2d-x payCallBack : arg0.code" + arg0.code);
		
		SDKPlugin.paySecessCallback(getmOrderNum(), "123");
		
		Log.d("callback","##cocos2d-x payCallBack" + getmOrderNum() );
	}


	public static String getmUid() {
		return mUid;
	}


	public static void setmUid(String mUid) {
		AppActivity.mUid = mUid;
	}
	
	
	public static String getmOrderNum() {
		Log.d("callback","##cocos2d-x morderNum in java" + mOrderNum);
		return mOrderNum;
	}


	public static void setmOrderNum(String mOrderNum) {
		AppActivity.mOrderNum = mOrderNum;
	}
}
