#include <ansi.h>
inherit NPC;
 
void create()
{
        set_name("ħ����", ({ "tian wang", "chiguo tianwang", "shou", "tianwang", "wang" }) );
        set("gender", "����" );
        set("long","
�Ĵ�����֮һ�����ű����󹬰�ȫ���ص�����ͬС�ɡ���
���书�ƺ�������һ�ɣ������������������ɱ�־��У���
û����֪����ʲô��Ҳ������Ϊ��ˣ���ʲŷ�����������
���Ρ�\n"
        );
        set("class", "xian");
        set("title", "�ֹ�����");
        set("age",43);
        set("str",60);
        set("int",37);
        set("max_kee",5100);
        set("kee",5100);

        set("max_sen",5100);
        set("sen",5100);
        set("combat_exp",4500000);
        set("daoxing",4500000);
        set("force",5500);
        set("max_force",2500);
        set("mana",4500);
        set("max_mana",2250);
        set("force_factor", 270);
        set("mana_factor",220);


        set("eff_dx", 3500000);
        set("nkgain", 800);


        set_skill("unarmed",140);
        set_skill("changquan", 180);
        set_skill("parry",280);
        set_skill("dodge",380);
        set_skill("mace",380);
        set_skill("spells", 180);
        set_skill("wusi-mace",380);
        set_skill("force",380);
        set_skill("moshenbu", 340);
        map_skill("dodge", "moshenbu");
        map_skill("mace","wusi-mace");
        map_skill("parry","lunhui-zhang");
        map_skill("unarmed", "changquan");
        set("inquiry", ([
                "name" : "���¾��ǳֹ���������ʥ�Ͱ��ر����š�",
                "here" : "������Ǳ����ţ������Ǻ󹬽��ء�",
        ]) );
        setup();
        carry_object("/d/obj/weapon/mace/copperjian")->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}


void kill_ob (object ob)
{
  object me = this_object();

  call_out ("huahudiao",5+random(2),me,ob);  
  ::kill_ob(ob);
}



void huahudiao (object me, object ob)
{
  object huobing;
  int damage;

  if (! me)
    return;

  if( !living(me) )
    return;

  if (! ob)
    return;

  if (environment(ob) != environment(me))
    return;

  message_vision (HIY"$N������ȡ�������������ڿ��У�����һֻ����"
       +"����Ѫ�裬������������$nҧ����\n"NOR,me,ob);

  if ( (ob->query("force")+random(500)) > 4000 )

     message_vision (HIY"$N���һ�����󵨣�\n"
       +"�������ŵ���æ���$n�����С�\n"NOR,ob,me);
  else 
    {
     message_vision (HIY"���$N��ҧ��һ��Ѫ��ģ���Ŀ��ӣ�\n"NOR,ob,me);
     damage=(me->query("force"))/5; 
     if ( ob->query("kee") < damage ) ob->unconcious();
     else ob->add("kee",-damage);
    } 

  remove_call_out ("huahudiao");  
  call_out ("huahudiao",random(6)+4,me,ob);  
}


void die ()
{
  object me = this_object();
  message_vision (HIY"$N�ŵ����Ⱦ��ܡ�\n"NOR,me);
  destruct (this_object());
  return ;
}
