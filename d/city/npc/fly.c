/***************************************
MUDLIB��Biographies         ����մ���  
Created Admin By Waiwai@2001/02/18
Admin Email��wkzstory@21cn.com         
****************************************/
// Created by waiwai@2000/07/10
// Update by waiwai@2001/04/17

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(CYN"��Ӭ"NOR, ({ "fly" }));
	set("race", "Ұ��");
        set("gender", "����");
	set("age", 1);
	set("long", "һֻ��ͷ��Ӭ��ר���ڷ�����ת��\n");
	
	set("str", 30);
	set("dex", 30);

	set("limbs", ({ "ͷ��", "���", "ǰ��", "���"}) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
              "��Ӭ��ͣ������ߴ�ת��������������\n",
		"��Ӭͣ��һ�ѷ���ϣ�̰����˱���š�\n",
	 	"��ӬͻȻһ�����壬�������ıǿף��ַ��˳�����\n",
		"��Ӭ���������ͣ��������ϣ��������ġ�\n",
		"��Ӭ����һ�������񣬷ɵ������е������������\n",
		"��Ӭ��С�ĵ�������Ŀ������������¶ǣ�������Ż��һ�ض��ǡ�\n"}));
	set_temp("apply/attack", 10);
       set_temp("apply/parry", 10);
       set_leader(1);

	setup();
}

void init()
{	
	object me;

	set_heart_beat(1);
	::init();
	if( interactive(me = this_player()) ) {
		remove_call_out("killing");
		call_out("follow", 1, me);
	}
}

void follow(object who)
{
  object me;
  me = this_object();
if( !wizardp(who)) {//��ֹfly��follow wiz 
  if (who &&
      environment(who) == environment(me) &&
      living(me) &&
      who->query_temp("has_paid") <= 0)  {
    command("follow " + who->query("id"));
    me->set_leader(who);

  }
}
}


void die()
{
//	object ob;
	message_vision("$N"HIB"���˵�һ��������......\n"NOR, this_object());
	destruct(this_object());
}