// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "��");
  set ("long", @LONG

��������һ��һ�ѵ����𣬶��Ķ�������һ��ʯ�����һ
�ڴ�ͭ����������һ�������������и�ʽ��Ƥ��������һ��
������ë�档��������һ���Ѻۣ����쵽������

LONG);

  set("exits", ([
        "southwest"   : __DIR__"qiandong",
      ]));
  set("objects", ([
        __DIR__"npc/yao" : 1,
      ]));

  setup();
}

void init ()
{
  add_action ("do_climb","climb");
}

int do_climb ()
{
  object who = this_player ();
  string midong = __DIR__"midong1";

  message_vision ("$N��ס�ұڣ�������ȥ��\n",who);  
  if (who->is_busy() || who->is_fighting() || 
	  present ("yao guai",this_object()))
  {
    message_vision ("$N���ұ��ϻ���������\n",who);  
    return 1;
  }
  midong[strlen(midong)-1] = '1'+random(5);
  who->move(midong);
  who->start_busy(2,2);

	if( random(2) ) {
  call_out ("sleeping",1,who);
  return 1;
	}
  call_out("fainting",1,who);
  return 1;
}

void sleeping (object who)
{
  message_vision ("�ض���ɢ����һ�ɴ̱ǵ�������$N��ʱ���Ȼ��\n\n",who);  
  message_vision ("$N��ǿգ��գ������۾������˸���Ƿ��\n",who);  
  who->set("last_sleep",time()-270);
  who->interrupt_me();
  who->command_function("sleep"); 
}
void fainting (object who)
{
	message_vision("ͻȻ�Ӱ��������һ�����̣�$N��ʱͷ�ؽ��ᡣ����\n", who);
	who->unconcious();
}
