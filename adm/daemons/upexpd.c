#include <ansi.h>

int *exp=({
        10000,//1
        30000,
        50000,//3
        70000,
        100000,//5
        125000,
        150000,//7
        200000,
        250000,//9
        300000,
        350000,//11
        400000,
        450000,//13
        500000,
        600000,//15
        700000,
        800000,//17
        900000,
        1000000,//19
        1200000,
        1400000,//21
        1600000,
        1800000,//23
        2000000,
        2300000,//25
        2600000,
        3000000,//27
        3400000,
        3800000,//29
        4200000,
        4800000,//31
        5800000,
        6500000,//33
        7500000,
        9000000,//35
        10000000,
        12000000,//37
        14000000,
        16000000,//39
        17000000,//40
        18000000,//41
        19000000,//42
        20000000,//43
        22000000,//44
        24000000,//45
        26000000,//46
        28000000,//47
        30000000,//48
        32000000,//49 
        34000000, //50
        36000000, //51
        38000000, //52
        40000000, //53
        42000000, //54
        44000000, //55
        46000000,//56
        48000000,//57
        50000000,//58
        52000000,//59
        54000000,//60
        56000000,//61
        58000000,//62
        60000000,//63
        62000000,//64
        64000000,//65
        66000000,//66
        68000000,//67
        70000000,//68
        72000000,//69
        74000000,//70
        76000000,//71
        78000000,//72
        80000000,//73
        82000000,//74
        84000000,//75
        86000000,//76
        88000000,//77
        90000000,//78
        92000000,//79
        94000000,//80
        96000000,//81
        98000000,//82
        100000000,//83
        111000000,//84
        112000000,//85
        113000000,//86
        114000000,//87
        115000000,//88
        116000000,//89
        118000000,//90
        120000000,//91
        130000000,//92
        140000000,//93
        150000000,//94
        160000000,//95
//      170000000,//96
//      180000000,//97
//      190000000,//98
//      200000000,//99
});
/**************************************************************************************************/

//added by gslxz@2002/11/30
string query_upexp(object ob)
{
        int exp;

        exp = (int)ob->query("combat_exp");
   
            if(exp >=0 && exp < 10000){
                        ob->set("level",0);
                return  " 0" ;  
        }
        else if(exp >=10000 && exp < 30000){
                       ob->set("level",1);
                return  " 1" ;  
        }
        else if(exp >= 30000 && exp < 50000){
                       ob->set("level",2);
                return  " 2" ;  
        }
        else if(exp >= 50000 && exp < 70000){
                        ob->set("level",3);
                return  " 3" ;
        }
        else if(exp >= 70000 && exp < 100000){
                        ob->set("level",4);
                return  " 4" ;  
        }
        else if(exp >= 100000 && exp < 125000){
                        ob->set("level",5);
                return  " 5" ;  
        }
        else if(exp >= 125000 && exp < 150000){ 
                        ob->set("level",6);
                return  " 6" ;  
        }
        else if(exp >= 150000 && exp < 200000){ 
                        ob->set("level",7);
                return  " 7" ;  
        }
        else if(exp >= 200000 && exp < 250000){ 
                        ob->set("level",8);
                return  " 8" ;  
        }
        else if(exp >= 250000 && exp < 300000){ 
                        ob->set("level",9);
                return  " 9" ;  
        }
        else if(exp >= 300000 && exp < 350000){ 
                        ob->set("level",10);
                return  "10" ;  
        }
        else if(exp >= 350000 && exp < 400000){ 
                        ob->set("level",11);
                return  "11" ;  
        }
        else if(exp >= 400000 && exp < 450000){ 
                        ob->set("level",12);
                return  "12" ;  
        }
        else if(exp >= 450000 && exp < 500000){ 
                        ob->set("level",13);
                return  "13" ;  
        }
        else if(exp >= 500000 && exp < 600000){ 
                        ob->set("level",14);
                return  "14" ;  
        }
        else if(exp >= 600000 && exp < 700000){ 
                        ob->set("level",15);
                return  "15" ;  
        }
        else if(exp >= 700000 && exp < 800000){ 
                        ob->set("level",16);
                return  "16" ;  
        }
        else if(exp >= 800000 && exp < 900000){ 
                        ob->set("level",17);
                return  "17" ;  
        }
        else if(exp >= 900000 && exp < 1000000){ 
                        ob->set("level",18);
                return  "18" ;  
        }
        else if(exp >= 1000000 && exp < 1200000){ 
                        ob->set("level",19);
                return  "19" ;  
        }
        else if(exp >= 1200000 && exp < 1400000){ 
                        ob->set("level",20);
                return  "20" ;  
        }
        else if(exp >= 1400000 && exp < 1600000){ 
                        ob->set("level",21);
                return  "21" ;  
        }
        else if(exp >= 1600000 && exp < 1800000){ 
                        ob->set("level",22);
                return  "22" ;  
        }
        else if(exp >= 1800000 && exp < 2000000){ 
                        ob->set("level",23);
                return  "23" ;  
        }
        else if(exp >= 2000000 && exp < 2300000){ 
                        ob->set("level",24);
                return  "24" ;  
        }
        else if(exp >= 2300000 && exp < 2600000){ 
                        ob->set("level",25);
                return  "25" ;  
        }
        else if(exp >= 2600000 && exp < 3000000){ 
                        ob->set("level",26);
                return  "26" ;  
        }
        else if(exp >= 3000000 && exp < 3400000){ 
                        ob->set("level",27);
                return  "27" ;  
        }
        else if(exp >= 3400000 && exp < 3800000){ 
                        ob->set("level",28);
                return  "28" ;  
        }
        else if(exp >= 3800000 && exp < 4200000){ 
                        ob->set("level",29);
                return  "29" ;  
        }
        else if(exp >= 4200000 && exp < 4800000){ 
                        ob->set("level",30);
                return  "30" ;  
        }
        else if(exp >= 4800000 && exp < 5800000){ 
                        ob->set("level",31);
                return  "31" ;  
        }
        else if(exp >= 5800000 && exp < 6500000){ 
                        ob->set("level",32);
                return  "32" ;  
        }
        else if(exp >= 6500000 && exp < 7500000){ 
                        ob->set("level",33);
                return  "33" ;  
        }
        else if(exp >= 7500000 && exp < 9000000){ 
                        ob->set("level",34);
                return  "34" ;  
        }
        else if(exp >= 9000000 && exp < 10000000){ 
                        ob->set("level",35);
                return  "35" ;  
        }
        else if(exp >= 10000000 && exp < 12000000){ 
                        ob->set("level",36);
                return  "36" ;  
        }
        else if(exp >= 12000000 && exp < 14000000){ 
                        ob->set("level",37);
                return  "37" ;  
        }
        else if(exp >= 14000000 && exp < 16000000){ 
                        ob->set("level",38);
                return  "38" ;  
        }
        else if(exp >= 16000000 && exp < 17000000){ 
                        ob->set("level",39);
                return  "39" ;  
        }
        else if(exp >= 17000000 && exp < 18000000){ 
                        ob->set("level",40);
                return  "40" ;  
        }
        else if(exp >= 18000000 && exp < 19000000){ 
                        ob->set("level",41);
                return  "41" ;  
        }
        else if(exp >= 19000000 && exp < 20000000){ 
                        ob->set("level",42);
                return  "42" ;  
        }
        else if(exp >= 20000000 && exp < 22000000){ 
                        ob->set("level",43);
                return  "43" ;  
        }
        else if(exp >= 22000000 && exp < 24000000){ 
                        ob->set("level",44);
                return  "44" ;  
        }
        else if(exp >= 24000000 && exp < 26000000){ 
                        ob->set("level",45);
                return  "45" ;  
        }
        else if(exp >= 26000000 && exp < 28000000){ 
                        ob->set("level",46);
                return  "46" ;  
        }
        else if(exp >= 28000000 && exp < 30000000){ 
                        ob->set("level",47);
                return  "47" ;  
        }
        else if(exp >= 30000000 && exp < 32000000){ 
                        ob->set("level",48);
                return  "48" ;  
        }
        else if(exp >= 32000000 && exp < 34000000){ 
                        ob->set("level",49);
                return  "49" ;  
        }
        else if(exp >= 34000000 && exp < 36000000){ 
                        ob->set("level",50);
                return  "50" ;  
        }
        else if(exp >= 36000000 && exp < 38000000){ 
                        ob->set("level",51);
                return  "51" ;  
        }
        else if(exp >= 38000000 && exp < 40000000){ 
                        ob->set("level",52);
                return  "52" ;  
        }
        else if(exp >= 40000000 && exp < 42000000){ 
                        ob->set("level",53);
                return  "53" ;  
        }
        else if(exp >= 42000000 && exp < 44000000){ 
                        ob->set("level",54);
                return  "54" ;  
        }
        else if(exp >= 44000000 && exp < 46000000){ 
                        ob->set("level",55);
                return  "55" ;  
        }
        else if(exp >= 46000000 && exp < 48000000){ 
                        ob->set("level",56);
                return  "56" ;  
        }
        else if(exp >= 48000000 && exp < 50000000){ 
                        ob->set("level",57);
                return  "57" ;  
        }        
        else if(exp >= 50000000 && exp < 52000000){ 
                        ob->set("level",58);
                return  "58" ;  
        }
        else if(exp >= 52000000 && exp < 54000000){ 
                        ob->set("level",59);
                return  "59" ;  
        }
        else if(exp >= 54000000 && exp < 56000000){ 
                        ob->set("level",60);
                return  "60" ;  
        }
        else if(exp >= 56000000 && exp < 58000000){ 
                        ob->set("level",61);
                return  "61" ;  
        }
        else if(exp >= 58000000 && exp < 60000000){ 
                        ob->set("level",62);
                return  "62" ;  
        }
        else if(exp >= 60000000 && exp < 62000000){ 
                        ob->set("level",63);
                return  "63" ;  
        }
        else if(exp >= 62000000 && exp < 64000000){ 
                        ob->set("level",64);
                return  "64" ;  
        }
        else if(exp >= 64000000 && exp < 66000000){ 
                        ob->set("level",65);
                return  "65" ;  
        }
        else if(exp >= 66000000 && exp < 68000000){ 
                        ob->set("level",66);
                return  "66" ;  
        }
        else if(exp >= 68000000 && exp < 70000000){ 
                        ob->set("level",67);
                return  "67" ;  
        }
        else if(exp >= 70000000 && exp < 72000000){ 
                        ob->set("level",68);
                return  "68" ;  
        }
        else if(exp >= 72000000 && exp < 74000000){ 
                        ob->set("level",69);
                return  "69" ;  
        }
        else if(exp >= 74000000 && exp < 76000000){ 
                        ob->set("level",70);
                return  "70" ;  
        }
        else if(exp >= 76000000 && exp < 78000000){ 
                        ob->set("level",71);
                return  "71" ;  
        }
        else if(exp >= 78000000 && exp < 80000000){ 
                        ob->set("level",72);
                return  "72" ;  
        }
        else if(exp >= 80000000 && exp < 82000000){ 
                        ob->set("level",73);
                return  "73" ;  
        }
        else if(exp >= 82000000 && exp < 84000000){ 
                        ob->set("level",74);
                return  "74" ;  
        }
        else if(exp >= 84000000 && exp < 86000000){ 
                        ob->set("level",75);
                return  "75" ;  
        }
        else if(exp >= 86000000 && exp < 88000000){ 
                        ob->set("level",76);
                return  "76" ;  
        }
        else if(exp >= 88000000 && exp < 90000000){ 
                        ob->set("level",77);
                return  "77" ;  
        }
        else if(exp >= 90000000 && exp < 92000000){ 
                        ob->set("level",78);
                return  "78" ;  
        }
        else if(exp >= 92000000 && exp < 94000000){ 
                        ob->set("level",79);
                return  "79" ;  
        }
        else if(exp >= 94000000 && exp < 96000000){ 
                        ob->set("level",80);
                return  "80" ;  
        }
        else if(exp >= 96000000 && exp < 98000000){ 
                        ob->set("level",81);
                return  "81" ;  
        }
        else if(exp >= 98000000 && exp < 100000000){ 
                        ob->set("level",82);
                return  "82" ;  
        }
        else if(exp >= 100000000 && exp < 111000000){ 
                        ob->set("level",83);
                return  "83" ;  
        }
        else if(exp >= 111000000 && exp < 112000000){ 
                        ob->set("level",84);
                return  "84" ;  
        }
        else if(exp >= 112000000 && exp < 113000000){ 
                        ob->set("level",85);
                return  "85" ;  
        }
        else if(exp >= 113000000 && exp < 114000000){ 
                        ob->set("level",86);
                return  "86" ;  
        }
        else if(exp >= 114000000 && exp < 115000000){ 
                        ob->set("level",87);
                return  "87" ;  
        }
        else if(exp >= 115000000 && exp < 116000000){ 
                        ob->set("level",88);
                return  "88" ;  
        }
        else if(exp >= 116000000 && exp < 118000000){ 
                        ob->set("level",89);
                return  "89" ;  
        }
        else if(exp >= 118000000 && exp < 120000000){ 
                        ob->set("level",90);
                return  "90" ;  
        }
        else if(exp >= 120000000 && exp < 130000000){ 
                        ob->set("level",91);
                return  "91" ;  
        }
        else if(exp >= 130000000 && exp < 140000000){ 
                        ob->set("level",92);
                return  "92" ;  
        }
        else if(exp >= 140000000 && exp < 150000000){ 
                        ob->set("level",93);
                return  "93" ;  
        }
        else if(exp >= 150000000&& exp < 160000000){  
                        ob->set("level",94);
                return  "94" ;  
        }
        else if(exp >= 160000000 ){ 
                        ob->set("level",95);
                return  "95" ;  
        }       
}
/**************************************************************************************************/

string query_timec(int time)
{
        string msg;
        int day, hour, min;
        
        time=time()-time;
        
        msg="";
        day=time/86400;
        hour=time%86400/3600;
        min=time/60%60;
        if(min<1)
                min=1;
        if(day)
                msg+=sprintf("%s��", chinese_number(day));
        if(day<10 && hour)
                msg+=sprintf("%sСʱ", chinese_number(hour));
        if(!day && hour<20 && min)
                msg+=sprintf("%s����", chinese_number(min));
        return msg;
}

string query_time(int time)
{
        string msg;
        int day, hour, min;
        
        time=time()-time;
        
        msg="";
        day=time/86400;
        hour=time%86400/3600;
        min=time/60%60;

        if(min<1)
                min=1;
        if(day)
                msg+=sprintf("%d��", day);
        if(day<10 && hour)
                msg+=sprintf("%dСʱ", hour);
        if(!day && hour<20 && min )
                msg+=sprintf("%d����", min);

        return msg;
}
