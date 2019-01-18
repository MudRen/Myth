//modified by vikee 2000.11
//under.c
#include <ansi.h>
inherit ROOM;
void create()
{
   set ("short","����̨");
   set ("long",
@LONG
    
����̨��ƽ̹���ʵĺ�ľһ������ɣ��������Ż��ƻ�Ƥ�ͽ�Ǯ��
Ƥ��̨�Ϸ���һ�����ɺ�����̫ʦ�Σ������ù���ǱȽ����ʵع�
������������ѡ��Ҳ�����������ѯ(checkscore)�Լ���ս������
һ�����ֵ�����(list),������ս(defend)��

LONG);
   set("no_flee",1);
   set("no_fight",1);
   set("no_magic",1);
   set("exits",([
     "south":"/d/city/wuguan",
   ]));
   set("alternative_die",1);
   setup();
}

void init()
{
   add_action("do_accept","defend");
}

int do_accept(string arg)
{  
   string myop,tempstr;
   int j;
   object ob,me; 
   me=this_player();
   if (me->is_busy()) return notify_fail("����æ���أ�\n");
   if (!arg) return notify_fail("��Ҫ��˭�д裿\n");    
   ob = LOGIN_D->find_body(arg);
   if (!ob) return notify_fail("�ף����� ���������\n");
   if (me->query("id")==arg) return notify_fail("������Լ��д�?\n");
   tempstr=ob->query_temp("objectob");
   if (tempstr!=me->query("id")) return notify_fail("�Է���û��������ս��\n");  
   if ( !present(ob,environment(me)) ) return notify_fail("������ս���˲������\n");
   if ( ob->is_busy() ) return notify_fail("�Է���æ���أ�\n"); 
   if ( sizeof(all_inventory(load_object(__DIR__"ground"))) >0 ) 
     {
       j=sizeof(all_inventory(load_object(__DIR__"ground")));
       while (j>0)
       {
         j=j-1;
         if (userp( all_inventory(load_object(__DIR__"ground") )[j]))
         return notify_fail("��̨���Ѿ������ˡ�\n");
       }
     }  
   message_vision("$N��$n˫˫����Ծ����̨,׼�����䡣\n",me,ob); 
   me->move(__DIR__"ground");
   ob->move(__DIR__"ground");
   me->set_temp("statusbef/kee",(int)me->query("kee"));
   me->set_temp("statusbef/eff_kee",(int)me->query("eff_kee"));
   me->set_temp("statusbef/sen",(int)me->query("sen"));
   me->set_temp("statusbef/eff_sen",(int)me->query("eff_sen"));
   me->set_temp("statusbef/force",(int)me->query("force"));
   me->set_temp("statusbef/mana",(int)me->query("mana"));
   me->set_temp("statusbef/kill_ob",ob);
   ob->set_temp("statusbef/kee",(int)ob->query("kee"));
   ob->set_temp("statusbef/sen",(int)ob->query("sen"));
   ob->set_temp("statusbef/eff_kee",(int)ob->query("eff_kee"));
   ob->set_temp("statusbef/eff_sen",(int)ob->query("eff_sen"));
   ob->set_temp("statusbef/force",(int)ob->query("force"));
   ob->set_temp("statusbef/mana",(int)ob->query("mana"));
   ob->set_temp("statusbef/kill_ob",me);
     ob->kill_ob(me);
     me->kill_ob(ob);
   ob->delete_temp("objectob");
   remove_call_out("wait_and_star");
   remove_call_out("finish_match");
   call_out("wait_and_start",2);
   return 1;
}

int wait_and_start()
{ object fan;
  object me,ob;
  object *allinv;
  allinv=all_inventory(environment(this_player()) );
  if (sizeof(allinv)<2) return 1;
  me=allinv[0];
  ob=allinv[1];
  message_vision(HIW"$N��$n���俪ʼ����ʱ����ӡ�\n"NOR,me,ob);
  fan->command("chat "+me->query("name")+"��"+ob->query("name")+"���俪ʼ����ʱ����ӡ�\n");
  "/cmds/std/kill"->main(me,(string)ob->query("id"));
  "/cmds/std/kill"->main(ob,(string)me->query("id"));
   call_out("finish_match",300); 
  return 1;
}
  
int finish_match()
{  object fan;
   int i,j;
  object me,ob;
   object *allinv,*playerinv;
   j=0;
   playerinv=({});
  allinv=all_inventory(load_object(__DIR__"ground"));
  if (sizeof(allinv)<2) return 1;
   i=sizeof(allinv);
   while (i>0)
   {
   i=i-1;
   if (userp(allinv[i]))
     {
     playerinv+=({allinv[i]});
     j=j+1;
     }
   }
   if (j<2) return 1;
   me=playerinv[0];
   ob=playerinv[1];
   fan=load_object(__DIR__"npc/fan");
   message_vision(HIG"$N��$n��ս���ٻغϣ�����ʤ�����ָ��³���Ϣ���д�������ս��\n"NOR,me,ob);
  me->remove_killer(ob);
  ob->remove_killer(me);
  me->move(__DIR__"under");
  ob->move(__DIR__"under");
   me->set("kee",me->query_temp("statusbef/kee"));
   me->set("eff_kee",me->query_temp("statusbef/eff_kee"));
   me->set("sen",me->query_temp("statusbef/sen"));
   me->set("eff_sen",me->query_temp("statusbef/eff_sen"));
   me->set("force",me->query_temp("statusbef/force"));
   me->set("mana",me->query_temp("statusbef/mana"));
   ob->set("kee",ob->query_temp("statusbef/kee"));
   ob->set("sen",ob->query_temp("statusbef/sen"));
   ob->set("eff_kee",ob->query_temp("statusbef/eff_kee"));
   ob->set("eff_sen",ob->query_temp("statusbef/eff_sen"));
   ob->set("force",ob->query_temp("statusbef/force"));
   ob->set("mana",ob->query_temp("statusbef/mana"));
  return 1;
}

void alternative_die(object me)
{ if (!userp(me))
  {
     set("alternative_die",0);
     me->die();
     set("alternative_die",1);
     return;
  }
   if (me->query("kee")<1)
        me->set("kee",10);
   if (me->query("eff_kee")<1)
        me->set("eff_kee",10);
   if (me->query("sen")<1)
        me->set("sen",10);
   if (me->query("eff_sen")<1)
        me->set("eff_sen",10);
  if (me->query_condition("no_pk_time"))
   {
     set("alternative_die",0);
     me->unconcious();
     set("alternative_die",1);
   }
     return;
 
}

