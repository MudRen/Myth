//Cracked by Roath
// bula and mon@xyj
// base file for inheritance.
inherit NPC;
#include <ansi.h>
int exp_reward, pot_reward;

string *death_msg= ({
"$nһ��������ȥ������һ���׹⣬��ʧ����Ӱ�����ˡ�\n",
"$n�������һЦ:�������⣬�һ�������ġ�����\n˵�껯��һ����⣬ֱ������ȥ�ˣ�����\n",
"$n̾�˿���:����֪���գ��αص�������\n���˰��ᣬ����һ����������ɢ������֮�У�����\n",
});

int random_place(object me, string* dirs);
void _leave();
void leave();
void leave2();
void copy_weapon(object me, object ob);

void create()
{
       set("title",HIR"ħ��ʹ��"NOR);
    set_name("��ħ", ({"mengmo"}));
    set("long",HIC"ħ����ڶ��������Ǳ���˵���������˵�˼�롣\n"NOR);
    set("attitude", "heroism");
    set("stay_time", time()+300);
    setup();
}

void copy_status(object me, object ob) 
{
   mapping map_status,skill_status;
   string *mname, *sname;
   int i,j;
     j=random(10);
    me->set("str", ob->query("str"));
    me->set("int", ob->query("int"));
    me->set("cps", ob->query("cps"));
    me->set("cor", ob->query("cor"));
    me->set("age", ob->query("age"));
    me->set("gender",ob->query("gender"));
    me->set("owner",ob->query("id"));
    me->set("max_gin",     ob->query("max_gin"));
    me->set("max_kee",     ob->query("max_kee")*2);
    me->set("max_sen",     ob->query("max_sen")*2);
    me->set("max_force",   ob->query("max_force"));
    me->set("max_mana",    ob->query("max_mana"));
    me->set("eff_gin", ob->query("max_gin"));
    me->set("gin",     ob->query("max_gin"));
    me->set("eff_kee", ob->query("max_kee"));
    me->set("kee",     ob->query("max_kee"));
    me->set("eff_sen", ob->query("max_sen"));
    me->set("sen",     ob->query("max_sen"));
    me->set("force",   ob->query("max_force")+ob->query("max_force")*4/5);
    me->set("mana",    ob->query("max_mana")+ob->query("max_mana")*4/5); 
    me->set("force_factor",ob->query_skill("force")*4/5);
    me->set("mana_factor", ob->query_skill("spells")*4/5);
    me->set("combat_exp",ob->query("combat_exp")+ob->query("combat_exp")/10);
    me->set("daoxing",ob->query("daoxing")+ob->query("daoxing")/10);
   //copy new skills.
   skill_status = ob->query_skills(); 
   if(skill_status){
   	sname  = keys(skill_status);
        for(i=0; i<sizeof(skill_status); i++) {
        me->set_skill(sname[i], skill_status[sname[i]]+j);
	}
    }
   //add new skill mappings.
   map_status = ob->query_skill_map();
   if(map_status){
        mname  = keys(map_status);
   	for(i=0; i<sizeof(map_status); i++){
   	me->map_skill(mname[i], map_status[mname[i]]);
	}
   }
   copy_weapon(me,ob);//����װ��
}
 
void copy_weapon(object me, object ob)
{
   object *inv;
   int i,j;
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++) 
   {
     destruct(inv[i]);
   }
   // save once here, an external bug might stop the following
    inv = all_inventory(ob);
    for(i=0; i<sizeof(inv); i++) 
    {
     if ( !inv[i]->query_unique() && 
     inv[i]->query("skill_type")&&
     inv[i]->query("equipped")) 
     {
        object obj = new(base_name(inv[i]));
        if (obj)
        {
          if(obj->move(me)) // mon 8/13/97
          obj->wield();
        }
        me->set("weapon", base_name(inv[i]));
     }
     else if ( !inv[i]->query_unique() && 
     !inv[i]->query("skill_type")&&
     inv[i]->query("equipped")) 
     {
        object obj = new(base_name(inv[i]));
        if (obj)
        {
          if(obj->move(me))
          obj->wear();   //mon 8/13/97
        }
        me->set("armor", base_name(inv[i]));
     }
   }
   me->set_skills();
}

void _leave()
{
    object me=this_object();
    
    // if in fighting, then don't disappear.
    if( is_fighting() ||  is_busy())
	return;
    leave();
}

void leave()
{
      if(this_object()) { 
        if(environment())
          message("vision",HIB + name() + 
		  "����һ�Σ����һ������ɢȥ�ˡ�\n" NOR,environment());
	this_object()->move("/obj/empty");
	call_out("leave2",5);
      }
      return;
}

void leave2()
{
    if(this_object()) {
	destruct(this_object());
    }
}
void check_room()
{
    object me=this_object();
    object env=environment(me);
    
    if(!living(me)) return;
    if(env && (env->query("no_fight") ||
		env->query("no_magic"))) {
	random_move();
    }
}

void init()
{
    object me=this_object();
    object who=this_player();
    string type;
    int t=query("stay_time");

    ::init();
    
    // if overtime too long, then destroy. mon 7/14/99
    if(t && time()>(t+600)) {
	remove_call_out("leave");
	call_out("leave",1);
	return;
    }

    if(t && time()>t) {
	remove_call_out("_leave");
	call_out("_leave",300);
    }
    
    if(!userp(this_player())) return;
    if(!living(this_object())) return;
    
}


void unconcious()
{
  if (query("kee")<0 || query("sen")<0) die();
   else ::unconcious();
}

void die()
{
        string skill;
	object *inv,who,me=this_object();
        object ob = query_temp("last_damage_from");
	string str;
	string msg;
	int exp,i,max_kee, max_sen, ratio, exp_r, pot_r;
	// determine reward
	exp=(query("combat_exp")+query("daoxing"))/2;
        if(exp<200000) {
	    exp_reward=500+exp/60;
	    pot_reward=200+exp/300;
        } else if(exp<500000) {
	    exp_reward=1000+exp/600;
	    pot_reward=300+exp/6000;
        } else if(exp<3000000) {
	    exp_reward=1500+exp/6000;
	    pot_reward=350+exp/20000;
	} else {
	    exp_reward=2000;
	    pot_reward=500;
	}

	    if(living(ob)&&ob->query("id")==query("owner")) {
		    max_kee=query("max_kee");
		    max_sen=query("max_sen");
 		    exp_r=exp_reward*2;
		    pot_r=pot_reward*2;
	  		    
		    str="kill mengmo got "+exp_r+"/"+exp_reward+" daoxing "+
			pot_r+"/"+pot_reward+" pot.\n";

		    MONITOR_D->report_system_object_msg(ob, str);

		    ob->add("daoxing",exp_r);
		    ob->add("potential",pot_r);
        CHANNEL_D->do_channel( this_object(), "rumor",
        sprintf("ħ�̵�"NOR+YEL"<%s>"HIM"��%sɱ���ˡ�"NOR,query("name"), ob->name() ));
	tell_object(ob, "��õ���"+COMBAT_D->chinese_daoxing(exp_r)
			    +"���к�"+chinese_number(pot_r)+"��Ǳ�ܣ�\n");
	}
        message_vision(death_msg[random(sizeof(death_msg))],ob,me);
	destruct(me);

}
