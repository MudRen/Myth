 // Crack By stey

inherit NPC;

#include <ansi.h>
#include "pfm.h"
void _leave();
void leave();
void copy_status(object me, int level);
void set_skills(int max_value, int level);
void set_hp_status(object me, int level);



object owner() {return query("owner");}



string *names = ({
  "����",
  "����",
  "����",
  "����",
  "Ы��",
  "���",
  "����",
  "����",
  "��ʨ",
  "��ʨ",
  "����",
  "�ϻ�",
  "ʨ��",
  "��ʨ",
  "��ʨ",
  "����",
  "ɽ��",
  "�ݱ�",
  "���",
  "���",
  "⨺�",
  "Գ��",
  "����",
  "Ұ��",
  "��¹",
  "��¹",
  "��¹",
  "��¹",
  "������",
  "�׺���",
  "�Һ���",
  "����",
  "����",
  "ˮţ",
  "��ţ",
  "Ұţ",
  "����",
  "����",
  "������",
  "����",
  "����",
});



void setname()
{
object ob = this_player();
object me = this_object();
    int i;
    string name;
    i=random(sizeof(names));
    name=names[i]+(random(2)?"Ӱ��ɱ��":"Ӱ��Ѫħ");

set_name(name, ({ob->query("id") + " yao guai"}));

}

void create()
{
    setname();
    set("age", 100+random(80));
    set("gender", random(2)?"����":"Ů��");
    set("attitude", "heroism");
    set("per", 40);
    set("str", 100);
    set("cor", 40);
    set("con", 40);
    set("int", 40);
    set("spi", 40);
    set("cps", 40);
    set("kar", 40);
    set("max_gin", 1000);
    set("food", 10000);
    set("water", 10000);
    set_weight(30000);
    set("no_steal",1);
    set("taskguai",1);
    set("questguai",1);
    set("chat_chance", 5);



    setup();
}





string invocation(object me, int level)
{
    object guai,env;
    string *dirs, where;

    guai=this_object();
    copy_status(me, level);

    set("owner", me);
    set("kind",me->query("rulaitask/kind"));
    set("level",level);
    call_out("check_player",guai,10);


}
void check_player(object guai)
{
        object me=owner();
        if(!living(me)) destruct(guai);
        if(environment(me)!=environment(guai))
        {guai->move(environment(me));
        guai->kill_ob(me);}
         remove_call_out("choose_player");
        call_out("check_player",guai,10);
}

void copy_status(object me, int level)
{
    mapping me_skill;
    int *skill_value, max_value, i;

    me_skill = me->query_skills();
    i=sizeof(me_skill);
    if(i>0) {
        skill_value=values(me_skill);
        max_value=skill_value[0];
        while(i--) { // �ҳ����skill���ֵ
            if(skill_value[i]>max_value)
                max_value=skill_value[i];
        }
    } else max_value=1;
    set("stay_time",time()+600+random(60));
    set_skills(max_value, level);

    set_hp_status(me,level);

}

void set_skills(int max_value, int level)
{
    object guai=this_object();
    int guai_value;

    if (level==1) guai_value = max_value+max_value/5;
    else if (level==2) guai_value = max_value+max_value/4;
    else guai_value = max_value+max_value/3;

    set_skill("unarmed", guai_value+random(16));
    set_skill("dodge", guai_value+random(16));
    set_skill("parry", guai_value+random(16));
    set_skill("force", guai_value+random(16));
    set_skill("spells", guai_value+20+random(16));
}


void set_hp_status(object me, int level)
{       int max_kee,max_sen,skill_force,maximum_mana,exp,daoxing;
    max_kee = me->query("max_kee");
    max_sen = me->query("max_sen");
    skill_force = query_skill("force");
    maximum_mana = me->query("maximum_mana");
    exp = me->query("combat_exp");
    daoxing = me->query("daoxing");

    set("max_force", skill_force*10);
    set("force", skill_force*20);
    set("force_factor", skill_force/2);
    set("mana_factor", query_skill("spells",1)/3);

    if (level==1)
    {
        set("max_kee", max_kee*2);
        set("eff_kee", max_kee*3);
        set("max_sen", max_sen*3/2);
        set("eff_sen", max_sen*3/2);
        set("kee", max_kee*3/2);
        set("sen", max_sen*3/2);
        set("max_mana", maximum_mana*9/10);
        set("mana",maximum_mana*10/11);
        set("combat_exp", exp+exp*1/10+random(exp));
        set("daoxing", daoxing+daoxing*1/8+random(daoxing*1/16));
        set_temp("apply/armor", 1000);
        set_temp("apply/damage", 380);
    }

    else if (level==2)
    {
        set("max_kee", max_kee*7/3);
        set("eff_kee", max_kee*8/3);
        set("max_sen", max_sen*2);
        set("eff_sen", max_sen*2);
        set("kee", max_kee*5/3);
        set("sen", max_sen*5/3);
        set("max_mana", maximum_mana*8/9);
        set("mana",maximum_mana*9/10);
        set("combat_exp", exp+exp*1/18+random(exp*1/12));
        set("daoxing", daoxing+daoxing*1/20+random(daoxing*1/12));
        set_temp("apply/armor",1250);
        set_temp("apply/damage", 430);
    }

    else
    {
        set("max_kee", max_kee*3);
        set("eff_kee", max_kee*3);
        set("eff_kee", max_kee*2);
        set("max_sen", max_sen*2);
        set("eff_sen", max_sen*2);
        set("kee", max_kee*2);
        set("sen", max_sen*2);
        set("max_mana", maximum_mana*8/9);
        set("mana",maximum_mana*10/11);
        set("combat_exp", exp+exp*1/10+random(exp*1/6));
        set("daoxing", daoxing+daoxing*1/10+random(daoxing*1/10));
        set_temp("apply/armor", 1500);
        set_temp("apply/damage", 580);
    }
    if ( exp > 50000000)
    {
        add("combat_exp", exp*1/8+random(exp*1/10));
        add("daoxing", daoxing*1/8+random(daoxing*1/10));
        add_temp("apply/armor", exp/120000);

        add_temp("armor_prop/armor_vs_force", exp/50000);
        add_temp("armor_prop/dodge",exp/50000);

        //                set("force", skill_force*20);
        add("max_kee", max_kee*2);
        add("eff_kee", max_kee*2);
        add("kee", max_kee*3/2);
        add("eff_sen", max_kee*2);
        add("max_sen", max_kee*2);
        add("sen", max_kee*2);
    }
}


void init ()
{
    object me=this_object();
    object who=this_player();
    int type;
    int t=query("stay_time");
    ::init();
    add_action("do_persuade", "persuade");

    if(t && time()>(t+150)) {
        remove_call_out("leave");
        call_out("leave",1);
        return;
    }

    if(t && time()>t) {
        remove_call_out("_leave");
        call_out("_leave",150);
    }
    if(!living(this_object())) return;
    if(!living(who)) return;
    
    if(who==owner())
    { 
         message_vision("$N����$n�����һ���������������������⣡\n",this_object(), who);
         add_action("do_block","",1); 
         kill_ob(this_player());
         this_player()->kill_ob(this_object());
       }

}



void heart_beat()
{  object guai = this_object();
    ::heart_beat();

    if ( !is_fighting()
      && query("eff_kee") >= query("max_kee") / 2
      && !query_skill("tonsillit",1)
      && !query_skill("shushan-force",1)

      && query("eff_kee") <  query("max_kee") )
    {
        //    command("exert heal");
        set("eff_kee",query("max_kee"));
        set("eff_sen",query("max_sen"));
        //           if (random(3) =1) call_out("check2",0);
    }
    if (query("kee") < query("eff_kee")-10 )
    {
        if(query("force")<100)        add("kee",20);
        command("exert recover");
        //          if (random(4) >3) call_out("check2",0);
    }
    if (query("sen") < query("eff_sen")-10)
        command("exert refresh");
    if( is_busy() )
        start_busy(1);
    if (query("force") < query("max_force"))
        command("cast transfer");
    if (!owner() || owner()->query("rulaitask/fail") )
        destruct(guai);

    if (is_fighting() )
    {
        if ( random(7)==1 ) call_out("check2",0);
    }
}







void kill_ob (object ob)
{
    object me = this_object();
    if (me->query("level")>1)
        me->set_leader(ob);
    ::kill_ob(ob);
}




void _leave()
{
        object me=this_object();
        if(me->is_fighting() || me->is_busy())
        return;
        leave();
}

void leave()
{
      if(this_object()) {
        if(environment())
{
          message("vision",HIB + name() +
                  "����һ�Σ����һ������ɢȥ�ˡ�\n" NOR,environment());
}
        destruct(this_object());
      }
      return;
}


int do_block(string arg) 
{        
    object me=this_object(); 
    object who=this_player(); 
    string verb=query_verb(); 
    int t; 
     
    if(wizardp(who) && !visible(who)) return 0; 

 
    if(verb!="go" && verb!="fly" && verb!="move"
             && verb!="cast chuqiao" && verb!="cast escape"
             && verb!="cast tudun" && verb!="cast shuidun"
             && verb!="cast yinshen"
             && !(environment() && environment()->query("exits/" + verb))) 
        return 0; 
 
   
 

        message_vision("$N�͵�����������$n��ǰ�������е���\n"+ 
                "          ������ĩ�գ����������£�\n"+ 
                "          Ҫ��Ѹ�������������Ǯ��\n\n",me,who); 
    
     
    tell_object(who,me->name()+"һ��ץס���㣡\n"); 
    return 1; 
} 
                                                                         
