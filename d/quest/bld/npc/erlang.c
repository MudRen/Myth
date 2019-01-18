#include <ansi.h>

inherit NPC;
int begin_chasing();
void create()
{
        set_name("������", ({"erlang shen", "erlang", "shen"}));
        set("long",HIC "���ǳ���ѻ�Ӣ��ʥ���Ի��ޱߺŶ��ɡ�
�����˹�����Զ�����÷ɽ��ʥ�С�\n"NOR);
        set("looking",HIM "�����忡ò���ã���������Ŀ�й⡣"NOR);
        set("age", 28);
        set("attitude", "peaceful");

        set("gender", "����");
        set("color", HIW);
        set("title", HIG"�ѻ�������"NOR);
        set("str", 40);
        set("int", 40);
        set("per", 30);
        set("con", 30);
        set("max_kee",8000);
        set("max_sen", 8000);
        set("taskguai", 1);
        set("combat_exp", 20000000);
        set("daoxing", 20000000);

        set("force", 22000);
        set("max_force", 22000);
        set("mana", 22000);
        set("max_mana", 22000);
        set("force_factor", 500);
        set("mana_factor", 500);

 //       set("eff_dx", 800000);
        set("nkgain", 800);

        set_skill("unarmed", 280);
        set_skill("force", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);
        set_skill("spear", 280);
        set_skill("bawang-qiang",280);
        set_skill("lengquan-force",280);
        set_skill("baguazhou",280);
        set_skill("yanxing-steps",280);
        set_skill("changquan",280);
        map_skill("dodge","yanxing-steps");
        map_skill("unarmed","changquan");
        map_skill("force","lengquan-force");
        map_skill("spells","baguazhou");
        map_skill("spear","bawang-qiang");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
        (: exert_function, "powerup" :),
        (: perform_action,"spear", "bugong" :),
        (: perform_action,"spear", "meihua" :),
        (: perform_action,"unarmed", "zhiqi" :),         
        }) );



        create_family("������", 2, "��");

        set("inquiry", ([ /* sizeof() == 2 */
                "here" : "���ڴ˿����ҵ����� ��",
                "name" : "���˶����������Ҳ��",
        ]) );

        setup();
        carry_object("/d/meishan/npc/obj/spear")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
        carry_object("/d/obj/drug/jinchuang")->set_amount(random(10));
}

/*
void init()
{
    object me=this_object();
    object who=this_player();
           ::init();
   
   
}
int do_no(string arg)
{
        object who = this_player();
        object me = this_object();
        message_vision("$N������첻֪���ʲô��$n����Ķ���$N��\n",who,me);
        return 1;
}
int do_qk(string arg)
{
    
        string cast_id,cast_name;
        object who = this_player();
        
    if (sscanf(arg, "%s on %s", cast_id,cast_name) == 2)
     
      if(cast_id=="qiankun" || arg=="qiankun")
     
       tell_object(who,"��������������Ԫ���ɵ�������������ͽ��"
                +"��Ҫ���ҹ��з���������ǣ����ȫ�۵��ӣ�\n");
      return 1;
 
   
}
*/
void kill_ob (object ob)
{
        set_temp("no_return",1);
        set_temp("my_killer",ob);
  call_out("check",1);
        ::kill_ob(ob);
}
                        
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
    ob->clear_condition();
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               

     switch(random(6))
     {        
        case 0:
        {
        message_vision(YEL"$Nͷ�ϵ���ֻ�۾�����һ����⣬�����$n������\n",ob,me);


       if(random(3)==0)
                {
              message_vision(YEL"$N���������ȫ��,�������ܣ�\n"NOR,me);
              me->receive_damage("kee",query("max_kee")/10);
              me->receive_wound("kee",query("max_sen")/10);
              me->receive_damage("sen",query("max_kee")/10);
              me->receive_wound("sen",query("max_sen")/10);
                }
        else
        message_vision(YEL"$N����һ�����Ǳ��Ķ�������⣡\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N�����дʣ�һֻХ��Ȯ��$n������\n",ob,me);

                if(random(3)==0)

                {
              message_vision(YEL"$N��Х��Ȯ�ļ���ҧ�˸��������\n"NOR,me);
              me->receive_damage("kee",2*query("max_kee")/10);
              me->receive_wound("kee",2*query("max_sen")/10);
              me->receive_damage("sen",2*query("max_kee")/10);
              me->receive_wound("sen",2*query("max_sen")/10);
                }
        }
        break;

        case 2:
        {

        message_vision(HIR"$N��Ϊ�����$nֱ���ȥ��\n",ob,me);

                if(random(3)==0)

                {
              message_vision(HIR"$N��������ܣ�����ӭ����ȥ��\n"NOR,me);
              me->receive_damage("kee",2*query("max_kee")/10);
              me->receive_wound("kee",2*query("max_sen")/10);
              me->receive_damage("sen",2*query("max_kee")/10);
              me->receive_wound("sen",2*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N��׼���򣬶㿪��$n�Ľ��ֱ��һ�У�\n"NOR,me,ob);
        }
        break;

  }
        if( random(8) == 5 )
        {  
           set("eff_kee", 8000);
           set("eff_gin", 8000);
           set("eff_sen", 8000);
           set("kee", 8000);
           set("gin", 8000);
           set("sen", 8000);
           set("force", 22000);
           set("mana", 22000);
        }

        remove_call_out("check");
        call_out("check",2+random(2));
}                     
void die()
{
  object ob = query_temp("my_killer");
  if (environment())
    message("sound", HIW"������"NOR+"ͷ�ϵ���ֻ�۾�����һ���ֱ���������\n\n", environment());

  set("eff_kee", 8000);
  set("eff_gin", 8000);
  set("eff_sen", 8000);
  set("kee", 8000);
  set("gin", 8000);
  set("sen", 8000);
  set("force", 22000);
  set("mana", 22000);
  if (ob->query("bld/mother") == 1 &&  ob->query("bld/taxue") == 1 && ob->query("bld/laozhe") == 1 )
  {
if (random(50)> 25)
          { 
                if (environment())
          message("sound", HIW"������"NOR+"����һ�Բ����Ҷ��ˡ�\n\n", environment());
             this_player()->remove_all_killer();
             ob->remove_all_killer();
           ob->set("bld/erlang",1);  
             }
             else {  
                 if (environment())
    message("sound", HIW"������"NOR+"ͷ�ϵ���ֻ�۾�����һ���ֱ���������\n\n", environment());
             }
        
      }
}

void unconcious()
{
  die ();  
}

