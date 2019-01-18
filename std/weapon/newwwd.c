// written by stey

#include <ansi.h> 
#include <dbase.h> 

#define WW_NAME       0 
#define WW_ID         1 
#define WW_VALUE      2 
#define WW_HARM       3 
#define WW_MAR        4 
 
string *s_type=({"fire","ice","poison","air","earth",}); 
mapping name_type=([ 
   "sword":"��","stick":"��","hammer":"��","staff":"��","whip":"��","axe":"��","blade":"��", 
   "fork":"��","spear":"ǹ","mace":"�", 
]); 
static mapping weapon_type = ([ 
 //����           ������     Ӣ����          ��ֵ    �����˺�ֵ ������ֵ 
   "fire0": ({ HIR"����"NOR, "flame",        20000,     10,   30 , }),  
   "fire1": ({ HIR"���һ�"NOR, "fire",         40000,     20,   40 , }),  
   "fire2": ({ HIR"ħ����"NOR, "magicfire",    70000,     30,   50 , }),  
   "fire3": ({ HIR"���˻�"NOR, "skyfire",     150000,     40,   60 , }),  
   "fire4": ({ HIR"��"NOR, "inferno",     200000,     50,   70 , }),  
   "fire5": ({ HIR"������"NOR, "fire",        250000,     60,   80 , }),  
   "fire6": ({ HIR"���ջ�"NOR, "inferno",     600000,     70,   90 , }), 
   "fire7": ({ HIR"������"NOR, "suns",        800000,     80,   100, }),  
   "fire8": ({ HIR"���ѻ�"NOR, "explosion",   900000,     95,   120, }),  
 
  
  "ice0":   ({ HIC"����"NOR, "ice",           20000,      10,   30 , }),  
  "ice1":   ({ HIC"����"NOR, "magicice",      40000,      20,   40 , }),  
  "ice2":   ({ HIC"�˱�"NOR, "coolest",       70000,      30,   50 , }),  
  "ice3":   ({ HIC"�춳"NOR, "skyice",       150000,      40,   60 , }),  
  "ice4":   ({ HIC"����"NOR, "fearfully ice",      200000,      50,   70 , }),  
  "ice5":   ({ HIC"ǧ��"NOR, "millenary ice",          250000,      60,   80 , }),  
  "ice6":   ({ HIC"���"NOR, "myriad ice",      600000,      70,   90 , }),  
  "ice7":   ({ HIC"����"NOR, "nineshade",         800000,      80,   100, }),  
  "ice8":   ({ HIC"����"NOR, "iceblow",    900000,      95,   120, }),  
 
 
  
 "poison0": ({  HIG"ɢ��"NOR, "disperse",        20000,      10,   30 , }),  
 "poison1": ({  HIG"�׶���"NOR, "crane",           40000,      20,   40 , }),  
 "poison2": ({  HIG"�ߵ���"NOR, "serpent",         70000,      30,   50 , }),  
 "poison3": ({  HIG"Ыβ��"NOR, "scorpion",        150000,      40,   60 , }),  
 "poison4": ({  HIG"��۶�"NOR, "moth",            200000,      50,   70 , }),  
 "poison5": ({  HIG"�Ƴ涾"NOR, "gu",              250000,      60,   80 , }),  
 "poison6": ({  HIG"��ʬ��"NOR, "ptomaine",        600000,      70,   90 , }),  
 "poison7": ({  HIG"���궾"NOR, "evil spirit",        800000,      80,   100, }),  
 "poison8": ({  HIG"ħѪ��"NOR, "evil",               900000,      95,   120, }),  
 
 
 
  
    "air0": ({ HIW"������"NOR, "air bomb",           20000,      10,   30 , }),  
    "air1": ({ HIW"����"NOR,   "air arrow",              40000,      20,   40 , }),  
    "air2": ({ HIW"ħ����"NOR, "air sword",        70000,      30,   50 , }),  
    "air3": ({ HIW"������"NOR, "air falchion",   150000,      40,   60 , }),  
    "air4": ({ HIW"����"NOR,   "high wind",      200000,      50,   70 , }),  
    "air5": ({ HIW"�ҷ�"NOR,   "strong wind",      250000,      60,   80 , }),  
    "air6": ({ HIW"����"NOR,   "strom wind",   600000,      70,   90 , }),  
    "air7": ({ HIW"�׵�"NOR,   "thunder",       800000,      80,   100, }),  
    "air8": ({ HIW"����"NOR,   "chain thunder",        900000,      95,   120, }),  
 
 
  
  "earth0": ({ YEL"��������"NOR, "earth",              20000,      10,   30 , }),  
  "earth1": ({ YEL"��ʯ��Ƭ"NOR, "stone bump",     40000,      20,   40 , }),  
  "earth2": ({ YEL"��ʯ�䶥"NOR, "megalith hit",    70000,      30,   50 , }),  
  "earth3": ({ YEL"̩ɽѹ��"NOR, "hill hit",      150000,      40,   60 , }),  
  "earth4": ({ YEL"��ɽ�Ѻ�"NOR, "volcano hit",       200000,      50,   70 , }),  
  "earth5": ({ YEL"���ǻ���"NOR, "star hit",            250000,      60,   80 , }),  
  "earth6": ({ YEL"����ײ��"NOR, "hesper bump",      600000,      70,   90 , }),  
  "earth7": ({ YEL"���Ǿۺ�"NOR, "stars bump ",    800000,      80,   100, }),  
  "earth8": ({ YEL"����ɽ��"NOR, "earthquake",     900000,      95,   120, }),  
]);  
mapping *base_names = ({ 
   
  (["name": HIR"ͭ","id": "copper",]),  
  (["name": HIR"��","id": "steel",]),             
  (["name": HIR"��","id": "iron",]),  
  (["name": HIR"��","id": "gold",]),  
  (["name": HIC"����","id": "jade",]), 
  (["name": HIC"����","id": "greenjade",]), 
  (["name": HIC"ϼ��","id": "sunjade",]), 
  (["name": HIC"����","id": "colourful jade",]), 
  (["name": HIY"��Х","id": "tiger",]), 
  (["name": HIY"�㳦","id": "harmful",]), 
  (["name": HIY"����","id": "dargonkiss",]), 
  (["name": HIY"���","id": "phoenix",]), 
  (["name": HIW"����","id": "thunder dragon",]), 
  (["name": HIW"����","id": "mad dradon",]), 
  (["name": HIW"����","id": "fury dragon",]), 
  (["name": HIW"����","id": "deity dragon",]), 
  (["name": HIW"����","id": "light",]), 
  (["name": HIW"�ڰ�","id": "dark",]),    
  (["name": HIW"а��","id": "evil",]),    
  (["name": HIW"����","id": "justice",]),    
  (["name": HIR"����","id": "spirit",]),    
  (["name": HIR"����","id": "genius",]),    
  (["name": HIR"����","id": "jinni",]),    
  (["name": HIR"����","id": "ahriman",]),    
  (["name": BLINK+HIR"���","id": "sky circles",]),    
  (["name": BLINK+HIR"�˽�","id": "human circles",]),    
  (["name": BLINK+HIR"�ؽ�","id": "abuttals",]),    
  (["name": BLINK+HIR"���","id": "gods circles",]),    
  (["name": BLINK+HIR"������ʦ","id": "sanjie koradji",]), 
  (["name": BLINK+HIR"��������","id": "sanjie powwow",]), 
  (["name": BLINK+HIR"�������","id": "sanjie emperor",]), 
  (["name": BLINK+HIR"��������","id": "sanjie deity",]), 
 
}); 
varargs void updatename(string ty) 
{ 
    int i,ii, j,k,kk,ppl,hr,val; 
    mapping nkl,mkl; 
    string name,ad_type,type,idd,*kn,*id,long; 
   // k=random(100); 
   long="��س���֮ʱ���̹ſ����ʱ���Ѿ�����һ�����صĴ�ʦ����������ؼ�Ž������������ܣ�\n" 
         +"�ʹ�����������������ѳɺ���������ħʹ�õı����������������������������������Ĵ��ε���\n" 
         +"��������Ͳ��ϳ��ָ������������������������ƣ��������е�������\n"; 
    
    for (j = 0;j < 8; j++)  
        {  
    
       if(random((j+1)*(j+1)*20) < 5) 
       { 
        i=random(4)+j*4; 
        ppl=1; 
        break;  
        } 
        } 
        if(ppl!=1)  i=random(8); 
     
        nkl=base_names[i]; 
//       ty=query("skill_type"); 
        name=nkl["name"]+name_type[ty]+NOR; 
        id=({nkl["id"]+" "+ty,ty}); 
        set("weapon_prop/damage", (48+i*2+random(i+1))); 
        set("w_lvl",i); 
        long +="����һ"+query("unit")+nkl["name"]+name_type[ty]+"��\n"+NOR; 
        hr=(48+i*2+random(i+1))*10; 
        val=(i+1)*200000+((random(i+1))*20000); 
      for(kk=0;kk<sizeof(s_type);kk++) 
       { 
        if(random(100)>80) 
        { 
                        ppl=0; 
                         for (j = 0;j < 9; j++)  
                         {  
                      
                        if(random((j+1)*(j+1)*10) < 5) 
                        { 
                         ii=j; 
                         ppl=1; 
                         break;  
                         } 
                         } 
                         if(ppl!=1)ii=random(3); 
                ad_type=s_type[kk]+ii; 
                set("h_w_"+s_type[kk],ii); 
                val+=weapon_type[ad_type][WW_VALUE]; 
                hr+=(weapon_type[ad_type][WW_MAR])*10; 
                set("weapon_prop/"+s_type[kk]+"_damage",weapon_type[ad_type][WW_HARM]); 
                long +="�������"+weapon_type[ad_type][WW_NAME]+"���⹥��,�˺�ֵ:  "+HIC+weapon_type[ad_type][WW_HARM]+"\n"+NOR; 
        } 
        } 
    set("weapon_scar",hr); 
    long +="�������Ͷ�ֵΪ:  "+hr+"�ȡ�\n"; 
    set("no_sell", 1); 
    set("long", long); 
    set("sell_value", val);
    set_name(name,id);
//      set("name",name);
//      set("id",id[0]);
 
}    
/* 
void changename(int i) 
{ 
    int j,k; 
    string name,*id; 
    object ob=this_object(); 
          if(i>27){ 
 
        j=i-28; 
        ob->set("is_monitored", 1); 
      }else if(i>20){ 
 
        j=i-21; 
        ob->set("is_monitored", 1); 
      }else if(i>13){ 
 
        j=i-14; 
       ob->set("is_monitored", 1); 
      }else if (i>7) 
         { 
         j=i-7; 
         ob->set("is_monitored", 1); 
        }else 
        { 
        j=i;} 
     ob->set("b_lvl",i+1); 
 
     
    name=b_names[i]+"��ʯ"; 
 
    id=({names[b_names[i]]+" baoshi","baoshi"}); 
 
    ob->set("baoshi",b_names[i]); 
 
    ob->set("reward_lvl",j+1); 
 
    if(j==0){ 
    ob->set_name(BLINK+HIR+name+NOR,id); } 
    if(j==1){ 
    ob->set_name(BLINK+HIB+name+NOR,id); } 
    if(j==2){ 
    ob->set_name(BLINK+HIG+name+NOR,id); } 
    if(j==3){ 
    ob->set_name(BLINK+HIC+name+NOR,id); } 
    if(j==4){ 
    ob->set_name(BLINK+HIY+name+NOR,id); } 
    if(j==5){ 
    ob->set_name(BLINK+HIM+name+NOR,id); } 
    if(j==6){ 
    ob->set_name(BLINK+YEL+name+NOR,id); } 
    if(j==7){ 
    ob->set_name(BLINK+YEL+name+NOR,id); } 
} 
*/ 
 

