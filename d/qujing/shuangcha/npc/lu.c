//Cracked by Roath
//  ����֮�� ������
//  by happ@YSZZ 2000.4.3
//  /d/qujing/shuangcha/npc/lu.c


inherit NPC;

void create()
{
   set_name("÷��¹", ({ "meihua lu" }) );
   set("race", "Ұ��");
   set("age", 3);
   set("long", "һֻ���Ӻܳ���÷��¹��\n");
   
   set("str", 32);
   set("dex", 36);

   set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "����" }) );
   set("verbs", ({ "bite", "claw" }) );

   set("chat_msg", ({
     (: call_other, this_object(), "random_move" :),
        }));
     
   set_temp("apply/attack", 20);
   set_temp("apply/armor", 10);

   setup();
}

int accept_object(object who, object ob)
{
   if( ob->id("grass") ) {
     set_leader(who);
     message("vision", name() + "�ܸ��˵ĳ���������Ĳݡ�\n", environment());
     return 1;
   }
}
