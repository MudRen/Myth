//Cracked by Roath

inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�����൱��ª����������һ�Ų�ϯ�����ǻ�ɽҰ������˾�������
��˯�����㲻��̾������ħ�������������갡��

LONG);

  set("exits", ([
        "south"  : __DIR__"indoor",

      ]));
	  set("sleep_room", 1);
	  set("light_up", 1);

  setup();
}

void init()
{
  	add_action("do_sleep", "sleep");
}
int do_sleep(string arg)
{	object ob;
  	object me=this_player();
	if( me->query("obstacle/yz") !="done" || !(me->query_condition("eyeill")))
	{ 
		if(me->query_temp("need_sleep")=="yes")
			me->delete_temp("need_sleep");
	return 0;
	}
	message_vision("$N����׼����Ϣһ�¡�\n",me);
	ob=new("/d/qujing/huangfeng/npc/lingji1");
	ob->move(this_object());
	message_vision("$N���˹�����������ϯǰ��\n",ob);
	call_out("zhibing",1,me,ob);	
	return 1;
} 
int zhibing(object me,object ob)
{
	message_vision("$N˵��������ִ���ȴ����ҩ�ġ��Ϻ�Ҳ��Щӭ�����ᣬ"+
		"�������ˣ�����һ����\n���������������Ӹ࡯������һ�з��ۡ����Ը��(agree)һ�ԣ�\n",ob);
	me->set_temp("lingjiask","yes");
	return 1;
}
	
