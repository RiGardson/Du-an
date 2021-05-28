//#include "effect.h"
//#include "TIM.h"

//	
//void wave (int val_test){
//	int j;
//	int a=255,b=0,c=0;
//  int d,e,f ;
//	
//	for (j=1;j<=16;j++){		
//		int k;
//			d=a;
//			e=b;
//			f=c;
//	for (k=1;k<=30;k++){	
//		BIT8_red(d);
//		BIT8_green(e);
//		BIT8_blue(f);
//		TIM_RES(val_test);
//		d=d-16;
//		e=e+16;
//		}
//	a=a-16;
//	b=b+16;
//	
//	}

//	//-------------------
//	for (j=1;j<=16;j++){		
//		int k;
//			d=a;
//			e=b;
//			f=c;
//	for (k=1;k<=30;k++){	
//		BIT8_red(d);
//		BIT8_green(e);
//		BIT8_blue(f);
//		
//		e=e-16;
//		f=f+16;
//		}
//	b=b-16;
//	c=c+16;
//	
//	}
//		//------------------
//	for (j=1;j<=16;j++){		
//		int k;
//			d=a;
//			e=b;
//			f=c;
//	for (k=1;k<=30;k++){	
//		BIT8_red(d);
//		BIT8_green(e);
//		BIT8_blue(f);
//		TIM_RES(val_test);
//		f=f-16;
//		d=d+16;
//		}
//	c=c-16;
//	a=a+16;
//	}
//}

//	


//void BIT8_red (uint8_t red){
//	int i;
//		for (i=0;i<=255;i++){
//			if (((uint8_t)red & (uint8_t)0x01)==1){
//			TIM_set(val_test);
//			}
//		  else {TIM_reset(val_test);}
//		  red = red >> 1;			
//	}
//}

//void BIT8_green (uint8_t green){
//	int i;
//		for (i=0;i<=255;i++){
//			if (((uint8_t)green & (uint8_t)0x01)==1){
//			TIM_set();
//			}
//		  else {TIM_reset();}
//		  green = green >> 1;			
//	}
//}
//void BIT8_blue (uint8_t blue){
//	int i;
//		for (i=0;i<=255;i++){
//			if (((uint8_t)blue & (uint8_t)0x01)==1){
//			TIM_set();
//			}
//		  else {TIM_reset();}
//		  blue = blue >> 1;			
//	}
//}

