// ���� by Calvin 

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int long();
string leave();
void create()
{
       set_name(HIW"����"NOR, ({"shen long", "long"}));
       set("long",
"����һ�����кܴ���������,������ʵ�����Ը����\n");
       set("title", HIR"��ɫ����"HIG"֮"NOR);
       set("gender", "����");
       set("age", 1000);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("per", 40);
       set("int", 40);
       set("max_kee", 30000);
       set("max_sen", 30000);
       set("force", 30000);
       set("max_force", 30000);
       set("force_factor", 3000);
       set("max_mana", 30000);
       set("mana", 30000);
       set("mana_factor", 3000);
       set("combat_exp", 100000000);
       set("daoxing", 100000000);
       set("eff_dx", 10000);
       set("nkgain", 10000);
       set_skill("literate", 1000);
       set_skill("unarmed", 1000);
       set_skill("dodge", 1000);
       set_skill("force", 1000);
       set_skill("parry", 1000);
        setup();
        carry_object("/d/quest/longzhu/armor/pao")->wear();
      add_money("gold", 5+random(50));
}

void init()
{
add_action("do_wish","wish");
}
int do_wish(string arg)
{
object me=this_player();
string *ans=({"����","��ѧ","Ǳ��"});
int ans1;
if (arg=="0"||arg=="1"||arg=="2")
{sscanf(arg,"%d",ans1);arg=ans[ans1];}
 if( !arg ||
     (arg != "����"
   && arg != "Ǳ��"
&& arg != "��ѧ"))
return notify_fail(CYN"����˵�����Բ�ס����ֻ�����������������������:1.wish ����,2.wish ��ѧ,3.wish Ǳ�ܡ������������Ҫʲô,�һ����ʵ��!\n"NOR);
  if (arg=="����"&& !(me->query("shenlonggive1")))
{
 me->add("daoxing",random(100000));
 me->set("shenlonggive1",1);
message_vision (HIG "$N�����۾�����һ��˵������Ҫ"+arg+"��!\n",me);
message_vision("$N����$n˵��:"+HIW"�ð�,�����ϰ���ʵ��Ը��.\n"+HIC"������Ŀڤ˼,�����૵���߶:"+HIR "��������,�������� ����������������! ����Ī��~~~ \n",this_object(),me);
 message_vision(HIC "$N�о���һ��������������������ӿ��,��������ɢ��ȫ��.����,���巢����΢��ı仯!\n\n",me);
message_vision(HIC "$N����$n˵��:"+HIC+"��ʵ��Ը����.�Ҹûص��ҵ�������!\n˵��,ת����ʧ��ããʱ��֮��.\n\n",this_object(),me);
destruct(this_object());
}
else if (arg=="��ѧ"&& !(me->query("shenlonggive2"))) { 
me->add("combat_exp",random(100000));
 me->set("shenlonggive2",1);
message_vision (HIG "$N�����۾�����һ��˵������Ҫ"+arg+"��!\n",me);
message_vision("$N����$n˵��:"+HIW"�ð�,�����ϰ���ʵ��Ը��.\n"+HIC"������Ŀڤ˼,�����૵���߶:"+HIR "��������,�������� ����������������! ����Ī��~~~ \n",this_object(),me);
 message_vision(HIC "$N�о���һ��������������������ӿ��,��������ɢ��ȫ��.����,���巢����΢��ı仯!\n\n",me);
message_vision(HIC "$N����$n˵��:"+HIC+"��ʵ��Ը����.�Ҹûص��ҵ�������!\n˵��,ת����ʧ��ããʱ��֮��.\n\n",this_object(),me);
destruct(this_object());
}
else if (arg=="Ǳ��"&&!(me->query("shenlonggive3"))) {
  me->add("potential",random(100000));
  me->set("shenlonggive3",1);
 message_vision (HIG "$N�����۾�����һ��˵������Ҫ"+arg+"��!\n",me);
message_vision("$N����$n˵��:"+HIW"�ð�,�����ϰ���ʵ��Ը��.\n"+HIC"������Ŀڤ˼,�����૵���߶:"+HIR "��������,�������� ����������������! ����Ī��~~~ \n",this_object(),me);
message_vision(HIC "$N�о���һ��������������������ӿ��,��������ɢ��ȫ��.����,���巢����΢��ı仯!\n\n",me);
 message_vision(HIC "$N����$n˵��:"+HIC+"��ʵ��Ը����.�Ҹûص��ҵ�������!\n˵��,ת����ʧ��ããʱ��֮��.\n\n",this_object(),me);
}
if((me->query("shenlonggive1"))||(me->query("shenlonggive2"))||(me->query("shenlonggive3"))) return notify_fail(CYN "������ŭ��˵��:������Ը�����Ѿ�������,��Ҫ̫̰��ѽ!\n");
if((me->query("shenlonggive1"))&&(me->query("shenlonggive2"))&&(me->query("shenlonggive3"))) {message_vision(CYN "������ŭ��˵��:$n������Ը�����Ѿ�������,�����ٰ�����!\n",me);destruct(this_object());}
return 1;
}
string leave()
{
destruct(this_object());
message("vision",
HIM"........................................................................................................................"HIG"�ž�����պ�Ȼ����һ���װ�ĺ�����:"HIW"������λ~~~~~"HIM"........................................................................................................................"

     HIW"����"HIB"˵��:"HIW"�������ٻ�����,�ҵû�ȥ��"HIB"��"HIB"����,һ��Ѥ��,������ȥ�����ϵ���Ӱ��"HIM".............................................................................................................\n"NOR
  NOR,environment(),  this_object() );
}

