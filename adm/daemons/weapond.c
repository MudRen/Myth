// weapond.c
// added by steywen@21cn.com 10/12/2002

//#pragma save_binary
#include <ansi.h>
#include <combat.h>
#define WW_NAME       0
#define WW_ID         1
#define WW_VALUE      2
#define WW_HARM       3
#define WW_MAR        4

void remove_broken_weapon(object ob);
int sharpless(object obj);

mapping weapon_actions = ([
        "slash": ([
                "damage_type":  "����",
                "action":               "$N�Ӷ�$w��ն��$n��$l",
                "parry":                20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "slice": ([
                "damage_type":  "����",
                "action":               "$N��$w��$n��$l��ȥ",
                "dodge":                20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "chop": ([
                "damage_type":  "����",
                "action":               "$N��$w����$n��$l������ȥ",
                "parry":                -20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "hack": ([
                "action":               "$N����$w����׼$n��$lһ���ҿ�",
                "damage_type":  "����",
                "damage":               30,
                "dodge":                30,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "thrust": ([
                "damage_type":  "����",
                "action":               "$N��$w��$n��$l��ȥ",
                "dodge":                15,
                "parry":                -15,
                ]),
        "pierce": ([
                "action":               "$N��$w��$n��$l�ݺݵ�һͱ",
                "damage_type":  "����",
                "dodge":                -30,
                "parry":                -30,
                ]),
        "wave": ([
                "action":               "$Nһ��$w����$n��$lһ��",
                "damage_type":  "����",
                "dodge":                -20,
                "parry":                30,
                ]),
        "whip": ([
                "action":               "$N��$wһ���$n��$l��ȥ",
                "damage_type":  "����",
                "dodge":                -20,
                "parry":                30,
                ]),
        "impale": ([
                "action":               "$N��$w��$n��$lֱ����ȥ",
                "damage_type":  "����",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "rake": ([
                "action":               "$N�߾�$w����$n��$l����һ��",
                "damage_type":  "����",
                "dodge":                -15,
                "parry":                15,
                ]),
        "strike": ([
                "action":               "$Nһ�����������$w������$n��$l����һ��",
                "damage_type":  "����",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "bash": ([
                "action":               "$N����$w����$n��$l����һ��",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "crush": ([
                "action":               "$N�߸߾���$w����$n��$l��ͷ����",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "slam": ([
                "action":               "$N����$w����¶�׹⣬�͵ض�׼$n��$l���˹�ȥ",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "throw": ([
                "action":               "$N��$w��׼$n��$l���˹�ȥ",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
        "shoot": ([
                "action":               "$N�乭�����ֻ����ಡ���һ����$w�ѵ�$n��$l",
                "damage_type":  "����",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
]);
string *s_type=({"fire","ice","poison","air","earth",});
mapping name_type=([
   "sword":"��","stick":"��","hammer":"��","staff":"��","whip":"��","axe":"��","blade":"��",
   "fork":"��","spear":"ǹ","mace":"�",
]);
nosave mapping weapon_type = ([
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
varargs mapping query_action()
{
        string verb, *verbs;
        object me, wp1, wp2;

        verbs = previous_object()->query("verbs");

        // 4/27/98 mon changed following 4 "hit" to "impale"
        // as "hit" is not defined in weapon_actions.
        if( !pointerp(verbs) ) return weapon_actions["impale"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
                else return weapon_actions["impale"];
        }
}

varargs mapping query_apply_action()
{
        string verb, *verbs;
        object me, wp1, wp2;

        verbs = previous_object()->query("apply/verbs");

        if( !pointerp(verbs) ) return weapon_actions["impale"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
                else return weapon_actions["impale"];
        }
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) {
                if( (int)weapon->query_amount()==1 ) {
                        weapon->unequip();
                        tell_object(me, "\n���" + weapon->query("name") + "�����ˣ�\n\n");
                }
                weapon->add_amount(-1);
        }
}


void bash_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp, z1, z2;
        string sharp1, sharp2;
        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon")) {
                  sharp1=weapon->query("material");
                  switch (sharp1)
                  {case "wood" : z1=5 ; break;
                  case "iron" :  z1=10 ; break;
                  case "cuprum" : z1=15 ; break;
                  case "steel" : z1=20 ; break;
                  case "blacksteel" : z1=25 ; break;
                   case "silver" : z1=30 ;break;
                  case "crimsonsteel" : z1=35 ; break;
                  case "purplegold" :z1=40 ; break;
// ����diamond�ǲ�ĥ��ģ�Ҳ���������������״������������
//                  case "diamond" : z1=200 ; break;
                  default : z1=0 ;break;
                   }
                  sharp2=ob->query("material");
                  switch (sharp2)
                  {case "wood" :z2=5 ; break;
                  case "iron" :  z2=10 ; break;
                  case "bronze" : z2=15 ; break;
                  case "steel" : z2=20 ; break;
                  case "blacksteel" : z2=25 ; break;
                  case "silver" : z2=30 ; break ;
                  case "crimsonsteel" : z2=35 ; break;
                  case "purplegold" : z2=40 ; break;
 //                 case "diamond" : z2=200 ; break;
                  default : z2=0 ;break;
                   }
                wap = (int)weapon->weight() / 500 +z1
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500 +z2
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "$Nֻ��������" + ob->name() + "�ѳֲ��������ַɳ���\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$Nֻ��������" + ob->name() + "һ����Щ���֣�\n",
                                victim);
                } else if( wap > wdp / 2 ) {
                        message_vision(HIW "ֻ������ž����һ����$N���е�" + ob->name()
                                + "�Ѿ���Ϊ���أ�\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "�ϵ���" + ob->query("name"));
                        //ob->set("value", (int)ob->query("value") / 20);
                        ob->set("value", 0);
                        //so can't sell broken weapon.
                        //otherwise may have problem in pawn shop
                        //when the broken weapon disappeared.
                        ob->set("weapon_prop", 0);
                        ob->set("armor_prop", 0);
                        call_out("remove_broken_weapon",
                          random(300)+60,ob);
                        //added by mon 10/27/97
                        victim->reset_action();
                } else {
                        message_vision("$N��" + weapon->name() + "��$n��" + ob->name()
                                + "�����ð�����Ļ��ǡ�\n", me, victim);
                }
        }
}

void fleshings_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp, z1, z2, onfall;
        string sharp1, sharp2;
        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                  sharp1=weapon->quary("material");
                  switch (sharp1)
                  {case "wood" : z1=5 ; break;
                  case "iron" :  z1=10 ; break;
                  case "bronze" : z1=15 ; break;
                  case "steel" : z1=20 ; break;
                  case "blacksteel" : z1=25 ; break;
                  case "silver" : z1=30 ; break;
                  case "crimsonsteel" : z1=35 ; break;
                  case "purplegold" : z1=40 ; break;
//                  case "diamond" : z1=200 ; break;
                  default : z1=0 ;break;
                   }
                  sharp2=ob->query("material");
                  switch (sharp2)
                  {case "wood" :z2=5 ; break ;
                  case "iron" :  z2=10 ; break;
                  case "bronze" : z2=15 ; break;
                  case "steel" : z2=20 ; break;
                  case "blacksteel" : z2=25 ; break;
                  case "silver" : z2=30 ; break;
                  case "crimsonsteel" : z2=35 ; break;
                  case "purplegold" : z2=40 ; break;
//                  case "diamond" : z2=200 ; break;
                  default : z2=0 ;break;
                   }
                    if (z1> 50)
                       z1=50;
                   onfall=(int)me->query("str")
                              -(int)victim->query("str");
                     if (onfall>20)
                           onfall=20;
                     else
                        {if (onfall<5)
                            onfall=5;}
           {
                wap = (int)weapon->keenness()
                                          + z1
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500
                                          + z2
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > wdp / 2 )
                 {

                        if (ob->query("weapon_prop/damage")>20)
                             {
                                            message_vision(HIW "$Nֻ��������" + ob->name() + "[�A�]һ����ԭ���Ǳ�����һ�ڣ���\n" NOR,
                              victim);
                              ob->unequip();
                              ob->add("weapon_prop/damage", -onfall);
                              if (ob->query("weight") > 200)
                              ob->add("weight", -200);// xintai 3/18/2001
                              ob->wield ();
                             }
                        else
                            {
                                            message_vision(HIW "$Nֻ��������һ�ᣬ" + ob->name() + "���������Σ���\n" NOR,
                              victim);
                              ob->unequip();
                              ob->move(environment(victim));
                              ob->set("name", "�ϵ���" + ob->query("name"));
                              ob->set("value", 0);
                              ob->set("weapon_prop", 0);
                              ob->set("armor_prop", 0);
                              call_out("remove_broken_weapon",
                              random(300)+60,ob);
                              victim->reset_action();
                            }

                }
                  else     {
                        message_vision("$N��" + weapon->name() + "��$n��" + ob->name()
                                + "�����ð�����Ļ��ǡ�\n", me, victim);
                            }
          }  }
}


void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "һ��΢�紵����"+ob->name()+"��ΪƬƬ��������ʧ�����ˡ�\n");
    destruct(ob);
  }
}
void update_weapon(object ob)
{
  int ii,i, j,k,kk,ppl,hr,val;
    mapping nkl,mkl;
    string name,ad_type,type,ty,idd,*kn,*id,long;
   // k=random(100);
   long=ob->query("long");
/*   long+="��س���֮ʱ���̹ſ����ʱ���Ѿ�����һ�����صĴ�ʦ����������ؼ�Ž������������ܣ�/n
         +"�ʹ�����������������ѳɺ���������ħʹ�õı����������������������������������Ĵ��ε���/n"
         +"��������Ͳ��ϳ��ָ������������������������ƣ��������е�������/n";
*/
    for (j = 0;j < 8; j++)
        {

       if(random((j+1)*(j+1)*40) < 5)
       {
        i=random(4)+j*4;
        ppl=1;
        break;
        }
        }
        if(ppl!=1)  i=random(8);

        nkl=base_names[i];
        ty=ob->query("skill_type");
        name=nkl["name"]+name_type[ty]+NOR;
        id=({nkl["id"]+ty,ty});
        ob->set("weapon_prop/damage", (48+i*2+random(i+1)));
        ob->set("w_lvl",i);
      long +="����һ"+ob->query("unit")+nkl["name"]+name_type[ty]+"��/n"+NOR;

        hr=(48+i*2+random(i+1))*10;
       val=(i+1)*200000+(random(i+1)*20000);
      for(kk=0;kk<sizeof(s_type);kk++)
       {
        if(random(100)>80)
        {
                        ppl=0;
                         for (j = 0;j < 9; j++)
                         {

                        if(random((j+1)*(j+1)*40) < 5)
                        {
                        ii=j;
                         ppl=1;
                         break;
                         }
                         }
                         if(ppl!=1)ii=random(3);
                ad_type=s_type[kk]+ii;
                ob->set("h_w_"+s_type[kk],ii);
                val+=weapon_type[ad_type][WW_VALUE];
                hr+=(weapon_type[ad_type][WW_MAR])*10;
                ob->set("weapon_prop/"+s_type[kk]+"_damage",weapon_type[ad_type][WW_HARM]);
                long +="�������"+weapon_type[ad_type][WW_NAME]+"���⹥��,�˺�ֵ:  "+HIC+weapon_type[ad_type][WW_HARM]+"/n"+NOR;
        }
        }
    ob->set("weapon_scar",hr);
   long +="�������Ͷ�ֵΪ:  "+hr+"�ȡ�/n";

    ob->set("long", long);


}
string get_look_msg(object weapon)
{
	string str,*c_type,ad_type;
	int i,k;
	
	c_type=({"��ϵ","��ϵ","��ϵ","��ϵ","��ϵ",});
	str="\n----------------------------------------------\n\n";
	str+=sprintf("����ս�����飺 %-8d ���Ͷ�ֵ:  %-8d\n",weapon->query("combat_exp"),weapon->query("weapon_scar"));
	for(i=0;i<sizeof(s_type);i++)
    {
    if(weapon->query("h_w_"+s_type[i]) >=0 )
    {k=weapon->query("h_w_"+s_type[i]);
    ad_type=s_type[i]+k;
    str +=sprintf(WHT"%s���⹥��"NOR":[%s]:%-12d\n",c_type[i],weapon_type[ad_type][WW_NAME],weapon->query("weapon_prop/"+s_type[i]+"_damage"));
    } 
    else str +=sprintf(WHT"%s���⹥��"NOR":[%s]:%-12d\n",c_type[i],"  ��  ",0);
    }
       return str;
}
void update_baoshi(object weapon,int bl,int i)
{
         object b_weapon;
        string ad_type;
        int k,l,j,ppl;
        mapping weapon_prop=([]);
               if(i >= sizeof(s_type)) i-=sizeof(s_type);
        k=0;
        
        weapon_prop = weapon->query("weapon_prop");
        if(weapon->query("weapon_prop/"+s_type[i]+"_damage"))
            k=weapon_prop[s_type[i]+"_damage"];


        k +=(bl/2);
        weapon_prop[s_type[i]+"_damage"]=k;
        for(j=0;j<9;j++)
        {
         if ( k > (j+1)*100 ) continue;
         else {
               ad_type=s_type[i]+j;
               weapon->set("look_w_msg/"+s_type[i],weapon_type[ad_type][WW_NAME]);
               weapon->set("h_w_"+s_type[i],j);
               break;
              }
         }
        weapon->add("add_baoshi",1);
       
        weapon->add("weapon_scar",bl*20);
        weapon->set("weapon_prop",weapon_prop);
        weapon->add("weapon_sp",1);
      b_weapon=find_object(base_name(weapon));
      destruct(b_weapon);
     return;

}
int radio(int vs)
{
    if (vs>300) return 100;
    return vs/300;
}
int do_s_attack(object me,object victim,object weapon)
{
    object shield;
    mapping my, your, action, victim_action;
    string limb, *limbs,*sst, result,fail_hit_msg,hit_ob_msg,sh_name;
    string ad_type,attack_skill, force_skill, martial_skill, dodge_skill, parry_skill;
    mixed foo;
    int i,k,ap, dp, pp, afp, vfp,sp,vd;   //afp: attacker->force power, vfp: victim->force power
    int damage, damage_bonus, defense_factor,force_adj;
    int wounded = 0;
           limbs = victim->query("limbs");
           limb = limbs[random(sizeof(limbs))];
            afp = COMBAT_D->skill_power(me, "force", SKILL_USAGE_ATTACK);

            vfp = COMBAT_D->skill_power(victim, "force", SKILL_USAGE_DEFENSE);

                my = me->query_entire_dbase();
                your = victim->query_entire_dbase();

             if (weapon->query("use_apply_skill"))
            attack_skill = weapon->query("apply/skill_type");
        else
            attack_skill = weapon->query("skill_type");

       ap = COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);

        if( ap < 1) ap = 1;

       dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
        if (!userp(me)) ap *=3;
        if (!userp(victim)) dp *=3;
        if (random(ap+dp) < dp) return 0;

        
           sst=s_type;
        for(i=0;i<sizeof(s_type);i++)
        {
         if(!me->query_temp("apply/"+s_type[i]+"_damage"))
         sst -=({ s_type[i] });
        }
        i=random(sizeof(sst));
        k=weapon->query("h_w_"+s_type[i]);
        ad_type=s_type[i]+weapon->query("h_w_"+s_type[i]);
        hit_ob_msg="$N��"+weapon->name()+"ͻȻ����"+weapon_type[ad_type][WW_NAME]+"������\n";
        
        damage=me->query_temp("apply/"+s_type[i]+"_damage");
        if(!me->query_temp("apply/vs_"+s_type[i]+"_damage"))
           vd =1;
            else vd = me->query_temp("apply/vs_"+s_type[i]+"_damage");
          vd = radio(vd);
          damage *=(120-vd)/100;
        if(objectp(shield=victim->query_temp("armor/shield")))
          { sp=shield->query("weapon_prop/damage");
           
             if (sp < damage) damage -=sp;
               else {
                  damage=0;
                  weapon->add("weapon_scar",-2);
                  hit_ob_msg+="����ȫ����$n��"+shield->name()+"���ˡ�$n˿��û�����ˡ�\n";
                  message_vision(hit_ob_msg,me,victim);
                  return damage;  
                    }
          }
        
         victim->receive_damage("kee",damage , me);
        weapon->add("combatd_exp",1);
        weapon->add("weapon_scar",-1);
        
//        hit_ob_msg="$N��"+weapon->name()+"ͻȻ����"+weapon_type[ad_type][WW_NAME]+"������\n";
                  message_vision(hit_ob_msg,me,victim);
        COMBAT_D->report_status(victim,damage);
        if(weapon->query("weapon_scar")<0)
        {   message_vision(HIW "$Nֻ��������һ�ᣬ" + weapon->name() + "���������Σ���\n" NOR,
                              me);
                              weapon->unequip();
                              weapon->move(environment(victim));
                              weapon->set("name", "�ϵ���" + weapon->query("name"));

                              weapon->set("value", 0);
                              weapon->delete("weapon_prop", 0);
                              weapon->delete("armor_prop", 0);
                              call_out("remove_broken_weapon",
                              random(300)+60,weapon);
        }
         
         if( damage >0 && random(damage) > (int)victim->query_temp("apply/armor") )
                {
                    // We are sure that damage is greater than victim's armor here.
                    victim->receive_wound("kee",
                        damage - (int)victim->query_temp("apply/armor"), me);

                }
                return damage;
}
