inherit ROOM;

void create ()
{
  set ("short", "������");
  set ("long", @LONG

����м���ʯ�Σ�����һ��ʯ�������ߵ������ͱڣ�����ƽ
�ڡ����Ǹ��÷�⡣����������̸��˵�صĵط��� 
LONG);
 
        set("objects", 
        ([ //sizeof() == 3
        ]));
  set("exits", ([
        "south" : __DIR__"lingdao4",
        "northdown"  : __DIR__"lingdao3",
      ]));

  set("outdoors", __DIR__);

  setup();
}
int valid_leave (object me, string dir)
{
	if ( dir == "northdown" )
	call_out("leave_here",60+random(120),me);
	return 1;
}
void leave_here(object me)
{
      object xiushi;
      if (! present("xiushi",environment(me)))
      {
        xiushi = new(__DIR__"npc/xiushi");
        xiushi->move(environment(me));
	tell_object(me,"��Ȼһ��ɳɳ����ת�ۼ䣬���Ӳ��������������\n");
	call_out("destruct_me",300+random(120),xiushi);
      }else{
	tell_object(me,"Ī�������һ��ɳɳ��������\n");
      }
}
void destruct_me(object me)
{
	if(me){
	destruct(me);
	tell_object(this_player(),"������ʿٿ��һ����û���ټ���\n");
	}
}
