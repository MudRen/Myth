//Cracked by Roath


inherit ROOM;

void create ()
{
  set ("short", "����");
  set ("long", @LONG

�Ի��˼ҵ����Һͱ��˼ҵ�Ҳ�ǲ�һ�����Ի��˼Ҿ�����һЩ
�����ëƤ�������죬��ůЧ����һ��ı���Ҫ�õĶࡣ

LONG);

  set("exits", ([
        "north" : __DIR__"yard",
      ]));
  setup();

}
void init()
{
  add_action("do_sleep", "sleep");
}
int do_sleep(string arg)
{
  object me=this_player();
      if( me->query_temp("sc_can_sleep"))
  {
  	 message_vision("��㱵أ�$N�ƺ������Լ�������һ���ط���\n",me); 
  	 me->move("/d/death/zhengtang");
    me->set_temp("can_ask",1);
  	 return 1;
  }
   return 0;
  
}   
